#include <iostream>
#include <windows.h>
using namespace std;
int main (){
int sumapares=0,sumaimpares=0;
int n,pos=0,og;
cout << "ingrese n"<<endl;
cin >> n;
og = n;
for (pos = 1;n > 0;pos++){
int aux=n % 10;
    if (pos % 2 ==0)
    {
    sumapares += aux;
    cout<<"par<<"<<aux<<endl;
    }
    else {
        sumaimpares += aux;
        cout <<"impar<<"<<aux<<endl;
    }
    n /= 10;
}
system("cls");
if (sumapares == sumaimpares){
    cout <<"el numero"<<og<<"es divisible por 11";
}
else {
    cout<<"el numero "<<og<<"no es divisible x 11";
}
    return 0;
}