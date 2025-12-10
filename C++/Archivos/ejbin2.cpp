#include <fstream>
#include <iostream>
#include <cstring>
#include <limits>
using namespace std;

struct Registro {
  char nombre[50];
  char direccion[80];
  long telefono;
  int id;
  float salario;
  ///////////////
  long numeroprestamo;
  char fecha[20];
  long valor;
  float interes;
  int numerocuotas;
  long valorcuotas;
};

int menu(int opc) {
  do {
    cout << "Menu de opciones:" << endl;
    cout << "1. Agregar clientes" << endl;
    cout << "2. Registro de prestamos" << endl;
    cout << "3. Consultas por id " << endl;
    cout << "4. Consultar un cliente" << endl;
    cout << "5. Reporte de prestatmos" << endl;
    cout << "6. Salir" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opc;

  } while (opc < 1 || opc > 6);
  return opc;
}

void registro(Registro &reg1) {
  static int contador = 1;

  ofstream archivoBinario("clientes.bin", ios::binary | ios::app);
  if (!archivoBinario) {
    cout << "No se pudo abrir el archivo.\n";
    return;
  }
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  cout << "ingrese el nombre del cliente :";
  cin.getline(reg1.nombre, 50);

  cout << "ingrese la direccion del cliente :";
  cin.getline(reg1.direccion, 80);

  cout << "ingrese el telefono del cliente :";
  cin >> reg1.telefono;

  reg1.id = contador;

  cout << "ingrese el salario del cliente :";
  cin >> reg1.salario;

  archivoBinario.write(reinterpret_cast<char *>(&reg1), sizeof(Registro));

  archivoBinario.close();
  contador++;
}
void Rprestamos(Registro &reg1) {
  ofstream archivoBinario("clientes.bin", ios::binary | ios::app);
  if (!archivoBinario) {
    cout << "No se pudo abrir el archivo.\n";
    return;
  }

  cout << "valor del prestamo :";
  cin >> reg1.valor;

  while (reg1.valor < 1) {
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "valor del prestamo :";
    cin >> reg1.valor;
  }

  if (reg1.valor <= 2000000) {
    reg1.interes = reg1.valor * 0.12;
    reg1.numerocuotas = 1;
    reg1.valorcuotas = reg1.interes + reg1.valor;
  }

  else if (reg1.valor > 2000000 && reg1.valor <= 5000000) {
    reg1.interes = reg1.valor * 0.1;
    reg1.numerocuotas = 3;
    reg1.valorcuotas = (reg1.interes + reg1.valor) / 3;
  }

  archivoBinario.write(reinterpret_cast<char *>(&reg1), sizeof(Registro));
  archivoBinario.close();
}
void Consultas(int subid) {
  ifstream ArchivoBinario("clientes.bin", ios::binary);
  if (!ArchivoBinario) {
    cout << "No se pudo abrir el archivo.\n";
    return;
  }
  Registro temp; // para leer
  bool encontrado = false;

  while (
      ArchivoBinario.read(reinterpret_cast<char *>(&temp), sizeof(Registro))) {
    if (temp.id == subid) {
      encontrado = true;
      cout << "=== Cliente encontrado ===\n";
      cout << "Nombre: " << temp.nombre << endl;
      cout << "Direccion: " << temp.direccion << endl;
      cout << "Telefono: " << temp.telefono << endl;
      cout << "ID: " << temp.id << endl;
      cout << "Salario: " << temp.salario << endl;

      cout << "\n--- Prestamos ---\n";
      cout << "Valor prestamo: " << temp.valor << endl;
      cout << "Interes: " << temp.interes << endl;
      cout << "Cuotas: " << temp.numerocuotas << endl;
      cout << "Valor cuotas: " << temp.valorcuotas << endl;
      break;
    }
  }
  ArchivoBinario.close();
  if (!encontrado) {
    cout << "no esta en el archivo" << endl;
  }
}
void ConsultasN(char name[50]) {
  ifstream ArchivoBinario("clientes.bin", ios::binary);
  if (!ArchivoBinario) {
    cout << " no existe :";
    return;
  } else {
    Registro temp;
    bool encontrado = false;
    while (ArchivoBinario.read(reinterpret_cast<char *>(&temp), sizeof(Registro))) {
      if (strcmp(temp.nombre, name) == 0) {// comparar strings tipo char[]
        encontrado=true;

      cout << "=== Cliente encontrado ===\n";
      cout << "Nombre: " << temp.nombre << endl;
      cout << "Direccion: " << temp.direccion << endl;
      cout << "Telefono: " << temp.telefono << endl;
      cout << "ID: " << temp.id << endl;
      cout << "Salario: " << temp.salario << endl;

      cout << "\n--- Prestamos ---\n";
      cout << "Valor prestamo: " << temp.valor << endl;
      cout << "Interes: " << temp.interes << endl;
      cout << "Cuotas: " << temp.numerocuotas << endl;
      cout << "Valor cuotas: " << temp.valorcuotas << endl;
      return;
      }

    } 
    if (!encontrado){
      cout << "no encontrado ";
      return;
    }
  }

}
void Reportes(){

  ifstream ArchivoBinario("clientes.bin",ios::in|ios::binary);
  Registro temp;
  cout << "=== LISTA DE CLIENTES ===\n";
  while(ArchivoBinario.read(reinterpret_cast<char *>(&temp),sizeof(Registro))){

      cout << "Nombre: " << temp.nombre << endl;
      cout << "Direccion: " << temp.direccion << endl;
      cout << "Telefono: " << temp.telefono << endl;
      cout << "ID: " << temp.id << endl;
      cout << "Salario: " << temp.salario << endl;

      cout << "\n--- Prestamos ---\n";

      cout << "Valor prestamo: " << temp.valor << endl;
      cout << "Interes: " << temp.interes << endl;
      cout << "Cuotas: " << temp.numerocuotas << endl;
      cout << "Valor cuotas: " << temp.valorcuotas << endl;
      cout << "-----------------------\n";
  }
  ArchivoBinario.close();
}
int main() {
  // Crear algunos registros y escribirlos en el archivo
  Registro reg1 = {0};

  int opc;

  do {
    opc = menu(opc);
    switch (opc) {

    case 1:
      registro(reg1);
      break;

    case 2:
      Rprestamos(reg1);
      break;

    case 3:
      long subid;
      cout << "Ingrese el ID :";
      cin >> subid;
      Consultas(subid);
      break;

    case 4:
      char amell[50];
      cout << "ingrese el nombre :";
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      cin.getline(amell, 50);
      ConsultasN(amell);
      break;
    case 5:
    Reportes();
    break;
    
    default:
    cout << "opcion invalida...";
  }

  } while (opc != 6);
  return 0;
}