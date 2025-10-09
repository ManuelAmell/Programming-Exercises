#include <iostream>
#include <clocale>//para usar setlocale y poder usar acentos y otros caracteres

using namespace std;

int main(){ 
    setlocale(LC_ALL,"Spanish");

    float c,re,r,f,k;
    cout << "ingrese la cantidad de grados celsius";
    cin>>c;

    re=c*0.8;
    r=(c+273.15)*1.8;
    f=(c*1.8)+32;
    k=c+273.15;

cout <<"grados centigrados a kelvin:"<<k<<"°"<<endl;
cout <<"grados centigrados a Rankine:"<<r<<"°"<<endl;
cout <<"grados centigrados a remaur :"<<re<<"°"<<endl;
cout <<"grados centigrados a fahrenheit :"<<f<<"°"<<endl;
 
    return 0;
}