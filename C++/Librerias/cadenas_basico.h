#ifndef CADENAS_UTIL_H
#define CADENAS_UTIL_H

#include <iostream>
using namespace std;

// --------------------- Contar ---------------------
int contarCaracteres(const char* s) {
    int count = 0;
    while(s[count] != '\0') count++;
    return count;
}

int contarPalabras(const char* s) {
    int count = 0;
    bool enPalabra = false;
    for(int i = 0; s[i] != '\0'; i++) {
        if(s[i] != ' ' && s[i] != '\n' && !enPalabra) {
            count++;
            enPalabra = true;
        }
        if(s[i] == ' ' || s[i] == '\n') enPalabra = false;
    }
    return count;
}

int contarLineas(const char* s) {
    int count = 1;
    for(int i = 0; s[i] != '\0'; i++)
        if(s[i] == '\n') count++;
    return count;
}

// --------------------- Manipulación ---------------------
void invertir(const char* s, char* r) {
    int len = contarCaracteres(s);
    for(int i = 0; i < len; i++)
        r[i] = s[len-1-i];
    r[len] = '\0';
}

void mayusculas(char* s) {
    for(int i = 0; s[i] != '\0'; i++)
        if(s[i] >= 'a' && s[i] <= 'z') s[i] -= 32;
}

void minusculas(char* s) {
    for(int i = 0; s[i] != '\0'; i++)
        if(s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
}

// --------------------- Palíndromos ---------------------
bool esPalindromo(const char* s) {
    int len = contarCaracteres(s);
    for(int i = 0; i < len/2; i++)
        if(s[i] != s[len-1-i]) return false;
    return true;
}

// --------------------- Buscar y Reemplazar ---------------------
bool contiene(const char* s, const char* sub) {
    int len_s = contarCaracteres(s);
    int len_sub = contarCaracteres(sub);
    for(int i = 0; i <= len_s - len_sub; i++) {
        bool match = true;
        for(int j = 0; j < len_sub; j++)
            if(s[i+j] != sub[j]) match = false;
        if(match) return true;
    }
    return false;
}

// Reemplaza subcadena vieja por nueva (muy básico, requiere suficiente espacio en s)
void reemplazar(char* s, const char* viejo, const char* nuevo) {
    if(!contiene(s,viejo)) return;
    char buffer[1000];
    int len_s = contarCaracteres(s);
    int len_viejo = contarCaracteres(viejo);
    int len_nuevo = contarCaracteres(nuevo);
    int k = 0;

    for(int i = 0; i < len_s; ) {
        bool match = true;
        for(int j = 0; j < len_viejo; j++)
            if(s[i+j] != viejo[j]) match = false;
        if(match) {
            for(int j = 0; j < len_nuevo; j++)
                buffer[k++] = nuevo[j];
            i += len_viejo;
        } else {
            buffer[k++] = s[i++];
        }
    }
    buffer[k] = '\0';
    for(int i = 0; i <= k; i++) s[i] = buffer[i];
}

#endif
