#include <iostream>
#include <random>
#include <vector>
#include <utility>

using namespace std;

// Burbuja recursiva
void ordenarVector(vector<int>& arr, int n) {
    // Caso base: si el sub-arreglo tiene 1 o menos elementos, ya está ordenado
    if (n <= 1) return;

    // Una pasada completa empuja el elemento mayor a la posición n - 1
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }

    // Llamada recursiva con tamaño n - 1
    ordenarVector(arr, n - 1);
}

int main() {
    int n;
    cout << "Ingrese N: ";
    cin >> n;

    vector<int> arr(n);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 100);

    for (int i = 0; i < n; i++) {
        arr[i] = dist(gen);
    }

    cout << "\nArreglo original:\n";
    for (int i = 0; i < n; i++) {
        cout << "arr[" << i << "] = " << arr[i] << "\n";
    }

    // 1. Ejecutar el ordenamiento
    ordenarVector(arr, arr.size());

    // 2. Imprimir el resultado
    cout << "\nVector ordenado:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}
