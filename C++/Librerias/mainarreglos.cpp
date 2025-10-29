#include "arreglos.h"

int main() {
    int arr[] = {5, 2, 9, 1, 7};
    int n = 5;

    cout << "Suma: " << suma(arr,n) << endl;
    cout << "Promedio: " << promedio(arr,n) << endl;
    cout << "Máximo: " << maximo(arr,n) << endl;
    cout << "Mínimo: " << minimo(arr,n) << endl;

    invertir(arr,n);
    cout << "Invertido: ";
    for(int i=0;i<n;i++) cout << arr[i] << " ";
    cout << endl;

    ordenarburbuja(arr,n);
    cout << "Ordenado: ";
    for(int i=0;i<n;i++) cout << arr[i] << " ";
    cout << endl;

    int val = 7;
    int pos = buscar(arr,n,val);
    if(pos != -1) cout << val << " encontrado en índice " << pos << endl;
    else cout << val << " no encontrado" << endl;

    return 0;
}
