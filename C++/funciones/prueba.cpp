#include <iostream>
using namespace std;

int bubbleshort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Intercambiar arr[j] y arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return 0;
}
float quickshort(int arr[], int low, int high) {//sin swap

    if (low < high) {
        // Elegir el pivote (aquí se elige el último elemento)
        int pivot = arr[high];
        int i = (low - 1); // Índice del elemento más pequeño

        for (int j = low; j < high; j++) {
            // Si el elemento actual es menor o igual al pivote
            if (arr[j] <= pivot) {
                i++; // Incrementar el índice del elemento más pequeño
                arr[i] = arr[j];
            }
        }
        arr[i + 1] = arr[high];
        int pi = i + 1;

        // Ordenar recursivamente los elementos antes y después de la partición
        quickshort(arr, low, pi - 1);
        quickshort(arr, pi + 1, high);
    }
    return 0;
}
float inserctionshort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Mover los elementos de arr[0..i-1], que son mayores que key,
        // a una posición adelante de su posición actual
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    //mostrar el array ordenado
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
int main(){


    cout << "hola mundo";
    return 0;
}