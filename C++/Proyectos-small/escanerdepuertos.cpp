#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <string>
#pragma comment(lib, "ws2_32.lib")  // Vincula la librería Winsock

int main() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Error al iniciar Winsock.\n";
        return 1;
    }

    std::string ip;
    std::cout << "Introduce la IP a escanear: ";
    std::cin >> ip;

    SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == INVALID_SOCKET) {
        std::cerr << "No se pudo crear el socket.\n";
        WSACleanup();
        return 1;
    }

    sockaddr_in target{};
    target.sin_family = AF_INET;
    target.sin_port = htons(80);
    if (inet_pton(AF_INET, ip.c_str(), &target.sin_addr) <= 0) {
        std::cerr << "IP no válida.\n";
        closesocket(sock);
        WSACleanup();
        return 1;
    }

    std::cout << "[*] Comprobando si el host está activo...\n";
    if (connect(sock, (sockaddr*)&target, sizeof(target)) == 0) {
        std::cout << "[+] El host \033[32m" << ip << "\033[0m está activo.\n";

        std::cout << "[*] Escaneando puertos comunes...\n";
        for (int puerto = 1; puerto <= 1024; puerto++) {
            SOCKET sockScan = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
            if (sockScan == INVALID_SOCKET) continue;

            sockaddr_in addr{};
            addr.sin_family = AF_INET;
            addr.sin_port = htons(puerto);
            inet_pton(AF_INET, ip.c_str(), &addr.sin_addr);

            if (connect(sockScan, (sockaddr*)&addr, sizeof(addr)) == 0) {
                std::cout << "[+] Puerto abierto: \033[32m" << puerto << "\033[0m\n";
            }

            closesocket(sockScan);
        }
    } else {
        std::cout << "[-] El host no está activo o no responde.\n";
    }

    closesocket(sock);
    WSACleanup();
    return 0;
}

