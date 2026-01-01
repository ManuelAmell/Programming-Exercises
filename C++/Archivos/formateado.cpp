// por que ponen los #include asi?
#include <string.h>

#include <fstream>
#include <iomanip>  //obviamente para los setw
#include <iostream>


using namespace std;

/*

        C�DIGO PRESENTADO POR:
        > JULIAN ALEJANDRO GUZM�N MORALES 0222420038
        > ALAN PEREIRA ESTRADA 0222420030
        > MANUEL AMELL 0222421001
        >
        >
        >

        UNIVERSIDAD DE CARTAGENA

        poner esto en la pantalla principal del programa cuando est� terminado.




        NOTAS PARA QUIEN HAGA EL PUNTO 4: !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1

        todo esta ordenado aqui, lee las descripciones si necesitas un contexto,
   dudo que necesites mucha explicacion, los dos archivos tienen toda la
   informacion necesaria.

        hay varios comentarios que dicen cosas que faltan por hacer, son
   principalmente visuales, hice todas las comprobaciones de esta parte asi que
   por esa parte todo est� bien.

*/

struct EmpleadoInfo {
  int id;
  char nombre[50];
  char cargo[50];
  int dependencia;  // Validar que solo se pueda ingresar de 1 - 3 si usada.
};

struct EmpleadoHoras {
  int id;
  int horas;
  double valor;
  int tardanza;
  bool registrado;  // Si el usuario registr� sus horas, aqu� se reflejar�.
};

void crear();

/* La funci�n crear(), crea los archivos binarios, se usa al inicio
del programa para evitar cualquier errir relacionado con estos.  */

int menuPrincipal();

/* Menu principal. */

bool validar(int id);

/* Valida la ID de un empleado, retorna TRUE si ya se encuentra registrado */

void registrarInfo();

/* Registra la informacion basica del empleado en un archivo binario */

void registrarHoras();

/* Registra la informaci�n sobre horas del empleado */

void menuConsultas();

/* Menu de las consultas */

void consultarEmpleado();

/* Consulta los datos de un empleado en los dos archivos (mediante su ID) */

void consultarDependencia();

/* Consulta los datos de empleados en los dos archivos (dependiendo de la
 * dependencia) */

void menuReportes();

/* Menu de los reportes */

void reporteGeneral();

/* Reporte sobre datos generales de los empleados en forma de un listado */

void reporteEmpleadosrt();

/* Reporte de empleados con minutos de tardanza, empleado con max y min
 * tardanza, promedio de tardanza */

void reporteEmpleadopt();

/* Reporte de empleados puntuales, cada uno lleva su informacion, y un promedio
 * de contabilidad, sistemas y logistica */

void reporteDescuento();

/* Reporte con todo los datos solicitados ademas de todo los calculos en las
 * horas */

///////// MAIN /////////

int main() {
  crear();

  int opc = 0;

  while (opc != 5) {
    opc = menuPrincipal();

    switch (opc) {  // aqui hay que validar que no puedas consultar o sacar
                    // estadisticas antes de registrar
      case 1: {
        registrarInfo();
        break;
      }
      case 2: {
        registrarHoras();
        break;
      }
      case 3: {
        menuConsultas();
        break;
      }
      case 4: {
        menuReportes();
        break;
      }
      case 5: {
        cout << "\nSaliendo.\n";
        break;
      }
    }
  }
}

////// FUNCIONES ///////

void crear() {
  ofstream empleados("empleados.txt", ios::app | ios::binary);

  if (empleados.fail()) {
    cout << "Se ha producido un error fatal... \n";
    exit(0);
  }

  empleados.close();

  ofstream registro_horas("registro_horas.txt", ios::app | ios::binary);

  if (registro_horas.fail()) {
    cout << "Se ha producido un error fatal... \n";
    exit(0);
  }

  registro_horas.close();
}

