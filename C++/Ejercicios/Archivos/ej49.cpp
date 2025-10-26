#include <iostream> //libreria estandar 
#include <windows.h> // Para usar SetConsoleOutputCP y forzar UTF-8 en la terminal
#include <string>   // Para usar string y empty
#include <cstdlib>  //para usar system("cls") y limpiar pantalla y system("pause") para pausar la //ejecucion del programa 
#include <iomanip>  // Para usar setprecision
#include <clocale>  //para usar setlocale y poder usar acentos y otros caracteres
int main(){
        using std::cout;// Para usar cout <<
        using std::cin;// Para usar cin >>
        using std::string;// Para usar string 
        using std::endl;// Para usar endl 
        using std::fixed;// Para usar fixed
        using std::setprecision;// Para usar setprecision (numero de decimales)
        using std::getline;// Para usar getline 
     int x,a=0,i=0,r=0;
    cout <<"ingrese el numero ";
    cin >>x;
    for (; 0 < x  ;i++){
        a= x % 10;
        r+=a;
        cout <<x<<endl;
        x/=10;
    }
    cout <<"suma de digitos:"<<r<<endl;
    cout <<"cantidad de digitos :"<<i;
    return 0;
}