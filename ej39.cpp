#include <iostream>
using namespace std;
int main(){

    int ingreso;
    long double t=0;
    int i;
    
    for (i=0;i < 12;i++)
    {
    cout <<"ingrese la cantidad para el mes  "<<i+1<<"\n";
    cin >>ingreso;
        t+=ingreso;
    }
    cout <<"el promedio de agua gastada en el año fue :"<<t/i;
    
    return 0;
}