#include <iostream>
using namespace std;        
int main() {                // Función principal
long donacion;
double administracion,sistemas,contabilidad;
cout << "Introduzca la cantidad de la donación: ";
cin >> donacion;      

administracion  = donacion * 0.3;
sistemas=administracion*0.15;
administracion=administracion-sistemas;
contabilidad=donacion*0.7;

cout <<"donacion total: "<<donacion<<endl;
cout <<"administracion: "<<administracion<<endl;
cout <<"sistemas: "<<sistemas<<endl;
cout <<"contabilidad: "<<contabilidad<<endl;
    
return 0;
// Entrada de datos

}