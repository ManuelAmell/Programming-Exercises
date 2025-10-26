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
    //circulo
while (n<1 or cin.fail()){
    cout <<"ingrese el numero:";
    cin >> n;
}
for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
        // Calcular la distancia al centro del círculo
        double distancia = sqrt(pow(i - n / 2.0, 2) + pow(j - n / 2.0, 2));
        if (distancia > n / 2.0 - 0.5 && distancia < n / 2.0 + 0.5) {
            cout << "*"; // Imprimir asterisco si está en el borde del círculo
        } else {
            cout << " "; // Imprimir espacio en blanco
        }
    }
    cout << endl; // Nueva línea después de cada fila
}
return 0;
}