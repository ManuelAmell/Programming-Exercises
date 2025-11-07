#include <cctype> // Para funciones de caracteres (toupper, tolower, isalpha)
#include <cstring> // Para funciones de manipulación de cadenas (strlen, strchr, strstr, strcat, strncat, strcpy)
#include <iostream> // Para entrada y salida estándar (cin, cout)
using namespace std;

//=================== FUNCIONES DE MANIPULACION DE CADENAS ====================

// Función: convertir_mayusculas
// Descripción: Recorre la cadena carácter por carácter y convierte cada letra a mayúscula
// Argumentos: cad -> cadena a convertir (puntero a char)
// Retorno: void (modifica la cadena original directamente)
void convertir_mayusculas(char* cad)
{
    for (int i = 0; cad[i]; i++) // Recorre todos los caracteres hasta el '\0'
        cad[i] = toupper(cad[i]); // Convierte a mayúscula si es letra, deja otros caracteres igual
}

// Función: convertir_minusculas
// Descripción: Recorre la cadena y convierte cada letra a minúscula
// Argumentos: cad -> cadena a convertir (puntero a char)
// Retorno: void (modifica la cadena original)
void convertir_minusculas(char* cad)
{
    for (int i = 0; cad[i]; i++)
        cad[i] = tolower(cad[i]); // Convierte a minúscula si es letra
}

// Función: invertir_cadena
// Descripción: Invierte la cadena en su lugar, intercambiando caracteres del inicio y final
// Argumentos: cad -> cadena a invertir
// Retorno: void (la cadena original queda invertida)
void invertir_cadena(char* cad)
{
    int n = strlen(cad); // Calcula longitud de la cadena
    for (int i = 0; i < n / 2; i++) { // Recorre hasta la mitad
        char tmp = cad[i]; // Guarda carácter temporal
        cad[i] = cad[n - i - 1]; // Intercambia con el carácter simétrico al final
        cad[n - i - 1] = tmp; // Coloca el temporal en el final
    }
}

// Función: quitar_espacios
// Descripción: Elimina todos los espacios de la cadena moviendo los caracteres hacia adelante
// Argumentos: cad -> cadena a procesar
// Retorno: void (la cadena original queda sin espacios)
void quitar_espacios(char* cad)
{
    int i = 0, j = 0; // i recorre la cadena original, j indica la posición de escritura
    while (cad[i]) {
        if (cad[i] != ' ')
            cad[j++] = cad[i]; // Copia solo caracteres que no sean espacio
        i++;
    }
    cad[j] = '\0'; // Asegura que la cadena termine correctamente
}

// Función: ordenar_consonantes_vocales
// Descripción: Reorganiza la cadena colocando todas las consonantes al inicio y todas las vocales al final
// Argumentos: cad -> cadena a organizar
// Retorno: void (modifica la cadena original)
// Nota: Considera vocales 'AEIOUaeiou', el resto se considera consonante
void ordenar_consonantes_vocales(char* cad)
{
    int n = strlen(cad); // Calcula longitud
    int i = 0, j = n - 1; // i inicia desde el principio, j desde el final
    while (i < j) {
        while (i < j && strchr("AEIOUaeiou", cad[i]) == nullptr)
            i++; // Avanza i hasta encontrar vocal
        while (i < j && strchr("AEIOUaeiou", cad[j]) != nullptr)
            j--; // Retrocede j hasta encontrar consonante
        if (i < j) { // Si no se cruzaron
            char tmp = cad[i]; // Intercambia caracteres
            cad[i] = cad[j];
            cad[j] = tmp;
        }
    }
}

// Función: ordenar_vocales_consonantes
// Descripción: Reorganiza la cadena colocando todas las vocales al inicio y todas las consonantes al final
void ordenar_vocales_consonantes(char* cad)
{
    int n = strlen(cad);
    int i = 0, j = n - 1;
    while (i < j) {
        while (i < j && strchr("AEIOUaeiou", cad[i]) != nullptr)
            i++; // Avanza i hasta consonante
        while (i < j && strchr("AEIOUaeiou", cad[j]) == nullptr)
            j--; // Retrocede j hasta vocal
        if (i < j) {
            char tmp = cad[i];
            cad[i] = cad[j];
            cad[j] = tmp;
        }
    }
}

