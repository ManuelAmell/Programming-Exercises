#include <iostream>
using namespace std;
int main (){
    int pma,pme,may,men,n;
    cout << "ingrese el tamaño del vector :";
    cin >> n;
    int arr[n];
    for (int i=0;i < n;i++){
        cout << "ingrese un numero para la posicion # "<<i+1<<" :";
        cin >>arr[i];
    }
    men=may=arr[0];
    pma=pme=0;
    for (int i=0;i < n;i++){
        if (arr[i]>may){
            may =arr[i];
        pma=i+1;
        }
        if (arr[i]<men){
            men =arr[i];
            pme=i+1;
        }
        cout << arr[i]<< "  ";
    }
    cout <<endl;
    cout << "el numero mayor del arreglo es :"<<may<<" y esta en la posicion #"<<pma<<endl;
    cout << "el numero menor de el arreglo es "<<men<<" y esta en la posicion #"<<pme<<endl;
    return 0;
}