#include <fstream>
#include <iostream>

using namespace std;

struct Datos {
  int numero;
  double decimal;
};

int main() {
  // Escritura en archivo binario
  ofstream archivoBinario("datos.bin", ios::binary);

  if (archivoBinario.is_open()) {
    Datos datos = {42, 3.14};

    // Escribir la estructura completa
    archivoBinario.write(reinterpret_cast<char *>(&datos), sizeof(Datos));

    archivoBinario.close();
    cout << "Escritura en binario completada." << endl;
  } else {
    cerr << "No se pudo abrir el archivo." << endl;
    return 1;
  }

  // Lectura desde archivo binario
  ifstream lectorBinario("datos.bin", ios::binary);

  if (lectorBinario.is_open()) {
    Datos datosLeidos;

    lectorBinario.seekg(0); // Volver al principio del archivo

    // Leer los bytes en la estructura correspondiente
    lectorBinario.read(reinterpret_cast<char *>(&datosLeidos), sizeof(Datos));

    cout << "Lectura de binario: ";
    cout << datosLeidos.numero << ", ";
    cout << datosLeidos.decimal << endl;

    lectorBinario.close();
  } else {
    cerr << "Error al abrir el archivo para lectura." << endl;
    return 1;
  }

  return 0;
}
