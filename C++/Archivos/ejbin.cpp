#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  // Crear y abrir un archivo en modo escritura
  ofstream archivoSalida("ejemplo.txt");

  // Verificar si el archivo se abrió correctamente
  if (!archivoSalida) {
    cerr << "Error al abrir el archivo para escritura." << endl;
    return 1;
  }

  // Escribir datos en el archivo
  archivoSalida << "Hola, este es un ejemplo de escritura en un archivo."<< endl;
  archivoSalida << "C++ es un lenguaje de programación poderoso." << endl;

  // Cerrar el archivo de salida
  archivoSalida.close();

  // Abrir el archivo en modo lectura
  ifstream archivoEntrada("ejemplo.txt");

  // Verificar si el archivo se abrió correctamente
  if (!archivoEntrada) {
    cerr << "Error al abrir el archivo para lectura." << endl;
    return 1;
  }

  // Leer y mostrar el contenido del archivo
  string linea;
  while (getline(archivoEntrada, linea)) {
    cout << linea << endl;
  }

  // Cerrar el archivo de entrada
  archivoEntrada.close();

  return 0;
}