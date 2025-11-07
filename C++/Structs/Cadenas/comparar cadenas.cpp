/*1. Dada dos cadenas de caracteres cad1, cad2, realizar los siguientes procesos. 
Mostrar la cadena en mayúscula si son iguales, si son diferentes indicar cual es la mayor y mostrarla invertida*/
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	
	char cad1[1000], cad2[1000];
	cout<<"Ingrese la primera cadena: ";
	gets(cad1);
	cout<<"Ingrese la segunda cadena: ";
	gets(cad2);
	
	if(strcmp(cad1, cad2) == 0)//las dos cadenas son iguales 
	{
		cout<<"Primera cadena "<<strupr(cad1)<<endl;
		cout<<"Segunda cadena "<<strupr(cad2)<<endl;
	}
	else //las cadenas no son iguales
	{
		if(strcmp(cad1, cad2) > 0)//cadena 1 es mayor
		{
			cout<<"Cadena mayor invertida "<<strrev(cad1) <<endl;
		}
		else
		{
			cout<<"Cadena mayor invertida "<<strrev(cad2) <<endl;
		}
	}
}

