// ejemplos_cmat.cpp
// Operaciones fundamentales con arreglos, matrices y números peculiares
// Sin funciones externas, solo usando <iostream> y <cmath>

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Sección 1: Porcentaje
    float parte = 25.0f, total = 200.0f;
    float porcentaje = (parte / total) * 100.0f;
    cout << "Porcentaje: " << porcentaje << "%\n";

    // Sección 2: Arreglos (vectores)
    const int N = 5;
    int arreglo[N] = {50, 10, 40, 20, 30};

    // Suma y promedio
    int suma = 0;
    for (int i = 0; i < N; i++) suma += arreglo[i];
    float promedio = (float)suma / N;
    cout << "Suma: " << suma << ", Promedio: " << promedio << "\n";

    // Ordenamiento burbuja
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (arreglo[j] > arreglo[j + 1]) {
                int temp = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temp;
            }
        }
    }
    cout << "Arreglo ordenado: ";
    for (int i = 0; i < N; i++) cout << arreglo[i] << " ";
    cout << "\n";

    // Búsqueda de elemento
    int buscar = 20;
    bool encontrado = false;
    for (int i = 0; i < N; i++) {
        if (arreglo[i] == buscar) {
            cout << "Elemento encontrado en la posición: " << i << "\n";
            encontrado = true;
        }
    }
    if (!encontrado) cout << "Elemento no encontrado.\n";

    // Sección 3: Matrices
    const int FIL = 3, COL = 4;
    int matriz[FIL][COL] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Recorrido por filas
    cout << "\nRecorrido por filas:\n";
    for (int i = 0; i < FIL; i++) {
        for (int j = 0; j < COL; j++) cout << matriz[i][j] << " ";
        cout << "\n";
    }

    // Recorrido por columnas
    cout << "\nRecorrido por columnas:\n";
    for (int j = 0; j < COL; j++) {
        for (int i = 0; i < FIL; i++) cout << matriz[i][j] << " ";
        cout << "\n";
    }

    // Recorrido en zigzag
    cout << "\nRecorrido en zigzag por filas:\n";
    for (int i = 0; i < FIL; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < COL; j++) cout << matriz[i][j] << " ";
        } else {
            for (int j = COL - 1; j >= 0; j--) cout << matriz[i][j] << " ";
        }
        cout << "\n";
    }

    // Diagonales (si es cuadrada)
    cout << "\nDiagonal principal:\n";
    for (int i = 0; i < FIL && i < COL; i++) cout << matriz[i][i] << " ";
    cout << "\nDiagonal secundaria:\n";
    for (int i = 0; i < FIL && COL - 1 - i >= 0; i++) cout << matriz[i][COL - 1 - i] << " ";
    cout << "\n";

    // Suma por filas y columnas
    cout << "\nSuma de filas:\n";
    for (int i = 0; i < FIL; i++) {
        int sumaFila = 0;
        for (int j = 0; j < COL; j++) sumaFila += matriz[i][j];
        cout << "Fila " << i << ": " << sumaFila << "\n";
    }
    cout << "Suma de columnas:\n";
    for (int j = 0; j < COL; j++) {
        int sumaCol = 0;
        for (int i = 0; i < FIL; i++) sumaCol += matriz[i][j];
        cout << "Columna " << j << ": " << sumaCol << "\n";
    }

    // Mínimo y máximo
    int min = matriz[0][0], max = matriz[0][0];
    for (int i = 0; i < FIL; i++) {
        for (int j = 0; j < COL; j++) {
            if (matriz[i][j] < min) min = matriz[i][j];
            if (matriz[i][j] > max) max = matriz[i][j];
        }
    }
    cout << "Mínimo: " << min << ", Máximo: " << max << "\n";

    // Sección 4: Números peculiares del 1 al 100
    cout << "\nNúmeros peculiares del 1 al 100:\n";
    for (int n = 1; n <= 100; n++) {
        bool primo = true;
        if (n < 2) primo = false;
        for (int i = 2; i <= sqrt(n); i++)
            if (n % i == 0) primo = false;

        bool oblongo = false;
        for (int i = 1; i * (i + 1) <= n; i++)
            if (i * (i + 1) == n) oblongo = true;

        bool perfecto = false;
        int sumaDiv = 0;
        for (int i = 1; i < n; i++)
            if (n % i == 0) sumaDiv += i;
        if (sumaDiv == n) perfecto = true;

        bool automorfico = true;
        int cuadrado = n * n, copia = n;
        while (copia > 0) {
            if (copia % 10 != cuadrado % 10) automorfico = false;
            copia /= 10;
            cuadrado /= 10;
        }

        bool feliz = false;
        int temp = n;
        for (int i = 0; i < 100; i++) {
            int sumaCuadros = 0, t = temp;
            while (t > 0) {
                int d = t % 10;
                sumaCuadros += d * d;
                t /= 10;
            }
            if (sumaCuadros == 1) {
                feliz = true;
                break;
            }
            temp = sumaCuadros;
        }

        bool armstrong = false;
        int dig = 0, tempA = n, sumaA = 0;
        while (tempA > 0) { dig++; tempA /= 10; }
        tempA = n;
        while (tempA > 0) {
            int d = tempA % 10;
            sumaA += pow(d, dig);
            tempA /= 10;
        }
        if (sumaA == n) armstrong = true;

        bool triangular = false;
        for (int k = 1; k * (k + 1) / 2 <= n; k++)
            if (k * (k + 1) / 2 == n) triangular = true;

        cout << n << ": ";
        if (primo) cout << "Primo ";
        if (oblongo) cout << "Oblongo ";
        if (perfecto) cout << "Perfecto ";
        if (automorfico) cout << "Automórfico ";
        if (feliz) cout << "Feliz ";
        if (armstrong) cout << "Armstrong ";
        if (triangular) cout << "Triangular ";
        cout << "\n";
    }

    return 0;
}
