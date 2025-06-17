#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 1, 4, 2, 8};      // Nuestra lista desordenada
    int n = sizeof(arr)/sizeof(arr[0]); // Calculamos el tamaño del arreglo

    for(int i = 0; i < n-1; i++) {      // Repetimos el proceso varias veces
        bool swap_flag = false;        // Señal para saber si hubo intercambios

        for(int j = 0; j < n-i-1; j++) {   // Recorremos los elementos aún sin ordenar
            if(arr[j] > arr[j+1]) {       // Si el número actual es mayor al siguiente
                int temp = arr[j];        // Guardamos el actual
                arr[j] = arr[j+1];        // Lo cambiamos por el siguiente
                arr[j+1] = temp;          // Y ponemos el actual donde estaba el siguiente
                swap_flag = true;         // Hubo un intercambio
            }
        }

        if(!swap_flag)     // Si no hubo cambios, ya está ordenado
            break;
    }

    cout << "Arreglo ordenado: ";
    for(int i = 0; i < n; i++)         // Mostramos el resultado
        cout << arr[i] << " ";

    return 0;   // Fin del programa
}
