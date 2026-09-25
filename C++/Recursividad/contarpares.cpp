#include <iostream>
using namespace std;

bool contarPares(int a){
	if (a < 0){
		a = -a;
	}
	if (a < 10)
	{
		return (a % 2 ==0);
	}
	if((a % 10 ) % 2 != 0){
		return false;
	}
	cout << "LOG "<<a<<endl;
	return contarPares(a/10);
}

int main (){
	int n ;
	cout << " ingrese N: "<<endl;cin >> n;
	
	
	if (contarPares(n)){
		cout << " Los digitos de "<<n << " Son todos pares ";
	}
	else
	cout <<"Los digitos de "<<n << " No son pares ";
	return 0;
}
