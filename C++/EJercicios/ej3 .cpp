#include <iostream>
using namespace std;
int main ()
{   int n;
    double centenas;
    double decenas;       
    double unidades;   

    cout << "ingrese un numero: ";
    cin >> n;

    if (n <=1000 && n >0)
    {
      centenas= n/100;
      decenas= (n%100)/10;
      unidades=n%10;
      cout <<n<<"descompuesto en centenas, decenas y unidades es: "<<centenas<<" centenas, "<<decenas<<" decenas y "<<unidades<<" unidades"<<endl;
    }
    return 0;
}