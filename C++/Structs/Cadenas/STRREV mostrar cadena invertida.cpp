#include <iostream>
#include <string.h>
using namespace std;

void invertir_cadena(char cad[]);

int main()
{
	char cad[1000];
	cout<<"Ingrese una cadena ";
	gets(cad);
	system("cls");
	cout<<"Cadena ingresada: "<<cad <<endl;
	cout<<"Cadena invertida: "<<strrev(cad);
}


