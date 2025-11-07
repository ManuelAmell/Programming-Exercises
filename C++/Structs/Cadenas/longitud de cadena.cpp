/*Crear una función que obtenga la longitud de una cadena de caracteres. 
Recuerde que el fin de una cadena de caracteres lo determina el carácter NULL (0 = ‘\0’).*/
#include <iostream>
using namespace std;

int longitud_cad(char *cad);

int main()
{
	char cad[100];
	cout<<"Ingrese una cadena para calcular su longitud: ";
	gets(cad);
	cout<<"Longitud de la cadena: "<<longitud_cad(cad) <<endl;
}

int longitud_cad(char *cad)
{
	int l=0;
	while(cad[l]!='\0')
	{
		l++;
	}
	return l;
}


