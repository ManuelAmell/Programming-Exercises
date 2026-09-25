#include <iostream>
using namespace std;

long potencia(int a ,int b){
	if (b <=0){
		return 1;
	}
	return a * potencia(a, b-1);
}

int main(){
	int a,b;
	cout << "ingrese numero (A) para calcular su potencia ";cin>>a;
	cout <<"ingrese numero al que desea elevar (B) :";cin >>b;
	
	cout << a <<" eleveado ala "<<b<<" = "<<potencia(a,b);
	return 0;
}
