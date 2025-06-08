#include <iostream> //libreria estandar 
#include <windows.h> // Para usar SetConsoleOutputCP y forzar UTF-8 en la terminal
#include <string>   // Para usar string y empty
#include <cstdlib>  //para usar system("cls") y limpiar pantalla y system("pause") para pausar la //ejecucion del programa 
#include <iomanip>  // Para usar setprecision
#include <clocale>  //para usar setlocale y poder usar acentos y otros caracteres
#include <cmath>
  
int main(){
    //no se usa using namespace std; por que es una mala practica y puede causar conflictos de nombres
    //en proyectos grandes, en este caso no es necesario pero es mejor no usarlo
    
    using std::cout;// Para usar cout <<
    using std::cin;// Para usar cin >>
    using std::string;// Para usar string 
    using std::endl;// Para usar endl 
    using std::fixed;// Para usar fixed
    using std::setprecision;// Para usar setprecision (numero de decimales)
    using std::getline;// Para usar getline 

 int n ;
cout <<"ingrese el numero:"<<endl;
cin>> n;
while (n<1 or cin.fail()){
    cout <<"ingrese el numero:";
    cin >> n;
}
   
    for (int fila = 1; fila <= n; fila++) {
        // Espacios para centrar
        for (int espacio = 1; espacio <= n - fila; espacio++) {
            cout << " ";
        }

        // Números ascendentes
        for (int asc = 1; asc <= fila; asc++) {
            cout << asc;
        }

        // Números descendentes
        for (int desc = fila - 1; desc >= 1; desc--) {
            cout << desc;
        }

        // Nueva línea
        cout << endl;
    }
    return 0;
}

    