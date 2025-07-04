// ventas_agencia.cpp
// ------------------------------------------------------------
// Procesa ventas de 15 vendedores para 10 modelos de autos.
// Muestra:
// a) Autos colocados por vendedor.
// b) Autos vendidos por modelo.
// c) Modelo menos vendido.
// d) Vendedores ordenados por ventas totales (ascendente).
//
// Sin funciones, sin swap, sin STL, todo en main.
// ------------------------------------------------------------
#include <iostream>
#include <iomanip>  // setw
using namespace std;

int main() {
    const int VENDEDORES = 15;
    const int MODELOS = 10;

    int ventas[VENDEDORES][MODELOS];

    int totalVend[VENDEDORES] = {0}; // Total por vendedor
    int totalMod[MODELOS] = {0};     // Total por modelo

    // -------------------- Ingreso de datos --------------------
    cout << "Ingrese ventas por vendedor y modelo:\n";
    for (int v = 0; v < VENDEDORES; ++v) {
        cout << "\nVendedor " << v + 1 << ":\n";
        for (int m = 0; m < MODELOS; ++m) {
            cout << "  Modelo " << m + 1 << ": ";
            cin >> ventas[v][m];
            totalVend[v] += ventas[v][m]; // Total por vendedor
            totalMod[m] += ventas[v][m];  // Total por modelo
        }
    }

    // -------------------- Modelo menos vendido --------------------
    int menor = totalMod[0];
    int modeloMenor = 0;
    for (int m = 1; m < MODELOS; ++m) {
        if (totalMod[m] < menor) {
            menor = totalMod[m];
            modeloMenor = m;
        }
    }

    // -------------------- Ordenar vendedores (burbuja manual) ------
    int orden[VENDEDORES]; // Guardamos los índices originales
    for (int i = 0; i < VENDEDORES; ++i)
        orden[i] = i;

    // Ordenamiento por ventas totales (ascendente)
    for (int i = 0; i < VENDEDORES - 1; ++i) {
        for (int j = 0; j < VENDEDORES - 1 - i; ++j) {
            int idx1 = orden[j];
            int idx2 = orden[j + 1];
            if (totalVend[idx1] > totalVend[idx2]) {
                // Intercambio manual de índices
                int temp = orden[j];
                orden[j] = orden[j + 1];
                orden[j + 1] = temp;
            }
        }
    }

    // -------------------- Mostrar resultados --------------------
    cout << "\n===========================================\n";
    cout << "TOTAL DE AUTOS POR VENDEDOR\n";
    cout << setw(10) << "Vendedor" << "Total\n";
    for (int v = 0; v < VENDEDORES; ++v)
        cout << setw(10) << v + 1 << totalVend[v] << "\n";

    cout << "\nTOTAL DE AUTOS POR MODELO\n";
    cout << setw(8) << "Modelo" << "Total\n";
    for (int m = 0; m < MODELOS; ++m)
        cout << setw(8) << m + 1 << totalMod[m] << "\n";

    cout << "\n>> Modelo menos vendido: Modelo " << modeloMenor + 1
         << " con " << menor << " unidades.\n";

    cout << "\nVENDEDORES ORDENADOS POR TOTAL DE VENTAS (↑)\n";
    cout << setw(10) << "Vendedor" << "Total\n";
    for (int i = 0; i < VENDEDORES; ++i) {
        int v = orden[i];
        cout << setw(10) << v + 1 << totalVend[v] << "\n";
    }

    cout << "===========================================\n";
    return 0;
}
