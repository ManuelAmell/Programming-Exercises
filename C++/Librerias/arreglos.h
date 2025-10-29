#ifndef ARREGLOS_H
#define ARREGLOS_H

#include <iostream>
using namespace std;

// --------------------- Funciones básicas ---------------------
int suma(int arr[], int n) {
    int total = 0;
    for(int i = 0; i < n; i++) total += arr[i];
    return total;
}

double promedio(int arr[], int n) {
    if(n == 0) return 0;
    return (double)suma(arr,n)/n;
}

int maximo(int arr[], int n) {
    if(n == 0) return 0;
    int max = arr[0];
    for(int i = 1; i < n; i++)
        if(arr[i] > max) max = arr[i];
    return max;
}

int minimo(int arr[], int n) {
    if(n == 0) return 0;
    int min = arr[0];
    for(int i = 1; i < n; i++)
        if(arr[i] < min) min = arr[i];
    return min;
}

void invertir(int arr[], int n) {
    for(int i = 0; i < n/2; i++) {
        int temp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = temp;
    }
}

// --------------------- Ordenamientos ---------------------

// Burbuja
void ordenarBurbuja(int arr[], int n) {
    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < n-1-i; j++)
            if(arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
}

// Inserción
void ordenarInsercion(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i-1;
        while(j >=0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// Selección
void ordenarSeleccion(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        int min_idx = i;
        for(int j = i+1; j < n; j++)
            if(arr[j] < arr[min_idx]) min_idx = j;
        swap(arr[i], arr[min_idx]);
    }
}

// Merge Sort (requiere función auxiliar)
void merge(int arr[], int l, int m, int r) {
    int n1 = m-l+1, n2 = r-m;
    int L[n1], R[n2];
    for(int i=0;i<n1;i++) L[i]=arr[l+i];
    for(int i=0;i<n2;i++) R[i]=arr[m+1+i];

    int i=0,j=0,k=l;
    while(i<n1 && j<n2) {
        if(L[i]<=R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while(i<n1) arr[k++] = L[i++];
    while(j<n2) arr[k++] = R[j++];
}

void ordenarMergeSort(int arr[], int l, int r) {
    if(l<r) {
        int m = l+(r-l)/2;
        ordenarMergeSort(arr,l,m);
        ordenarMergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

// Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void ordenarQuickSort(int arr[], int low, int high) {
    if(low<high){
        int pi = partition(arr, low, high);
        ordenarQuickSort(arr, low, pi-1);
        ordenarQuickSort(arr, pi+1, high);
    }
}

// --------------------- Búsquedas ---------------------

// Lineal
int buscarLineal(int arr[], int n, int valor){
    for(int i=0;i<n;i++)
        if(arr[i]==valor) return i;
    return -1;
}

// Binaria (arreglo ordenado)
int buscarBinaria(int arr[], int n, int valor){
    int l=0,r=n-1;
    while(l<=r){
        int m=l+(r-l)/2;
        if(arr[m]==valor) return m;
        else if(arr[m]<valor) l=m+1;
        else r=m-1;
    }
    return -1;
}

#endif