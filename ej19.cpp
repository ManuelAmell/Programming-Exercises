#include <iostream>
#include <cstdlib>

using namespace std;

int main(){

 int m1[3][3],m2 [3][3];

   for (int i = 0; i < 3; i++)
   {
       for (int j = 0; j < 3; j++)
       {
           cout << "Ingrese el valor para la posicion [" << i << "] [" << j << "]: ";
           cin >> m1[i][j];
       }
   }
    system("cls");

    cout <<"Matriz original"<<endl;
    for(int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            cout <<"["<<m1[i][j]<<"]";
        }
        cout <<endl;
    }

    for(int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        { 
        
            m2[j][i]=m1[i][j];
             
        }
    }

    cout <<"Matriz transpuesta"<<endl;

    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            cout <<"["<<m2[i][j]<<"]";
        }
        cout <<endl;
    }
    return 0;
}