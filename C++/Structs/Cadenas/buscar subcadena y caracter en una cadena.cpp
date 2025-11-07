/*Dada dos cadenas de caracteres cad1, cad2, verificar si la cadena más corta está contenida en la más larga,
 en caso de tener el mismo tamaño buscar un carácter dado en ambas cadenas*/
 
 #include <iostream>
#include <string.h>
using namespace std;

int main()
{
	
	char cad1[1000], cad2[1000];
	char car; 
	
	setlocale(LC_ALL, "spanish");
	cout<<"Ingrese la primera cadena: ";
	gets(cad1);
	cout<<"Ingrese la segunda cadena: ";
	gets(cad2);
	
	if(strlen(cad1) == strlen(cad2))
	{
		cout<<"Ingrese el caracter a buscar en las cadenas: ";
		cin>>car;
		if(strchr(cad1, car))
		{
			cout<<car <<" Se encontró en "<<cad1 <<endl;
		}	
		else
		{
			cout<<car <<" No Se encontró en "<<cad1 <<endl;
		}
		
		if(strchr(cad2, car))
		{
			cout<<car <<" Se encontró en "<<cad2 <<endl;
		}	
		else
		{
			cout<<car <<" No Se encontró en "<<cad2 <<endl;
		}
		
	}
	else if(strlen(cad1) > strlen(cad2) )
	{
		if(strstr(cad1, cad2))
		{
			cout<<cad2 <<" esta contenida en "<<cad1 <<endl;
		}
	}
	else
	{
		if(strstr(cad2, cad1))
		{
			cout<<cad1 <<" esta contenida en "<<cad2 <<endl;
		}	
	}
	
}
