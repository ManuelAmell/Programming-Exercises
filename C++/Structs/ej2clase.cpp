#include <iostream>
#include <string>
using namespace std;

struct Texto {
  int referencia;// número de referencia único
  string titulo;// título del texto
  string autor;//
  string editorial;
  string clasePublicacion; // "libro" o "revista"
  int numeroEdicion;       // solo libros
  int anioPublicacion;     // solo libros
  string nombreRevista;    // solo revistas
};

int main() {
  Texto *textos = nullptr;
  int cantidad = 0;
  int opcion;

  do {
    cout << "\n===== SISTEMA DE BIBLIOTECA =====\n";
    cout << "1. Registrar texto\n";
    cout << "2. Consultar\n";
    cout << "3. Modificar\n";
    cout << "4. Salir\n";
    cout << "Seleccione una opción: ";
    cin >> opcion;
    cin.ignore();

    switch (opcion) {
    case 1: {
      // 🔹 Registrar nuevo texto
      Texto *nuevo = new Texto[cantidad + 1];

      // Copiar los anteriores
      for (int i = 0; i < cantidad; i++)
        nuevo[i] = textos[i];

      delete[] textos;
      textos = nuevo;

      cout << "\n=== Registro de texto #" << cantidad + 1 << " ===\n";
      cout << "Número de referencia: ";
      cin >> textos[cantidad].referencia;
      cin.ignore();
      cout << "Título: ";
      getline(cin, textos[cantidad].titulo);
      cout << "Autor: ";
      getline(cin, textos[cantidad].autor);
      cout << "Editorial: ";
      getline(cin, textos[cantidad].editorial);
      cout << "Clase de publicación (libro/revista): ";
      getline(cin, textos[cantidad].clasePublicacion);

      if (textos[cantidad].clasePublicacion == "libro" ||
          textos[cantidad].clasePublicacion == "Libro") {
        cout << "Número de edición: ";
        cin >> textos[cantidad].numeroEdicion;
        cout << "Año de publicación: ";
        cin >> textos[cantidad].anioPublicacion;
        cin.ignore();
        textos[cantidad].nombreRevista = "N/A";
      } else {
        textos[cantidad].numeroEdicion = 0;
        textos[cantidad].anioPublicacion = 0;
        cout << "Nombre de la revista: ";
        getline(cin, textos[cantidad].nombreRevista);
      }

      cantidad++;
      cout << "\n✅ Texto registrado correctamente.\n";
      break;
    }

    case 2: {
      if (cantidad == 0) {
        cout << "\n⚠️ No hay textos registrados.\n";
        break;
      }

      int subop;
      cout << "\n=== CONSULTAS ===\n";
      cout << "1. Por clase de publicación\n";
      cout << "2. Por nombre de autor\n";
      cout << "3. Por nombre de revista\n";
      cout << "Seleccione una opción: ";
      cin >> subop;
      cin.ignore();

      switch (subop) {
      case 1: {
        string clase;
        cout << "Ingrese la clase de publicación (libro/revista): ";
        getline(cin, clase);

        cout << "\n=== Resultados ===\n";
        for (int i = 0; i < cantidad; i++) {
          if (textos[i].clasePublicacion == clase) {
            cout << "\nReferencia: " << textos[i].referencia
                 << "\nTítulo: " << textos[i].titulo
                 << "\nAutor: " << textos[i].autor
                 << "\nEditorial: " << textos[i].editorial;

            if (clase == "libro")
              cout << "\nEdición: " << textos[i].numeroEdicion
                   << "\nAño: " << textos[i].anioPublicacion;
            else
              cout << "\nNombre de la revista: " << textos[i].nombreRevista;

            cout << "\n-------------------";
          }
        }
        break;
      }

      case 2: {
        string autorBuscado;
        cout << "Ingrese el nombre del autor: ";
        getline(cin, autorBuscado);

        cout << "\n=== Resultados ===\n";

        for (int i = 0; i < cantidad; i++) {
          if (textos[i].autor == autorBuscado) {
            cout << "\nTítulo: " << textos[i].titulo << " ("
                 << textos[i].clasePublicacion << ")\n";
          }
        }
        break;
      }

      case 3: {
        string revistaBuscada;
        cout << "Ingrese el nombre de la revista: ";
        getline(cin, revistaBuscada);

        cout << "\n=== Resultados ===\n";
        for (int i = 0; i < cantidad; i++) {
          if (textos[i].nombreRevista == revistaBuscada) {
            cout << "\nTítulo: " << textos[i].titulo
                 << "\nAutor: " << textos[i].autor
                 << "\nEditorial: " << textos[i].editorial << endl;
          }
        }
        break;
      }

      default:
        cout << "Opción no válida.\n";
      }
      break;
    }

    case 3: {
      if (cantidad == 0) {
        cout << "\n⚠️ No hay textos para modificar.\n";
        break;
      }

      int ref;
      cout << "Ingrese el número de referencia del texto a modificar: ";
      cin >> ref;
      cin.ignore();

      bool encontrado = false;
      for (int i = 0; i < cantidad; i++) {
        if (textos[i].referencia == ref) {
          encontrado = true;
          cout << "\nModificando texto: " << textos[i].titulo << endl;
          cout << "Nuevo título: ";
          getline(cin, textos[i].titulo);
          cout << "Nuevo autor: ";
          getline(cin, textos[i].autor);
          cout << "Nueva editorial: ";
          getline(cin, textos[i].editorial);
          cout << "Nueva clase de publicación (libro/revista): ";
          getline(cin, textos[i].clasePublicacion);

          if (textos[i].clasePublicacion == "libro") {
            cout << "Nueva edición: ";
            cin >> textos[i].numeroEdicion;
            cout << "Nuevo año: ";
            cin >> textos[i].anioPublicacion;
            textos[i].nombreRevista = "N/A";
            cin.ignore();
          } else {
            textos[i].numeroEdicion = 0;
            textos[i].anioPublicacion = 0;
            cout << "Nuevo nombre de revista: ";
            getline(cin, textos[i].nombreRevista);
          }

          cout << "✅ Registro modificado correctamente.\n";
          break;
        }
      }

      if (!encontrado)
        cout << "❌ No se encontró un texto con esa referencia.\n";

      break;
    }

    case 4:
      cout << "\nSaliendo del sistema...\n";
      break;

    default:
      cout << "Opción inválida.\n";
    }

  } while (opcion != 4);

  delete[] textos;
  return 0;
}
