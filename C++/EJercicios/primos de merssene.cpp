/*Programa que dado un numero primo p, determine si p es un primo de merssene
"uno que dado x^p - 1 sea primo siendo x un valor arbitrario" */ 
#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	long p, cant_divisor=0,resultado=1, merssene_divisores=0, merssene;
	int expo=1;
	do
	{
		system("pause");
		system("cls");
		
		cout<<"ingrese un numero primo para verificar que cumpla la condicion: "<<endl;
		cin>>p;
		cant_divisor=0;
		for(int divisor=1; divisor<=p; divisor++)
		{
			
			if (p%divisor==0)
			{
				cout<<"divisores: "<<divisor<<endl;
				cant_divisor++;
			}
		}
		if(cant_divisor==2)
		{
			cout<<"verificacion exitosa, es un primo, continue"<<endl;
		}else if (cant_divisor!=2)
		{
			cout<<"su numero no es primo, intente nuevamente.....";
		}
	}while(cant_divisor!=2);
	
	cout<<"ya realizada la comprobacion de que "<<p<<" sea primo, se realiza la prueba 2^ "<<p<<" para la condicion "<<endl;
	//ciclo para determinar si 2^p == primo
	do
	{
		resultado*=2;
		
		expo++;
	}while(expo<=p);
	// ahora se realiza el ciclo para determinar la cantidad de divisores de el resultado
	merssene=resultado-1;
	for (int divisor=1; divisor<=sqrt(merssene); divisor++)
	{
		if ( merssene % divisor == 0)
		{
			cout<<"divisores de "<<merssene<<" : "<<divisor<<endl;
			merssene_divisores++;
		}
			
		
			
	}	
		if(merssene_divisores==2)
			{
				cout<<"su numero es "<<merssene<<" es un primo de mersenne :DDD "<<endl;
			}else 
			{
				cout<<"su numero "<<merssene<<" no es un primo de merssene "<<endl;
			}
	
}

