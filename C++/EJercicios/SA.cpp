/*En una tienda de venta de repuestos automotrices se tiene que el descuento depende del monto de venta, as�:
 Se ingresa el monto de venta y el sistema debe calcular el descuento y restarlo del total seg�n las reglas:
 
Si el monto es menor que 50.000 no hay descuento
Si el monto est� comprendido entre 50.000 y 100.000 inclusive, el descuento es de 5%
Si el monto es mayor a 100.000 hasta 700.000 inclusive, el descuento es del 11%
Si el monto es superior a 700.000 pero no mayor a 1.500.000, el descuento es del 18%
Si  el monto es mayor de 1.500.000 el descuento es del 25%.*/

#include <iostream>//*Para usar cout y cin*/
#include <iomanip>//*Para usar setprecision*/
#include <cstdlib> // Para usar system("cls")
using namespace std;

int main()
{
double venta;
double descuento, total;

cout<<"Ingrese el monto de la venta realizada: "<<endl;
cin>>venta;


if (venta<50000)
{
	descuento = 0;
	total = venta;
}


else if (venta>=50000 && venta<=100000)
	{
		descuento = 0.05;
	}
	else if (venta>100000 && venta<=700000)
		{
			descuento = 0.11;
		}
		
		else if (venta>700000 && venta<=1500000)
			{
				descuento = 0.18;
			}
			
			else 
			{
				descuento = 0.25;
			}
		
	
system ("cls");

cout <<"\n\n\n";
cout <<fixed<<setprecision(2);
cout<<"El monto de la venta es: $"<<venta<<endl;

cout<<"El descuento que se le realizara sera de: "<<descuento*100<<"%"<<endl;

cout<<"El total que debe cancelar es: $"<<venta-(venta*descuento);
}
