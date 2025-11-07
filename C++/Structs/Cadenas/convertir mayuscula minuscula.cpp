/*Crear una función que convierta una cadena a mayúscula o minúscula según seleccione el usuario.*/
#include <iostream>
#include <ctype.h>
using namespace std;

void may_min(int opc, char *cad);

int main()
{
	char cad[1000];
	int opc;
	char continuar;
	do
	{
		cout<<"Ingrese una cadena de caracteres: ";
		fflush(stdin);
		gets(cad);
		do
		{
			cout<<"Seleccione el formato a convertir 1.Mayúscula - 2.Minúscula: ";
			cin>>opc;	
		}while(opc<1||opc>2);
		
		may_min(opc, cad);
		
		cout<<cad <<endl;
		do
		{
			cout<<"Desea continuar [S]i - [N]o: ";
			cin>>continuar; 
			continuar = toupper(continuar);	
		}while(continuar!='S' && continuar !='N');
		
		
	}while(continuar =='S');
}

void may_min(int opc, char *cad)
{
	int x=0;
	if(opc==1)
	{
		do
		{
			if(isalpha(cad[x]) )
			{
				cad[x] = toupper(cad[x]);
			}
			x++;
		}while(cad[x]!='\0');
	}
	else
	{
		do
		{
			if(isalpha(cad[x]))
			{
				cad[x] = tolower(cad[x]);
			}
			x++;
		}while(cad[x]!='\0');	
	}
}