// Función: ordenar_alfabetico
// Descripción: Ordena la cadena alfabéticamente usando burbuja simple
void ordenar_alfabetico(char* cad)
{
    int n = strlen(cad);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (cad[i] > cad[j]) { // Compara valores ASCII
                char tmp = cad[i];
                cad[i] = cad[j];
                cad[j] = tmp;
            }
        }
    }
}

// Función: contar_letras
// Descripción: Cuenta letras, vocales y consonantes
void contar_letras(char* cad)
{
    int letras = 0, vocales = 0, consonantes = 0;
    for (int i = 0; cad[i]; i++) {
        if (isalpha(cad[i])) { // Comprueba si es letra
            letras++;
            if (strchr("AEIOUaeiou", cad[i]))
                vocales++;
            else
                consonantes++;
        }
    }
    cout << "Total letras: " << letras
         << " | Vocales: " << vocales
         << " | Consonantes: " << consonantes << endl;
}

// Función: buscar_caracter
// Descripción: Busca primera ocurrencia de un carácter
int buscar_caracter(char* cad, char c)
{
    char* ptr = strchr(cad, c); // strchr devuelve puntero al carácter encontrado
    if (ptr)
        return ptr - cad; // Calcula índice relativo
    return -1; // No encontrado
}

// Función: reemplazar_caracter
// Descripción: Reemplaza todas las ocurrencias de un carácter
void reemplazar_caracter(char* cad, char buscar, char reemplazo)
{
    for (int i = 0; cad[i]; i++)
        if (cad[i] == buscar)
            cad[i] = reemplazo;
}

// Función: contar_subcadena
// Descripción: Cuenta cuántas veces aparece una subcadena dentro de otra
int contar_subcadena(char* cad, char* sub)
{
    int veces = 0;
    char* ptr = cad;
    while ((ptr = strstr(ptr, sub)) != nullptr) { // strstr devuelve puntero a la ocurrencia
        veces++; // Incrementa contador
        ptr++; // Avanza para contar posibles superposiciones
    }
    return veces;
}

// Función: reemplazar_subcadena
// Descripción: Reemplaza todas las ocurrencias de una subcadena por otra
void reemplazar_subcadena(char* cad, char* sub, char* rep)
{
    char buffer[1000];
    buffer[0] = '\0'; // Inicializa buffer vacío
    char* ptr = cad;
    while (*ptr) {
        char* occ = strstr(ptr, sub); // Busca ocurrencia de subcadena
        if (occ) {
            strncat(buffer, ptr, occ - ptr); // Copia hasta la subcadena
            strcat(buffer, rep); // Agrega subcadena reemplazo
            ptr = occ + strlen(sub); // Avanza después de la subcadena
        } else {
            strcat(buffer, ptr); // Copia resto de cadena
            break;
        }
    }
    strcpy(cad, buffer); // Copia el resultado a la cadena original
}

// Función: contiene_subcadena
// Descripción: Indica si la cadena contiene a otra y cuántas veces
void contiene_subcadena(char* cad, char* sub)
{
    int veces = contar_subcadena(cad, sub);
    if (veces > 0)
        cout << "La cadena contiene la subcadena '" << sub << "' " << veces << " veces." << endl;
    else
        cout << "La cadena NO contiene la subcadena '" << sub << "'." << endl;
}

