#include <iostream>
#include <string>
using namespace std;

// Estructura para guardar los datos del paciente
struct Paciente {
    int id;
    string nombre;
    string motivo;
    string fecha;
};

// Estructura para guardar los datos del médico y sus pacientes
struct Medico {
    int registro;
    string nombre;
    string especialidad;
    int consultorio;
    Paciente* pacientes; // arreglo dinámico de pacientes
};

int main() {
    int numMedicos, numPacientes;

    cout << "=== SISTEMA DE ASIGNACIÓN DE CITAS MÉDICAS ===\n";
    cout << "¿Cuántos médicos desea registrar?: ";
    cin >> numMedicos;
    cout << "¿Cuántos pacientes asignará a cada médico?: ";
    cin >> numPacientes;
    cin.ignore(); // limpiar buffer

    // Crear arreglo dinámico de médicos
    Medico* medicos = new Medico[numMedicos];

    // Ingreso de datos
    for (int i = 0; i < numMedicos; i++) {
        cout << "\n=== MÉDICO #" << i + 1 << " ===\n";
        cout << "Registro médico: ";
        cin >> medicos[i].registro;
        cin.ignore();
        cout << "Nombre: ";
        getline(cin, medicos[i].nombre);
        cout << "Especialidad: ";
        getline(cin, medicos[i].especialidad);
        cout << "Consultorio: ";
        cin >> medicos[i].consultorio;
        cin.ignore();

        // Crear arreglo de pacientes
        medicos[i].pacientes = new Paciente[numPacientes];

        // Ingresar los pacientes de este médico
        cout << "\n--- Asignar pacientes al médico ---\n";
        for (int j = 0; j < numPacientes; j++) {
            cout << "\nPaciente #" << j + 1 << endl;
            cout << "ID: ";
            cin >> medicos[i].pacientes[j].id;
            cin.ignore();
            cout << "Nombre: ";
            getline(cin, medicos[i].pacientes[j].nombre);
            cout << "Motivo de consulta: ";
            getline(cin, medicos[i].pacientes[j].motivo);
            cout << "Fecha de cita (dd/mm/aaaa): ";
            getline(cin, medicos[i].pacientes[j].fecha);
        }
    }

    int opcion;
    do {
        cout << "\n\n=== MENÚ PRINCIPAL ===\n";
        cout << "1. Listado de médicos con pacientes\n";
        cout << "2. Consultar un médico\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                cout << "\n=== LISTADO DE MÉDICOS Y PACIENTES ===\n";
                for (int i = 0; i < numMedicos; i++) {
                    cout << "\nMédico: " << medicos[i].nombre
                         << " | Especialidad: " << medicos[i].especialidad
                         << " | Registro: " << medicos[i].registro
                         << " | Consultorio: " << medicos[i].consultorio << endl;

                    cout << "Pacientes:\n";
                    for (int j = 0; j < numPacientes; j++) {
                        cout << "  - " << medicos[i].pacientes[j].nombre
                             << " (ID: " << medicos[i].pacientes[j].id
                             << ", Motivo: " << medicos[i].pacientes[j].motivo
                             << ", Fecha: " << medicos[i].pacientes[j].fecha << ")\n";
                    }
                }
                break;
            }

            case 2: {
                int regBuscar;
                bool encontrado = false;
                cout << "\nIngrese el registro médico a consultar: ";
                cin >> regBuscar;

                for (int i = 0; i < numMedicos; i++) {
                    if (medicos[i].registro == regBuscar) {
                        encontrado = true;
                        cout << "\nMédico encontrado:\n";
                        cout << "Nombre: " << medicos[i].nombre << endl;
                        cout << "Especialidad: " << medicos[i].especialidad << endl;
                        cout << "Consultorio: " << medicos[i].consultorio << endl;

                        cout << "\nPacientes asignados:\n";
                        for (int j = 0; j < numPacientes; j++) {
                            cout << "  - ID: " << medicos[i].pacientes[j].id
                                 << ", Nombre: " << medicos[i].pacientes[j].nombre
                                 << ", Motivo: " << medicos[i].pacientes[j].motivo
                                 << ", Fecha: " << medicos[i].pacientes[j].fecha << endl;
                        }
                        break;
                    }
                }

                if (!encontrado)
                    cout << "❌ No se encontró un médico con ese registro.\n";
                break;
            }

            case 3:
                cout << "\nSaliendo del programa...\n";
                break;

            default:
                cout << "Opción inválida.\n";
        }

    } while (opcion != 3);

    // Liberar memoria
    for (int i = 0; i < numMedicos; i++) {
        delete[] medicos[i].pacientes;
    }
    delete[] medicos;

    return 0;
}
