#include <string.h>

#include <fstream>
#include <iostream>
using namespace std;

struct people {
  char name[50];
  int age;
  float weight;
  int height;
  long id;
};

int menu() {
  int opc;
  do {
    cout << "\n---MENU---\n";
    cout << "1) Ingresar persona\n";
    cout << "2) Editar datos persona\n";
    cout << "3) Mostrar todo\n";
    cout << "4) Consultar persona\n";
    cout << "5) Mostrar personas por encima del promedio de peso\n";
    cout << "6) Mostrar personas por debajo del promedio de peso\n";
    cout << "7) Mostrar persona con mayor peso\n";
    cout << "8) Mostrar persona con menor peso\n";
    cout << "0) Salir\n";
    cout << "Ingrese opcion: ";
    cin >> opc;
    if (cin.fail()) {
      cin.clear();
      cin.ignore(1000, '\n');
      opc = -1;
      cout << "Error: ingrese un número válido.\n";
    }
  } while (opc < 0 || opc > 8);
  return opc;
}

void ingresar(people& one) {
  static int count = 0;
  ofstream Archivobin("pesos.bin", ios::app | ios::binary);
  if (!Archivobin.is_open()) {
    cout << "Error al abrir archivo\n";
    return;
  }

  cin.ignore();
  do {
    cout << "Ingrese nombre: ";
    cin.getline(one.name, 50);
  } while (one.name[0] == '\0');

  do {
    cout << "Ingrese edad: ";
    cin >> one.age;
    cin.ignore();
  } while (one.age <= 0 || cin.fail());

  do {
    cout << "Ingrese peso: ";
    cin >> one.weight;
    cin.ignore();
  } while (one.weight <= 0 || cin.fail());

  do {
    cout << "Ingrese altura: ";
    cin >> one.height;
    cin.ignore();
  } while (one.height <= 0 || cin.fail());

  one.id = count;
  Archivobin.write(reinterpret_cast<char*>(&one), sizeof(people));
  Archivobin.close();
  cout << "Datos guardados correctamente.\n";
  count++;
}

void editar(people& one) {
  char buscar[50];
  cout << "Ingrese el nombre a buscar: ";
  cin.ignore();
  cin.getline(buscar, 50);

  fstream ArchivoBin("pesos.bin", ios::in | ios::out | ios::binary);
  if (!ArchivoBin.is_open()) {
    cout << "Error al abrir archivo\n";
    return;
  }

  people temp;
  bool encontrado = false;
  while (ArchivoBin.read(reinterpret_cast<char*>(&temp), sizeof(people))) {
    if (strcmp(temp.name, buscar) == 0) {
      encontrado = true;
      cout << "Persona encontrada. Ingrese nuevos datos:\n";
      cin.ignore();
      cout << "Ingrese nombre: ";
      cin.getline(temp.name, 50);
      cout << "Ingrese edad: ";
      cin >> temp.age;
      cout << "Ingrese peso: ";
      cin >> temp.weight;
      cout << "Ingrese altura: ";
      cin >> temp.height;
      ArchivoBin.seekp(-static_cast<int>(sizeof(people)), ios::cur);
      ArchivoBin.write(reinterpret_cast<char*>(&temp), sizeof(people));
      break;
    }
  }

  if (!encontrado) {
    cout << "No se encontró la persona\n";
  }
  ArchivoBin.close();
}

void Mostrar() {
  ifstream ArchivoBin("pesos.bin", ios::binary);
  if (!ArchivoBin.is_open()) {
    cout << "Error al abrir archivo\n";
    return;
  }

  people temp;
  cout << "---Lista de personas---\n";
  while (ArchivoBin.read(reinterpret_cast<char*>(&temp), sizeof(people))) {
    cout << "Nombre: " << temp.name << "\nEdad: " << temp.age
         << "\nPeso: " << temp.weight << "\nAltura: " << temp.height
         << "\nId: " << temp.id << "\n------------------------------\n";
  }
  ArchivoBin.close();
}

void Consultar() {
  cin.ignore();
  char buscar[50];
  cout << "Ingrese nombre a consultar: ";
  cin.getline(buscar, 50);

  ifstream Archivobin("pesos.bin", ios::binary);
  if (!Archivobin.is_open()) {
    cout << "Error al abrir archivo\n";
    return;
  }

  people temp;
  bool encontrado = false;
  while (Archivobin.read(reinterpret_cast<char*>(&temp), sizeof(people))) {
    if (strcmp(buscar, temp.name) == 0) {
      encontrado = true;
      cout << "---Datos de " << temp.name << "---\n";
      cout << "Edad: " << temp.age << "\nPeso: " << temp.weight
           << "\nAltura: " << temp.height << "\nId: " << temp.id
           << "\n------------------------------\n";
      break;
    }
  }

  if (!encontrado) {
    cout << "No se encontró la persona.\n";
  }
  Archivobin.close();
}

