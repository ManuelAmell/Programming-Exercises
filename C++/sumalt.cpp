#include <bits/stdc++.h>
using namespace std;
int main (){
	int n,aux,s1=0,s2=0;
	
	cout <<"ingrese un numero :";
	cin >>n;
	aux=n;
	
	for (int i=1;i < n;i++){
	int digito=aux%10;
	if (aux%2==0){
		s1+=digito;cout <<"s1="<<s1<<endl;
	}
	else {
		s2+=digito;cout <<"s2="<<s2<<endl;
	}
	aux=n/=10;
							}
}
