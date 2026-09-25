#include <iostream>
using namespace std; 

long producto (int a,int b){
	if (b < 0){
		return -producto(a, -b);
	}
	if (b == 0){
		return 0;
	}
	return a + producto(a, b-1);
}



int main(){
	int a,b;
	 cout << " ingrese numero 1:";
	 cin >> a, 
	 cout << "ingrese numero 2:";
	 cin >>b;
	 
	 cout <<endl<< a<<" x "<<b<<" = "<< producto(a,b);
	 return 0;
}
