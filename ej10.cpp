#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    float a, b, c;
    double t = 0;

    cout << fixed << setprecision(2); // Configurar salida con 2 decimales

    cout << "Ingrese el primer número: ";
    cin >> a;
    cout << "Ingrese el segundo número: ";
    cin >> b;
    cout << "Ingrese el tercer número: ";
    cin >> c;

    t = a + b + c;

    // Verificar que la suma no sea 0 para evitar división por cero
    

    cout << "La suma de los tres números es: " << t << endl;
    cout << "El porcentaje del primer número es: " << (a * 100) / t << "%" << endl;
    cout << "El porcentaje del segundo número es: " << (b * 100) / t << "%" << endl;
    cout << "El porcentaje del tercer número es: " << (c * 100) / t << "%" << endl;

    return 0;
}
