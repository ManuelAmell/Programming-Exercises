#include <iostream>
#include <windows.h>
using namespace std;
int main(){
int sumapares=0,sumaimpares=0;
int n,pos=1,og;
cout <<"ingrese el numero:"<<endl;
cin >>n;
string numero=to_string(n);//combiertye el numero a cadena de texto
for (char c : numero){
    int digito = c-'0';//convierte el digito a entero
    if (pos %2==0){
        sumapares+=digito;
        cout <<"par <"<<digito<<endl;
    }
    else {
        sumaimpares+=digito;
       cout <<"impar <"<<digito;
    }
    pos++;
}
    return 0;
}