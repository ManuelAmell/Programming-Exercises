#include <iostream>
#include <iomanip>
#include <string>
#include <sys/ioctl.h>
#include <unistd.h>
using namespace std;

// =====================================================
// 🔹 Función para obtener el ancho actual de la terminal
// =====================================================
int obtenerAnchoTerminal() {
    struct winsize w;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == -1)
        return 80;
    return w.ws_col;
}

// =====================================================
// 🔹 Imprimir texto centrado con color
// =====================================================
void imprimirCentrado(const string& texto, const string& color = "\033[0m") {
    int ancho = obtenerAnchoTerminal();
    int espacio = (ancho - (int)texto.size()) / 2;
    if (espacio < 0) espacio = 0;
    cout << setw(espacio + texto.size()) << color << texto << "\033[0m" << endl;
}

// =====================================================
// 🔹 Función genérica para mostrar tablas estéticas
// =====================================================
void mostrarTablaEncabezado(const string& titulo) {
    int ancho = obtenerAnchoTerminal();
    int anchoTabla = 60;
    int margen = (ancho - anchoTabla) / 2;

    cout << "\n";
    cout << setw(margen) << "" << "\033[1;36m-" << string(anchoTabla - 2, '-') << "-\033[0m" << endl;
    cout << setw(margen) << "" << "\033[1;36m-" 
         << setw((anchoTabla - titulo.size()) / 2 - 1) << "" 
         << "\033[1;33m" << titulo << "\033[1;36m"
         << setw((anchoTabla - titulo.size()) / 2 - 1) << "" << "-\033[0m" << endl;
    cout << setw(margen) << "" << "\033[1;36m|" << string(anchoTabla - 2, '-') << "|\033[0m" << endl;

    cout << setw(margen) << "" << "\033[1;34m| "
         << left << setw(8) << "ID"
         << setw(20) << "NOMBRE"
         << setw(25) << "MOTIVO"
         << "|\033[0m" << endl;

    cout << setw(margen) << "" << "\033[1;36m|" << string(anchoTabla - 2, '-') << "|\033[0m" << endl;
}

void mostrarFila(int id, const string& nombre, const string& motivo) {
    int ancho = obtenerAnchoTerminal();
    int anchoTabla = 60;
    int margen = (ancho - anchoTabla) / 2;

    cout << setw(margen) << "" << "\033[0;37m| "
         << left << setw(8) << id
         << setw(20) << nombre
         << setw(25) << motivo
         << "|\033[0m" << endl;
}

void mostrarFinTabla() {
    int ancho = obtenerAnchoTerminal();
    int anchoTabla = 60;
    int margen = (ancho - anchoTabla) / 2;
    cout << setw(margen) << "" << "\033[1;36m-" << string(anchoTabla - 2, '-') << "-\033[0m" << endl;
}

// =====================================================
// 🔹 Ejemplo de uso (puedes cambiar los datos fácilmente)
// =====================================================
int main() {
    imprimirCentrado("===================================", "\033[1;34m");
    imprimirCentrado("   CENTRO MÉDICO VIDA SALUDABLE   ", "\033[1;32m");
    imprimirCentrado("===================================", "\033[1;34m");

    mostrarTablaEncabezado("LISTA DE PACIENTES");

    mostrarFila(1, "Juan Pérez", "Control general");
    mostrarFila(2, "Ana López", "Dolor de cabeza");
    mostrarFila(3, "Carlos Díaz", "Chequeo anual");

    mostrarFinTabla();

    imprimirCentrado("Fin de la lista", "\033[1;35m");
    cout << endl;
    return 0;
}
