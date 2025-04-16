#include <iostream>
#include <windows.h>

int main() {
    SetConsoleOutputCP(65001); // Fuerza UTF-8 en la terminal
    std::cout << "Español, canción, corazón, piñata, ñoño" << std::endl;
    return 0;
}