int menuPrincipal() {
  system("cls");

  int opc = 0;

  cout << "\nEMPRESA LS (Logistics Service)\n";
  cout << "  REGISTRO DE TARDANZA\n";

  cout << "1. Registra informaci�n de empleados.\n";
  cout << "2. Registrar horas trabajadas y minutaje de tardanza.\n";
  cout << "3. Consultas.\n";
  cout << "4. Reportes.\n";
  cout << "5. Salir.\n";

  while (opc < 1 || opc > 5) {
    cin >> opc;

    if (opc < 1 || opc > 5) {
      cout << "\n Ha ingresado un valor invalido!, int�ntelo de nuevo.\n";
    }
  }

  return opc;
}

bool validar(int id) {
  EmpleadoInfo buffer;

  ifstream empleados("empleados.txt", ios::in | ios::binary);

  if (empleados.fail()) {
    cout << "Se ha producido un error fatal...";
    exit(0);
  }

  while (!empleados.eof()) {
    empleados.read(reinterpret_cast<char*>(&buffer), sizeof(EmpleadoInfo));

    if (!empleados.eof()) {
      if (buffer.id == id) {
        return true;
      }
    }
  }

  return false;
}

void registrarInfo() {
  EmpleadoInfo buffer;
  bool end = false;
  int opc = 0;

  system("cls");

  while (!end) {
    cout << "\nREGISTRO DE LA INFORMACI�N DE EMPLEADOS\n\n";

    cout << "Ingrese la ID del empleado: ";
    cin >> buffer.id;

    if (!validar(buffer.id)) {
      cout << "Ingrese el nombre del empleado: ";
      fflush(stdin);
      gets(buffer.nombre);

      cout << "En que dependencia se encuentra el empleado?: \n";
      cout << "1. Contabilidad.\n";
      cout << "2. Sistemas.\n";
      cout << "3. Log�stica.\n";

      buffer.dependencia = 0;

      while (buffer.dependencia < 1 || buffer.dependencia > 3) {
        cin >> buffer.dependencia;

        if (buffer.dependencia < 1 || buffer.dependencia > 3) {
          cout << "\nDato invalido, intentelo de nuevo.\n";
        }
      }

      ofstream empleados("empleados.txt", ios::app | ios::binary);

      if (empleados.fail()) {
        cout << "Ha ocurrido un error fatal...";
        exit(0);
      }

      empleados.write(reinterpret_cast<char*>(&buffer), sizeof(EmpleadoInfo));

      empleados.close();
    } else {
      cout << "Esta ID de empleado ya est� relacionada con un registro. \n";
    }

    opc = 0;
    cout << "\n Desea ingresar otro empleado? (1. SI, 2. NO): ";

    while (opc < 1 || opc > 2) {
      cin >> opc;

      if (opc < 1 || opc > 2) {
        cout << "\nValor invalido, ingresar de nuevo.\n";
      }
    }

    switch (opc) {
      case 1:
        cout << "\nContinuando el registro.\n";
        break;
      case 2:
        cout << "\nTerminando el registro.\n";
        end = true;
        break;
    }
  }
}

void registrarHoras() {
  EmpleadoHoras buffer;
  bool end = false;
  int opc = 0;

  system("cls");

  cout << "\n REGISTRO HORAS DE LOS EMPLEADOS.\n\n";

  while (!end) {
    cout << "Ingrese la ID del empleado al que le desea registrar sus horas: ";
    cin >> buffer.id;

    if (validar(buffer.id)) {
      buffer.registrado = true;

      cout << "\nSe ha encontrado al empleado relacionado con la ID.\n";

      cout << "Cuantas horas semanales tiene el empleado?: ";
      cin >> buffer.horas;

      cout << "Ingrese los minutos de tardanza: ";
      cin >> buffer.tardanza;

      cout << "Ingrese el valor de la hora: ";
      cin >> buffer.valor;

      ofstream registro_horas("registro_horas.txt", ios::app | ios::binary);

      if (registro_horas.fail()) {
        cout << "Se ha ocurrido un error fatal...";
        exit(0);
      }

      registro_horas.write(reinterpret_cast<char*>(&buffer),
                           sizeof(EmpleadoHoras));

      registro_horas.close();
    } else {
      cout << "\nEsta ID no corresponde a ning�n empleado registrado.\n";
    }

    opc = 0;
    cout << "Desea registrar las horas de otro empleado? (1. SI, 2. NO): ";

    while (opc < 1 || opc > 2) {
      cin >> opc;

      if (opc < 1 || opc > 2) {
        cout << "Porfavor ingrese un valor v�lido.\n";
      }
    }

    switch (opc) {
      case 1:
        cout << "\nContinuando al siguiente registro.\n";
        break;
      case 2:
        cout << "\nTerminando el registro. \n";
        end = true;
        break;
    }
  }
}

