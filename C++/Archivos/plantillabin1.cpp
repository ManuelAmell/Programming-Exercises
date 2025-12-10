// =============================================================
//   PLANTILLA COMPLETA PARA MANEJO DE ARCHIVOS BINARIOS EN C++
//   CRUD + utilidades (crear, agregar, mostrar, buscar, editar,
//   eliminar, copiar, limpiar, contar, etc.)
//   TODO COMENTADO DE FORMA CLARA
// =============================================================

#include <cstring> // Para strncpy
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// -------------------------------------------------------------
// ESTRUCTURA DEL REGISTRO (se guarda TAL CUAL en el archivo .bin)
// -------------------------------------------------------------
struct Persona {
  char nombre[50]; // Se usa char[] para guardar binario fijo
  int edad;        // Tipos primitivos se guardan directo
};

// -------------------------------------------------------------
// PROTOTIPOS
// -------------------------------------------------------------
void crearArchivo();
void agregarRegistro();
void mostrarRegistros();
void buscarRegistro();
void editarRegistro();
void eliminarRegistro();
void copiarArchivo();
void limpiarArchivo();
void contarRegistros();

// Archivo principal
const char *ARCHIVO = "personas.bin";

int main() {
  int opcion;

  do {
    cout << "\n===== MENU BINARIO =====\n";
    cout << "1. Crear archivo binario\n";
    cout << "2. Agregar registro\n";
    cout << "3. Mostrar registros\n";
    cout << "4. Buscar registro\n";
    cout << "5. Editar registro\n";
    cout << "6. Eliminar registro\n";
    cout << "7. Contar registros\n";
    cout << "8. Copiar archivo\n";
    cout << "9. Limpiar archivo\n";
    cout << "0. Salir\n> ";
    cin >> opcion;
    cin.ignore(); // Limpia buffer

    switch (opcion) {
    case 1:
      crearArchivo();
      break;
    case 2:
      agregarRegistro();
      break;
    case 3:
      mostrarRegistros();
      break;
    case 4:
      buscarRegistro();
      break;
    case 5:
      editarRegistro();
      break;
    case 6:
      eliminarRegistro();
      break;
    case 7:
      contarRegistros();
      break;
    case 8:
      copiarArchivo();
      break;
    case 9:
      limpiarArchivo();
      break;
    case 0:
      break;
    default:
      cout << "Opción inválida.\n";
    }

  } while (opcion != 0);

  return 0;
}

// -------------------------------------------------------------
// CREAR ARCHIVO BINARIO (lo sobrescribe)
// -------------------------------------------------------------
void crearArchivo() {
  ofstream file(ARCHIVO, ios::binary | ios::trunc);
  cout << "Archivo binario creado o reiniciado.\n";
}

// -------------------------------------------------------------
// AGREGAR REGISTRO AL ARCHIVO BINARIO
// -------------------------------------------------------------
void agregarRegistro() {
  ofstream file(ARCHIVO, ios::binary | ios::app);

  Persona p;
  string temp;

  cout << "Nombre: ";
  getline(cin, temp);

  strncpy(p.nombre, temp.c_str(), sizeof(p.nombre));
  p.nombre[sizeof(p.nombre) - 1] = '\0';

  cout << "Edad: ";
  cin >> p.edad;
  cin.ignore();

  file.write(reinterpret_cast<char *>(&p), sizeof(Persona));

  cout << "Registro guardado en binario.\n";
}

// -------------------------------------------------------------
// MOSTRAR TODOS LOS REGISTROS
// -------------------------------------------------------------
void mostrarRegistros() {
  ifstream file(ARCHIVO, ios::binary);
  Persona p;

  cout << "\n--- CONTENIDO DEL ARCHIVO ---\n";

  while (file.read(reinterpret_cast<char *>(&p), sizeof(Persona))) {
    cout << p.nombre << " | " << p.edad << "\n";
  }
}

// -------------------------------------------------------------
// BUSCAR UN REGISTRO POR NOMBRE
// -------------------------------------------------------------
void buscarRegistro() {
  ifstream file(ARCHIVO, ios::binary);
  Persona p;
  string buscar;
  bool encontrado = false;

  cout << "Nombre a buscar: ";
  getline(cin, buscar);

  while (file.read(reinterpret_cast<char *>(&p), sizeof(Persona))) {
    if (buscar == p.nombre) {
      cout << "Encontrado: " << p.nombre << " | " << p.edad << "\n";
      encontrado = true;
    }
  }

  if (!encontrado)
    cout << "No encontrado.\n";
}

// -------------------------------------------------------------
// EDITAR UN REGISTRO EN BINARIO
// -------------------------------------------------------------
void editarRegistro() {
  ifstream file(ARCHIVO, ios::binary);
  ofstream temp("temp.bin", ios::binary);

  Persona p;
  string buscar;
  bool encontrado = false;

  cout << "Nombre a editar: ";
  getline(cin, buscar);

  while (file.read(reinterpret_cast<char *>(&p), sizeof(Persona))) {
    if (buscar == p.nombre) {
      encontrado = true;

      cout << "Nuevo nombre: ";
      string tempNombre;
      getline(cin, tempNombre);

      strncpy(p.nombre, tempNombre.c_str(), sizeof(p.nombre));
      p.nombre[sizeof(p.nombre) - 1] = '\0';

      cout << "Nueva edad: ";
      cin >> p.edad;
      cin.ignore();
    }

    temp.write(reinterpret_cast<char *>(&p), sizeof(Persona));
  }

  file.close();
  temp.close();

  remove(ARCHIVO);
  rename("temp.bin", ARCHIVO);

  if (encontrado)
    cout << "Registro editado.\n";
  else
    cout << "No encontrado.\n";
}

// -------------------------------------------------------------
// ELIMINAR REGISTRO
// -------------------------------------------------------------
void eliminarRegistro() {
  ifstream file(ARCHIVO, ios::binary);
  ofstream temp("temp.bin", ios::binary);

  Persona p;
  string buscar;
  bool eliminado = false;

  cout << "Nombre a eliminar: ";
  getline(cin, buscar);

  while (file.read(reinterpret_cast<char *>(&p), sizeof(Persona))) {
    if (buscar == p.nombre) {
      eliminado = true;
      continue; // OMITIR → eliminar
    }

    temp.write(reinterpret_cast<char *>(&p), sizeof(Persona));
  }

  file.close();
  temp.close();

  remove(ARCHIVO);
  rename("temp.bin", ARCHIVO);

  if (eliminado)
    cout << "Registro eliminado.\n";
  else
    cout << "No encontrado.\n";
}

// -------------------------------------------------------------
// CONTAR REGISTROS BINARIOS
// -------------------------------------------------------------
void contarRegistros() {
  ifstream file(ARCHIVO, ios::binary);
  Persona p;
  int contador = 0;

  while (file.read(reinterpret_cast<char *>(&p), sizeof(Persona)))
    contador++;

  cout << "Registros en binario: " << contador << "\n";
}

// -------------------------------------------------------------
// COPIAR ARCHIVO BINARIO COMPLETO
// -------------------------------------------------------------
void copiarArchivo() {
  ifstream file(ARCHIVO, ios::binary);
  ofstream copia("personas_copia.bin", ios::binary);

  copia << file.rdbuf();

  cout << "Archivo binario copiado.\n";
}

// -------------------------------------------------------------
// LIMPIAR ARCHIVO (DEJARLO VACÍO)
// -------------------------------------------------------------
void limpiarArchivo() {
  ofstream file(ARCHIVO, ios::binary | ios::trunc);
  cout << "Archivo binario vaciado.\n";
}
