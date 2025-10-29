#include <iostream>
#include <cstdio>   // fgets
#include <cstring>  // strlen, strcspn
using namespace std;

int main() {
    char texto[100];

    cout << "Escribe algo: ";
    fgets(texto, 100, stdin);  // lee máximo 99 caracteres + '\0'

    // fgets guarda el salto de línea '\n', lo quitamos:
    texto[strcspn(texto, "\n")] = '\0';

    cout << "Leíste: " << texto << endl;
    return 0;
}
