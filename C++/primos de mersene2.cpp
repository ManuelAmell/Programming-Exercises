#include <iostream>
#include <cmath> // Para usar sqrt()
using namespace std;

int main() {
    long p;
    int cantidad_divisores = 0;

    // Entrada del número primo
    do {
        cout << "Ingrese un numero primo para verificar si genera un primo de Mersenne: ";
        cin >> p;

        cantidad_divisores = 0;
        for (int i = 1; i <= p; i++) {
            if (p % i == 0) {
                cantidad_divisores++;
            }
        }

        if (cantidad_divisores == 2) {
            cout << "✓ Es primo. Continuamos...\n\n";
        } else {
            cout << "✗ No es primo. Intente nuevamente...\n\n";
        }

    } while (cantidad_divisores != 2);

    // Calculamos 2^p - 1
    long long resultado = 1;
    for (int i = 1; i <= p; i++) {
        resultado *= 2;
    }
    resultado -= 1;

    cout << "Evaluando si " << resultado << " (2^" << p << " - 1) es primo...\n";

    // Verificar si el resultado es primo
    int divisores_mersenne = 0;
    for (long long i = 1; i <= sqrt(resultado); i++) {
        if (resultado % i == 0) {
            divisores_mersenne++;
            if (i != resultado / i) {
                divisores_mersenne++;
            }
        }
    }

    // Mostrar resultado
    if (divisores_mersenne == 2) {
        cout << "✓ " << resultado << " es un primo de Mersenne :D\n";
    } else {
        cout << "✗ " << resultado << " no es un primo de Mersenne\n";
    }

    return 0;
}
