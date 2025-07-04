#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int n;
    cout << "ingrese la cantidad de empleados: "<<endl;
    cin >> n;
    string nombres[n];
int empleados[4][n];

for (int i = 0; i < n; i++) {
    cin.ignore(); // Limpia el salto de línea anterior si hubo un cin antes
    cout << "Ingrese su nombre: ";
    getline(cin, nombres[i]);

    for (int x = 0; x < 4; x++) {
     
        cout << "Empleado # " << i + 1 << " ingrese su venta del trimestre #" << x + 1 << ": ";
        cin >> empleados[i][x];
    }
}
for (int i = 0; i < n; i++) { // filas
    cout << "Nombre: " << setw(7) << left << nombres[i]; // Alineado a la izquierda

    for (int x = 0; x < 4; x++) {
        cout << " | Trimestre #" << x + 1 <<endl<< ": $" << setw(5) << right << empleados[i][x];
    }
    cout << endl;
}
    return 0;
}