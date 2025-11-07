/*Crear una función que obtenga la longitud de una cadena de caracteres. 
Recuerde que el fin de una cadena de caracteres lo determina el carácter NULL (0 = ‘\0’).*/
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	char cad[100];
	cout<<"Ingrese una cadena para calcular su longitud: ";
	gets(cad);
	cout<<"Longitud de la cadena: "<<strlen(cad) <<endl;
}
