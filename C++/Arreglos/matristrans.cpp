#include <iostream>
using namespace std;
int main (){
int f,c;

cout << "ingrese la cantidad de filas :";
cin >>f;
cout << "ingrese la cantidad de columnas :";
cin >>c;
int matriz[f][c];
for (int i =0;i < f;i++){
    for (int x=0;x <c ;x++){
        cout <<"ingrese el dato para la posicion :";
        cin >>matriz [i][x];
    }
}
for (int i =0;i < f;i++){
    for (int x=0;x <c ;x++){
        cout <<"["<<matriz [i][x]<<"]   ";

    }
    cout << endl;

}

cout << endl;

for (int i =0;i < c;i++){//recorrer matriz en esprial y caracol 
    for (int x=0;x < f;x++){
        cout <<"["<<matriz [x][i]<<"]   ";//practicar sumar filas //sumar columnas
    }
cout <<endl;
}
    return 0;
}