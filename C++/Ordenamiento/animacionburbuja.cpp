#include <iostream>
#include <windows.h> // Para usar Sleep en milisegundos
using namespace std;

void mostrarArreglo(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
        Sleep(350);
    }
    cout << endl;
}

void bubbleSortAnimado(int arr[], int n) {
    cout << "\n Estado inicial:\n";
    mostrarArreglo(arr, n);
    cout << "--------------------------\n";
    Sleep(900);

    for (int i = 0; i < n - 1; i++) {
        cout << " Vuelta " << i + 1 << ":\n";
        Sleep(1300);

        for (int j = 0; j < n - i - 1; j++) {
            cout << "  Comparando " << arr[j] << " y " << arr[j + 1];

            if (arr[j] > arr[j + 1]) {
                cout << " -> intercambio \n";
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            } else {
                cout << " -> no hago nada \n";
            }

            cout << "  Estado actual: ";
            mostrarArreglo(arr, n);
            cout <<endl;
            Sleep(1500); // Pausa después de cada comparación
        }

        cout << "--------------------------\n";
        Sleep(500);
    }

    cout << "Orden final:\n";
    mostrarArreglo(arr, n);
    Sleep(3000);
    cout << " Arreglo ordenado con exito.\n";
}

int main() {
    int arr[] = {5, 1, 4, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSortAnimado(arr, n);

    return 0;
}
