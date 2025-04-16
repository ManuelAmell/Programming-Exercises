#include <iostream>
#include <windows.h> 

using namespace std;

int main(){

    int matriz [3][3]={0};
    int n=3;
    long sumad=0,sumad2=0;

    cout << "suma de diagonales "<<endl;

    for (int x=0; x < n ;x++)
    {
        for (int i=0; i < n ;i++)
        {
            cout <<"ingrese el numero para la casilla ("<<x<<")-("<<i<<")";
            cin >> matriz [x][i];

            system("CLS");

                for (int u=0; u < n ;u++)
                 {
                    for (int y=0; y < n;y++)
                    {
                         cout <<"["<<matriz[u][y]<<"]"<<"\t";
                    }
                    cout <<endl;    
                }
                
        }
    
    }

    for (int x=0; x < n ;x++)
    {
            sumad += matriz [x][x];   
    }
    cout <<"el suma de la diagonal principal es : "<<sumad<<endl;

    for (int x=0;x < n;x++)
    {
     sumad2+=matriz[x][n-1-x];
    }

    cout <<"suma diagonal secundaria:"<<sumad2;

    return 0;
}