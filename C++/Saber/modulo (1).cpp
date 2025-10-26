#include <iostream>
using namespace std;

int main() {
    long numero, original, invertido = 0;
    cout << "Ingresa un numero entero positivo de al menos 6 cifras: ";
    cin >> numero;

    if (numero < 100000) {
        cout << "Error: el numero debe tener al menos 6 cifras." << endl;
        return 1;
    }

    original = numero;
    long copia = numero;

    // Variables de análisis
    int digito, anterior = -1;
    int cantidad_digitos = 0;
    int suma_total = 0, suma_pares = 0, suma_impares = 0;
    int cuenta_pares = 0, cuenta_impares = 0;
    int mayor = -1, menor = 10;
    int alternancia = 0, suma_alterna = 0;
    bool creciente = true, decreciente = true;
    bool repetido = false;

    cout << "\nAnalizando el numero...\n";

    // Recorremos los dígitos
    while (copia > 0) {
        digito = copia % 10;
        copia /= 10;
        cantidad_digitos++;

        // Invertir el número
        invertido = invertido * 10 + digito;

        // Suma total
        suma_total += digito;

        // Suma y cuenta pares e impares
        if (digito % 2 == 0) {
            suma_pares += digito;
            cuenta_pares++;
        } else {
            suma_impares += digito;
            cuenta_impares++;
        }

        // Mayor y menor dígito
        if (digito > mayor) mayor = digito;
        if (digito < menor) menor = digito;

        // Regla del 11: suma alternada
        if (alternancia % 2 == 0)
            suma_alterna += digito;
        else
            suma_alterna -= digito;
        alternancia++;

        // Orden creciente / decreciente (comparamos con anterior)
        if (anterior != -1) {
            if (digito > anterior) creciente = false;
            if (digito < anterior) decreciente = false;
            if (digito == anterior) repetido = true;
        }
        anterior = digito;
    }

    // Salida básica
    cout << "\n--- Resultados ---\n";
    cout << "Cantidad de digitos: " << cantidad_digitos << endl;
    cout << "Suma total de los digitos: " << suma_total << endl;
    cout << "Suma de digitos pares: " << suma_pares << " (Cantidad: " << cuenta_pares << ")" << endl;
    cout << "Suma de digitos impares: " << suma_impares << " (Cantidad: " << cuenta_impares << ")" << endl;
    cout << "Mayor digito: " << mayor << endl;
    cout << "Menor digito: " << menor << endl;

    // Divisibilidades
    cout << "\n--- Divisibilidad ---\n";
    cout << "Par o impar: " << (original % 2 == 0 ? "Par" : "Impar") << endl;
    cout << "Divisible por 2: " << (original % 2 == 0 ? "Sí" : "No") << endl;
    cout << "Divisible por 3: " << (original % 3 == 0 ? "Sí" : "No") << endl;
    cout << "Divisible por 5: " << (original % 5 == 0 ? "Sí" : "No") << endl;
    cout << "Divisible por 7: " << (original % 7 == 0 ? "Sí" : "No") << endl;
    cout << "Divisible por 10: " << (original % 10 == 0 ? "Sí" : "No") << endl;
    cout << "Divisible por 11 (regla de alternancia): " << (suma_alterna % 11 == 0 ? "Sí" : "No") << endl;
    cout << "Suma divisible por 9: " << (suma_total % 9 == 0 ? "Sí" : "No") << endl;

    // Capicúa
    cout << "\n--- Capicua ---\n";
    cout << "Numero invertido: " << invertido << endl;
    cout << "Es capicua: " << (original == invertido ? "Sí" : "No") << endl;

    // Extra
    cout << "\n--- Orden y repetición ---\n";
    cout << "Dígitos en orden creciente: " << (creciente ? "Sí" : "No") << endl;
    cout << "Dígitos en orden decreciente: " << (decreciente ? "Sí" : "No") << endl;
    cout << "Tiene dígitos repetidos: " << (repetido ? "Sí" : "No") << endl;

    // Mostrar dígitos pares e impares
    cout << "\n--- Digitos pares ---\n";
    copia = original;
    while (copia > 0) {
        digito = copia % 10;
        if (digito % 2 == 0) cout << digito << " ";
        copia /= 10;
    }

    cout << "\n--- Digitos impares ---\n";
    copia = original;
    while (copia > 0) {
        digito = copia % 10;
        if (digito % 2 != 0) cout << digito << " ";
        copia /= 10;
    }

    cout << "\n";

    return 0;
}
// Fin del programa