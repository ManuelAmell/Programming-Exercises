#include <iostream>
using namespace std;
int main(){

    int m=0;
    int f,c;
    int matriz[100][100];

    cout << "ingrese la cantidad de filas de la matriz:";
    cin >>f;
    cout <<"ingrese la cantidad de columnas de la matariz:";
    cin >>c;

    for (int x=0 ;x < f;x++)
    {
        for (int i=0;i < c ;i++)
        {
            cout <<"ingrese el valor para ["<<x+1<<"]"<<"["<<i+1<<"]";
            cin >>matriz[x][i];
            
            
        }
    }

    m=matriz[0][0];

    for (int g=0;g < f;g++)
    {
        for (int h=0;h < c;h++)
        {
            if (matriz [g][h] < m)
            {
                m=matriz[g][h];
            }
        }
    }
    for (int x=0 ;x < f;x++)
    {
        for (int i=0;i < c ;i++)
        {
            cout<<"["<<matriz [x][i]<<"]\t";
        }
        cout <<"\n";
    }
    cout <<" el numero menor de la matriz es :"<<m;
    
    return 0;
}