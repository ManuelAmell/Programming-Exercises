#include <iostream>
#include <string>
using namespace std;

struct Paciente {
    int id;
    string nombre;
    string motivo;
};

int main() {
    int n;
    cout << "¿Cuántos pacientes desea registrar?: ";
    cin >> n;
    cin.ignore();

    // 🔹 Crear arreglo dinámico de tamaño 'n'
    Paciente* pacientes = new Paciente[n];

    // 🔹 Ingresar datos
    for (int i = 0; i < n; i++) {
        cout << "\nPaciente #" << i + 1 << endl;
        cout << "ID: ";
        cin >> pacientes[i].id;
        cin.ignore();
        cout << "Nombre: ";
        getline(cin, pacientes[i].nombre);
        cout << "Motivo: ";
        getline(cin, pacientes[i].motivo);
    }

    // 🔹 Mostrar datos
    cout << "\n=== LISTA DE PACIENTES ===\n";
    for (int i = 0; i < n; i++) {
        cout << pacientes[i].id << " - " << pacientes[i].nombre
             << " (" << pacientes[i].motivo << ")\n";
    }

    // 🔹 Liberar memoria
    delete[] pacientes;

    return 0;
}
