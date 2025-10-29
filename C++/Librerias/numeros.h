#ifndef NUMEROS_H
#define NUMEROS_H

#include <iostream>
using namespace std;

// Función para potencia
long potencia(long base, int exponente) {
    long resultado = 1;
    for(int i = 0; i < exponente; i++)
        resultado *= base;
    return resultado;
}

// Suma de dígitos
int sumaDigitos(int n) {
    int suma = 0;
    while(n != 0) {
        suma += n % 10;
        n /= 10;
    }
    return suma;
}

// Suma de divisores propios
int sumaDivisoresPropios(int n) {
    int suma = 0;
    for(int i = 1; i <= n/2; i++)
        if(n % i == 0)
            suma += i;
    return suma;
}

// Cantidad de dígitos
int cantidadDigitos(int n) {
    int count = 0;
    if(n == 0) return 1;
    while(n != 0) {
        count++;
        n /= 10;
    }
    return count;
}

// Cantidad de divisores propios
int cantidadDivisoresPropios(int n) {
    int count = 0;
    for(int i = 1; i <= n/2; i++)
        if(n % i == 0)
            count++;
    return count;
}

// Raíz cuadrada entera aproximada
int raizCuadrada(int n) {
    int i = 1;
    while(i*i <= n) i++;
    return i - 1;
}

// Número primo
bool esPrimo(int n) {
    if(n <= 1) return false;
    for(int i = 2; i <= raizCuadrada(n); i++)
        if(n % i == 0) return false;
    return true;
}

// Número perfecto
bool esPerfecto(int n) {
    return sumaDivisoresPropios(n) == n;
}

// Números amigos
bool sonAmigos(int a, int b) {
    return sumaDivisoresPropios(a) == b && sumaDivisoresPropios(b) == a;
}

// Número Narcisista
bool esNarcisista(int n) {
    int suma = 0, temp = n;
    int digitos = cantidadDigitos(n);
    while(temp != 0) {
        int d = temp % 10;
        suma += potencia(d, digitos);
        temp /= 10;
    }
    return suma == n;
}

// Número abundante o deficiente
string abundanteODeficiente(int n) {
    int suma = sumaDivisoresPropios(n);
    if(suma > n) return "Abundante";
    else if(suma < n) return "Deficiente";
    else return "Perfecto";
}

#endif
