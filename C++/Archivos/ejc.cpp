#include <fstream>
#include <iostream>
#include <string.h>
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
    cout << "1)Ingresar persona :\n";
    cout << "2)Editar datos persona :\n";
    cout << "3)Mosatrar todo \n";
    cout << "4)Consultar :\n";
    cout << "0)Salir:\n";
    cout << "Ingrese opcion :";
    cin >> opc;
    if (cin.fail()) {
      cin.clear();            // limpiar error
      cin.ignore(1000, '\n'); // limpiar buffer
      opc = -1;               // fuerza repetir
      cout << "Error: ingrese un número válido.\n";
    }
  } while (opc < 0 || opc > 4);
  return opc;
}
void ingresar(people &one) {
  static int count = 0;
  ofstream Archivobin("pesos.bin", ios::app);
  if (!Archivobin.is_open()) {
    cout << "error al abrir ";
    return;
  }

  do {
    cin.ignore();
    cout << "ingrese nombre :";
    cin.getline(one.name, 50);

    if (cin.fail()) {

      cin.clear();
      cin.ignore();

      cout << "nombre invalido pls ingrese nombre :";
      cin.getline(one.name, 50);
    }
  } while (cin.fail() || one.name[0] == '\0');

  do {
    cout << "ingrese edad:";
    cin >> one.age;
    cin.ignore();

  } while (one.age <= 0 or cin.fail());

  do {

    cout << "ingrese el peso:";
    cin >> one.weight;

    if (cin.fail()) {
      cin.clear();
      cin.ignore();
    }

  } while (one.weight <= 0 or cin.fail());

  do {
    cout << "ingrese altura:";
    cin >> one.height;

    if (cin.fail()) {
      cin.clear();
      cin.ignore();
    }
  } while (one.height <= 0 or cin.fail());
  one.id = count;

  Archivobin.write(reinterpret_cast<char *>(&one), sizeof(people));

  Archivobin.close();
  cout << "Datos Guradados";

  count++;
  /*
  Archivobin<<"Persona #"<<count<<"\n";
  Archivobin<<"Nombre :"<<one.name<<"\n";
  Archivobin<<"Edad :"<<one.age<<"\n";
  Archivobin<<"Altura :"<<one.height<<"\n";
  Archivobin<<"Peso :"<<one.weight<<"\n";
  */
}

void editar(people &one) {

  char buscar[50];
  cout << "Ingrese el nombre a buscar :";
  cin.ignore();
  cin.getline(buscar, 50);

  fstream ArchivoBin("pesos.bin", ios::in | ios::out | ios::binary);
  if (!ArchivoBin.is_open()) {
    cout << "Error al abrir el archivo\n";
    return;
  }

  people temp;

  bool encontrado = false;
  while (ArchivoBin.read(reinterpret_cast<char *>(&temp), sizeof(people))) {

    if (strcmp(temp.name, buscar) == 0) {
      encontrado = true;
      cout << "Persona encontrada , ingrese nuevos datos \n";

      cout << "ingrese nombre :";
      cin.getline(temp.name, 50);

      cout << "ingrese edad:";
      cin >> temp.age;
      cin.ignore();

      cout << "ingrese el peso:";
      cin >> temp.weight;

      cout << "ingrese altura:";
      cin >> temp.height;
      ArchivoBin.seekp(-static_cast<int>(sizeof(people)),
                       ios::cur); // mover el puntero de escritura al inicio del
                                  // registro actual
      ArchivoBin.write(
          reinterpret_cast<char *>(&temp),
          sizeof(people)); // sobrescribir el registro con los nuevos datos
      break;
    }
  }
  if (!encontrado) {
    cout << "No se encontro la persona \n";
    return;
  }
  ArchivoBin.close();
}
void Mostrar() {

  ifstream ArchivoBin("pesos.bin", ios::binary);
  people temp;
  cout << "---Pesos/Personas---" << endl;
  while (ArchivoBin.read(reinterpret_cast<char *>(&temp), sizeof(people))) {
    cout << "Nombre :" << temp.name << endl;
    cout << "Edad :" << temp.age << endl;
    cout << "Peso :" << temp.weight << endl;
    cout << "Altura :" << temp.height << endl;
    cout << "Id :" << temp.id << endl;
    cout << "------------------------------\n";
  }
  cout << "--------------Fin--------------";
}
void Consultar() {
  cin.ignore(); // limpiar el buffer antes de getline por q sino crashea
  char buscar[50];
  do {

    cout << "Buscar :";
    cin.getline(buscar, 50);

    if (cin.fail()) {
      cin.clear();
      cin.ignore();
    }
  } while (cin.fail());

  ifstream Archivobin("pesos.bin", ios::binary);
  people temp;
  bool encontrado = false;
  while (Archivobin.read(reinterpret_cast<char *>(&temp), sizeof(people))) {
    if (strcmp(buscar, temp.name) == 0) { // si se encuentra el nombre
      encontrado = true;
      cout << " el cv de ";
      cout << temp.name << endl;
      cout << "Edad :" << temp.age << endl;
      cout << "Peso :" << temp.weight << endl;
      cout << "Altura :" << temp.height << endl;
      cout << "Id :" << temp.id << endl;
      cout << "------------------------------\n";
      break; // salir del bucle una vez encontrado
    }
  }
  if (!encontrado) {
    cout << " asi no se llama nadie ....";
  }
  Archivobin.close(); // cerrar el archivo
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
    }
  } while (opc != 0);

  return 0;
}