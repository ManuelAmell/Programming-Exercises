#include <iostream>
using namespace std;

int main() {
    // Variables
    int a;
    int auxiliar = 0;
    int multiplo = 0, output_multiplo = 0;
    int digitos_s = 0, digitos_p = 0, digitos_d = 0;
    bool propios = false;
    int n;

    // Entrada del n�mero
    cout << "Ingresar un n�mero natural: ";
    cin >> n;
    auxiliar = n;

    // Mostrar divisores del n�mero
    cout << "El n�mero tiene los siguientes m�ltiplos (divisores):" << endl;
    for (a = 1; a <= n; a++) {
        if (n % a == 0) {
            multiplo = a;
            output_multiplo = a;
            cout << a << endl;
        }
    }

    // C�lculo de suma de d�gitos y cantidad de d�gitos
    for (a = 0; auxiliar != 0; a++) {
        digitos_d++; // cantidad de d�gitos
        digitos_s += auxiliar % 10; // suma de d�gitos
        auxiliar = auxiliar / 10;
    }

    // Mostrar resultados
    cout << "N�mero S (suma de los d�gitos): " << digitos_s << endl;
    cout << "N�mero D (cantidad de d�gitos de n): " << digitos_d << endl;

    // Calcular P = S * D
    digitos_p = digitos_s * digitos_d;
    cout << "D�gito P (producto S * D): " << digitos_p << endl;

    // Verificar si P es un divisor propio del n�mero
    for (a = 1; a < n; a++) { // solo divisores propios (menores que n)
        if (n % a == 0 && a == digitos_p) {
            cout << "P es uno de los propios divisores del n�mero, lo que significa que el n�mero es un DPD." << endl;
        }
    }
return 0;
}