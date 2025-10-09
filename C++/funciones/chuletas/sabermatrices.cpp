// ejemplos_cmat.cpp
// Operaciones fundamentales con arreglos, matrices y números peculiares
// Sin funciones externas, solo usando <iostream> y <cmath>
// Recomendación: usar nombres descriptivos, comentar cada sección y evitar repetición innecesaria

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // -----------------------------
    // MATRICES - CADA PROCESO INDIVIDUAL Y TODOS LOS RECORRIDOS + ORDENAMIENTO
    // -----------------------------
    const int FIL = 3, COL = 4;
    int matriz[FIL][COL] = {
        {1,  2,   3,    4},
        {5,  6,   7,    8},
        {9, 10,  11,    12}
    };

    // 1. Mostrar matriz original
    cout << "Matriz original:\n";
    for (int i = 0; i < FIL; i++) {
        for (int j = 0; j < COL; j++) cout << matriz[i][j] << " ";
        cout << "\n";
    }

    // 2. Recorrido por filas (horizontal)
    // Recorre cada fila de izquierda a derecha
    cout << "\nRecorrido por filas (horizontal):\n";
    for (int i = 0; i < FIL; i++) {
        for (int j = 0; j < COL; j++) cout << matriz[i][j] << " ";
        cout << "\n";
    }

    // 3. Recorrido por columnas (vertical)
    // Recorre cada columna de arriba a abajo
    cout << "\nRecorrido por columnas (vertical):\n";
    for (int j = 0; j < COL; j++) {
        for (int i = 0; i < FIL; i++) cout << matriz[i][j] << " ";
        cout << "\n";
    }

    // 4. Recorrido en zigzag por filas
    // Recorre una fila hacia la derecha, la siguiente hacia la izquierda
    cout << "\nRecorrido zigzag por filas:\n";
    for (int i = 0; i < FIL; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < COL; j++) cout << matriz[i][j] << " ";
        } else {
            for (int j = COL - 1; j >= 0; j--) cout << matriz[i][j] << " ";
        }
        cout << "\n";
    }

    // 5. Recorrido en zigzag por columnas
    // Recorre una columna hacia abajo, la siguiente hacia arriba
    cout << "\nRecorrido zigzag por columnas:\n";
    for (int j = 0; j < COL; j++) {
        if (j % 2 == 0) {
            for (int i = 0; i < FIL; i++) cout << matriz[i][j] << " ";
        } else {
            for (int i = FIL - 1; i >= 0; i--) cout << matriz[i][j] << " ";
        }
        cout << "\n";
    }

    // 6. Diagonal inferior (debajo de la principal)
    cout << "\nDiagonal inferior:\n";
    for (int d = 1; d < FIL; d++) {
        for (int i = d, j = 0; i < FIL && j < COL; i++, j++) {
            cout << matriz[i][j] << " ";
        }
    }
    cout << "\n";

    // 7. Diagonal superior (encima de la principal)
    cout << "\nDiagonal superior:\n";
    for (int d = 1; d < COL; d++) {
        for (int i = 0, j = d; i < FIL && j < COL; i++, j++) {
            cout << matriz[i][j] << " ";
        }
    }
    cout << "\n";

    // 8. Diagonal principal (de arriba izquierda a abajo derecha)
    cout << "\nDiagonal principal:\n";
    for (int i = 0; i < FIL && i < COL; i++) cout << matriz[i][i] << " ";
    cout << "\n";

    // 9. Diagonal secundaria (de arriba derecha a abajo izquierda)
    cout << "\nDiagonal secundaria:\n";
    for (int i = 0; i < FIL && (COL - 1 - i) >= 0; i++) cout << matriz[i][COL - 1 - i] << " ";
    cout << "\n";

    // 10. Transpuesta (intercambia filas por columnas)
    cout << "\nTranspuesta:\n";
    for (int j = 0; j < COL; j++) {
        for (int i = 0; i < FIL; i++) cout << matriz[i][j] << " ";
        cout << "\n";
    }

    // 11. Suma por fila
    cout << "\nSuma por fila:\n";
    for (int i = 0; i < FIL; i++) {
        int sumaFila = 0;
        for (int j = 0; j < COL; j++) sumaFila += matriz[i][j];
        cout << "Fila " << i << ": " << sumaFila << "\n";
    }

    // 12. Suma por columna
    cout << "\nSuma por columna:\n";
    for (int j = 0; j < COL; j++) {
        int sumaCol = 0;
        for (int i = 0; i < FIL; i++) sumaCol += matriz[i][j];
        cout << "Columna " << j << ": " << sumaCol << "\n";
    }

    // 13. Mínimo y máximo
    // Busca el valor mínimo y máximo de toda la matriz
    int min = matriz[0][0], max = matriz[0][0];
    for (int i = 0; i < FIL; i++) {
        for (int j = 0; j < COL; j++) {
            if (matriz[i][j] < min) min = matriz[i][j];
            if (matriz[i][j] > max) max = matriz[i][j];
        }
    }
    cout << "\nMínimo: " << min << ", Máximo: " << max << "\n";

    // 14. Ordenamiento de la matriz en forma lineal (Bubble Sort)
    // Recomendación: no óptimo para grandes tamaños. Convertimos la matriz en array, ordenamos y la reconstruimos.
    int total = FIL * COL;
    int temp[total];
    int k = 0;
    // Paso 1: Convertir la matriz en un arreglo temporal
    for (int i = 0; i < FIL; i++) {
        for (int j = 0; j < COL; j++) {
            temp[k++] = matriz[i][j];
        }
    }
    // Paso 2: Ordenar con burbuja
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - 1 - i; j++) {
            if (temp[j] > temp[j + 1]) {
                int aux = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = aux;
            }
        }
    }
    // Paso 3: Volver a cargar la matriz ordenada
    k = 0;
    for (int i = 0; i < FIL; i++) {
        for (int j = 0; j < COL; j++) {
            matriz[i][j] = temp[k++];
        }
    }

    cout << "\nMatriz ordenada en forma ascendente:\n";
    for (int i = 0; i < FIL; i++) {
        for (int j = 0; j < COL; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << "\n";
    }

    // Recomendaciones adicionales:
    // - Para matrices grandes, usar ordenamientos más eficientes como quicksort.
    // - Para operaciones frecuentes, usar funciones auxiliares aunque aquí no se permite.
    // - Agregar validaciones de tamaño en programas más grandes.

    return 0;
}