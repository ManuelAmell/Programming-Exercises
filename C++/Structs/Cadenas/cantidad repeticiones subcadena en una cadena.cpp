/* Dada una cadena y una subcadena ingresada por el usuario, 
desarrollar un programa que indique cuantas veces se encuentra 
dicha subcadena en la cadena */
#include <iostream>
#include <string.h>
using namespace std;

int buscar_subcadena(char *cad, char *sub)
{
	int x=0; //indice para recorrer la cadena
	int y=0; //indice para recorrer la subcadena
	int z; //indice auxiliar para recorrer la subcadena cuando hay una propabilidad de ocurrencia 
	int veces=0; //contador para contabilizar las repeticiones de la subcadena en la cadena 
	int encontro;
	do
	{
		if(cad[x] == sub[y])
		{
			z=x;
			encontro=0;
			for(y=0; y<strlen(sub); y++)//recorre la subcadena 
			{
				if(cad[z] == sub[y])
				{
					encontro++;
					z++;	
				}
				else
				{
					break;
				}
			}
			if(encontro == strlen(sub))
			{
				veces++;//incrementamos para indicar que hubo una ocurrencia de la subcadena en la cadena
			}
			x=z; y=0;
		}
		else
		{
			x++;
		}
	}while(cad[x]!= '\0');
	
	return veces;
}
//*****************************************************
int main()
{
	char cad[100], sub[100];
	int veces;
	int continuar;
	setlocale(LC_ALL, "spanish");
	do
	{
		system("cls");
		cout<<"Ingrese una cadena de caracteres: ";
		fflush(stdin); gets(cad);
		cout<<"Ingrese la subcadena a buscar en el texto ingresado: ";
		fflush(stdin); gets(sub);
		veces = buscar_subcadena(cad, sub);
		if(veces>0)
		{
			cout<<sub <<" se encontró " <<veces <<" veces en el texto "<<cad <<endl;
		}
		else
		{
			cout<<sub <<" No se encontró " <<" en el texto "<<cad <<endl;
		}
		
		cout<<"Desea buscar otra subcadena 1.SI - No cualquier otro valor: ";
		cin>>continuar;
	}while(continuar == 1);
		
}