//=================== MENU ====================
int main()
{
    char cad[500], sub[50], rep[50]; // Variables para cadena principal, subcadena y reemplazo
    int opcion;

    do {
        cout << "\n===== MENU DE OPERACIONES CON CADENAS =====\n";
        cout << "1. Convertir a mayusculas\n";
        cout << "2. Convertir a minusculas\n";
        cout << "3. Invertir cadena\n";
        cout << "4. Quitar espacios\n";
        cout << "5. Ordenar consonantes al inicio y vocales al final\n";
        cout << "6. Ordenar vocales al inicio y consonantes al final\n";
        cout << "7. Ordenar alfabeticamente\n";
        cout << "8. Contar letras, vocales y consonantes\n";
        cout << "9. Buscar caracter\n";
        cout << "10. Reemplazar caracter\n";
        cout << "11. Contar subcadena\n";
        cout << "12. Reemplazar subcadena\n";
        cout << "13. Ver si una cadena contiene a otra y cuantas veces\n";
        cout << "0. Salir\n";
        cout << "Ingrese opcion: ";
        cin >> opcion;
        cin.ignore(); // Limpiar buffer

        switch (opcion) {
        case 1:
            cout << "Ingrese cadena: ";
            cin.getline(cad, 500);
            convertir_mayusculas(cad);
            cout << "Cadena en mayusculas: " << cad << endl;
            break;
        case 2:
            cout << "Ingrese cadena: ";
            cin.getline(cad, 500);
            convertir_minusculas(cad);
            cout << "Cadena en minusculas: " << cad << endl;
            break;
        case 3:
            cout << "Ingrese cadena: ";
            cin.getline(cad, 500);
            invertir_cadena(cad);
            cout << "Cadena invertida: " << cad << endl;
            break;
        case 4:
            cout << "Ingrese cadena: ";
            cin.getline(cad, 500);
            quitar_espacios(cad);
            cout << "Cadena sin espacios: " << cad << endl;
            break;
        case 5:
            cout << "Ingrese cadena: ";
            cin.getline(cad, 500);
            ordenar_consonantes_vocales(cad);
            cout << "Cadena ordenada (consonantes/vocales): " << cad << endl;
            break;
        case 6:
            cout << "Ingrese cadena: ";
            cin.getline(cad, 500);
            ordenar_vocales_consonantes(cad);
            cout << "Cadena ordenada (vocales/consonantes): " << cad << endl;
            break;
        case 7:
            cout << "Ingrese cadena: ";
            cin.getline(cad, 500);
            ordenar_alfabetico(cad);
            cout << "Cadena ordenada alfabeticamente: " << cad << endl;
            break;
        case 8:
            cout << "Ingrese cadena: ";
            cin.getline(cad, 500);
            contar_letras(cad);
            break;
        case 9: {
            cout << "Ingrese cadena: ";
            cin.getline(cad, 500);
            char c;
            cout << "Ingrese caracter a buscar: ";
            cin >> c;
            cin.ignore();
            int pos = buscar_caracter(cad, c);
            if (pos >= 0)
                cout << "Caracter encontrado en posicion: " << pos << endl;
            else
                cout << "Caracter no encontrado\n";
            break;
        }
        case 10: {
            cout << "Ingrese cadena: ";
            cin.getline(cad, 500);
            char c1, c2;
            cout << "Caracter a reemplazar: ";
            cin >> c1;
            cout << "Caracter reemplazo: ";
            cin >> c2;
            cin.ignore();
            reemplazar_caracter(cad, c1, c2);
            cout << "Cadena modificada: " << cad << endl;
            break;
        }
        case 11: {
            cout << "Ingrese cadena: ";
            cin.getline(cad, 500);
            cout << "Ingrese subcadena a contar: ";
            cin.getline(sub, 50);
            int v = contar_subcadena(cad, sub);
            cout << "La subcadena aparece " << v << " veces.\n";
            break;
        }
        case 12: {
            cout << "Ingrese cadena: ";
            cin.getline(cad, 500);
            cout << "Ingrese subcadena a reemplazar: ";
            cin.getline(sub, 50);
            cout << "Ingrese subcadena nueva: ";
            cin.getline(rep, 50);
            reemplazar_subcadena(cad, sub, rep);
            cout << "Cadena modificada: " << cad << endl;
            break;
        }
        case 13: {
            cout << "Ingrese cadena: ";
            cin.getline(cad, 500);
            cout << "Ingrese subcadena a buscar: ";
            cin.getline(sub, 50);
            contiene_subcadena(cad, sub);
            break;
        }
        case 0:
            cout << "Saliendo...\n";
            break;
        default:
            cout << "Opcion invalida\n";
        }
    } while (opcion != 0);

    return 0;
}
