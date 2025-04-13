#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
int main() {

    long  comision, totalventas,autos,comisionautos,salario;
    string nombre;

    cout<<"Ingrese el nombre del vendedor: ";
    cin>>nombre;

    cout << "Ingrese el salario base: ";
    cin >> salario;

    cout << "Ingrese el total de ventas: ";
    cin >> totalventas;
    cout << "Ingrese el numero de autos vendidos: ";    
    cin >> autos;

    comisionautos = (300000*autos)+(0.075*totalventas);
 
    cout << "Nombre del vendedor: " << nombre << endl;
    cout << "Salario base: " << salario << endl;
    cout << "Comision por autos vendidos: " << comisionautos << endl;
    cout << "Total a pagar: " << salario + comisionautos << endl;
    
 return 0;
}
