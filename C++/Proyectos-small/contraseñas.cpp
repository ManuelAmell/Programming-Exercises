#include <cctype>   // para tolower
#include <iomanip>  //set w
#include <iostream>
#include <limits>  //para limpiar el buufer seguro
using namespace std;

void cls() {  // Por compatibilidad para limpiar pantalla en cualquier SO
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}
// en windows para centrar
#ifdef _WIN32
#include <windows.h>
int anchoConsola() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}
#else  // linux centrar
#include <sys/ioctl.h>
#include <unistd.h>
int anchoConsola() {
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  return w.ws_col;  // columnas de la terminal
}
#endif /

#ifdef _WIN32  // sleep para la api de windows
#include <windows.h>
#else  // usleep linux
#include <unistd.h>
#endif

// Funcion para sleep
void SleepMs(int milisegundos) {
#ifdef _WIN32
  Sleep(milisegundos);
#else
  usleep(milisegundos * 1000);
#endif
}

void Centrado(const string& texto) {
  int ancho = anchoConsola();
  int espacios = (ancho - texto.length()) / 2;
  if (espacios > 0) cout << string(espacios, ' ');  // agrega espacios al inicio
  cout << texto << endl;
}  // importante

void Enter() {
  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  Centrado("Presione enter para continuar");
  cin.get();

  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Titulo() {
  string titulo[] = {
      "   _____    ___________________ _______  ________      _____   ",
      "  /  _  \\  /  _____/\\_   _____/ \\      \\ \\______ \\    /  _  \\  ",
      " /  /_\\  \\/   \\  ___ |    __)_  /   |   \\ |    |  \\  /  /_\\  \\ ",
      "/    |    \\    \\_\\  \\|        \\/    |    \\|    `   \\/    |    \\",
      "\\____|__  /\\______  /_______  /\\____|__  /_______  /\\____|__  /",
      "        \\/        \\/        \\/         \\/        \\/         \\/"};

  for (auto& linea : titulo) {
    Centrado("\033[1;36m" + linea + "\033[0m");  // color celeste brillante
  }
}

struct Contacto {  // con arreglos me daba flojera y pienso q seria mas tedioso
                   // buscar cuando implemente la funcion
  // son como arreglos con esteroides XD
  string sitio;
  string contraseña;  // si no entienden consulte Programacion ATS por favor
  string email;
};

Contacto* agenda =
    nullptr;  // puntero al array dinamico(osea q no apunta anada en la
              // inizializacion y null es mejor que las otras opciones
int cantidad = 0;

void menu(int& opc) {
  do {
    cls();
    Centrado("\033[1;37mBIENVENIDO A \033[0m");  // blanco brillante
    Titulo();

    Centrado("\033[1;34m1) Agregar Credenciales \033[0m");  // azules
    Centrado("\033[1;34m2) Buscar Credenciales\033[0m");    // azules
    Centrado("\033[1;34m3) Ver Contraseñas (PIN)\033[0m");  // azules
    Centrado("\033[1;34m4) Salir\033[0m");                  // azules

    Centrado("\033[1;37mElige una opcion: \033[0m");
    cout << "                                                                  "
            "                                          > ";
    cin >> opc;

    if (cin.fail() ||
        (opc < 1 ||
         opc > 4)) {  // para datos ingresados no esperados del tipo de dato
      cin.clear();    // limpia estado de error
      cin.ignore(numeric_limits<streamsize>::max(),
                 '\n'); /*limpia el buffer y es la unica manera eficiente*/

      cout << endl;

      Centrado(
          " Error: debe ingresar un numero entero dentro del rango ."); /*confiable
                                                                           que
                                                                           encontre
                                                                           para
                                                                           que
                                                                           no
                                                                           crashe
                                                                           con
                                                                           letras*/
      opc = -1;  // repite el ciclo

      cout << "                                                                "
              "                                            > ";
    }

  } while (opc < 1 || opc > 4);
}

void AgregarContacto() {
  Contacto* NuevaAgenda = new Contacto[cantidad + 1];

  // Copiar datos existentes
  for (int i = 0; i < cantidad; i++) {
    NuevaAgenda[i] = agenda[i];
  }

  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  // Rellenar datos del nuevo contacto con detectores de vacio
  Centrado("Nombre Del Sitio (opcional) :");
  cout << "                                                                    "
          "                                        > ";
  getline(cin, NuevaAgenda[cantidad].sitio);
  if (NuevaAgenda[cantidad].sitio.empty()) {
    Centrado("\033[31mEl Nombre esta vacio. (AVISO).\033[0m");
  }

  do {
    Centrado("Correo :");
    cout << "                                                                  "
            "                                          > ";
    getline(cin, NuevaAgenda[cantidad].email);

    if (NuevaAgenda[cantidad].email.empty()) {
      Centrado(
          "\033[31mEl correo no puede estar vacio. Intenta de nuevo.\033[0m");
    }
  } while (NuevaAgenda[cantidad].email.empty());

  do {
    Centrado("Contraseña :");
    cout << "                                                                  "
            "                                          > ";
    getline(cin, NuevaAgenda[cantidad].contraseña);
    if (NuevaAgenda[cantidad].contraseña.empty()) {
      Centrado(
          "\033[31mla contraseña no puede estar vacia. Intenta de "
          "nuevo.\033[0m");
    }
  } while (NuevaAgenda[cantidad].contraseña.empty());

  // Verificar si el contacto ya existe
  bool existeE = false;

  int indiceExistente = -1;
  for (int i = 0; i < cantidad; i++) {
    if (NuevaAgenda[cantidad].sitio == agenda[i].sitio) {
      existeE = true;
      indiceExistente = i;  // guardamos el indice
      break;
    }
  }

  if (existeE) {
    char opcion = 0;
    do {
      Centrado("\033[31mEl contacto ya existe\033[0m");  // rojo
      Centrado("\033[32mNombre : \033[0m" + agenda[indiceExistente].sitio);
      Centrado("\033[32mTelefono : \033[0m" + agenda[indiceExistente].email);
      Centrado("\033[32mEmail : \033[0m" + agenda[indiceExistente].contraseña);
      Centrado("\033[33m¿Deseas actualizarlo? (s/n): \033[0m");
      cout << "                                                                "
              "                                            > ";

      cin >> opcion;
      opcion = tolower(opcion);
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (opcion != 's' && opcion != 'n');

    if (opcion == 's') {
      cout << "\033[33mSitio anterior : \033[0m" + agenda[indiceExistente].sitio
           << endl;
      cout << "Ingresa el nuevo nombre del sitio: ";
      getline(cin, agenda[indiceExistente].sitio);

      cout << "\033[33mTelefono anterior : \033[0m" +
                  agenda[indiceExistente].email
           << endl;
      cout << "Ingresa el nuevo telefono: ";
      getline(cin, agenda[indiceExistente].email);

      cout << "\033[33mEmail / Correo anterior : \033[0m" +
                  agenda[indiceExistente].contraseña
           << endl;
      cout << "Ingresa el nuevo correo: ";
      getline(cin, agenda[indiceExistente].contraseña);

      Centrado("\033[32mContacto actualizado correctamente.\033[0m");  // verde
    } else {
      Centrado("\033[33mNo se agregó el contacto.\033[0m");  // amarillo
      SleepMs(1000);
    }

    delete[] NuevaAgenda;  // liberar memoria temporal
    return;

  } else {
    // No existe, agregamos normalmente
    delete[] agenda;       // liberamos memoria anterior
    agenda = NuevaAgenda;  // apuntamos al nuevo arreglo
    cantidad++;            // actualizar contador
    Centrado("\033[32mContacto agregado con exito!\033[0m");
  }
}

string TodoMinusculas(const string& s) {
  string resultado = s;
  for (char& c : resultado) {  // se asegura de toda la cadena
    c = tolower(c);            // convierte cada letra a minuscula
  }
  return resultado;
}

void BuscarContactos() {
  if (cantidad == 0) {
    Centrado("No hay contactos registrados...");
    cout << "                                                                  "
            "                                          > ";
    Enter();  // pausa aquí
    SleepMs(100);
    return;
  }

  string ebuscado;

  Centrado("Ingrese el nombre a buscar: ");
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  getline(cin, ebuscado);

  bool encontrado = false;

  for (int i = 0; i < cantidad; i++) {
    // Convertir ambos a minusculas antes de comparar
    if (TodoMinusculas(agenda[i].sitio) == TodoMinusculas(ebuscado)) {
      Centrado("\nContacto encontrado:\n");
      Centrado("Nombre : " + agenda[i].sitio);
      Centrado("Tel    : " + agenda[i].email);
      Centrado("Email  : " + agenda[i].contraseña);
      encontrado = true;
      Enter();
      cout << "                                                                "
              "                                            > ";
      break;

    } else if (TodoMinusculas(agenda[i].email) == TodoMinusculas(ebuscado)) {
      Centrado("\nContacto encontrado:\n");
      Centrado("Nombre : " + agenda[i].sitio);
      Centrado("Tel    : " + agenda[i].email);
      Centrado("Email  : " + agenda[i].contraseña);
      encontrado = true;
      Enter();
      cout << "                                                                "
              "                                            > ";

      break;
    } else if (TodoMinusculas(agenda[i].contraseña) ==
               TodoMinusculas(ebuscado)) {
      Centrado("\nContacto encontrado:\n");
      Centrado("Nombre : " + agenda[i].sitio);
      Centrado("Tel    : " + agenda[i].email);
      Centrado("Email  : " + agenda[i].contraseña);
      encontrado = true;
      Enter();
      cout << "                                                                "
              "                                            > ";
      break;
    }
  }

  if (!encontrado) {
    Centrado("No se encontro esas Credenciales.\n");
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    Enter();
    cout << "                                                                  "
            "                                          > ";
  }
}

void VerContactos() {
  if (cantidad == 0) {
    Centrado("No hay sesiones registrados aun...");
    Enter();

    return;
  }

  for (int i = 0; i < cantidad; i++) {
    // Crear la línea completa como string
    string contacto = "| " + to_string(i + 1) +
                      " ) Nombre: " + agenda[i].sitio +
                      "  Correo : " + agenda[i].email +
                      +"  Contraseña : " + agenda[i].contraseña + " |";
    string borde(contacto.length(), '-');

    Centrado(borde);

    Centrado(contacto);
    Centrado(borde);
  }
  // Pausa para que el usuario pueda leer
  Enter();
}

int main() {
  int opc = 0;

  do {
    menu(opc);

    switch (opc) {
      case 1:
        cls();
        Titulo();
        {
          Centrado("\033[33mHas seleccionado: Agregar credenciales.\033[0m");

          AgregarContacto();
          break;
        }
      case 2: {
        cls();
        Titulo();
        cls();
        Centrado("\033[33mHas seleccionado: Buscar credenciales.\033[0m");
        BuscarContactos();
        break;
      }
      case 3: {
        cls();
        Titulo();
        cls();
        Centrado("\033[33mHas seleccionado:Ver credenciales.\033[0m");
        VerContactos();
        break;
      }
      case 4: {
        cls();
        Titulo();
        cout << endl;
        cout << endl;
        Centrado("\033[32m¡Vuelve pronto! By: Manuel Amell!\033[0m");
        cout << "                                                              "
                "                                              > ";
        delete[] agenda;  // liberando memoria
        // añadir guardado en texto modificacion en archivo cuando tenga tiempo
        // libre
        break;
      }
    }

  } while (opc != 4);
  return 0;
}