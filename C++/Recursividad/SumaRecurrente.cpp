#include <iostream>
using namespace std;
/*Ejercicio 19: Realice una función recursiva que sume los primeros n enteros positivos.
Nota: para plantear la función recursiva tenga en cuenta que la suma puede expresarse
mediante la siguiente recurrencia:

    suma(n) = 1             , si n=1
              n+suma(n-1)   , si n>1
*/
int suma (int n){
	
	if (n==1){
		return 1;
	}
	if (n > 1){
		return n + suma(n-1);
	}
	else 
		{
			cout << " Sea serio ponga numeros positivos...";
			return 0;
		}
	
}
 
 
int main (){
	int n;
	cout << " Ingrese N : ";
	cin >> n;
		cout << " Suma de Numeros positivos hasta N "<<suma(n);

	return 0;
}
