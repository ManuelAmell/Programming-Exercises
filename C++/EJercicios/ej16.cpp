#include <iostream>
#include <cstdlib>

using namespace std;    
// Ejercicio 16: Crear un vector de 10 elementos enteros, luego pedir al usuario que ingrese un número a eliminar, si el número se encuentra en el vector, eliminarlo y desplazar los elementos restantes hacia la izquierda, mostrar el vector resultante.
int main(){

int grupo[10],e;

for (int x=0;x<10;x++)
{
    cout <<"ingrese el numero para la casilla :"<<x+1<<":";
    cin >>grupo[x];

}
system("cls");

for (int i=0;i<10;i++)
{
    cout <<grupo[i]<<"   ";
    
}
cout <<"ingrese el numero a eliminar:";
cin >>e;


for (int i=0;i<10;i++)
{  grupo[i];

    if(grupo[i]!=e)
    {
        cout <<grupo[i]<<"   ";
    }    
    
}
    return 0;
}