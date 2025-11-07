#include <cstring> // Biblioteca que contiene funciones de manipulación de cadenas y memoria
#include <iostream>
using namespace std;

int main()
{
    char cad1[100], cad2[100], sub[100];
    int opcion;

    do {
        cout << "\n===== MENU DE FUNCIONES DE CADENAS CON COMENTARIOS EXPLICATIVOS =====\n";
        cout << "1. strcpy\n";
        cout << "2. strncpy\n";
        cout << "3. strcat\n";
        cout << "4. strncat\n";
        cout << "5. strchr\n";
        cout << "6. strrchr\n";
        cout << "7. strstr\n";
        cout << "8. strncmp\n";
        cout << "9. memset\n";
        cout << "10. memcpy\n";
        cout << "11. memmove\n";
        cout << "0. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cin.ignore(); // Limpiar buffer de entrada antes de getline

        switch (opcion) {
        case 1: {
            // strcpy(destino, origen)
            // - Copia toda la cadena 'origen' en 'destino'
            // - Primer argumento: destino (debe tener suficiente espacio)
            // - Segundo argumento: origen
            // - Devuelve un puntero a destino
            cout << "\n--- strcpy(destino, origen) ---\n";
            cout << "Copia toda la cadena origen en destino.\n";
            cout << "Ingrese cadena origen: ";
            cin.getline(cad2, 100);
            strcpy(cad1, cad2);
            cout << "Cadena destino: " << cad1 << endl;
            break;
        }

        case 2: {
            // strncpy(destino, origen, n)
            // - Copia los primeros n caracteres de 'origen' en 'destino'
            // - Si n < strlen(origen), NO agrega '\0', por lo que se debe agregar manualmente
            // - Devuelve un puntero a destino
            cout << "\n--- strncpy(destino, origen, n) ---\n";
            int n;
            cout << "Ingrese cadena origen: ";
            cin.getline(cad2, 100);
            cout << "Ingrese numero de caracteres a copiar: ";
            cin >> n;
            cin.ignore();
            strncpy(cad1, cad2, n);
            cad1[n] = '\0'; // asegurarse de terminar con '\0'
            cout << "Cadena destino: " << cad1 << endl;
            break;
        }

        case 3: {
            // strcat(destino, origen)
            // - Concatena toda la cadena 'origen' al final de 'destino'
            // - 'destino' debe tener suficiente espacio para la cadena resultante
            // - Devuelve un puntero a 'destino'
            cout << "\n--- strcat(destino, origen) ---\n";
            cout << "Ingrese cadena destino: ";
            cin.getline(cad1, 100);
            cout << "Ingrese cadena a concatenar: ";
            cin.getline(cad2, 100);
            strcat(cad1, cad2);
            cout << "Cadena concatenada: " << cad1 << endl;
            break;
        }

        case 4: {
            // strncat(destino, origen, n)
            // - Concatena los primeros n caracteres de 'origen' al final de 'destino'
            // - 'destino' debe tener suficiente espacio para la cadena resultante
            // - Devuelve un puntero a 'destino'
            cout << "\n--- strncat(destino, origen, n) ---\n";
            int n;
            cout << "Ingrese cadena destino: ";
            cin.getline(cad1, 100);
            cout << "Ingrese cadena a concatenar: ";
            cin.getline(cad2, 100);
            cout << "Ingrese numero de caracteres a concatenar: ";
            cin >> n;
            cin.ignore();
            strncat(cad1, cad2, n);
            cout << "Cadena concatenada: " << cad1 << endl;
            break;
        }

        case 5: {
            // strchr(cad, c)
            // - Busca la PRIMERA ocurrencia del caracter 'c' en 'cad'
            // - Devuelve un puntero a la posición del caracter o nullptr si no existe
            cout << "\n--- strchr(cad, c) ---\n";
            char c;
            cout << "Ingrese cadena: ";
            cin.getline(cad1, 100);
            cout << "Ingrese caracter a buscar: ";
            cin >> c;
            cin.ignore();
            char* ptr = strchr(cad1, c);
            if (ptr)
                cout << "Caracter encontrado en posicion " << (ptr - cad1) << endl;
            else
                cout << "Caracter no encontrado\n";
            break;
        }

        case 6: {
            // strrchr(cad, c)
            // - Busca la ULTIMA ocurrencia del caracter 'c' en 'cad'
            // - Devuelve un puntero a la posición del caracter o nullptr si no existe
            cout << "\n--- strrchr(cad, c) ---\n";
            char c;
            cout << "Ingrese cadena: ";
            cin.getline(cad1, 100);
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

        case 7: {
            // strstr(cad, sub)
            // - Busca la subcadena 'sub' dentro de 'cad'
            // - Devuelve un puntero a la primera ocurrencia o nullptr si no existe
            cout << "\n--- strstr(cad, sub) ---\n";
            cout << "Ingrese cadena: ";
            cin.getline(cad1, 100);
            cout << "Ingrese subcadena a buscar: ";
            cin.getline(sub, 100);
            char* ptr = strstr(cad1, sub);
            if (ptr)
                cout << "Subcadena encontrada en posicion " << (ptr - cad1) << endl;
            else
                cout << "Subcadena no encontrada\n";
            break;
        }

        case 8: {
            // strncmp(cad1, cad2, n)
            // - Compara los primeros n caracteres de dos cadenas
            // - Devuelve 0 si son iguales, >0 si cad1>cad2, <0 si cad1<cad2
            cout << "\n--- strncmp(cad1, cad2, n) ---\n";
            int n;
            cout << "Ingrese primera cadena: ";
            cin.getline(cad1, 100);
            cout << "Ingrese segunda cadena: ";
            cin.getline(cad2, 100);
            cout << "Ingrese numero de caracteres a comparar: ";
            cin >> n;
            cin.ignore();
            int cmp = strncmp(cad1, cad2, n);
            if (cmp == 0)
                cout << "Primeros " << n << " caracteres iguales\n";
            else if (cmp > 0)
                cout << "Cadena1 es mayor en los primeros " << n << " caracteres\n";
            else
                cout << "Cadena2 es mayor en los primeros " << n << " caracteres\n";
            break;
        }

        case 9: {
            // memset(ptr, valor, n)
            // - Llena n bytes de memoria apuntados por ptr con el valor dado
            // - Útil para inicializar arreglos o buffers
            // - NO agrega '\0' automáticamente si es una cadena
            cout << "\n--- memset(ptr, valor, n) ---\n";
            char buffer[50];
            char valor;
            int n;
            cout << "Ingrese caracter para llenar el buffer: ";
            cin >> valor;
            cout << "Ingrese numero de posiciones a llenar: ";
            cin >> n;
            cin.ignore();
            memset(buffer, valor, n);
            buffer[n] = '\0'; // importante si queremos imprimir como cadena
            cout << "Buffer: " << buffer << endl;
            break;
        }

        case 10: {
            // memcpy(dest, src, n)
            // - Copia n bytes de memoria de src a dest
            // - NO verifica solapamiento de bloques
            cout << "\n--- memcpy(dest, src, n) ---\n";
            char src[100], dest[100];
            cout << "Ingrese cadena fuente: ";
            cin.getline(src, 100);
            memcpy(dest, src, strlen(src) + 1); // +1 para incluir '\0'
            cout << "Cadena destino: " << dest << endl;
            break;
        }

        case 11: {
            // memmove(dest, src, n)
            // - Copia n bytes de memoria de src a dest
            // - Seguro si hay solapamiento entre src y dest
            cout << "\n--- memmove(dest, src, n) ---\n";
            char texto[100];
            cout << "Ingrese cadena: ";
            cin.getline(texto, 100);
            // Ejemplo: mover los primeros 5 caracteres 2 posiciones adelante
            memmove(texto + 2, texto, 5);
            texto[7] = '\0';
            cout << "Cadena después de memmove: " << texto << endl;
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
