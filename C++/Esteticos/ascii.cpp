#include <iostream>
using namespace std;

int main() {
    string numero = "0123456789";

    cout << "Caracter | ASCII | Valor numerico\n";
    cout << "-------------------------------\n";

    for (char c : numero) {
        int ascii_val = c;          // valor ASCII del caracter
        int digito = c - '0';      // conversión a número

        cout << "   " << c << "     |  " << ascii_val << "   |      " << digito << endl;
    }
    return 0;
}