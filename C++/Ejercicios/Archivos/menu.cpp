#include <iostream>
#include <chrono>
#include <thread>  // Para sleep_for
using namespace std;

int main() {
    int opcion;

    // Mostramos el menú carácter por carácter con \n para saltos de línea
    string menu = "===== MENÚ PRINCIPAL =====\n"
                  "1. Ver perfil\n"
                  "2. Configuración\n"
                  "3. Ayuda\n"
                  "4. Salir\n"
                  "Seleccione una opción: ";

    // Efecto máquina de escribir
    for (char c : menu) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(30)); // velocidad
    }

    cin >> opcion;

    // Procesamos la opción
    string respuesta;
    if (opcion == 1)
        respuesta = "Mostrando perfil...\n";
    else if (opcion == 2)
        respuesta = "Abriendo configuración...\n";
    else if (opcion == 3)
        respuesta = "Mostrando ayuda...\n";
    else if (opcion == 4)
        respuesta = "Saliendo del programa...\n";
    else
        respuesta = "Opción inválida. Intente de nuevo.\n";

    // Mostrar respuesta con efecto
    for (char c : respuesta) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(30));
    }

    return 0;
}
