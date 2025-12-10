#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

struct empleado {
  int id;
  char nombre[30];
  long salariOrdinario;
  int salarioextra;
  float horasTrabajadas;
  float horasExtras;
  float pagoPorHora;
  long salud;
  long pension;
  char eps[100];
  char fpensiones[100];
  long totalpagar;
};

int menu() {
  int opc;
  do {
    system("clear");

    cout << "1)ingresar datos :\n";
    cout << "2)calcular nomina :\n";
    cout << "3)consultas :\n";
    cout << "4)banco :\n";
    cout << "5)pila :\n";
    cout << " 6)salir :\n";
    cin >> opc;

  } while (opc < 1 || opc > 6);
  return opc;
}

void ingresar(struct empleado nomina[], int N) {
  for (int x = 0; x < N; x++) {
    system("clear");
    cout << "Registrando Datos de de nomina Empleado #" << x + 1 << ": "
         << endl;
    cout << "ingrese id :";
    cin >> nomina[x].id;
    cout << "ingrese nombre :";
    cin >> nomina[x].nombre;
    cout << "ingrese salario ordinario :";
    cin >> nomina[x].salariOrdinario;
    cout << "ingrese horas trabajadas :";
    cin >> nomina[x].horasTrabajadas;
    cout << "ingrese pago por hora :";
    cin >> nomina[x].pagoPorHora;
    cout << "ingrese eps :";
    cin >> nomina[x].eps;
    cout << "ingrese fondo de pensiones :";
    cin >> nomina[x].fpensiones;
  }
}
/*1.Desarrollar una aplicación que permita generar el proceso de pago de nomina
para una empresa que paga a sus trabajadores por horas. Tenga en cuenta que
cuando las horas pasan de 40 se consideran horas extras y se pagan al doble de
una hora ordinaria. Por otro lado a cada empleado se le descuenta 4% por salud,
4% por pensiónSe deben implementar los siguientes procesos 1.Ingresar datos de
nomina (Id, nombre del trabajador, horas trabajadas, valor hora)
2. Calcular nomina se debe generar un desprendible de pago con el nombre del
empleado, horas ordinarias trabajadas, horas extras, valor de la hora, salario
ordinario, salario horas extras, descuento por salud y pensión, neto a pagar.
3. Consultas
1. consulta a un empleado (Ingresar el nombre y mostrar todos sus datos)
2. reporte nomina (Mostrar el nombre del empleado, las horas trabajadas, el
salario ordinario, Horas extras, salario extra, descuentos (salud y
pensión),neto a pagar. Indicar el total de la nómina)
3. Reporte horas extras (mostrar el nombre del empleado, la cantidad de horas
extras y el pago por las horas extras. Indicar el promedio de horas extras y el
porcentaje de trabajadores que no hicieron horas extras.)
4. Información Banco
4.1 Generar un archivo de texto al banco (Nombre, Id, salario neto a pagar)
4.2 Imprimir Archivo de texto enviado al banco
5. Pago de Pila
5.1 Generar archivo de texto para pago de pila (ID, nombre, aporte salud, eps,
pensión, empresa administradora de fondos de pensiones 5.2 Imprimir archivo
pila*/
void calnomina(struct empleado nomina[], int n) {
  for (int x = 0; x < n; x++) {
    nomina[x].salud = nomina[x].salariOrdinario * 0.04;
    nomina[x].pension = nomina[x].salariOrdinario * 0.04;
    if (nomina[x].horasTrabajadas > 40) {
      nomina[x].horasExtras = nomina[x].horasTrabajadas - 40;
      nomina[x].salarioextra =
          nomina[x].horasExtras * nomina[x].pagoPorHora * 1.5;
    } else {
      nomina[x].horasExtras = 0;
      nomina[x].salarioextra = 0;
    }

    nomina[x].totalpagar = nomina[x].salarioextra + nomina[x].salariOrdinario -
                           (nomina[x].salud + nomina[x].pension);

    cout << "Empleado :" << nomina[x].nombre << endl;
    cout << "pension :" << nomina[x].pension << endl;
    cout << "salud a " << nomina[x].eps << " :" << nomina[x].salud << endl;
    cout << "salario ordinario :" << nomina[x].salariOrdinario << endl;
    cout << "salario extra :" << nomina[x].salarioextra << endl;
    cout << "horas extras :" << nomina[x].horasExtras << endl;
    cout << "Neto a pagar :" << nomina[x].totalpagar << endl;
    getchar();
  }
}
// case 3
void consultas(struct empleado nomina[], char nombre[100], int n) {
  for (int x = 0; x < n; x++) {
    if (strcmp(nomina[x].nombre, nombre) == 0) {  // comparar cadenas
      cout << "id :" << nomina[x].id << endl;
      cout << "nombre :" << nomina[x].nombre << endl;
      cout << "salario ordinario :" << nomina[x].salariOrdinario << endl;
      cout << "horas trabajadas :" << nomina[x].horasTrabajadas << endl;
      cout << "pago por hora :" << nomina[x].pagoPorHora << endl;
      cout << "eps :" << nomina[x].eps << endl;
      cout << "fondo de pensiones :" << nomina[x].fpensiones << endl;
    }
  }
}

void banco(struct empleado nomina[], int n) {
  int opc;

  do {
    cout << " 1) generar Archivo de texto al banco :" << endl;
    cout << " 2) imprimir Archivo :" << endl;
    cout << " 3 salir " << endl;
    cin >> opc;
    switch (opc) {
      case 1: {
        ofstream archivoBanco("banco.txt");
        if (!archivoBanco) {
          cout << "Error al abrir" << endl;
          return (0);
        }

        for (int x = 0; x < n; x++) {
          archivoBanco << "ID: " << nomina[x].id
                       << ", Nombre: " << nomina[x].nombre
                       << ", Salario Neto a Pagar: " << nomina[x].totalpagar
                       << endl;
        }
        archivoBanco.close();
        cout << "Archivo de banco generado exitosamente." << endl;
        break;
      }

      case 2: {
        ifstream archivoBanco("banco.txt");
        if (!archivoBanco) {
          cout << "Error al abrir el archivo." << endl;
          return (0);
        }

        string linea;
        cout << "Contenido del archivo del banco:" << endl;
        while (getline(archivoBanco, linea)) {
          cout << linea << endl;
        }

        archivoBanco.close();
        cout << "Archivo del banco leído exitosamente." << endl;
        break;
      }
    }
  } while (opc != 3);
}

int main() {
  int empleados;

  cout << "cantidad de de empleados :";
  cin >> empleados;
  empleado nomina[empleados];
  int opc;
  do {
    opc = menu();

    switch (opc) {
      case 1: {
        ingresar(nomina, empleados);
        break;
      }
      case 2: {
        calnomina(nomina, empleados);
        break;
      }
      case 3: {
        char nombre[100];
        cout << "ingrese nombre a consultar :";
        cin >> nombre;
        consultas(nomina, nombre, empleados);
        break;
      }
      case 4: {
        banco(nomina, empleados);
        break;
      }
      case 5: {
        break;
      }
    }

  } while (opc != 6);

  return 0;
}