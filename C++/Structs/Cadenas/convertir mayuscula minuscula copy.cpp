/*Crear una funci�n que convierta una cadena a may�scula o min�scula seg�n seleccione el usuario.*/
#include <ctype.h>
#include <iostream>

using namespace std;

void may_min(int opc, char* cad);

int main()
{
    char cad[1000];
    int opc;
    char continuar;
    do {
        cout << "Ingrese una cadena de caracteres: ";
        fflush(stdin);
        gets(cad);
        do {
            cout << "Seleccione el formato a convertir 1.May�scula - 2.Min�scula: ";
            cin >> opc;
        } while (opc < 1 || opc > 2);

        may_min(opc, cad);

        cout << cad << endl;
        do {
            cout << "Desea continuar [S]i - [N]o: ";
            cin >> continuar;
            continuar = toupper(continuar);
        } while (continuar != 'S' && continuar != 'N');

    } while (continuar == 'S');
}

void may_min(int opc, char* cad)
{
    int x = 0;
    if (opc == 1) {
        do {
            if (isalpha(cad[x])) {
                cad[x] = toupper(cad[x]);
            }
            x++;
        } while (cad[x] != '\0');
    } else {
        do {
            if (isalpha(cad[x])) {
                cad[x] = tolower(cad[x]);
            }
            x++;
        } while (cad[x] != '\0');
    }
}
