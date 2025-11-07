#include <cstring>
#include <iostream>
using namespace std;

// Definición de un struct Paciente
struct Paciente {
    int id;
    char nombre[50];
    char motivo[100];
};

//================ FUNCIONES ==================

// Agregar un paciente al arreglo
void agregarPaciente(Paciente pacientes[], int& num)
{
    if (num >= 100) { // limite del arreglo
        cout << "No se pueden agregar más pacientes.\n";
        return;
    }
    cout << "Ingrese ID: ";
    cin >> pacientes[num].id;
    cin.ignore();
    cout << "Ingrese nombre: ";
    cin.getline(pacientes[num].nombre, 50);
    cout << "Ingrese motivo: ";
    cin.getline(pacientes[num].motivo, 100);
    num++;
    cout << "Paciente agregado.\n";
}

// Mostrar todos los pacientes
void mostrarPacientes(Paciente pacientes[], int num)
{
    if (num == 0) {
        cout << "No hay pacientes registrados.\n";
        return;
    }
    cout << "\n--- Lista de Pacientes ---\n";
    for (int i = 0; i < num; i++) {
        cout << "ID: " << pacientes[i].id
             << " | Nombre: " << pacientes[i].nombre
             << " | Motivo: " << pacientes[i].motivo << endl;
    }
}

// Buscar paciente por ID
void buscarPorID(Paciente pacientes[], int num, int id)
{
    for (int i = 0; i < num; i++) {
        if (pacientes[i].id == id) {
            cout << "Paciente encontrado: "
                 << pacientes[i].nombre
                 << " | Motivo: " << pacientes[i].motivo << endl;
            return;
        }
    }
    cout << "Paciente no encontrado.\n";
}

// Ordenar pacientes por nombre (alfabéticamente)
void ordenarPorNombre(Paciente pacientes[], int num)
{
    for (int i = 0; i < num - 1; i++) {
        for (int j = i + 1; j < num; j++) {
            if (strcmp(pacientes[i].nombre, pacientes[j].nombre) > 0) {
                Paciente tmp = pacientes[i];
                pacientes[i] = pacientes[j];
                pacientes[j] = tmp;
            }
        }
    }
    cout << "Pacientes ordenados por nombre.\n";
}

// Modificar motivo de un paciente dado su ID
void modificarMotivo(Paciente pacientes[], int num, int id)
{
    for (int i = 0; i < num; i++) {
        if (pacientes[i].id == id) {
            cout << "Ingrese nuevo motivo: ";
            cin.ignore();
            cin.getline(pacientes[i].motivo, 100);
            cout << "Motivo actualizado.\n";
            return;
        }
    }
    cout << "Paciente no encontrado.\n";
}

// Eliminar paciente por ID
void eliminarPaciente(Paciente pacientes[], int& num, int id)
{
    for (int i = 0; i < num; i++) {
        if (pacientes[i].id == id) {
            // Desplazar todos los elementos posteriores una posición hacia atrás
            for (int j = i; j < num - 1; j++) {
                pacientes[j] = pacientes[j + 1];
            }
            num--;
            cout << "Paciente eliminado.\n";
            return;
        }
    }
    cout << "Paciente no encontrado.\n";
}

//================ MENU ==================
int main()
{
    Paciente pacientes[100];
    int numPacientes = 0;
    int opcion;

    do {
        cout << "\n===== MENU DE PACIENTES =====\n";
        cout << "1. Agregar paciente\n";
        cout << "2. Mostrar todos los pacientes\n";
        cout << "3. Buscar paciente por ID\n";
        cout << "4. Ordenar pacientes por nombre\n";
        cout << "5. Modificar motivo de paciente\n";
        cout << "6. Eliminar paciente por ID\n";
        cout << "0. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            agregarPaciente(pacientes, numPacientes);
            break;

        case 2:
            mostrarPacientes(pacientes, numPacientes);
            break;

        case 3: {
            int id;
            cout << "Ingrese ID a buscar: ";
            cin >> id;
            buscarPorID(pacientes, numPacientes, id);
            break;
        }

        case 4:
            ordenarPorNombre(pacientes, numPacientes);
            mostrarPacientes(pacientes, numPacientes);
            break;

        case 5: {
            int id;
            cout << "Ingrese ID del paciente a modificar: ";
            cin >> id;
            modificarMotivo(pacientes, numPacientes, id);
            break;
        }

        case 6: {
            int id;
            cout << "Ingrese ID del paciente a eliminar: ";
            cin >> id;
            eliminarPaciente(pacientes, numPacientes, id);
            break;
        }

        case 0:
            cout << "Saliendo...\n";
            break;

        default:
            cout << "Opcion invalida\n";
        }

    } while (opcion != 0);

    return 0;
}
