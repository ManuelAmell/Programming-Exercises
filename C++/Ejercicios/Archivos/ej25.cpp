#include <iostream>
using namespace std;
int main(){

    int matriz[3][3];
    long s1=0,s2=0,s3=0,c1=0,c2=0,c3=0;
    
    for (int x=0;x <3;x++)
    {
        for (int i=0;i < 3;i++)
        {
            cout << "ingrese un valor para la posicion ["<<x+1<<"]"<<"["<<i+1<<"]\t";
            cin >>matriz[x][i];

        }
    }
    for (int x=0;x <3;x++)
    {
        for (int i=0;i < 3;i++)
        {
            cout << "["<<matriz[x][i]<<"]\t";
        }
        cout <<endl;
    }
    for (int o=0;o <3;o++)
    {
        
        for (int u=0;u < 3;u++)
        {
            if(o==0)
            {
                s1+=matriz[o][u];
            }
            if (o==1)
            {
                s2+=matriz[o][u];
            }
            if (o==2)
            {
                s3+=matriz[o][u];
            }
        }
        c1+=matriz[o][0];
        c2+=matriz[o][1];
        c3+=matriz[o][2];
    }

    cout <<"la suma de la fila 1 es:"<<s1<<"\t";
    cout <<"la suma de la fila 2 es:"<<s2<<"\t";
    cout <<"la suma de la fila 3 es:"<<s3<<"\t";

    cout <<endl;

    cout <<"la suma de la columna 1 es:"<<c1<<endl;
    cout <<"la suma de la columna 2 es:"<<c2<<endl;
    cout <<"la suma de la columna 3 es:"<<c3<<endl;
    
    return 0;
}