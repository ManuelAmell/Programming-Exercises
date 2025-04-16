#include <iostream>
#include <string>
using namespace std;    
int main (){
    string nombre;
    long long int salariobruto,salarioneto;
    long long int horas,sueldo_hora;
    long long int impuesto;
    long long int sss,factorexoneracion;

    cout << "Ingrese del trabajador nombre: ";
    cin >> nombre;
   
    cout << "Ingrese las horas trabajadas: ";
    cin >> horas;

    cout << "Ingrese el sueldo por hora: ";
    cin >> sueldo_hora;

    cout <<"ingrese factor de exoneracion: ";
    cin >> factorexoneracion;

    salariobruto=sueldo_hora*(1.5*(horas-400)+40);
    sss=salariobruto*0.06;
    impuesto=((salariobruto-580)*factorexoneracion)*0.2;
    salarioneto=salariobruto-sss-impuesto;

cout << "El salario bruto de "<<nombre<<" es: "<<salariobruto<<endl;
cout << "El salario neto de "<<nombre<<" es: "<<salarioneto<<endl;
cout << "El impuesto de "<<nombre<<" es: "<<impuesto<<endl;
cout << "El seguro social de "<<nombre<<" es: "<<sss<<endl;
    return 0;
}