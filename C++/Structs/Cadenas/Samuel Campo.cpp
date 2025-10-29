#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cctype> // para toupper() y tolower()
using namespace std;

void ToUpper(char str[]) {
    for (int i = 0; i < strlen(str); i++) {
        str[i] = toupper(str[i]);
    }
}

void ToLower(char str[]) {
    for (int i = 0; i < strlen(str); i++) {
        str[i] = tolower(str[i]);
    }
}

int main(int argc, char** argv) {
    char words[1000];
    cout << "Escriba una oracion:" << endl;

    // ✅ fgets reemplaza gets de forma segura
    fgets(words, 1000, stdin);

    // ✅ Eliminar salto de línea que guarda fgets()
    words[strcspn(words, "\n")] = '\0';

    cout << "Desea convertir todo a minuscula(1) o a mayuscula(2)?" << endl;
    int opc;
    cin >> opc;

    if (opc == 1)
        ToLower(words);
    else if (opc == 2)
        ToUpper(words);
    else
        cout << "Opcion invalida" << endl;

    cout << "La palabra en "
         << ((opc == 1) ? "minuscula" : "mayuscula")
         << " es: " << words << endl;

    return 0;
}

