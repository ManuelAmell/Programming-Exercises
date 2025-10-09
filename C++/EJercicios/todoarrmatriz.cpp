#include <iostream>
using namespace std;

int main() {
    int opcion;
    const int MAX = 100;

    do {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1. Operaciones con vector\n";
        cout << "2. Operaciones con matriz\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            int n;
            cout << "Tamaño del vector: ";
            cin >> n;
            int v[n];

            cout << "Ingrese " << n << " valores:\n";
            for (int i = 0; i < n; i++) {
                cout << "v[" << i << "] = ";
                cin >> v[i];
            }

            int opcionV;
            do {
                cout << "\n--- MENU VECTOR ---\n";
                cout << "1. Mostrar vector\n";
                cout << "2. Suma y promedio\n";
                cout << "3. Buscar un numero\n";
                cout << "4. Ordenar ascendente\n";
                cout << "5. Invertir vector\n";
                cout << "0. Volver\n";
                cout << "Opcion: ";
                cin >> opcionV;

                if (opcionV == 1) {
                    for (int i = 0; i < n; i++) {
                        cout << "[" << v[i] << "] ";
                    }
                    cout << endl;
                } else if (opcionV == 2) {
                    int suma = 0;
                    for (int i = 0; i < n; i++) suma += v[i];
                    float prom = (float)suma / n;
                    cout << "Suma = " << suma << ", Promedio = " << prom << endl;
                } else if (opcionV == 3) {
                    int x;
                    cout << "Numero a buscar: ";
                    cin >> x;
                    bool encontrado = false;
                    for (int i = 0; i < n; i++) {
                        if (v[i] == x) {
                            cout << "Encontrado en posicion " << i << endl;
                            encontrado = true;
                        }
                    }
                    if (!encontrado) cout << "No se encontro el numero." << endl;
                } else if (opcionV == 4) {
                    for (int i = 0; i < n - 1; i++) {
                        for (int j = 0; j < n - i - 1; j++) {
                            if (v[j] > v[j + 1]) {
                                int aux = v[j];
                                v[j] = v[j + 1];
                                v[j + 1] = aux;
                            }
                        }
                    }
                    cout << "Vector ordenado.\n";
                } else if (opcionV == 5) {
                    for (int i = 0; i < n / 2; i++) {
                        int aux = v[i];
                        v[i] = v[n - 1 - i];
                        v[n - 1 - i] = aux;
                    }
                    cout << "Vector invertido.\n";
                }

            } while (opcionV != 0);

        } else if (opcion == 2) {
            int filas, columnas;
            cout << "Numero de filas: ";
            cin >> filas;
            cout << "Numero de columnas: ";
            cin >> columnas;

            int m[filas][columnas];

            cout << "Ingrese los valores de la matriz:\n";
            for (int i = 0; i < filas; i++) {
                for (int j = 0; j < columnas; j++) {
                    cout << "m[" << i << "][" << j << "] = ";
                    cin >> m[i][j];
                }
            }

            int opcionM;
            do {
                cout << "\n--- MENU MATRIZ ---\n";
                cout << "1. Mostrar matriz\n";
                cout << "2. Suma total\n";
                cout << "3. Suma por filas\n";
                cout << "4. Suma por columnas\n";
                cout << "5. Diagonales (si es cuadrada)\n";
                cout << "6. Transpuesta (si es cuadrada)\n";
                cout << "7. Verificar simetria (si es cuadrada)\n";
                cout << "0. Volver\n";
                cout << "Opcion: ";
                cin >> opcionM;

                if (opcionM == 1) {
                    for (int i = 0; i < filas; i++) {
                        for (int j = 0; j < columnas; j++) {
                            cout << "[" << m[i][j] << "] ";
                        }
                        cout << endl;
                    }
                } else if (opcionM == 2) {
                    int suma = 0;
                    for (int i = 0; i < filas; i++) {
                        for (int j = 0; j < columnas; j++) {
                            suma += m[i][j];
                        }
                    }
                    cout << "Suma total = " << suma << endl;
                } else if (opcionM == 3) {
                    for (int i = 0; i < filas; i++) {
                        int sumaFila = 0;
                        for (int j = 0; j < columnas; j++) {
                            sumaFila += m[i][j];
                        }
                        cout << "Suma fila " << i << ": " << sumaFila << endl;
                    }
                } else if (opcionM == 4) {
                    for (int j = 0; j < columnas; j++) {
                        int sumaCol = 0;
                        for (int i = 0; i < filas; i++) {
                            sumaCol += m[i][j];
                        }
                        cout << "Suma columna " << j << ": " << sumaCol << endl;
                    }
                } else if (opcionM == 5) {
                    if (filas == columnas) {
                        cout << "Diagonal principal: ";
                        for (int i = 0; i < filas; i++) {
                            cout << m[i][i] << " ";
                        }
                        cout << "\nDiagonal secundaria: ";
                        for (int i = 0; i < filas; i++) {
                            cout << m[i][filas - 1 - i] << " ";
                        }
                        cout << endl;
                    } else {
                        cout << "La matriz no es cuadrada.\n";
                    }
                } else if (opcionM == 6) {
                    if (filas == columnas) {
                        cout << "Transpuesta:\n";
                        for (int i = 0; i < filas; i++) {
                            for (int j = 0; j < columnas; j++) {
                                cout << "[" << m[j][i] << "] ";
                            }
                            cout << endl;
                        }
                    } else {
                        cout << "La matriz no es cuadrada.\n";
                    }
                } else if (opcionM == 7) {
                    if (filas == columnas) {
                        bool simetrica = true;
                        for (int i = 0; i < filas; i++) {
                            for (int j = 0; j < columnas; j++) {
                                if (m[i][j] != m[j][i]) {
                                    simetrica = false;
                                }
                            }
                        }
                        if (simetrica)
                            cout << "La matriz es simetrica.\n";
                        else
                            cout << "La matriz no es simetrica.\n";
                    } else {
                        cout << "La matriz no es cuadrada.\n";
                    }
                }

            } while (opcionM != 0);
        }

    } while (opcion != 0);

    cout << "Programa finalizado.\n";
    return 0;
}
