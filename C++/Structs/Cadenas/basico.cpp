#include <cctype> // Para isalpha, isdigit, isspace, isupper, islower
#include <iostream>
using namespace std;

int main()
{
    char cad[100];
    int letras = 0, numeros = 0, espacios = 0, mayusculas = 0, minusculas = 0;

    cout << "Ingrese una cadena: ";
    cin.getline(cad, 100);

    for (int i = 0; cad[i] != '\0'; i++) {
        if (isalpha(cad[i])) { // Es letra
            letras++;
            if (isupper(cad[i]))
                mayusculas++; // Mayúscula
            if (islower(cad[i]))
                minusculas++; // Minúscula
        }
        if (isdigit(cad[i]))
            numeros++; // Es número
        if (isspace(cad[i]))
            espacios++; // Es espacio/tab/salto de línea
    }

    cout << "Total letras: " << letras << endl;
    cout << "Mayusculas: " << mayusculas << endl;
    cout << "Minusculas: " << minusculas << endl;
    cout << "Numeros: " << numeros << endl;
    cout << "Espacios: " << espacios << endl;

    return 0;
}
