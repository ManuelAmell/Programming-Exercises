#include <iostream>
#include <cctype>
#include <cstring>

int totalCaracteres(const char* texto) {
    return strlen(texto);
}

int contarVocales(const char* texto) {
    int count = 0;
    for (int i = 0; texto[i] != '\0'; i++) {
        char c = tolower(texto[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            count++;
    }
    return count;
}

int contarNumericos(const char* texto) {
    int count = 0;
    for (int i = 0; texto[i] != '\0'; i++) {
        if (isdigit(texto[i]))
            count++;
    }
    return count;
}

int contarEspacios(const char* texto) {
    int count = 0;
    for (int i = 0; texto[i] != '\0'; i++) {
        if (isspace(texto[i]))
            count++;
    }
    return count;
}

int contarEspeciales(const char* texto) {
    int count = 0;
    for (int i = 0; texto[i] != '\0'; i++) {
        if (!isalnum(texto[i]) && !isspace(texto[i]))
            count++;
    }
    return count;
}

int contarPalabras(const char* texto) {
    int count = 0;
    bool enPalabra = false;
    for (int i = 0; texto[i] != '\0'; i++) {
        if (isspace(texto[i])) {
            enPalabra = false;
        } else if (!enPalabra) {
            count++;
            enPalabra = true;
        }
    }
    return count;
}

void aMayusculas(char* texto) {
    for (int i = 0; texto[i] != '\0'; i++)
        texto[i] = toupper(texto[i]);
}

void aMinusculas(char* texto) {
    for (int i = 0; texto[i] != '\0'; i++)
        texto[i] = tolower(texto[i]);
}

const char* tipoOracion(const char* texto) {
    int len = strlen(texto);
    if (len == 0) return "Vacía";
    char ultimo = texto[len - 1];
    if (ultimo == '?') return "Interrogativa";
    if (ultimo == '!') return "Exclamativa";
    if (ultimo == '.') return "Declarativa";
    return "Indefinida";
}

void capitalizarPalabras(char* texto) {
    bool nuevaPalabra = true;
    for (int i = 0; texto[i] != '\0'; i++) {
        if (isspace(texto[i])) {
            nuevaPalabra = true;
        } else if (nuevaPalabra) {
            texto[i] = toupper(texto[i]);
            nuevaPalabra = false;
        } else {
            texto[i] = tolower(texto[i]);
        }
    }
}

void asignarColor(int opcion) {
    switch (opcion) {
        case 1: std::cout << "\033[31m"; break;
        case 2: std::cout << "\033[32m"; break;
        case 3: std::cout << "\033[34m"; break;
        case 4: std::cout << "\033[33m"; break;
        case 5: std::cout << "\033[0m";  break;
        default: std::cout << "\033[0m"; break;
    }
}

