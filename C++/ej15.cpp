#include <iostream>

using namespace std;
int main(){
    
    int grupo[8];
    int mayor=0;
    int menor=0;

    for (int x=0;x<8;x++)//se recorre el arreglo para ingresar los numeros
    {
        cout<<"ingrese un numero para la casilla "<<x+1<<" --:";
        cin>>grupo[x];

        if(x==0)//para que el primer numero sea el mayor y el menor al inicio
        {
            mayor=grupo[x];
            menor=grupo[x];
        }

        if(grupo[x]>mayor)//si el numero ingresado es mayor al mayor actual
        {
            mayor=grupo[x];
        }
        
        if (grupo[x]<=menor)//si el numero ingresado es menor o igual al menor actual
        {
            menor=grupo[x];
        }
    }
         cout <<"mayor:"<<mayor<<endl; 
         cout <<"menor:"<<menor<<endl;
         return 0;
}