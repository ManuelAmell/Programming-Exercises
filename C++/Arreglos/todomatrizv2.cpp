#include <iostream>
using namespace std;

int main() {

    int opcionPrincipal;          // Opción elegida en el menú principal

    do {
        // -------- MENÚ PRINCIPAL --------
        cout << "\n========== MENU PRINCIPAL ==========\n";
        cout << "1. Trabajar con VECTOR (arreglo 1D)\n";
        cout << "2. Trabajar con MATRIZ (arreglo 2D)\n";
        cout << "0. Salir del programa\n";
        cout << "Seleccione una opcion: ";
        cin  >> opcionPrincipal;

        /* -------------------------------------------------------------------
           ====================== BLOQUE DE VECTORES =========================
           ------------------------------------------------------------------- */
        if (opcionPrincipal == 1) {

            int n;                                // Tamaño del vector
            cout << "\n--- VECTOR ---\n";
            cout << "Ingrese el tamano del vector (n>0): ";
            cin  >> n;

            int v[n];                             // VLA: vector de tamaño n

            // -------------- CARGA DEL VECTOR --------------
            cout << "Ingrese " << n << " valores enteros:\n";
            for (int i = 0; i < n; ++i) {
                cout << "v[" << i << "] = ";
                cin  >> v[i];
            }

            int opcionV;                          // Opción en el sub‑menú de vectores
            do {
                // -------- SUB‑MENU VECTOR --------
                cout << "\n====== MENU VECTOR ======\n";
                cout << "1. Mostrar vector\n";
                cout << "2. Suma y promedio\n";
                cout << "3. Buscar un numero\n";
                cout << "4. Ordenar ascendentemente\n";
                cout << "5. Invertir vector\n";
                cout << "0. Volver al MENU PRINCIPAL\n";
                cout << "Opcion: ";
                cin  >> opcionV;

                /* ---------- 1. Mostrar vector ---------- */
                if (opcionV == 1) {
                    cout << "Vector: ";
                    for (int i = 0; i < n; ++i) {
                        cout << "[" << v[i] << "] ";
                    }
                    cout << endl;
                }

                /* ---------- 2. Suma y promedio ---------- */
                else if (opcionV == 2) {
                    long suma = 0;
                    for (int i = 0; i < n; ++i) suma += v[i];
                    float promedio = static_cast<float>(suma) / n;
                    cout << "Suma = " << suma << ", Promedio = " << promedio << endl;
                }

                /* ---------- 3. Buscar un número ---------- */
                else if (opcionV == 3) {
                    int x;  bool encontrado = false;
                    cout << "Numero a buscar: ";
                    cin  >> x;
                    for (int i = 0; i < n; ++i) {
                        if (v[i] == x) {
                            cout << "Encontrado en posicion " << i << endl;
                            encontrado = true;
                        }
                    }
                    if (!encontrado) cout << "No se encontro el numero.\n";
                }

                /* ---------- 4. Ordenar ascendente (burbuja) ---------- */
                else if (opcionV == 4) {
                    for (int i = 0; i < n - 1; ++i)          // pasadas
                        for (int j = 0; j < n - i - 1; ++j)  // comparaciones
                            if (v[j] > v[j + 1]) {
                                int aux = v[j];
                                v[j] = v[j + 1];
                                v[j + 1] = aux;
                            }
                    cout << "Vector ordenado.\n";
                }

                /* ---------- 5. Invertir vector ---------- */
                else if (opcionV == 5) {
                    for (int i = 0; i < n / 2; ++i) {
                        int aux = v[i];
                        v[i] = v[n - 1 - i];
                        v[n - 1 - i] = aux;
                    }
                    cout << "Vector invertido.\n";
                }

            } while (opcionV != 0);   // Fin sub‑menú vector
        }

        /* -------------------------------------------------------------------
           ====================== BLOQUE DE MATRICES =========================
           ------------------------------------------------------------------- */
        else if (opcionPrincipal == 2) {

            int filas, columnas;
            cout << "\n--- MATRIZ ---\n";
            cout << "Numero de filas: ";
            cin  >> filas;
            cout << "Numero de columnas: ";
            cin  >> columnas;

            int m[filas][columnas];              // VLA bidimensional

            // -------------- CARGA DE LA MATRIZ --------------
            cout << "Ingrese los valores de la matriz:\n";
            for (int i = 0; i < filas; ++i)
                for (int j = 0; j < columnas; ++j) {
                    cout << "m[" << i << "][" << j << "] = ";
                    cin  >> m[i][j];
                }

            int opcionM;                         // Opción en el sub‑menú de matrices
            do {
                // -------- SUB‑MENU MATRIZ --------
                cout << "\n====== MENU MATRIZ ======\n";
                cout << "1. Mostrar matriz\n";
                cout << "2. Suma total\n";
                cout << "3. Suma por filas\n";
                cout << "4. Suma por columnas\n";
                cout << "5. Diagonales (si es cuadrada)\n";
                cout << "6. Transpuesta (si es cuadrada)\n";
                cout << "7. Verificar simetria (si es cuadrada)\n";
                cout << "0. Volver al MENU PRINCIPAL\n";
                cout << "Opcion: ";
                cin  >> opcionM;

                /* ---------- 1. Mostrar matriz ---------- */
                if (opcionM == 1) {
                    for (int i = 0; i < filas; ++i) {
                        for (int j = 0; j < columnas; ++j)
                            cout << "[" << m[i][j] << "] ";
                        cout << endl;
                    }
                }

                /* ---------- 2. Suma total ---------- */
                else if (opcionM == 2) {
                    long suma = 0;
                    for (int i = 0; i < filas; ++i)
                        for (int j = 0; j < columnas; ++j)
                            suma += m[i][j];
                    cout << "Suma total = " << suma << endl;
                }

                /* ---------- 3. Suma por filas ---------- */
                else if (opcionM == 3) {
                    for (int i = 0; i < filas; ++i) {
                        long sumaFila = 0;
                        for (int j = 0; j < columnas; ++j)
                            sumaFila += m[i][j];
                        cout << "Suma fila " << i << " = " << sumaFila << endl;
                    }
                }

                /* ---------- 4. Suma por columnas ---------- */
                else if (opcionM == 4) {
                    for (int j = 0; j < columnas; ++j) {
                        long sumaCol = 0;
                        for (int i = 0; i < filas; ++i)
                            sumaCol += m[i][j];
                        cout << "Suma columna " << j << " = " << sumaCol << endl;
                    }
                }

                /* ---------- 5. Diagonales ---------- */
                else if (opcionM == 5) {
                    if (filas == columnas) {
                        cout << "Diagonal principal: ";
                        for (int i = 0; i < filas; ++i)
                            cout << m[i][i] << " ";
                        cout << "\nDiagonal secundaria: ";
                        for (int i = 0; i < filas; ++i)
                            cout << m[i][filas - 1 - i] << " ";
                        cout << endl;
                    } else
                        cout << "La matriz NO es cuadrada.\n";
                }

                /* ---------- 6. Transpuesta ---------- */
                else if (opcionM == 6) {
                    if (filas == columnas) {
                        cout << "Transpuesta:\n";
                        for (int i = 0; i < filas; ++i) {
                            for (int j = 0; j < columnas; ++j)
                                cout << "[" << m[j][i] << "] ";
                            cout << endl;
                        }
                    } else
                        cout << "La matriz NO es cuadrada.\n";
                }

                /* ---------- 7. Simetría ---------- */
                else if (opcionM == 7) {
                    if (filas == columnas) {
                        bool simetrica = true;
                        for (int i = 0; i < filas && simetrica; ++i)
                            for (int j = i + 1; j < columnas && simetrica; ++j)
                                if (m[i][j] != m[j][i])
                                    simetrica = false;
                        cout << (simetrica ? "La matriz es SIMETRICA.\n"
                                           : "La matriz NO es simetrica.\n");
                    } else
                        cout << "La matriz NO es cuadrada.\n";
                }

            } while (opcionM != 0);   // Fin sub‑menú matriz
        }

    } while (opcionPrincipal != 0);   // Fin menú principal

    cout << "\nPrograma finalizado.\n";
    return 0;
}

