#include <iostream>
using namespace std;

int main() {
    int opc;
    int n;
    bool cargado = false;

    do {
        cout << "\nMenú de opciones:\n"
             << "1) Cargar arreglo (1 a 100 elementos)\n"
             << "2) Mostrar arreglo\n"
             << "3) Calcular sumatoria y promedio\n"
             << "4) Contar pares e impares\n"
             << "5) Buscar un número\n"
             << "6) Mostrar mayor y menor\n"
             << "7) Salir\n"
             << "Opción: ";
        cin >> opc;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Entrada inválida. Intente de nuevo.\n";
            opc = -1;
            continue;
        }

        switch (opc) {
            case 1: {
                do {
                    cout << "Ingrese el tamaño del arreglo (1 a 100): ";
                    cin >> n;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Entrada inválida.\n";
                        n = 0;
                    }
                } while (n < 1 || n > 100);

                int A[n];  // ✅ VLA declarado una sola vez, aquí

                for (int i = 0; i < n; i++) {
                    cout << "A[" << i << "]: ";
                    cin >> A[i];
                }

                // ✅ Bucle interno para operar después de cargar
                bool subMenu = true;
                do {
                    cout << "\nOperaciones disponibles:\n"
                         << "2) Mostrar arreglo\n"
                         << "3) Sumatoria y promedio\n"
                         << "4) Contar pares e impares\n"
                         << "5) Buscar valor\n"
                         << "6) Mayor y menor\n"
                         << "7) Volver al menú principal\n"
                         << "Opción: ";
                    cin >> opc;

                    switch (opc) {
                        case 2: {
                            cout << "Arreglo: ";
                            for (int i = 0; i < n; i++)
                                cout << "[" << A[i] << "] ";
                            cout << endl;
                            break;
                        }

                        case 3: {
                            long suma = 0;
                            for (int i = 0; i < n; i++)
                                suma += A[i];
                            cout << "Sumatoria = " << suma
                                 << " | Promedio = " << (float)suma / n << endl;
                            break;
                        }

                        case 4: {
                            int pares = 0, impares = 0;
                            for (int i = 0; i < n; i++) {
                                if (A[i] % 2 == 0) pares++;
                                else impares++;
                            }
                            cout << "Pares = " << pares << " | Impares = " << impares << endl;
                            break;
                        }

                        case 5: {
                            int x;
                            cout << "Ingrese el valor a buscar: ";
                            cin >> x;
                            bool encontrado = false;
                            for (int i = 0; i < n; i++) {
                                if (A[i] == x) {
                                    if (!encontrado) cout << "Encontrado en posiciones: ";
                                    cout << i << " ";
                                    encontrado = true;
                                }
                            }
                            if (!encontrado) cout << "No se encontró el valor." << endl;
                            else cout << endl;
                            break;
                        }

                        case 6: {
                            int mayor = A[0], menor = A[0];
                            for (int i = 1; i < n; i++) {
                                if (A[i] > mayor) mayor = A[i];
                                if (A[i] < menor) menor = A[i];
                            }
                            cout << "Mayor: " << mayor << " | Menor: " << menor << endl;
                            break;
                        }

                        case 7:
                            subMenu = false;
                            break;

                        default:
                            cout << "Opción no válida en operaciones.\n";
                    }

                } while (subMenu);

                break;
            }

            case 7:
                cout << "Programa finalizado.\n";
                break;

            default:
                cout << "Debe primero cargar el arreglo (opción 1).\n";
        }

    } while (opc != 7);

    return 0;
}
