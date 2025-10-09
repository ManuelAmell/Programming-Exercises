#include <iostream>
using namespace std;

int main() {
    long numero;
    cout << "Ingresa un numero entero positivo de al menos 6 cifras: ";
    cin >> numero;

    if (numero < 100000) {
        cout << "Error: el numero debe tener al menos 6 cifras." << endl;
        return 1;
    }

    long original = numero;
    long copia = numero;

    int primer_digito = 0, ultimo_digito = 0;
    int mayor = -1, menor = 10;
    int cantidad_digitos = 0;
    bool creciente = true, decreciente = true;
    int anterior = -1;
    bool tiene_cero = false;
    bool todos_pares = true, todos_impares = true;
    int anterior_diferencia = -1000;
    bool secuencia_aritmetica = true;
    bool todos_distintos = true;

    long invertido = 0;
    long copia_comparativa = numero;

    cout << "\n--- Analizando el numero (solo if y switch) ---\n";

    // Extraer último dígito (sin %)
    ultimo_digito = numero - (numero / 10) * 10;

    while (copia > 0) {
        int digito = copia - (copia / 10) * 10;

        cantidad_digitos++;

        // Invertir número
        invertido = invertido * 10 + digito;

        // Guardar el primer dígito (último en salir del bucle)
        if (copia / 10 == 0)
            primer_digito = digito;

        // Mayor y menor
        if (digito > mayor) mayor = digito;
        if (digito < menor) menor = digito;

        // Tiene cero
        if (digito == 0) tiene_cero = true;

        // Todos pares/impares
        if (digito != 0 && digito != 2 && digito != 4 && digito != 6 && digito != 8)
            todos_pares = false;
        if (digito != 1 && digito != 3 && digito != 5 && digito != 7 && digito != 9)
            todos_impares = false;

        // Orden
        if (anterior != -1) {
            if (digito > anterior) creciente = false;
            if (digito < anterior) decreciente = false;

            // Secuencia aritmética (diferencia constante)
            int diferencia = anterior - digito;
            if (anterior_diferencia == -1000) {
                anterior_diferencia = diferencia;
            } else {
                if (diferencia != anterior_diferencia)
                    secuencia_aritmetica = false;
            }

            if (digito == anterior)
                todos_distintos = false;
        }

        anterior = digito;
        copia = copia / 10;
    }

    // Clasificación por tamaño
    cout << "\n--- Clasificacion por rango ---\n";
    if (original >= 100000 && original < 1000000)
        cout << "Es un numero de 6 cifras\n";
    else if (original >= 1000000 && original < 10000000)
        cout << "Es un numero de 7 cifras\n";
    else if (original >= 10000000)
        cout << "Es un numero muy grande (8 cifras o más)\n";

    // Propiedades generales
    cout << "\n--- Propiedades del numero ---\n";
    cout << "Cantidad de digitos: " << cantidad_digitos << endl;
    cout << "Mayor digito: " << mayor << ", Menor digito: " << menor << endl;
    cout << "Empieza con: " << primer_digito << ", Termina con: " << ultimo_digito << endl;

    if (tiene_cero)
        cout << "Contiene al menos un 0\n";

    if (creciente)
        cout << "Dígitos en orden creciente (de derecha a izquierda)\n";
    else if (decreciente)
        cout << "Dígitos en orden decreciente (de derecha a izquierda)\n";
    else
        cout << "Dígitos en orden mixto\n";

    if (todos_pares)
        cout << "Todos los digitos son pares\n";
    else if (todos_impares)
        cout << "Todos los digitos son impares\n";

    if (secuencia_aritmetica)
        cout << "Los digitos forman una secuencia aritmética\n";

    if (todos_distintos)
        cout << "Todos los digitos son diferentes\n";
    else
        cout << "Tiene digitos repetidos\n";

    if (original == invertido)
        cout << "El numero es capicua\n";
    else
        cout << "El numero NO es capicua\n";

    // Clasificación con switch
    cout << "\n--- Significado del primer digito (switch) ---\n";
    switch (primer_digito) {
        case 1: cout << "Inicia como identificador de región 1\n"; break;
        case 2: cout << "Inicia como código nacional 2\n"; break;
        case 3: cout << "Común en números institucionales\n"; break;
        case 9: cout << "Alerta: número prioritario (9...)\n"; break;
        default: cout << "Inicio numérico general\n";
    }

    cout << "\n--- Interpretación de los dígitos (switch) ---\n";
    copia = original;
    while (copia > 0) {
        int dig = copia - (copia / 10) * 10;
        copia = copia / 10;

        switch (dig) {
            case 0: cout << "0 = Cero absoluto\n"; break;
            case 1: cout << "1 = Unidad\n"; break;
            case 2: cout << "2 = Dualidad\n"; break;
            case 3: cout << "3 = Trino o equilibrio\n"; break;
            case 4: cout << "4 = Estabilidad\n"; break;
            case 5: cout << "5 = Movimiento\n"; break;
            case 6: cout << "6 = Armonía\n"; break;
            case 7: cout << "7 = Misticismo\n"; break;
            case 8: cout << "8 = Poder\n"; break;
            case 9: cout << "9 = Finalización o alerta\n"; break;
        }
    }

    return 0;
}
// Fin del programa