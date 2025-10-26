#include <iostream>
#include <string>   
#include <windows.h> // Para usar SetConsoleOutputCP y forzar UTF-8
#include <iomanip> // Para usar setprecision y fixed
#include <clocale>  // Para usar setlocale y poder usar acentos y otros caracteres
#include <cstdlib>// Para usar system("cls") y limpiar pantalla y system("pause") para pausar la

int main(){

using std::cout;
using std ::cin;
using std::string;
using std::endl;
using std::fixed;
using std::getline;
using std::setprecision;

float p1,p2,p3;
float total;
string nombre;

SetConsoleOutputCP(65001); // Para que se vean ñ y tildes
setlocale(LC_ALL, "Spanish"); // Para usar acentos y caracteres especiales


cout << "Ingrese su nombre: ";
getline(cin,nombre);
cout <<"ingrese su primer nota :";
cin >> p1;
cout <<"ingrese su segunda nota :";
cin >> p2;
cout <<"ingrese su tercer nota :";
cin >> p3;
if (p1 < 0 || p1 > 5 || p2 < 0 || p2 > 5 || p3 < 0 || p3 > 5) {
    cout << "Las notas deben estar entre 0 y 5." << endl;
    return 1;
}
total = (p1 + p2 + p3) / 3;
system("cls"); // Limpiar pantalla
cout << "su nombre es: " << nombre << endl;
cout << "su promedio es: " << fixed << setprecision(2) << total << endl;
if (total >= 3.0){
    cout << "usted aprobo" << endl;
}
else{
    cout << "usted no aprobo" << endl;
}
    return 0;
}