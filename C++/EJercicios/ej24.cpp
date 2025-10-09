#include <iostream>
#include <cstdlib>// Para usar system("cls")
#include <windows.h>// Para usar system("cls")
#include <iomanip>// Para usar setprecision 
using namespace std;
int main(){

    int f,c,mayor,fm,cm;
    long matriz [100][100];

    cout <<"ingrese un valor para las filas :";
    cin >>f;
    cout <<"ingrese un valor para las columnas :";
    cin >>c;

for (int x=0;x < f;x++ )
{
    for (int i=0;i < c;i++)
    {
        cout <<"ingrese un valor para la posicion [" << x+1<<"]"<<"["<<i+1<<"]";
        cin >> matriz[x][i];
        
    }
    
}
system ("cls");

mayor=matriz[0][0];

    for (int x=0;x < f;x++)
    {
        for (int i=0;i < c;i++)
        {
            cout  <<"["<<matriz[x][i]<<"]\t";
            if (matriz[x][i]>mayor)
            {
                mayor =matriz[x][i];
                fm=x+1;
                cm=i+1;
            }
        }
        cout <<"\n";
    }
    cout <<"el numero mayor de la matriz es :"<<mayor<<"\t";
    cout <<"y su posicion es "<<"("<<fm<<")"<<"("<<cm<<")";
    return 0;
}