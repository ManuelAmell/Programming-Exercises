/*Dada una cadena ingresada por el usuario implementar una solución que 
ordenen de la siguiente forma: consonantes al inicio de la cadena y vocales 
al final.  Ejemplo si se ingresa la cadena hola mundo se debe generar como 
salida hdlnmuaoo.  
Nota: No se puede utilizar una cadena auxiliar.*/
#include <iostream>
#include <string.h>
using namespace std;

//¨**********************
void quitar_espacios(char *cadena)
{
	int x=0;
	int y=0;
	do
	{
		if(cadena[x] == ' ')
		{
			y=x;
			while(cadena[y] == ' ')
			{
				y++;
			}
			for(int i=x; cadena[i]!='\0'; i++)
			{
				cadena[i] = cadena[y];
				y++;
			}
		}
		x++;
	}while(cadena[x] !='\0');
}
//**************************************
void ordenar(char *cadena)
{
	int x=0;
	int y=strlen(cadena)-1;
	char aux;
	do
	{
		if(toupper(cadena[x]) == 'A'|| toupper(cadena[x]) == 'E'|| toupper(cadena[x]) == 'I'||toupper(cadena[x]) == 'O'||toupper(cadena[x]) == 'U' )
		{
			if(toupper(cadena[y]) == 'A'|| toupper(cadena[y]) == 'E'|| toupper(cadena[y]) == 'I'||toupper(cadena[y]) == 'O'||toupper(cadena[y]) == 'U' )	
			{
				while(toupper(cadena[y]) == 'A'|| toupper(cadena[y]) == 'E'|| toupper(cadena[y]) == 'I'||toupper(cadena[y]) == 'O'||toupper(cadena[y]) == 'U')
				{
					y--;
				}
			}//mientras encuentre vocales continuas, una vez encuentre una consonalte sale para mover
			aux = cadena[x];
			cadena[x]= cadena[y];
			cadena[y] = aux;
			y--;
		}
		x++; 
	}while(x<strlen(cadena)/2 && y>strlen(cadena)/2);	
}
//***********************
int main()
{
	char cadena[100];
	char continuar;
	do
	{
		system("cls");
		cout<<"Ingrese una cadena: "; 
		fflush(stdin); 
		gets(cadena);
		quitar_espacios(cadena);
		ordenar(cadena);
		cout<<"Al ordenar la cadena según se solicitó consonantes al inicio y vocales al final"<<endl;
		cout<<"La cadena resultante es: "<<cadena <<endl;
		cout<<"Desea ordenar otra cadena [S]i - Cualquier otro caracter NO: ";
		cin>>continuar;
	}while(toupper(continuar)=='S');
}