void menuConsultas() {
  int opt = 0;

  do {
    system("cls");

    cout << "\nSUBMEN� CONSULTAS\n";

    cout << "1. Consultar un empleado.\n";
    cout << "2. Consultar una dependencia.\n";
    cout << "3. Volver al men� principal.\n";

    cin >> opt;

    switch (opt) {
      case 1:
        consultarEmpleado();
        break;
      case 2:
        consultarDependencia();
        break;
      case 3:
        cout << "Volviendo...\n";
        break;
      default:
        cout << "\nPorfavor ingresar un valor v�lido.\n";
    }
  } while (opt != 3);
}

void consultarEmpleado() {
  EmpleadoInfo bufferInfo;
  EmpleadoHoras bufferHoras;
  int id;

  cout << "CONSULTAR UN EMPLEADO\n\n";
  cout << "HAY QUE REFORMATEAR ESTO PARA QUE CUMPLA LAS EXPECTATIVAS "
          "DICHAS\n\n";  // <-------------------------------------------------------------------------------
                         // evil ass rape arrow (leer)

  cout << "Ingresar la ID del empleado que desea consultar: ";
  cin >> id;

  ifstream empleados("empleados.txt", ios::in | ios::binary);

  if (empleados.fail()) {
    cout << "Error fatal.\n";
    exit(0);
  }

  ifstream registro_horas("registro_horas.txt", ios::in | ios::binary);

  if (registro_horas.fail()) {
    cout << "Error fatal.\n";
    exit(0);
  }

  bool infoID = false;

  while (!empleados.eof()) {
    empleados.read(reinterpret_cast<char*>(&bufferInfo), sizeof(EmpleadoInfo));

    if (!empleados.eof()) {
      if (bufferInfo.id == id) {
        infoID = true;
        break;
      }
    }
  }

  bool horasID = false;

  while (!registro_horas.eof()) {
    registro_horas.read(reinterpret_cast<char*>(&bufferHoras),
                        sizeof(EmpleadoHoras));

    if (!registro_horas.eof()) {
      if (bufferHoras.id == id) {
        horasID = true;
        break;
      }
    }
  }

  if (!horasID) {
    bufferHoras.horas = 0;
    bufferHoras.valor = 0;
    bufferHoras.tardanza = 0;
  }

  if (infoID) {
    cout << "\nDATOS DEL EMPLEADO\n";

    cout << bufferInfo.id << " " << bufferInfo.nombre << " "
         << bufferHoras.horas << " " << bufferInfo.dependencia << " "
         << bufferHoras.tardanza
         << endl;  // <---------------- aqui lo hay que poner bonito todo
  } else {
    cout << "Esta id no est� relacionada con ning�n empleado.\n";
  }

  empleados.close();
  registro_horas.close();

  system("pause");
}

