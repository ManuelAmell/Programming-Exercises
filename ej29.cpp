#include <iostream>
#include <string>
using namespace std;
int main (){

    string nombre;
    long double sueldo,aumento=0;
    int categoria;

    cout <<"ingrese el nombre del empleado: ";
    getline(cin,nombre);
    
    cout <<"\n\n\n";

    if (nombre.empty())
    {
        cout <<"nombre no valido"<<endl;
        return 0;
    }

    cout <<"ingrese el sueldo del empleado: $";
    cin >>sueldo;

    cout <<"categoria del empleado: 1-4"<<endl;
    cout <<"\n1. categoria : 15%\n2. categoria  : 10%\n3. categoria : 8% \n4. categoria  : 7%"<<endl;
     
    cout <<"ingrese la categoria del empleado: ";
    cin >>categoria;

    switch (categoria)
    {
    case 1:
    {
        aumento=1.15; 
        break;
    } 
    case 2:
    {
        aumento=1.10;
        break;
    }
    case 3:
    {
        aumento=1.08;
        break;
    }
    case 4:
    {
        aumento=1.07;
        break;
    }
    default:
    {
        cout <<"categoria no valida"<<endl;
        break;
    }
    }
        cout <<"\n\n\n";
     cout <<"el nombre del empleado es :" <<nombre<<endl;
     cout <<"el aumento es de: $"<<sueldo*aumento-sueldo<<endl;
     cout <<"el sueldo total es de: $"<<aumento*sueldo<<endl;

    return 0;
}