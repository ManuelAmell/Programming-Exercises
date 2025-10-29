#include "cadenas_basico.h"

int main() {
    char texto[] = "Hola Mundo!\nEsto es un ejemplo.";
    char invertida[100];

    cout << "Caracteres: " << contarCaracteres(texto) << endl;
    cout << "Palabras: " << contarPalabras(texto) << endl;
    cout << "Lineas: " << contarLineas(texto) << endl;

    invertir(texto, invertida);
    cout << "Invertido: " << invertida << endl;

    mayusculas(texto);
    cout << "Mayúsculas: " << texto << endl;

    minusculas(texto);
    cout << "Minúsculas: " << texto << endl;

    cout << "Es palíndromo 'anilina'? " << (esPalindromo("anilina") ? "Sí" : "No") << endl;
    cout << "Contiene 'Mundo'? " << (contiene(texto, "mundo") ? "Sí" : "No") << endl;

    reemplazar(texto, "hola", "hi");
    cout << "Reemplazar 'hola' por 'hi': " << texto << endl;

    return 0;
}
