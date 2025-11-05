#include <iostream>
using namespace std;

int main() {
    cout << "\033[0;31mRojo\033[0m" << endl;        // Rojo
    cout << "\033[0;32mVerde\033[0m" << endl;       // Verde
    cout << "\033[0;33mAmarillo\033[0m" << endl;    // Amarillo
    cout << "\033[0;34mAzul\033[0m" << endl;        // Azul
    cout << "\033[0;35mMagenta\033[0m" << endl;     // Magenta
    cout << "\033[0;36mCian\033[0m" << endl;        // Cian
    cout << "\033[0;37mBlanco\033[0m" << endl;      // Blanco
    cout << "\033[1;30mGris oscuro\033[0m" << endl; // Gris oscuro

    cout << "\n\033[1;41mFondo rojo\033[0m" << endl;   // Fondo rojo
    cout << "\033[1;42mFondo verde\033[0m" << endl;    // Fondo verde
    cout << "\033[1;44mFondo azul\033[0m" << endl;     // Fondo azul
    cout << "\033[1;45mFondo magenta\033[0m" << endl;  // Fondo magenta
    cout << "\033[1;46mFondo cian\033[0m" << endl;     // Fondo cian
    cout << "\033[1;47mFondo blanco\033[0m" << endl;   // Fondo blanco

    return 0;
}
