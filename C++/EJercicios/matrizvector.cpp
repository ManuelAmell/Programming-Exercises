#include <iostream>
#include <windows.h>
using namespace std;
int main(){
    int matriz [4][3];
    int filas,columnas;
    cout << "ingrese la cantidad de filas :";cin >>filas;
    cout <<"ingrese la cantidad de columnas :";cin >>columnas;
    for (int i=0; i < filas;i++){
cout << "fila "<<i+1<<endl;

        for (int x=0;x < columnas;x++){
            cout << "ingrese el dato para la posicion "<<x+1<<" :";
            cin>>matriz[i][x];

        }
    }

for (int j=0;j < filas;j++){
cout << "fila "<<j+1<<endl;
for(int k=0;k < columnas;k++){
    cout << "[ "<<matriz[j][k]<<"]  ";
}
cout <<endl;
}

for (int j=0;j < columnas;j++){
cout << "fila "<<j+1<<endl;
for(int k=0;k < filas;k++){
    cout << "[ "<<matriz[k][j]<<"]  ";
}
cout <<endl;
}

    return 0;
}