void MostrarPorEncimaDelPromedio() {
  ifstream ArchivoBin("pesos.bin", ios::binary);
  if (!ArchivoBin.is_open()) {
    cout << "Error al abrir archivo\n";
    return;
  }

  people temp;
  int count = 0;
  float suma = 0;
  while (ArchivoBin.read(reinterpret_cast<char*>(&temp), sizeof(people))) {
    suma += temp.weight;
    count++;
  }

  if (count == 0) {
    cout << "No hay personas registradas.\n";
    ArchivoBin.close();
    return;
  }

  float promedio = suma / count;
  cout << "Promedio de peso: " << promedio << endl;
  ArchivoBin.clear();
  ArchivoBin.seekg(0, ios::beg);

  cout << "---Personas por encima del promedio---\n";
  while (ArchivoBin.read(reinterpret_cast<char*>(&temp), sizeof(people))) {
    if (temp.weight > promedio) {
      cout << "Nombre: " << temp.name << "\nPeso: " << temp.weight
           << "\n------------------------------\n";
    }
  }
  ArchivoBin.close();
}

void MostrarPorDebajoDelPromedio() {
  ifstream ArchivoBin("pesos.bin", ios::binary);
  if (!ArchivoBin.is_open()) {
    cout << "Error al abrir archivo\n";
    return;
  }

  people temp;
  int count = 0;
  float suma = 0;
  while (ArchivoBin.read(reinterpret_cast<char*>(&temp), sizeof(people))) {
    suma += temp.weight;
    count++;
  }

  if (count == 0) {
    cout << "No hay personas registradas.\n";
    ArchivoBin.close();
    return;
  }

  float promedio = suma / count;
  cout << "Promedio de peso: " << promedio << endl;
  ArchivoBin.clear();
  ArchivoBin.seekg(0, ios::beg);

  cout << "---Personas por debajo del promedio---\n";
  while (ArchivoBin.read(reinterpret_cast<char*>(&temp), sizeof(people))) {
    if (temp.weight < promedio) {
      cout << "Nombre: " << temp.name << "\nPeso: " << temp.weight
           << "\n------------------------------\n";
    }
  }
  ArchivoBin.close();
}

void MostrarMayorPeso() {
  ifstream ArchivoBin("pesos.bin", ios::binary);
  if (!ArchivoBin.is_open()) {
    cout << "Error al abrir archivo\n";
    return;
  }

  people temp, mayor;
  bool primero = true;
  while (ArchivoBin.read(reinterpret_cast<char*>(&temp), sizeof(people))) {
    if (primero || temp.weight > mayor.weight) {
      mayor = temp;
      primero = false;
    }
  }

  if (primero) {
    cout << "No hay personas registradas.\n";
  } else {
    cout << "---Persona con mayor peso---\n";
    cout << "Nombre: " << mayor.name << "\nPeso: " << mayor.weight
         << "\n------------------------------\n";
  }

  ArchivoBin.close();
}

void MostrarMenorPeso() {
  ifstream ArchivoBin("pesos.bin", ios::binary);
  if (!ArchivoBin.is_open()) {
    cout << "Error al abrir archivo\n";
    return;
  }

  people temp, menor;
  bool primero = true;
  while (ArchivoBin.read(reinterpret_cast<char*>(&temp), sizeof(people))) {
    if (primero || temp.weight < menor.weight) {
      menor = temp;
      primero = false;
    }
  }

  if (primero) {
    cout << "No hay personas registradas.\n";
  } else {
    cout << "---Persona con menor peso---\n";
    cout << "Nombre: " << menor.name << "\nPeso: " << menor.weight
         << "\n------------------------------\n";
  }

  ArchivoBin.close();
}

int main() {
  people one;
  int opc;
  do {
    opc = menu();
    switch (opc) {
      case 1:
        ingresar(one);
        break;
      case 2:
        editar(one);
        break;
      case 3:
        Mostrar();
        break;
      case 4:
        Consultar();
        break;
      case 5:
        MostrarPorEncimaDelPromedio();
        break;
      case 6:
        MostrarPorDebajoDelPromedio();
        break;
      case 7:
        MostrarMayorPeso();
        break;
      case 8:
        MostrarMenorPeso();
        break;
    }
  } while (opc != 0);

  return 0;
}
