#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int primos[30], cprimos = 0;

    for (int i = 2; i < 500 && cprimos < 30; i++) {
        bool esPrimo = true;

        for (int x = 2; x <= sqrt(i); x++) {
            if (i % x == 0) {
                esPrimo = false;
                break;  // No es primo, salimos del ciclo
            }
        }

        if (esPrimo) {
            primos[cprimos] = i;
            cprimos++;
        }
    }

    // Mostrar los primos encontrados
    cout << "Los primeros 30 números primos son:\n";
    for (int i = 0; i < cprimos; i++) {
        cout << primos[i] << " ";
    }
    cout << endl;

    return 0;
}
