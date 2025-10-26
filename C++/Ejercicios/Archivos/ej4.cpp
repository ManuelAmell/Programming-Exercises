#include <iostream>
using namespace std;

int main(){
    int horas, minutos, segundos;
    cout << "Ingrese la cantidad de segundos: ";
    cin >> segundos;    
    cout << "Ingrese la cantidad de minutos: ";
    cin >> minutos;
    cout << "Ingreese la cantidad de horas: ";
    cin >> horas;

        minutos=minutos+segundos/60;//para actualizar el valor de segundos a minutos
       
        segundos=segundos%60;//para actualizar el valor de segundos

        cout <<" cantidad de segundos "<< segundos << " segundos"<<endl;

        horas=horas+minutos/60;
        minutos%=60;
        
        cout <<" cantidad de minutos "<< minutos << " minutos"<<endl;
        cout <<" cantidad de horas "<< horas << " horas"<<endl;
return 0;
}