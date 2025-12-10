#include <cstdlib>
#include <fstream>   //flujos de archivos
#include <iomanip>   //manipuladores de flujo
#include <iostream>  //exit system
#include <string>    //cadenas de texto
using namespace std;
void imprimirMensaje(int& cuenta1, string& nombre1, double& saldo1) {
  cout << cuenta1 << setw(10) << nombre1 << setw(10) << saldo1 << endl;
}
int main() {
  ofstream archivo("basic.txt");

  if (!archivo) {
    cout << "Error al crear el archivo";
    return (0);
  }
  cout << "ingrse nombre numero de cuenta y saldo" << endl;
  string nombre;
  int numeroCuenta;
  double saldo;

  while (cin >> nombre >> numeroCuenta >>
         saldo) {  // como funciona el while : lee hasta que no haya mas datos

    archivo << "Nombre: " << nombre;
    archivo << "Cuenta: " << numeroCuenta;
    archivo << "Saldo: " << saldo;

  }  // para cerrar archivo ctrl + z en windows o ctrl + d en linux

  archivo.close();
  ifstream leerArchivo("basic.txt", ios::in);  // para modo lectura
  if (!leerArchivo) {
    cout << "error al abrir el archivo";
    return (0);
  }
  cout << "Contenido del archivo: " << endl;

  string nombre1;
  int numeroCuenta1;
  double saldo1;
  cout << left << setw(10) << "Cuenta" << setw(10) << "Nombre" << setw(10)
       << "Saldo" << endl
       << fixed << showpoint;  // showpoint para mostrar los decimales

  while (leerArchivo >> numeroCuenta1 >> nombre1 >>
         saldo1) {  // lee linea por linea
    imprimirMensaje(numeroCuenta1, nombre1, saldo1);
  }

  leerArchivo.close();

  return 0;
}