void consultarDependencia() {
  EmpleadoInfo bufferInfo;
  EmpleadoHoras bufferHoras;
  int dep = 0;
  bool enHoras = false;

  cout << "\nCONSULTAR DEPENDENCIA\n";
  cout << "Ingrese la dependencia:\n";
  cout << "1. Contabilidad\n";
  cout << "2. Sistemas\n";
  cout << "3. Log�sticas\n";

  while (dep < 1 || dep > 3) {
    cin >> dep;

    if (dep < 1 || dep > 3) {
      cout << "invalido.\n";
    }
  }

  ifstream empleados("empleados.txt", ios::in | ios::binary);

  if (empleados.fail()) {
    cout << "error.\n";
    exit(0);
  }

  cout << "\nEMPLEADOS EN LA DEPENDENCIA:\n";

  while (!empleados.eof()) {
    empleados.read(reinterpret_cast<char*>(&bufferInfo), sizeof(EmpleadoInfo));

    if (empleados.fail()) {
      break;
    }

    if (!empleados.eof()) {
      if (bufferInfo.dependencia == dep) {
        ifstream registro_horas("registro_horas.txt", ios::in | ios::binary);

        if (registro_horas.fail()) {
          cout << "error\n";
          exit(0);
        }

        enHoras = false;

        while (!registro_horas.eof()) {
          registro_horas.read(reinterpret_cast<char*>(&bufferHoras),
                              sizeof(EmpleadoHoras));

          if (registro_horas.fail()) {
            break;
          }

          if (!registro_horas.eof()) {
            if (bufferHoras.id == bufferInfo.id) {
              enHoras = true;
              break;
            }
          }
        }

        registro_horas.close();

        if (!enHoras) {
          bufferHoras.horas = 0;
          bufferHoras.valor = 0;
          bufferHoras.tardanza = 0;
        }

        cout << bufferInfo.id << " " << bufferInfo.nombre << " "
             << bufferHoras.horas << " " << bufferInfo.dependencia << " "
             << bufferHoras.tardanza
             << endl;  // <---------------- aqui lo hay que poner bonito todo
      }
    }
  }

  empleados.close();

  system("pause");
}

void menuReportes() {
  int opt = 0;

  do {
    system("cls");

    cout << "\nSUBMEN� REPORTES\n";

    cout << "1. Reporte General.\n";
    cout << "2. Reporte de empleados con tardanza.\n";
    cout << "3. Reporte de empleados puntuales.\n";
    cout << "4. Reporte de descuento de tiempo\n";
    cout << "5. Salir al menu principal\n";

    cin >> opt;

    switch (opt) {
      case 1:
        reporteGeneral();
        break;
      case 2:
        reporteEmpleadosrt();
        break;
      case 3:
        reporteEmpleadopt();
        break;
      case 4:
        reporteDescuento();
        break;
      case 5:
        cout << "Volviendo...\n";
        break;
      default:
        cout << "\nPorfavor ingresar un valor v�lido.\n";
    }
  } while (opt != 5);
}

void reporteGeneral() {
  system("cls");
  cout << "REPORTE GENERAL DE EMPLEADOS\n\n";

  ifstream empleados("empleados.txt", ios::binary);

  ifstream horas("registro_horas.txt", ios::binary);

  if (empleados.fail() or horas.fail()) {
    cout << "Error al abrir los archivos.\n";
    system("pause");
    return;
  }

  EmpleadoInfo info;
  EmpleadoHoras h;

  cout << "===================================================================="
          "============\n";
  cout << left << setw(10) << "Codigo" << setw(25) << "Nombre" << setw(15)
       << "Horas Trab." << setw(18) << "Oficina" << setw(15) << "Min. Tardanza"
       << endl;
  cout << "===================================================================="
          "============\n";

  while (!empleados.eof()) {
    empleados.read(reinterpret_cast<char*>(&info), sizeof(EmpleadoInfo));
    if (empleados.eof()) break;

    // Usaremos estos comandos para hacer el recorrido y reiniciar el recorrido
    // del archivo
    horas.clear();
    horas.seekg(0);

    bool encontrado = false;

    while (!horas.eof()) {
      horas.read(reinterpret_cast<char*>(&h), sizeof(EmpleadoHoras));
      if (horas.eof()) break;

      if (h.id == info.id) {
        encontrado = true;
        break;
      }
    }

    // si no tiene nada establecemos los valores en 0
    if (!encontrado) {
      h.horas = 0;
      h.valor = 0;
      h.tardanza = 0;
    }

    char dep[20];
    switch (info.dependencia) {
      case 1:
        strcpy(dep, "Contabilidad");
        break;
      case 2:
        strcpy(dep, "Sistemas");
        break;
      case 3:
        strcpy(dep, "Logistica");
        break;
      default:
        strcpy(dep, "N/A");
    }

    cout << left << setw(10) << info.id << setw(25) << info.nombre << setw(15)
         << h.horas << setw(18) << dep << setw(15) << h.tardanza << endl;
  }
  cout << "===================================================================="
          "============\n";

  empleados.close();
  horas.close();
  system("pause");
}

