#include <iostream>
#include <iomanip>
#include <string>
#include <sys/ioctl.h>
#include <unistd.h>
using namespace std;

// =====================================================
// 🔹 ESTRUCTURA BASE — CAMBIA ESTO SEGÚN TU PROYECTO
// =====================================================
struct Paciente {
    int id;
    string nombre;
    string motivo;
};

// =====================================================
// 🔹 FUNCIONES DE DISEÑO VISUAL
// =====================================================

// Obtener el ancho de la terminal actual (para centrar texto)
int obtenerAnchoTerminal() {
    struct winsize w;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == -1)
        return 80; // valor por defecto si no se puede obtener
    return w.ws_col;
}

// Imprimir texto centrado con color
void imprimirCentrado(const string& texto, const string& color = "\033[0m") {
    int ancho = obtenerAnchoTerminal();
    int espacio = (ancho - (int)texto.size()) / 2;
    if (espacio < 0) espacio = 0;
    cout << setw(espacio + texto.size()) << color << texto << "\033[0m" << endl;
}

// Mostrar encabezado de tabla
void mostrarTablaEncabezado(const string& titulo) {
    int ancho = obtenerAnchoTerminal();
    int anchoTabla = 60; // 👉 ajusta el ancho total de la tabla
    int margen = (ancho - anchoTabla) / 2;

    cout << "\n";
    cout << setw(margen) << "" << "\033[1;36m+" << string(anchoTabla - 2, '=') << "+\033[0m" << endl;
    cout << setw(margen) << "" << "\033[1;36m|" 
         << setw((anchoTabla - titulo.size()) / 2 - 1) << "" 
         << "\033[1;33m" << titulo << "\033[1;36m"
         << setw((anchoTabla - titulo.size()) / 2 - 1) << "" << "|\033[0m" << endl;
    cout << setw(margen) << "" << "\033[1;36m+" << string(anchoTabla - 2, '=') << "+\033[0m" << endl;

    // 👉 Cambia los nombres de las columnas si tu struct tiene otros campos
    cout << setw(margen) << "" << "\033[1;34m| "
         << left << setw(8) << "ID"
         << setw(20) << "NOMBRE"
         << setw(25) << "MOTIVO"
         << "|\033[0m" << endl;

    cout << setw(margen) << "" << "\033[1;36m+" << string(anchoTabla - 2, '-') << "+\033[0m" << endl;
}

// Mostrar una fila de datos (recibe un struct)
void mostrarFila(const Paciente& p) {
    int ancho = obtenerAnchoTerminal();
    int anchoTabla = 60;
    int margen = (ancho - anchoTabla) / 2;

    cout << setw(margen) << "" << "\033[0;37m| "
         << left << setw(8) << p.id
         << setw(20) << p.nombre
         << setw(25) << p.motivo
         << "|\033[0m" << endl;
}

// Línea final de la tabla
void mostrarFinTabla() {
    int ancho = obtenerAnchoTerminal();
    int anchoTabla = 60;
    int margen = (ancho - anchoTabla) / 2;
    cout << setw(margen) << "" << "\033[1;36m+" << string(anchoTabla - 2, '=') << "+\033[0m" << endl;
}

// =====================================================
// 🔹 FUNCIONES DE GESTIÓN DE ESTRUCTURAS DINÁMICAS
// =====================================================

// ✅ Agregar un nuevo paciente al arreglo dinámico
void agregarPaciente(Paciente*& pacientes, int& cantidad) {
    // Crear un nuevo arreglo con un espacio adicional
    Paciente* nuevo = new Paciente[cantidad + 1];

    // Copiar los elementos existentes al nuevo arreglo
    for (int i = 0; i < cantidad; i++) {
        nuevo[i] = pacientes[i];
    }

    // Liberar la memoria antigua
    delete[] pacientes;

    // Apuntar al nuevo bloque de memoria
    pacientes = nuevo;

    // Ingresar datos del nuevo paciente
    cout << "\n=== Ingreso de paciente #" << cantidad + 1 << " ===\n";
    cout << "ID: ";
    cin >> pacientes[cantidad].id;
    cin.ignore(); // limpiar el buffer de entrada
    cout << "Nombre: ";
    getline(cin, pacientes[cantidad].nombre);
    cout << "Motivo: ";
    getline(cin, pacientes[cantidad].motivo);

    cantidad++; // aumentar el contador total
}

// ✅ Mostrar todos los pacientes
void listarPacientes(Paciente* pacientes, int cantidad) {
    if (cantidad == 0) {
        imprimirCentrado("No hay pacientes registrados aún.", "\033[1;31m");
        return;
    }

    mostrarTablaEncabezado("LISTA DE PACIENTES");
    for (int i = 0; i < cantidad; i++) {
        mostrarFila(pacientes[i]);
    }
    mostrarFinTabla();
}

// ✅ Eliminar un paciente por su ID
void eliminarPaciente(Paciente*& pacientes, int& cantidad, int idEliminar) {
    if (cantidad == 0) {
        imprimirCentrado("No hay pacientes para eliminar.", "\033[1;31m");
        return;
    }

    int indice = -1;
    for (int i = 0; i < cantidad; i++) {
        if (pacientes[i].id == idEliminar) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        imprimirCentrado("⚠️  No se encontró un paciente con ese ID.", "\033[1;33m");
        return;
    }

    // Crear nuevo arreglo con uno menos
    Paciente* nuevo = new Paciente[cantidad - 1];
    int pos = 0;

    for (int i = 0; i < cantidad; i++) {
        if (i != indice) { // copiamos todos excepto el eliminado
            nuevo[pos++] = pacientes[i];
        }
    }

    delete[] pacientes; // liberar el viejo
    pacientes = nuevo;
    cantidad--;

    imprimirCentrado("✅ Paciente eliminado correctamente.", "\033[1;32m");
}

// =====================================================
// 🔹 FUNCIÓN PRINCIPAL (MAIN)
// =====================================================
int main() {
    imprimirCentrado("===================================", "\033[1;34m");
    imprimirCentrado("   SISTEMA DE GESTIÓN DE PACIENTES  ", "\033[1;32m");
    imprimirCentrado("===================================", "\033[1;34m");

    Paciente* pacientes = nullptr; // puntero inicial vacío
    int cantidad = 0;              // número de pacientes actuales
    int opcion;

    do {
        cout << "\n\033[1;36m===== MENÚ PRINCIPAL =====\033[0m\n";
        cout << "1. Agregar paciente\n";
        cout << "2. Mostrar pacientes\n";
        cout << "3. Eliminar paciente\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarPaciente(pacientes, cantidad);
                break;
            case 2:
                listarPacientes(pacientes, cantidad);
                break;
            case 3: {
                int idEliminar;
                cout << "Ingrese el ID del paciente a eliminar: ";
                cin >> idEliminar;
                eliminarPaciente(pacientes, cantidad, idEliminar);
                break;
            }
            case 4:
                imprimirCentrado("Saliendo del sistema...", "\033[1;35m");
                break;
            default:
                imprimirCentrado("⚠️  Opción inválida. Intente de nuevo.", "\033[1;31m");
        }

    } while (opcion != 4);

    delete[] pacientes; // liberar memoria final
    return 0;
}
