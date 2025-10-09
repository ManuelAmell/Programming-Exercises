#include <iostream>
using namespace std;
int main(){
    
    int compra;
    long npiesas,precio;

    cout <<"ingrese el numero de piezas:";
    cin >>npiesas;  
    cout <<"ingrese el precio de las piezas:";
    cin >>precio;

    cout <<"el total de la compra es de: $"<<npiesas*precio<<endl;
    
    compra=npiesas*precio;

    if (compra>500000)
    {
        cout <<"plata empresa  55%: $"<<compra*0.55<<endl;
        cout <<"plata banco 30%: $"<<compra*0.30<<endl;
        cout <<"plata credito fabricante 15%: $"<<compra*0.15<<endl;
        cout <<"intereses del fabicante 20%: $"<<(compra*0.15)*0.20<<endl;
        cout <<"intereses del fabicante 20% mas interes: $"<<((compra*0.15)*0.20)+compra*0.15<<endl;
        cout <<"total a pagar es de: $"<<compra+((compra*0.15)*0.20);
        cout <<"total a pagar es de: $ "<<compra;
    }
    else
    {
        cout <<"plata empresa 70%: $"<<compra*0.70<<endl;
        cout <<"plata credito fabricante 30%: $"<<compra*0.30<<endl;
        cout <<"intereses del fabicante 20%: $"<<(compra*0.30)*0.20<<endl;
        cout <<"pago total al fabicante 20% mas interes: $"<<((compra*0.30)*0.20)+compra*0.30<<endl;
        cout <<"total a pagar es de : $"<<compra+((compra*0.30)*0.20);
    } 
    return 0;
}