void reporteEmpleadosrt() {
  system("cls");

  int t_tardanza = 0, cantidad = 0, max_t = -1, min_t = 999999;
  bool existe = false;

  cout << "REPORTE DE EMPLEADOS TARDANZA\n";

  ifstream empleados("empleados.txt", ios::binary);
  ifstream horas("registro_horas.txt", ios::binary);

  if (empleados.fail() or horas.fail()) {
    cout << "Error abriendo archivos\n";
    system("pause");
    return;
  }

  EmpleadoInfo info;

  EmpleadoHoras h;
  // creamos apartados para poder guardar el maximo y minimo
  EmpleadoInfo emp_max, emp_min;

  cout << "===================================================================="
          "============\n";
  cout << left << setw(25) << "Nombre" << setw(20) << "Cargo" << setw(18)
       << "Dependencia" << setw(15) << "Min. Tardanza" << endl;
  cout << "===================================================================="
          "============\n";

  while (!empleados.eof()) {
    empleados.read(reinterpret_cast<char*>(&info), sizeof(EmpleadoInfo));
    if (empleados.eof()) break;

    horas.clear();
    horas.seekg(0);

    bool encontrado = false;

    while (!horas.eof()) {
      horas.read(reinterpret_cast<char*>(&h), sizeof(EmpleadoHoras));
      if (horas.eof()) break;

      if (h.id == info.id) {
        encontrado = true;
        break;
      }
    }

    if (!encontrado) continue;  // continuamos ya que no se encuentra el
                                // registro

    if (h.tardanza > 0) {
      existe = true;
      cantidad++;
      t_tardanza += h.tardanza;

      char dep[20];
      switch (info.dependencia) {
        case 1:
          strcpy(dep, "Contabilidad");
          break;
        case 2:
          strcpy(dep, "Sistemas");
          break;
        case 3:
          strcpy(dep, "Logistica");
          break;
        default:
          strcpy(dep, "N/A");
      }

      cout << left << setw(25) << info.nombre << setw(20) << info.cargo
           << setw(18) << dep << setw(15) << h.tardanza << endl;

      // sacamos el maximo
      if (h.tardanza > max_t) {
        max_t = h.tardanza;
        emp_max = info;
      }

      // hacemos lo mismo pero con el minimo
      if (h.tardanza < min_t) {
        min_t = h.tardanza;
        emp_min = info;
      }
    }
  }

  cout << "===================================================================="
          "============\n\n";

  if (!existe) {
    cout << "\nNo hay empleados con tardanza registrada.\n";
  } else {
    double promedio;
    promedio = (double)t_tardanza / cantidad;

    cout << "  * Empleado con MAYOR tardanza: " << emp_max.nombre << " ("
         << max_t << " minutos)\n";
    cout << "  * Empleado con MENOR tardanza: " << emp_min.nombre << " ("
         << min_t << " minutos)\n";
    cout << "  * Promedio general de tardanza: " << fixed << setprecision(2)
         << promedio << " minutos\n";
  }

  empleados.close();
  horas.close();
  system("pause");
}

