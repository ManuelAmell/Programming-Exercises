#include <iostream>
#include <string>
using namespace std;

struct Paciente {
    int id;
    string nombre;
    string motivo;
};

// 🔹 Función para mostrar todos los pacientes
void mostrarPacientes(Paciente* pacientes, int cantidad) {
    if (cantidad == 0) {
        cout << "\nNo hay pacientes registrados.\n";
        return;
    }

    cout << "\n=== LISTA DE PACIENTES ===\n";
    for (int i = 0; i < cantidad; i++) {
        cout << i + 1 << ". ID: " << pacientes[i].id
             << " | Nombre: " << pacientes[i].nombre
             << " | Motivo: " << pacientes[i].motivo << endl;
    }
}

int main() {
    Paciente* pacientes = nullptr;
    int cantidad = 0;
    int opcion;

    do {
        cout << "\n=== MENÚ DE PACIENTES ===\n";
        cout << "1. Agregar paciente\n";
        cout << "2. Eliminar paciente\n";
        cout << "3. Copiar paciente\n";
        cout << "4. Mostrar pacientes\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1: { // ➕ Agregar
            Paciente* nuevo = new Paciente[cantidad + 1];

            // Copiar los existentes
            for (int i = 0; i < cantidad; i++) {
                nuevo[i] = pacientes[i];
            }

            // Ingresar el nuevo paciente
            cout << "\n=== Nuevo paciente ===\n";
            cout << "ID: ";
            cin >> nuevo[cantidad].id;
            cin.ignore();
            cout << "Nombre: ";
            getline(cin, nuevo[cantidad].nombre);
            cout << "Motivo: ";
            getline(cin, nuevo[cantidad].motivo);

            // Liberar viejo arreglo
            delete[] pacientes;
            pacientes = nuevo;
            cantidad++;

            cout << "Paciente agregado con éxito.\n";
            break;
        }

        case 2: { // ❌ Eliminar
            if (cantidad == 0) {
                cout << "No hay pacientes para eliminar.\n";
                break;
            }

            int idEliminar;
            cout << "Ingrese el ID del paciente a eliminar: ";
            cin >> idEliminar;

            int indice = -1;
            for (int i = 0; i < cantidad; i++) {
                if (pacientes[i].id == idEliminar) {
                    indice = i;
                    break;
                }
            }

            if (indice == -1) {
                cout << "No se encontró un paciente con ese ID.\n";
                break;
            }

            Paciente* nuevo = new Paciente[cantidad - 1];

            for (int i = 0, j = 0; i < cantidad; i++) {
                if (i != indice) {
                    nuevo[j++] = pacientes[i];
                }
            }

            delete[] pacientes;
            pacientes = nuevo;
            cantidad--;

            cout << "Paciente eliminado correctamente.\n";
            break;
        }

        case 3: { // 📋 Copiar
            if (cantidad == 0) {
                cout << "No hay pacientes para copiar.\n";
                break;
            }

            int idCopiar;
            cout << "Ingrese el ID del paciente que desea duplicar: ";
            cin >> idCopiar;

            int indice = -1;
            for (int i = 0; i < cantidad; i++) {
                if (pacientes[i].id == idCopiar) {
                    indice = i;
                    break;
                }
            }

            if (indice == -1) {
                cout << "No se encontró un paciente con ese ID.\n";
                break;
            }

            // Crear nuevo arreglo con espacio adicional
            Paciente* nuevo = new Paciente[cantidad + 1];

            // Copiar todos los anteriores
            for (int i = 0; i < cantidad; i++) {
                nuevo[i] = pacientes[i];
            }

            // Copiar el paciente seleccionado
            nuevo[cantidad] = pacientes[indice];
            nuevo[cantidad].id = pacientes[indice].id + 1000; // nuevo ID para diferenciar
            nuevo[cantidad].nombre += " (Copia)";

            delete[] pacientes;
            pacientes = nuevo;
            cantidad++;

            cout << "Paciente copiado correctamente.\n";
            break;
        }

        case 4: // 📄 Mostrar
            mostrarPacientes(pacientes, cantidad);
            break;

        case 5:
            cout << "Saliendo del programa...\n";
            break;

        default:
            cout << "Opción inválida.\n";
        }

    } while (opcion != 5);

    delete[] pacientes;
    return 0;
}
