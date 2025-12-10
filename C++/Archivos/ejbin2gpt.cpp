#include <fstream>
#include <iostream>
#include <cstring>
#include <limits>

using namespace std;

struct Cliente {
    int id;
    char nombre[50];
    char direccion[80];
    long telefono;
};

struct Prestamo {
    int idCliente;          // ID del cliente
    long numPrestamo;       // número de préstamo (consecutivo)
    char fecha[11];         // "DD/MM/YYYY" (10 + '\0')
    long valor;             // valor del préstamo
    float interes;          // porcentaje (0.12 por ejemplo)
    int numCuotas;          // 1,3 o 5
    long valorCuota;        // valor por cuota (entero)
};

// ---- PROTOTIPOS ----
int menu();
bool clienteExiste(int id);
void registrarCliente();
void registrarPrestamo();
long siguienteNumeroPrestamo();
void consultarClientePorID();
void reportePrestamos();
void limpiarEntrada();

// ---- CONSTANTES ARCHIVOS
const char* ARCH_CLIENTES = "clientes.bin";
const char* ARCH_PRESTAMOS = "prestamos.bin";

int main() {
    int opc;
    do {
        opc = menu();
        switch (opc) {
            case 1: registrarCliente(); break;
            case 2: registrarPrestamo(); break;
            case 3: consultarClientePorID(); break;
            case 4: reportePrestamos(); break;
            case 5: cout << "Saliendo...\n"; break;
            default: cout << "Opcion invalida\n";
        }
    } while (opc != 5);
    return 0;
}

// ---- MENU ----
int menu() {
    int op;
    cout << "\n--- PRESTAMOS LA SOLUCION ---\n";
    cout << "1. REGISTRO DE CLIENTES\n";
    cout << "2. REGISTRO DE PRESTAMOS\n";
    cout << "3. CONSULTAR UN CLIENTE (por ID)\n";
    cout << "4. REPORTE DE PRESTAMOS\n";
    cout << "5. SALIR\n";
    cout << "Seleccione una opcion: ";
    cin >> op;
    // validar y limpiar buffer
    while (op < 1 || op > 5) {
        cout << "Opcion invalida. Ingrese otra: ";
        cin >> op;
    }
    limpiarEntrada();
    return op;
}