void reporteEmpleadopt() {
  system("cls");

  bool puntuales = false;
  double sum_c = 0, sum_s = 0, sum_l = 0;
  int cont_c = 0, cont_s = 0, cont_l = 0;

  cout << "REPORTE DE EMPLEADOS PUNTUALES\n\n";

  ifstream empleados("empleados.txt", ios::binary);
  ifstream horas("registro_horas.txt", ios::binary);

  if (empleados.fail() or horas.fail()) {
    cout << "Error abriendo archivos.\n";
    system("pause");
    return;
  }

  EmpleadoInfo info;
  EmpleadoHoras h;

  cout << "===================================================================="
          "====================\n";
  cout << left << setw(8) << "ID" << setw(25) << "Nombre" << setw(20) << "Cargo"
       << setw(18) << "Dependencia" << setw(15) << "Horas Trabajadas" << endl;
  cout << "===================================================================="
          "====================\n";

  while (!empleados.eof()) {
    empleados.read(reinterpret_cast<char*>(&info), sizeof(EmpleadoInfo));
    if (empleados.eof()) break;

    horas.clear();
    horas.seekg(0);

    bool encontrado = false;

    while (!horas.eof()) {
      horas.read(reinterpret_cast<char*>(&h), sizeof(EmpleadoHoras));
      if (horas.eof()) break;

      if (h.id == info.id) {
        encontrado = true;
        break;
      }
    }

    if (!encontrado) continue;

    if (h.tardanza == 0) {
      puntuales = true;

      char dep[20];
      switch (info.dependencia) {
        case 1:
          strcpy(dep, "Contabilidad");
          break;
        case 2:
          strcpy(dep, "Sistemas");
          break;
        case 3:
          strcpy(dep, "Logistica");
          break;
        default:
          strcpy(dep, "N/A");
      }

      cout << left << setw(8) << info.id << setw(25) << info.nombre << setw(20)
           << info.cargo << setw(18) << dep << setw(15) << h.horas << endl;

      switch (info.dependencia) {
        case 1:
          sum_c += h.horas;
          cont_c++;
          break;
        case 2:
          sum_s += h.horas;
          cont_s++;
          break;
        case 3:
          sum_l += h.horas;
          cont_l++;
          break;
      }
    }
  }
  // puse los iguale  po q se ve mejor
  cout << "===================================================================="
          "====================\n\n";

  if (!puntuales) {
    cout << "\nNo hay empleados puntuales registrados.\n";
  } else {
    double prom_c, prom_s, prom_l;
    // recordemos que esta estructura es como un if else pero mas compacto para
    // que lo tengan en cuenta amigos
    prom_c = cont_c > 0 ? (sum_c / cont_c) : 0;
    prom_s = cont_s > 0 ? (sum_s / cont_s) : 0;
    prom_l = cont_l > 0 ? (sum_l / cont_l) : 0;

    // aqui ppl añadi el fixed pa q se vea bien bonito
    cout << "PROMEDIO DE HORAS TRABAJADAS POR OFICINA:\n";
    cout << "  * Contabilidad: " << fixed << setprecision(2) << prom_c
         << " horas\n";
    cout << "  * Sistemas: " << fixed << setprecision(2) << prom_s
         << " horas\n";
    cout << "  * Logistica: " << fixed << setprecision(2) << prom_l
         << " horas\n";
  }

  empleados.close();
  horas.close();
  system("pause");
}

