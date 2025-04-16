#include <iostream>
#include <clocale>  // Para usar setlocale y poder usar acentos y otros caracteres
#include <cstdlib>// Para usar system("cls") y limpiar pantalla y system("pause") para pausar la
#include <ctime>// Para usar time y localtime
#include <windows.h>
#include <fstream>// Para usar ofstream
#include <string>// Para usar string y empty
#include <iomanip>// Para usar setprecision y fixed
#include <ctime>    // para time()

 int main(){
    using std::cout;// Para usar cout <<
    using std::cin;// Para usar cin >>  
    using std::string;// Para usar string
    using std::endl;// Para usar endl
    using std::fixed;// Para usar fixed 
    using std::setprecision;// Para usar setprecision (numero de decimales)
    using std::getline;// Para usar getline
    SetConsoleOutputCP(65001); // Fuerza UTF-8 para imprimir ñ y tildes
    
      setlocale(LC_ALL, "Spanish"); // Para usar acentos y caracteres especiales
      srand(time(NULL));
      // Definicion de variables
      int j1=rand()% 6 +1, j2=rand() % 6+1;

      

      cout << "Bienvenido al juego de dados jugador 1" << endl;
      cout <<endl;
      cout << "Tira el dado" << endl; 
      cout <<endl;
      cout << "El resultado es: " << j1 << endl;
      cout <<"bienvenido al juego de dados jugador 2" << endl;
      cout <<endl;
      cout << "Tira el dado" << endl;
      cout <<endl;
      cout << "El resultado es: " << j2 << endl;

 if (j1==j2){
cout << "empate;" << endl;
 }
 else

 if (j1 >j2){
  cout << "El jugador 1 gana" << endl;
 }   
else
  if (j1 < j2){
    cout << "El jugador 2 gana" << endl;
 }
}