#include <iostream>
#include <string>
#include <string.h> // Para usar string y to_string
#include <windows.h> // Para usar SetConsoleOutputCP y forzar UTF-8
#include <iomanip> // Para usar setprecision y fixed
#include <clocale>  // Para usar setlocale y poder usar acentos y otros caracteres
#include <cstdlib>// Para usar system("cls") y limpiar pantalla y system("pause") para pausar la
 
int main(){
using std :: cout ;
using std :: cin ;  
using std :: string ;
using std :: endl ;
using std :: fixed ;
using std :: setprecision ;
using std :: getline ;

SetConsoleOutputCP(65001); // Fuerza UTF-8 para imprimir ñ y tildes


 // Fuerza UTF-8 para imprimir ñ y tildes
int cedula[10];
string cedula2[10];
cout <<"Ingrese su cedula : ";

for(int i=0;i<10;i++)
{
    cin >> cedula[i];
    if (cedula[i] >= 0 || cedula[i] <= 9)
    {
        
       
        cedula2[i] = cedula[i] + '0'; // Convertir el número a su representación en letras
        // Convertir el número a su representación en letras
        cout << "Los números de la cedula en letras son: " << cedula2[i] << endl;
    
    
    }
    else
    {
        cout << "La cedula es correcta" << endl;
    }
}



    return 0;
}