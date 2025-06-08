#include <iostream>
#include <cstdlib>//para usar system("cls") y limpiar pantalla y system("pause") para pausar la 
//ejecucion del programa
using namespace std;
int main(){

    int t[3][3],j[3][3],k[3][3];

    for(int i=0;i<3;i++)
    {
        for (int x=0;x < 3;x++)
        {
            cout <<"matriz 1 Ingrese el valor para la posicion" <<"["<<i+1<<"] "<<"["<<x+1<<"]";
            cin >>t[i][x];
        }
    }
    cout<<endl;

    for(int i=0;i<3;i++)
    {
        for (int x=0;x<3;x++)
        {
         cout <<"matriz 2 ingrese el valor para la posicion:"<<"["<<i<<"] ";
         cin >>j[i][x];
        }
    }

    system("cls");

    cout<<" matriz 1"<<endl;

    for (int i=0;i <3;i++)
    {
        for (int x=0;x<3;x++)
        {
            cout <<"["<<t[i][x]<<"]";
        }
    }
    cout <<endl;

    cout<<" matriz 2"<<endl;

    for (int i=0;i <3;i++)
    {
        for (int x=0;x<3;x++)
        {
            cout <<"["<<j[i][x]<<"]";
        }
    }
    
    cout<<endl;

    cout<<" matriz 3"<<endl;

    for(int i=0;i<3;i++)
    {
        for (int x=0;x<3;x++)
        {
            k[i][x]=t[i][x]+j[i][x];
            cout <<"["<<k[i][x]<<"]";
        }
    }
   
        return 0;
}