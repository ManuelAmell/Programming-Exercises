#include <iostream>
#include <string>
#include <iomanip>
#include <sys/ioctl.h> // Para obtener el tamaño de la terminal
#include <unistd.h>    // Necesario para ioctl()
using namespace std;

// 🔹 Función para obtener el ancho actual de la terminal
int obtenerAnchoTerminal() {
    struct winsize w;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == -1) {
        return 80; // Valor por defecto si no se puede obtener
    }
    return w.ws_col;
}

// 🔹 Función para imprimir texto centrado con color
void imprimirCentrado(const string& texto, const string& color = "\033[0m") {
    int ancho = obtenerAnchoTerminal();
    int espacio = (ancho - (int)texto.size()) / 2;
    if (espacio < 0) espacio = 0;
    cout << setw(espacio + texto.size()) << color << texto << "\033[0m" << endl;
}

int main() {
    imprimirCentrado("===================================", "\033[1;34m");
    imprimirCentrado("   CENTRO MÉDICO VIDA SALUDABLE   ", "\033[1;32m");
    imprimirCentrado("===================================", "\033[1;34m");
    cout << endl;
    imprimirCentrado("Bienvenido al sistema de citas médicas", "\033[1;36m");
    imprimirCentrado("Desarrollado en C++", "\033[1;33m");
    cout << endl;

    return 0;
}
