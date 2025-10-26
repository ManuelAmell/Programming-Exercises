#include <iostream>
using namespace std;
int main(){
	int i=0,n,aux,s=0,p;
	string dpd="no es un dpd";
	cout << "ingrese n"<<endl;
	cin >>n;
	aux=n;
	for (i=0;aux>0;i++){
		s+=aux%10;
		cout<<aux%10<<endl;
		aux/=10;
	}
	p=s*i;
	cout <<"p="<<p<<endl;
	for (int x=2;x < n;x++)
	{
		if (n%x==0)
		{
			cout <<x<<" es un divisor propio "<<endl;
			  if (x==p){
			  dpd="el numero es DPD";
			  }
		}
	}
	cout<<dpd;
	
	
	return 0;
}
