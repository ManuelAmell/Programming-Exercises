#include <iostream>
using namespace std;

long factorial(int a ){
	
	 if (a == 1){	
			return 1;
		}
	cout << a <<" x "<<a-1<<" = "<<a*(a-1)<<endl;
	
	return  a * factorial (a - 1);
}

int main (){
	long factorialito;
	
	cout << " Ingrese Numero para calcular su factorial N! :";
	cin >>factorialito;
	
	
	cout << "Factorial = "<< factorial (factorialito); ;
	return 0;
}
