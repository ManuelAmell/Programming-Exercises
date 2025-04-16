#include <iostream>
using namespace std;
int main(){
    
int valores;
float cinta[100];
long long  suma=0;

cout <<"cantidad de numeros :";
cin >>valores;

for (int x=0;x < valores;x++)
{
    cout <<"ingrese el valor "<<x+1<<":";
    cin >>cinta[x];
    suma+=cinta[x];
}

cout <<"la suma de los valores es:"<<suma<<endl;
cout <<"el promedio es :"<<suma/valores;
    return 0;
}
