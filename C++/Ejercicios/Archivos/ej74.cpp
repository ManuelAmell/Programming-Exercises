#include <iostream>//matrices
using namespace std;
int main(){int matriz [2][3];int sumatoria=0;

for (int f=0; f < 2 ; f++){
    //siempre el primer ciclo es filas
    for (int c=0; c < 3 ; c++){
        //el segundo ciclo siempre va a ser el de las columnas         
        cout <<"ingrese el numero para la posicion ("<<f<<") , "<<"("<<c<<") = ";
        cin >> matriz [f][c];

        sumatoria += matriz[f][c];
    }
    cout << endl;
}
for (int f=0;f < 2 ;f++){
    for (int c=0;c < 3;c++){
        cout << " ["<<matriz [f][c]<<"]";
    }
    cout << endl;
}
cout << endl<<endl<<endl;

    return 0;
}