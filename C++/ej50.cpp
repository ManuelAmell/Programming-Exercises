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
int r,r2,cn=0;
int d=0;
int mod;

for(int n=1;n<=1000;n++){
    cn=n;


r=n*n;
r2=n*n*n;


while (cn > 0){
    d++;
    cn/=10;
}
mod=pow(10,d);
if (r%mod==n && r2%mod==n){
    cout <<"es trimorfico y amorfico"<<n<<endl;
}
else if(r%mod==n)
{
    cout <<"es amorfico"<<n<<endl;
}
else if (r2%mod==n)
{
    cout <<"es trimorfico : "<<n<<endl;
}
d=0;
}
return 0;
}
