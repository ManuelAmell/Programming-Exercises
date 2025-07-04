#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int x,y;
    cout << "ingrese la longitud x (filas):";
    cin >> y;

    cout << "ingrese la longitud y (columnas):";
    cin >> x;
    int matriz[y][x];

    for (int i=0; i < y ;i++){
        for (int j=0; j < x;j++){
            cout << "fila :"<<i+1<<"  columna :  "<<j+1<<"   :";
            cin >>matriz[i][j];
        }
    }
        system("cls");

        for (int i=0; i < y ;i++){
        for (int j=0; j < x;j++){
                cout <<"[ "<<setw(2)<<matriz[i][j]<<setw(2)<<" ]";
            }
            cout << endl;
             cout << endl;
        }
        cout << "\n\n\n";

 for (int i=0; i < x ;i++){
        for (int j=0; j < y;j++){
                cout << "[ "<<setw(2)<<matriz[j][i]<<setw(2)<<" ]";
            }
            cout << endl;
            cout << endl;
        }

        
    return 0;
}