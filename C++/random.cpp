#include <iostream>
#include <random>       // Librería moderna de aleatorios
using namespace std;

int main() {
    random_device rd;                        // 1. Semilla aleatoria
    mt19937 generador(rd());                // 2. Motor de números pseudoaleatorios
    uniform_int_distribution<int> dist(6, 20); // 3. Distribución uniforme de enteros

    int numero = dist(generador);           // 4. Generar número aleatorio
    cout << "Número aleatorio: " << numero << endl;

    return 0;
}
