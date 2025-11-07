#include <cctype> // toupper: convierte caracteres a mayúsculas
#include <cstring> // strlen, strcmp, strcpy, strcat, strchr: funciones para manipular C-strings
#include <iostream> // entrada/salida estándar
using namespace std;

// ============================
// Función para convertir una cadena a mayúsculas
// ============================
void convertirMayusculas(char* cad)
{
    // Recorre cada carácter hasta encontrar el terminador '\0'
    for (int i = 0; cad[i]; i++) {
        cad[i] = toupper(cad[i]); // Convierte cada letra a mayúscula
    }
}

// ============================
// Función para invertir una cadena
// ============================
void invertirCadena(char* cad)
{
    int n = strlen(cad); // Obtiene la longitud de la cadena
    // Intercambia los caracteres desde los extremos hacia el centro
    for (int i = 0; i < n / 2; i++) {
        char temp = cad[i];
        cad[i] = cad[n - i - 1];
        cad[n - i - 1] = temp;
    }
}

// ============================
// Función para mostrar la longitud de la cadena
// ============================
void mostrarLongitud(char* cad)
{
    cout << "La longitud de la cadena es: " << strlen(cad) << endl;
    // strlen devuelve el número de caracteres antes de '\0'
}

// ============================
// Función para comparar dos cadenas
// ============================
void compararCadenas(char* cad1, char* cad2)
{
    int res = strcmp(cad1, cad2);
    // strcmp compara lexicográficamente:
    // 0 si son iguales, >0 si cad1 > cad2, <0 si cad1 < cad2

    if (res == 0) {
        cout << "Las cadenas son iguales." << endl;
    } else if (res > 0) {
        cout << "Cadena 1 es mayor que Cadena 2." << endl;
    } else {
        cout << "Cadena 2 es mayor que Cadena 1." << endl;
    }
}

// ============================
// Función para buscar un carácter en la cadena
// ============================
void buscarCaracter(char* cad, char c)
{
    char* ptr = strchr(cad, c);
    // strchr devuelve un puntero a la primera ocurrencia de 'c' o nullptr si no se encuentra

    if (ptr) {
        cout << "El caracter '" << c << "' se encuentra en la posición " << (ptr - cad) << endl;
        // ptr - cad calcula la posición del carácter en la cadena
    } else {
        cout << "El caracter '" << c << "' no se encuentra en la cadena." << endl;
    }
}

// ============================
// Función principal con menú
// ============================
int main()
{
    char cad1[100], cad2[100]; // Cadenas de trabajo
    int opcion;

    do {
        // Menú de opciones
        cout << "\n===== MENU DE OPERACIONES CON CADENAS =====" << endl;
        cout << "1. Convertir cadena a mayusculas" << endl;
        cout << "2. Invertir cadena" << endl;
        cout << "3. Mostrar longitud de cadena" << endl;
        cout << "4. Comparar dos cadenas" << endl;
        cout << "5. Buscar caracter en cadena" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cin.ignore(); // Limpia el buffer antes de leer cadenas

        switch (opcion) {
        case 1:
            cout << "Ingrese la cadena: ";
            cin.getline(cad1, 100); // Lectura segura de línea
            convertirMayusculas(cad1); // Llama a la función
            cout << "Cadena en mayusculas: " << cad1 << endl;
            break;

        case 2:
            cout << "Ingrese la cadena: ";
            cin.getline(cad1, 100);
            invertirCadena(cad1);
            cout << "Cadena invertida: " << cad1 << endl;
            break;

        case 3:
            cout << "Ingrese la cadena: ";
            cin.getline(cad1, 100);
            mostrarLongitud(cad1);
            break;

        case 4:
            cout << "Ingrese la primera cadena: ";
            cin.getline(cad1, 100);
            cout << "Ingrese la segunda cadena: ";
            cin.getline(cad2, 100);
            compararCadenas(cad1, cad2);
            break;

        case 5:
            char c;
            cout << "Ingrese la cadena: ";
            cin.getline(cad1, 100);
            cout << "Ingrese el caracter a buscar: ";
            cin >> c;
            buscarCaracter(cad1, c);
            break;

        case 0:
            cout << "Saliendo del programa..." << endl;
            break;

        default:
            cout << "Opcion invalida." << endl;
        }

    } while (opcion != 0);

    return 0;
}
