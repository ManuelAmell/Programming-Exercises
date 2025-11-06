// escaner_linux.cpp
#include <iostream>
#include <string>
#include <vector>
#include <cstring>      // memset, strerror
#include <cerrno>
#include <unistd.h>     // close
#include <fcntl.h>      // fcntl
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <netinet/in.h>

bool is_port_open(const std::string &host, int port, int timeout_ms) {
    struct addrinfo hints{}, *res = nullptr;
    hints.ai_family = AF_INET;          // IPv4; cambiar a AF_UNSPEC para IPv4/IPv6
    hints.ai_socktype = SOCK_STREAM;

    std::string port_str = std::to_string(port);
    if (getaddrinfo(host.c_str(), port_str.c_str(), &hints, &res) != 0) {
        return false;
    }

    int sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sock < 0) {
        freeaddrinfo(res);
        return false;
    }

    // Poner socket en modo no bloqueante
    int flags = fcntl(sock, F_GETFL, 0);
    fcntl(sock, F_SETFL, flags | O_NONBLOCK);

    int ret = connect(sock, res->ai_addr, res->ai_addrlen);
    if (ret == 0) {
        // Conexión inmediata (rara)
        fcntl(sock, F_SETFL, flags); // restaurar
        close(sock);
        freeaddrinfo(res);
        return true;
    } else if (errno != EINPROGRESS) {
        // Error inmediato distinto a "conexión en progreso"
        fcntl(sock, F_SETFL, flags);
        close(sock);
        freeaddrinfo(res);
        return false;
    }

    // Esperar con select hasta timeout_ms
    fd_set wfds;
    FD_ZERO(&wfds);
    FD_SET(sock, &wfds);
    struct timeval tv{};
    tv.tv_sec = timeout_ms / 1000;
    tv.tv_usec = (timeout_ms % 1000) * 1000;

    ret = select(sock + 1, nullptr, &wfds, nullptr, &tv);
    if (ret > 0) {
        // Comprobar errores en la conexión
        int so_error = 0;
        socklen_t len = sizeof(so_error);
        getsockopt(sock, SOL_SOCKET, SO_ERROR, &so_error, &len);
        fcntl(sock, F_SETFL, flags);
        close(sock);
        freeaddrinfo(res);
        return (so_error == 0);
    } else {
        // timeout o error
        fcntl(sock, F_SETFL, flags);
        close(sock);
        freeaddrinfo(res);
        return false;
    }
}

int main() {
    std::string ip;
    std::cout << "Introduce la IP o hostname a escanear: ";
    if (!(std::cin >> ip)) return 1;

    std::cout << "[*] Comprobando host en puerto 80 (si responde, asumimos activo)...\n";
    if (is_port_open(ip, 80, 700)) {
        std::cout << "[+] El host \033[32m" << ip << "\033[0m parece estar activo.\n";
    } else {
        std::cout << "[-] El host no responde en el puerto 80 (puede estar caído o protegido por firewall).\n";
    }

    std::cout << "[*] Escaneando puertos 1-1024 (timeout 250 ms por puerto)...\n";
    for (int puerto = 1; puerto <= 1024; ++puerto) {
        if (is_port_open(ip, puerto, 250)) {
            std::cout << "[+] Puerto abierto: \033[32m" << puerto << "\033[0m\n";
        }
    }

    std::cout << "[*] Escaneo finalizado.\n";
    return 0;
}