void limpiarEntrada() {
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// ---- FUNCIONES UTILES ----
bool clienteExiste(int id) {
    ifstream f(ARCH_CLIENTES, ios::binary);
    if (!f) return false;
    Cliente c;
    while (f.read(reinterpret_cast<char*>(&c), sizeof(Cliente))) {
        if (c.id == id) {
            f.close();
            return true;
        }
    }
    f.close();
    return false;
}

long siguienteNumeroPrestamo() {
    ifstream f(ARCH_PRESTAMOS, ios::binary);
    if (!f) return 1; // si no existe archivo, primer préstamo = 1
    Prestamo p;
    long maxNum = 0;
    while (f.read(reinterpret_cast<char*>(&p), sizeof(Prestamo))) {
        if (p.numPrestamo > maxNum) maxNum = p.numPrestamo;
    }
    f.close();
    return maxNum + 1;
}

// ---- REGISTRO DE CLIENTES ----
void registrarCliente() {
    Cliente c;
    // pedir datos
    cout << "Ingrese ID del cliente (entero): ";
    cin >> c.id;
    limpiarEntrada();

    if (clienteExiste(c.id)) {
        cout << "Ya existe un cliente con ese ID. Registro cancelado.\n";
        return;
    }

    cout << "Ingrese nombre: ";
    cin.getline(c.nombre, 50);

    cout << "Ingrese direccion: ";
    cin.getline(c.direccion, 80);

    cout << "Ingrese telefono (numerico): ";
    cin >> c.telefono;
    limpiarEntrada();

    // escribir al final
    ofstream fout(ARCH_CLIENTES, ios::binary | ios::app);
    if (!fout) {
        cout << "Error al abrir archivo de clientes.\n";
        return;
    }
    fout.write(reinterpret_cast<char*>(&c), sizeof(Cliente));
    fout.close();
    cout << "Cliente registrado correctamente.\n";
}

// ---- REGISTRO DE PRÉSTAMOS ----
void registrarPrestamo() {
    Prestamo p;
    cout << "Ingrese ID del cliente que solicita el prestamo: ";
    cin >> p.idCliente;
    limpiarEntrada();

    if (!clienteExiste(p.idCliente)) {
        cout << "Cliente no registrado. No se puede asignar prestamo.\n";
        return;
    }

    // generar numero de prestamo
    p.numPrestamo = siguienteNumeroPrestamo();

    cout << "Ingrese fecha (DD/MM/YYYY): ";
    cin.getline(p.fecha, 11);

    cout << "Ingrese valor del prestamo (enteros): ";
    cin >> p.valor;
    while (p.valor <= 0) {
        cout << "Valor invalido. Ingrese valor mayor a 0: ";
        cin >> p.valor;
    }
    limpiarEntrada();

    // calcular interes y cuotas según reglas
    if (p.valor < 5000000L) {
        p.interes = 0.12f;
    } else {
        p.interes = 0.10f;
    }

    if (p.valor <= 2000000L) {
        p.numCuotas = 1;
    } else if (p.valor <= 5000000L) {
        p.numCuotas = 3;
    } else {
        p.numCuotas = 5;
    }

    // calcular valor cuota (total / numCuotas), redondear hacia entero
    double total = p.valor + (p.valor * p.interes);
    long cuota = static_cast<long>( (total / p.numCuotas) + 0.5 ); // redondeo aproximado
    p.valorCuota = cuota;

    // escribir prestamo al archivo de prestamos
    ofstream fout(ARCH_PRESTAMOS, ios::binary | ios::app);
    if (!fout) {
        cout << "No se puede abrir archivo de prestamos.\n";
        return;
    }
    fout.write(reinterpret_cast<char*>(&p), sizeof(Prestamo));
    fout.close();

    cout << "Prestamo registrado. Numero de prestamo: " << p.numPrestamo << "\n";
}

// ---- CONSULTAR UN CLIENTE (mostrar todos sus prestamos y deuda) ----
void consultarClientePorID() {
    int id;
    cout << "Ingrese ID del cliente a consultar: ";
    cin >> id;
    limpiarEntrada();

    if (!clienteExiste(id)) {
        cout << "Cliente no registrado.\n";
        return;
    }

    // cargar nombre y direccion desde clientes.bin
    ifstream fc(ARCH_CLIENTES, ios::binary);
    Cliente c;
    while (fc.read(reinterpret_cast<char*>(&c), sizeof(Cliente))) {
        if (c.id == id) break;
    }
    fc.close();
    cout << "Cliente: " << c.nombre << " | Direccion: " << c.direccion << "\n";

    // leer prestamos y mostrar los que correspondan
    ifstream fp(ARCH_PRESTAMOS, ios::binary);
    if (!fp) {
        cout << "No hay prestamos registrados.\n";
        return;
    }
    Prestamo p;
    bool found = false;
    double deudaTotal = 0.0;
    cout << "\nPrestamos del cliente:\n";
    cout << "Num | Fecha      | Valor     | Interes | Total     | Cuotas | Valor cuota\n";
    cout << "---------------------------------------------------------------------\n";
    while (fp.read(reinterpret_cast<char*>(&p), sizeof(Prestamo))) {
        if (p.idCliente == id) {
            found = true;
            double total = p.valor + p.valor * p.interes;
            deudaTotal += total;
            cout << p.numPrestamo << " | "
                 << p.fecha << " | "
                 << p.valor << " | "
                 << (p.interes * 100) << "% | "
                 << static_cast<long>(total) << " | "
                 << p.numCuotas << " | "
                 << p.valorCuota << "\n";
        }
    }
    fp.close();
    if (!found) cout << "No se encontraron prestamos para este cliente.\n";
    else cout << "\nDeuda total del cliente (aprox): " << static_cast<long>(deudaTotal) << "\n";
}

// ---- REPORTE DE PRESTAMOS ----
void reportePrestamos() {
    // leer prestamos; para cada uno buscar nombre del cliente (o guardar mapa si se desea)
    ifstream fp(ARCH_PRESTAMOS, ios::binary);
    if (!fp) {
        cout << "No hay prestamos registrados.\n";
        return;
    }

    // Para calcular estadisticas
    long contadorPrestamos = 0;
    long contadorMayores5000000 = 0;
    double totalPrestado = 0.0;
    double totalIntereses = 0.0;

    Prestamo p;
    cout << "\n=== REPORTE DE PRESTAMOS ===\n";
    cout << "IDCliente | Nombre                 | NumPrest | Fecha      | Valor     | Interes% | Cuotas\n";
    cout << "-----------------------------------------------------------------------------------------\n";

    while (fp.read(reinterpret_cast<char*>(&p), sizeof(Prestamo))) {
        // buscar nombre del cliente en clientes.bin
        ifstream fc(ARCH_CLIENTES, ios::binary);
        Cliente c;
        char nombreBuf[50] = "Desconocido";
        while (fc.read(reinterpret_cast<char*>(&c), sizeof(Cliente))) {
            if (c.id == p.idCliente) {
                strncpy(nombreBuf, c.nombre, 49);
                nombreBuf[49] = '\0';
                break;
            }
        }
        fc.close();

        cout << p.idCliente << " | " << nombreBuf << " | " << p.numPrestamo
             << " | " << p.fecha << " | " << p.valor << " | " << (p.interes*100)
             << "% | " << p.numCuotas << "\n";

        contadorPrestamos++;
        totalPrestado += p.valor;
        totalIntereses += p.valor * p.interes;
        if (p.valor > 5000000L) contadorMayores5000000++;
    }
    fp.close();

    if (contadorPrestamos == 0) {
        cout << "No hay prestamos para reportar.\n";
        return;
    }

    double porcentajeMayores = (100.0 * contadorMayores5000000) / contadorPrestamos;
    cout << "\nTotal prestamos: " << contadorPrestamos << "\n";
    cout << "Porcentaje de prestamos > 5.000.000: " << porcentajeMayores << "%\n";
    cout << "Total prestado por la empresa: " << static_cast<long>(totalPrestado) << "\n";
    cout << "Total recibido por intereses (aprox): " << static_cast<long>(totalIntereses) << "\n";
}