void reporteDescuento() {
  system("cls");

  cout << "REPORTE DE DESCUENTO POR TARDANZA\n\n";

  ifstream empleados("empleados.txt", ios::binary);
  ifstream horas("registro_horas.txt", ios::binary);
  ofstream txt("presentaciones.txt", ios::binary);

  if (empleados.fail() or horas.fail() or txt.fail()) {
    cout << "Error abriendo archivos.\n";
    system("pause");
    return;
  }

  EmpleadoInfo info;
  EmpleadoHoras h;

  bool existe = false;

  // esto no es parte de la impresion, es el encabezado que se vera en el
  // documento
  txt << "REPORTE DE PRESTACIONES - DESCUENTO POR TARDANZA\n\n";
  txt << "ID\tNombre\tCargo\tDependencia\tValor hora\tHoras "
         "trabajadas\tTardanza\tHoras descontadas\tHoras "
         "netas\tDescuento\tSalario Neto\n";
  txt << "---------------------------------------------------------------------"
         "-----------------------------------------------------------";

  cout << "===================================================================="
          "===================================================================="
          "======================================================\n";
  cout << left << setw(6) << "ID" << setw(20) << "Nombre" << setw(15) << "Cargo"
       << setw(15) << "Dependencia" << setw(12) << "Valor/Hora" << setw(10)
       << "Hrs Trab" << setw(10) << "Tardanza" << setw(12) << "Hrs Desc."
       << setw(12) << "Hrs Netas" << setw(12) << "Descuento" << setw(15)
       << "Salario Neto" << endl;
  cout << "===================================================================="
          "===================================================================="
          "======================================================\n";

  while (!empleados.eof()) {
    empleados.read(reinterpret_cast<char*>(&info), sizeof(EmpleadoInfo));
    if (empleados.eof()) break;

    horas.clear();
    horas.seekg(0);

    bool encontrado = false;

    while (!horas.eof()) {
      horas.read(reinterpret_cast<char*>(&h), sizeof(EmpleadoHoras));
      if (horas.eof()) break;

      if (h.id == info.id) {
        encontrado = true;
        break;
      }
    }

    if (!encontrado) continue;

    if (h.tardanza <= 0) continue;  // esto es para los empleados con tardanza

    existe = true;

    char dep[20];
    switch (info.dependencia) {
      case 1:
        strcpy(dep, "Contabilidad");
        break;
      case 2:
        strcpy(dep, "Sistemas");
        break;
      case 3:
        strcpy(dep, "Logistica");
        break;
    }

    double H_desc, H_netas, descuento, S_neto;

    H_desc = h.tardanza / 60.0;
    H_netas = h.horas - H_desc;

    if (H_netas < 0)
      H_netas = 0;  // comprobacion temporal para evitar negativos arreglenlo
                    // algo mejor si es posible

    descuento = H_desc * h.valor;
    S_neto = H_netas * h.valor;

    cout << left << setw(6) << info.id << setw(20) << info.nombre << setw(15)
         << info.cargo << setw(15) << dep << setw(12) << fixed
         << setprecision(2) << h.valor << setw(10) << h.horas << setw(10)
         << h.tardanza << setw(12) << H_desc << setw(12) << H_netas << setw(12)
         << descuento << setw(15) << S_neto << endl;
    // esta segunda impresion se realiza para guardar en el archivo no para
    // mostrar en pantalla tener eso en cuenta porfa no lo muevan
    txt << info.id << "\t" << info.nombre << "\t" << info.cargo << "\t" << dep
        << "\t" << h.valor << "\t" << h.horas << "\t" << h.tardanza << "\t"
        << H_desc << "\t" << H_netas << "\t" << descuento << "\t" << S_neto
        << "\n";
  }

  empleados.close();
  horas.close();
  txt.close();

  if (!existe) {
    cout << "\nNo hay empleados con tardanza registrada.\n";
    system("pause");
    return;
  }

  int opc = 0;
  cout << "\nArchivo 'Prestaciones.txt' generado de forma exitosa.\n";
  cout << "¿quiere ver el archivo? [1] si [2] no: ";
  cin >> opc;

  if (opc == 1) {
    system("cls");

    ifstream visual("prestaciones.txt");

    if (!visual.fail()) {
      char linea[300];

      while (!visual.eof()) {
        visual.getline(linea, 300);
        cout << linea << endl;
      }
      visual.close();
    }
  }
  system("pause");
}