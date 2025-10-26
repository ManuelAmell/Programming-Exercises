#include <iostream>
using namespace std;

int main(){ 

    int five[5];
    int suma=0;

for (int x=0;x<5;x++)
{
    cout<<"ingrese un numero para la casilla "<<x+1;
    cin>>five[x];
    
    suma+=five[x];
}
for(int x=0;x<5;x++)
{
    cout<<"["<<five[x]<<"]"<<endl;
}
    cout <<"la suma de los numeros es: "<<suma<<endl;
    return 0;
}