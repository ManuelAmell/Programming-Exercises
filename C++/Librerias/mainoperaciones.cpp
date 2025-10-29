#include "numeros.h"

int main() {
    int n = 28;
    int m = 496;
    
    cout << "Potencia 2^5 = " << potencia(2,5) << endl;
    cout << "Suma de dígitos de 123 = " << sumaDigitos(123) << endl;
    cout << "Suma de divisores propios de " << n << " = " << sumaDivisoresPropios(n) << endl;
    cout << n << " tiene " << cantidadDigitos(n) << " dígitos" << endl;
    cout << n << " tiene " << cantidadDivisoresPropios(n) << " divisores propios" << endl;
    cout << n << " es primo? " << (esPrimo(n) ? "Sí" : "No") << endl;
    cout << n << " es perfecto? " << (esPerfecto(n) ? "Sí" : "No") << endl;
    cout << "28 y 496 son amigos? " << (sonAmigos(n,m) ? "Sí" : "No") << endl;
    cout << "153 es narcisista? " << (esNarcisista(153) ? "Sí" : "No") << endl;
    cout << n << " es " << abundanteODeficiente(n) << endl;
    
    return 0;
}
