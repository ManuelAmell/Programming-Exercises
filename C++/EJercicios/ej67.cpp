#include <iostream>
#include <windows.h>
#include <conio.h> // Para _getch()
#define nombre "manuel amell" // macro
#define salir return 0;       // macro para salir
#define VERSION_LITE          // definición de versión
#define ESC 27                // código ASCII para Escape

using namespace std;

int main() {
    #ifdef VERSION_LITE
        cout << "Cargando versión ligera...\n";
    #endif

    #ifndef VERSION_LITE
        cout << "Cargando versión completa...\n";
    #endif

    const float PI = 3.14f;   //fpara floats sino el compilador les asigna double
    float e = 2.781f;         
    int numero = 2;           

    int arr[5] = {1, 2, 3, 4}; // arr[4] se vuelve 0 automáticamente

    cout << numero << endl;

    cout << "Elementos y sus direcciones:\n";
    for (int i = 0; i < 5; i++) {
        cout << "arr[" << i << "] = " << arr[i]
             << " \tDirección: " << &arr[i] << endl;
    }

    int opcion = 0;
    while (opcion != ESC) {
        cout << "\nPresiona ESC para salir...\n";
        opcion = _getch(); // captura tecla sin necesidad de Enter
        Sleep(500); // medio segundo
    }
    cout <<"PI :"<<PI<<endl;
    cout <<"euler "<< e<<endl;
    cout << "\nTamaño total del arreglo arr: " << sizeof(arr) << " bytes" << endl;
    cout << "Tamaño de un elemento arr[0]: " << sizeof(arr[0]) << " bytes" << endl;

    int totalElementos = sizeof(arr) / sizeof(arr[0]);
    cout << "Cantidad de elementos en arr: " << totalElementos << endl;

    cout << "\nDirección del arreglo (arr): " << arr << endl;

    cout << "\nValores como float multiplicados por 0.1:\n";
    for (int i = 0; i < 5; i++) {
        cout << static_cast<float>(arr[i]) * 0.1f << endl;
    }

    cout << nombre << endl;

    cin.ignore();
    return 0;
}
