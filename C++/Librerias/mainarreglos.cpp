#include "arreglos.h"
void mostrar(int arr[], int n){
    for(int i=0;i<n;i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {5, 2, 9, 1, 7};
    int n = 5;

    cout << "Original: "; mostrar(arr,n);

    ordenarBurbuja(arr,n);
    cout << "Burbuja: "; mostrar(arr,n);

    int arr2[] = {5,2,9,1,7};
    ordenarInsercion(arr2,n);
    cout << "Inserción: "; mostrar(arr2,n);

    int arr3[] = {5,2,9,1,7};
    ordenarSeleccion(arr3,n);
    cout << "Selección: "; mostrar(arr3,n);

    int arr4[] = {5,2,9,1,7};
    ordenarMergeSort(arr4,0,n-1);
    cout << "Merge Sort: "; mostrar(arr4,n);

    int arr5[] = {5,2,9,1,7};
    ordenarQuickSort(arr5,0,n-1);
    cout << "Quick Sort: "; mostrar(arr5,n);

    int val = 7;
    int pos = buscarLineal(arr,n,val);
    cout << val << " encontrado con búsqueda lineal en índice " << pos << endl;

    pos = buscarBinaria(arr,n,val);
    cout << val << " encontrado con búsqueda binaria en índice " << pos << endl;

    return 0;
}