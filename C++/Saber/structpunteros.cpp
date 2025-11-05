#include <iostream>
#include <string>
using namespace std;

struct Paciente {
    int id;
    string nombre;
    string motivo;
};

int main() {
    Paciente* pacientes = nullptr;
    int cantidad = 0;
    char continuar = 's';

    while (continuar == 's') {
        // crear nuevo arreglo con un espacio adicional
        Paciente* nuevo = new Paciente[cantidad + 1];

        // copiar los datos antiguos (si existen)
        for (int i = 0; i < cantidad; i++) {
            nuevo[i] = pacientes[i];
        }

        // eliminar el arreglo viejo
        delete[] pacientes;

        // apuntar al nuevo
        pacientes = nuevo;

        // ingresar el nuevo paciente
        cout << "\n=== Ingreso de paciente #" << cantidad + 1 << " ===\n";
        cout << "ID: ";
        cin >> pacientes[cantidad].id;
        cin.ignore();
        cout << "Nombre: ";
        getline(cin, pacientes[cantidad].nombre);
        cout << "Motivo: ";
        getline(cin, pacientes[cantidad].motivo);

        cantidad++;

        cout << "\n¿Desea agregar otro paciente? (s/n): ";
        cin >> continuar;
    }

    cout << "\n=== Lista de pacientes ingresados ===\n";
    for (int i = 0; i < cantidad; i++) {
        cout << i + 1 << ". " << pacientes[i].nombre
             << " (ID: " << pacientes[i].id
             << ", Motivo: " << pacientes[i].motivo << ")\n";
    }

    // liberar la memoria final
    delete[] pacientes;

    return 0;
}
