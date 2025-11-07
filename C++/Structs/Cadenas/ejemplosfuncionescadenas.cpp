#include <cctype> // toupper, tolower
#include <cstring> // strcpy, strcat, strlen, strcmp, strchr, strstr
#include <iostream>
using namespace std;

//================ FUNCIONES MANUALES ==================

// Quitar espacios de una cadena
void quitar_espacios(char* cad)
{
    int i = 0, j = 0;
    while (cad[i]) {
        if (cad[i] != ' ') {
            cad[j++] = cad[i];
        }
        i++;
    }
    cad[j] = '\0';
}

// Ordenar consonantes al inicio y vocales al final (sin cadena auxiliar)
void ordenar_consonantes_vocales(char* cad)
{
    int n = strlen(cad);
    int i = 0, j = n - 1;
    while (i < j) {
        // mientras i es vocal y j es consonante, intercambiar
        while (i < j && strchr("AEIOUaeiou", cad[i]) == nullptr)
            i++;
        while (i < j && strchr("AEIOUaeiou", cad[j]) != nullptr)
            j--;
        if (i < j) {
            char tmp = cad[i];
            cad[i] = cad[j];
            cad[j] = tmp;
        }
    }
}

// Contar ocurrencias de subcadena en cadena
int contar_subcadena(char* cad, char* sub)
{
    int veces = 0;
    char* ptr = cad;
    while ((ptr = strstr(ptr, sub)) != nullptr) {
        veces++;
        ptr++; // avanzar un carácter para encontrar ocurrencias superpuestas
    }
    return veces;
}

// Convertir cadena a mayúsculas
void convertir_mayusculas(char* cad)
{
    for (int i = 0; cad[i]; i++)
        cad[i] = toupper(cad[i]);
}

// Convertir cadena a minúsculas
void convertir_minusculas(char* cad)
{
    for (int i = 0; cad[i]; i++)
        cad[i] = tolower(cad[i]);
}

// Invertir cadena
void invertir_cadena(char* cad)
{
    int n = strlen(cad);
    for (int i = 0; i < n / 2; i++) {
        char tmp = cad[i];
        cad[i] = cad[n - i - 1];
        cad[n - i - 1] = tmp;
    }
}

// Reemplazar un carácter por otro en toda la cadena
void reemplazar_caracter(char* cad, char buscar, char reemplazo)
{
    for (int i = 0; cad[i]; i++) {
        if (cad[i] == buscar)
            cad[i] = reemplazo;
    }
}

//=================== MENU PRINCIPAL ===================
int main()
{
    char cad1[200], cad2[200], sub[100];
    int opcion;

    do {
        cout << "\n===== MENU DE MANIPULACION DE CADENAS =====\n";
        cout << "1. Quitar espacios de una cadena\n";
        cout << "2. Ordenar consonantes al inicio y vocales al final\n";
        cout << "3. Contar ocurrencias de subcadena\n";
        cout << "4. Convertir cadena a mayusculas\n";
        cout << "5. Convertir cadena a minusculas\n";
        cout << "6. Invertir cadena\n";
        cout << "7. Buscar primer ocurrencia de un caracter (strchr)\n";
        cout << "8. Buscar ultima ocurrencia de un caracter (strrchr)\n";
        cout << "9. Reemplazar un caracter por otro\n";
        cout << "10. Concatenar cadenas (strcat)\n";
        cout << "11. Copiar cadena (strcpy)\n";
        cout << "0. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cin.ignore(); // limpiar buffer

        switch (opcion) {
        case 1:
            cout << "Ingrese cadena: ";
            cin.getline(cad1, 200);
            quitar_espacios(cad1);
            cout << "Cadena sin espacios: " << cad1 << endl;
            break;

        case 2:
            cout << "Ingrese cadena: ";
            cin.getline(cad1, 200);
            ordenar_consonantes_vocales(cad1);
            cout << "Cadena ordenada: " << cad1 << endl;
            break;

        case 3:
            cout << "Ingrese cadena: ";
            cin.getline(cad1, 200);
            cout << "Ingrese subcadena a buscar: ";
            cin.getline(sub, 100);
            cout << "La subcadena aparece " << contar_subcadena(cad1, sub) << " veces\n";
            break;

        case 4:
            cout << "Ingrese cadena: ";
            cin.getline(cad1, 200);
            convertir_mayusculas(cad1);
            cout << "Cadena en mayusculas: " << cad1 << endl;
            break;

        case 5:
            cout << "Ingrese cadena: ";
            cin.getline(cad1, 200);
            convertir_minusculas(cad1);
            cout << "Cadena en minusculas: " << cad1 << endl;
            break;

        case 6:
            cout << "Ingrese cadena: ";
            cin.getline(cad1, 200);
            invertir_cadena(cad1);
            cout << "Cadena invertida: " << cad1 << endl;
            break;

        case 7: {
            cout << "Ingrese cadena: ";
            cin.getline(cad1, 200);
            char c;
            cout << "Ingrese caracter a buscar: ";
            cin >> c;
            cin.ignore();
            char* ptr = strchr(cad1, c);
            if (ptr)
                cout << "Primer ocurrencia en posicion " << (ptr - cad1) << endl;
            else
                cout << "Caracter no encontrado\n";
            break;
        }

        case 8: {
            cout << "Ingrese cadena: ";
            cin.getline(cad1, 200);
            char c;
            cout << "Ingrese caracter a buscar: ";
            cin >> c;
            cin.ignore();
            char* ptr = strrchr(cad1, c);
            if (ptr)
                cout << "Ultima ocurrencia en posicion " << (ptr - cad1) << endl;
            else
                cout << "Caracter no encontrado\n";
            break;
        }

        case 9: {
            cout << "Ingrese cadena: ";
            cin.getline(cad1, 200);
            char buscar, reemplazo;
            cout << "Ingrese caracter a reemplazar: ";
            cin >> buscar;
            cout << "Ingrese nuevo caracter: ";
            cin >> reemplazo;
            cin.ignore();
            reemplazar_caracter(cad1, buscar, reemplazo);
            cout << "Cadena modificada: " << cad1 << endl;
            break;
        }

        case 10:
            cout << "Ingrese cadena destino: ";
            cin.getline(cad1, 200);
            cout << "Ingrese cadena a concatenar: ";
            cin.getline(cad2, 200);
            strcat(cad1, cad2);
            cout << "Cadena concatenada: " << cad1 << endl;
            break;

        case 11:
            cout << "Ingrese cadena origen: ";
            cin.getline(cad2, 200);
            strcpy(cad1, cad2);
            cout << "Cadena copiada: " << cad1 << endl;
            break;

        case 0:
            cout << "Saliendo...\n";
            break;

        default:
            cout << "Opcion invalida\n";
        }

    } while (opcion != 0);

    return 0;
}
