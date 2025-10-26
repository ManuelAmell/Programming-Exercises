#include <iostream>
using namespace std;
void menu(int &opc) {
    cout << "===== MENU =====\n";
    cout << "1. Cargar datos del vendedor\n";
    cout << "2. Registrar Ventas\n";
    cout << "3. Reporte Pago Comision (Ordenado ascendentemente por la venta)\n";
    cout << "4. Consultar vendedor\n";
    cout << "5. Salir\n";
    cout << "Seleccione una opcion: ";
    cin >> opc;
}
int  main() {
    int opc;
    int n;
    cout << "cantidad de vendedores :";
    cin >>n;

    long codigo;

    string nombres[n];

    long ventas[n];
    do {
        menu(opc);

        switch(opc) {
            case 1:
                for (int i = 0; i < n; i++) {
                    cout << "Ingrese nombre del vendedor " << i+1 << ": ";
                    cin >> nombres[i][i];
                }
                break;

            case 2:
                for (int i = 0; i < n; i++) {
                    cout << "Ingrese ventas de " << nombres[i] << ": ";
                    cin >> ventas[i];
                }
                break;

            case 3:
                cout << "\n--- Reporte de comisiones ---\n";
                for (int i = 0; i < n; i++) {
                    cout << nombres[i][i] << " -> $" << ventas[i] << endl;
                }
                break;

            case 4:
                {
                    string buscar;
                    cout << "Ingrese nombre a consultar: ";
                    cin >> buscar;
                    bool encontrado = false;
                    for (int i = 0; i < n; i++) {
                        if (nombres[i]== buscar) {
                            cout << "Vendedor: " << nombres[i][i] 
                                << " | Ventas: $" << ventas[i] << endl;
                            encontrado = true;
                        }
                    }
                    if (!encontrado) cout << "No encontrado.\n";
                }
                break;

            case 5:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opcion invalida\n";
        }

    } while(opc != 5);
    return 0;
}