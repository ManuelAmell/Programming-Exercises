#include <iostream>
#include <iomanip>  // para usar std::setprecision
using namespace std;

int main() {
    int totalClientes = 0;
    int clientesConPuntos = 0;
    int totalPuntos = 0;
    int mayorPuntaje = 0;
    int menorPuntaje = 999999; // inicializamos con un valor grande
    int r100 = 0, r200 = 0, r350 = 0, r450 = 0;

    char continuar;

    do {
        float compras;
        int puntos = 0;

        cout << "\nIngrese el valor total de las compras del cliente: $";
        cin >> compras;

        // Asignación de puntos
        if (compras >= 80000 && compras <= 200000) {
            puntos = 100;
            r100++;
        } else if (compras <= 400000) {
            puntos = 200;
            r200++;
        } else if (compras < 700000) {
            puntos = 350;
            r350++;
        } else if (compras >= 700000) {
            puntos = 450;
            r450++;
        }

        if (puntos > 0) {
            clientesConPuntos++;
            totalPuntos += puntos;

            if (puntos > mayorPuntaje) mayorPuntaje = puntos;
            if (puntos < menorPuntaje) menorPuntaje = puntos;
        }

        totalClientes++;

        cout << ">>> Bono generado <<<\n";
        cout << "Compras del cliente: $" << compras << endl;
        cout << "Puntos asignados: " << puntos << "\n";

        cout << "¿Desea ingresar otro cliente? (s/n): ";
        cin >> continuar;

    } while (continuar == 's' || continuar == 'S');

    // Mostrar resultados finales
    cout << fixed << setprecision(2);  // para porcentajes

    cout << "\nResumen del día:\n";
    cout << "---------------------------\n";
    cout << "Total de clientes: " << totalClientes << endl;
    cout << "Clientes con puntos asignados: " << clientesConPuntos << endl;
    cout << "Total de puntos asignados: " << totalPuntos << endl;
    if (clientesConPuntos > 0) {
        cout << "Mayor cantidad de puntos asignados: " << mayorPuntaje << endl;
        cout << "Menor cantidad de puntos asignados: " << menorPuntaje << endl;
    }

    // Porcentajes por rango
    cout << "\nPorcentaje de clientes por rango:\n";
    cout << "100 puntos: " << (r100 * 100.0 / totalClientes) << "%\n";
    cout << "200 puntos: " << (r200 * 100.0 / totalClientes) << "%\n";
    cout << "350 puntos: " << (r350 * 100.0 / totalClientes) << "%\n";
    cout << "450 puntos: " << (r450 * 100.0 / totalClientes) << "%\n";

    return 0;
}
