#include <iostream>
using namespace std;

// Función iterativa que suma los dígitos de un número
int suma(int u)
{
    int total = 0;
    while (u > 0) {
        total += u % 10; // extrae el último dígito
        u /= 10;         // elimina el último dígito
    }
    return total;
}

int main() {
    int nro;
    int opc;

    do {
        cout << "Ingrese un numero para calcular la suma de sus digitos: ";
        cin >> nro;

        cout << "Suma de los digitos de " << nro << " = " << suma(nro) << endl;

        cout << "¿Desea continuar? (1 = sí, 0 = no): ";
        cin >> opc;

    } while (opc == 1);

    return 0;
}
