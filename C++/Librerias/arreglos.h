#ifndef ARREGLOS_H
#define ARREGLOS_H

#include <iostream>
using namespace std;

// --------------------- Suma de elementos ---------------------
int suma(int arr[], int n) {
    int total = 0;
    for(int i = 0; i < n; i++) total += arr[i];
    return total;
}

// --------------------- Promedio ---------------------
double promedio(int arr[], int n) {
    if(n == 0) return 0;
    return (double)suma(arr,n)/n;
}

// --------------------- Máximo y Mínimo ---------------------
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

// --------------------- Invertir ---------------------
void invertir(int arr[], int n) {
    for(int i = 0; i < n/2; i++) {
        int temp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = temp;
    }
}

// --------------------- Ordenar (burbuja) ---------------------
void ordenarburbuja(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-1-i; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// --------------------- Búsqueda lineal ---------------------
int buscar(int arr[], int n, int valor) {
    for(int i = 0; i < n; i++)
        if(arr[i] == valor) return i; // devuelve índice
    return -1; // no encontrado
}

#endif
