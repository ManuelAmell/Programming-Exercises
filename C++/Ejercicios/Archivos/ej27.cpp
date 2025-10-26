#include <iostream>
using namespace std;
int main(){
    float kilos,diferencia=0,d1;
    cout <<"ingrese la cantidad de kilos";
    cin >>kilos;

    if (kilos<=10)
    { 
        cout <<"el precio es de 98";

        cout <<"totalal a pagar es de "<<kilos*98;
    }
    else
    {
        diferencia=kilos-10;
        cout <<"total a pagar es de diferencia despues de 10 kilos "<<diferencia*138<<endl;
       
        cout <<"total a pagar es de "<<(980)+((kilos-10)*138);

    }
    return 0;
}