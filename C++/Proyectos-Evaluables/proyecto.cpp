#include <windows.h>  // Para usar SetConsoleOutputCP y forzar UTF-8 en la terminal

#include <clocale>  //para usar setlocale y poder usar acentos y otros caracteres
#include <cstdlib>  //para usar system("cls") y limpiar pantalla y system("pause") para pausar la //ejecucion del programa
#include <iomanip>  // Para usar setprecision
#include <iostream>  //libreria estandar
#include <string>    // Para usar string y empty

// no se usa using namespace std; por que es una mala practica y puede causar
// conflictos de nombres

using std::cin;           // Para usar cin >>
using std::cout;          // Para usar cout <<
using std::endl;          // Para usar endl
using std::fixed;         // Para usar fixed
using std::getline;       // Para usar getline
using std::left;          // para alinear ala izquierda
using std::setprecision;  // Para usar setprecision (numero de decimales)
using std::setw;          // para predefinir con espacios
using std::string;        // Para usar string

int main() {
  int estrato;
  long cedula;
  long long ingresos_M;
  int opcionm1, opcionm2;
  long long precioV;
  string nombrec;
  float recargos = 0;
  int jardin = 0, piscina = 0;
  long long cuota_inicial = 0;         // estas variables aun no se han usado
  int tiempo_financiacion, meses = 0;  // estas variables aun no se han usado
  double interes_A, interes_M;         // estas variables aun no se han usado

  SetConsoleOutputCP(65001);  // Fuerza UTF-8 para imprimir � y tildes

  cout << "\033[32mMY HOME\033[0m\n";
  cout << "Bienvenido \n";
  cout << "Ingrese nombre del cliente :";
  getline(cin, nombrec);

  if (nombrec.empty()) {
    cout << "\033[31mnombre invalido \033[0m\n";
    cout << "Saliendo...";
    Sleep(1500);
    return (0);
  }
  cout << "Ingrese la cedula del cliente (Solo se aceptan diez digitos): \n";
  cin >> cedula;

  if (cin.fail() || cedula < 1 ||
      cedula > 9999999999)  // solo funciona hasta 10 digitoslo cual es
                            // suficientey detecta si la entrada es invalida
  {
    cout << "\033[31 Cedula  invalida o vacia solo se aceptan diez digitos "
            "\033[0m\n";
    cout << "Saliendo...";
    Sleep(1500);
    return (0);
  }

  cout << "bienvenido SR@ " << "\033[94m" << nombrec << "\033[0m\n";

  cout << "Por favor, ingrese su estrato social :";  // Validar que el usuario
                                                     // este en el rango de los
                                                     // estratos a beneficiar
  cin >> estrato;
  if (estrato < 1 || estrato > 3) {
    cout << "No cumple los requisitos...";
    cout << "Saliendo..";
    Sleep(1500);
    return (0);
  }
  cout
      << "Ingrese sus ingresos mensuales (Personales o Familiares)\n";  // Validar
                                                                        // que
                                                                        // el
                                                                        // usuario
                                                                        // cumpla
                                                                        // los
                                                                        // requisitos
                                                                        // de
                                                                        // ingresos
                                                                        // mensuales
  cin >> ingresos_M;

  if (ingresos_M < 2300000 || ingresos_M > 3500000) {
    cout << "No cumple los requisitos...";
    cout << "Saliendo..";
    Sleep(1500);
    return (0);
  }

  // Encabezados
  cout << left << setw(30) << "Tipo de vivienda" << setw(20) << "En obra negra"
       << setw(25) << "Acabados sencillos" << setw(25) << "Acabados especiales"
       << endl;

  cout << string(100, '-') << endl;

  // Filas de la tabla
  cout << left << setw(30) << "1) De un piso colindante" << setw(20)
       << "$75.000.000" << setw(25) << "$85.000.000" << setw(25)
       << "$90.000.000" << endl;

  cout << left << setw(30) << "2) De dos pisos colindante" << setw(20)
       << "$85.000.000" << setw(25) << "$95.000.000" << setw(25)
       << "$100.000.000" << endl;

  cout << left << setw(30) << "3) De un piso esquinera" << setw(20)
       << "$80.000.000" << setw(25) << "$90.000.000" << setw(25)
       << "$95.000.000" << endl;

  cout << left << setw(30) << "4) De dos pisos esquinera" << setw(20)
       << "$90.000.000" << setw(25) << "$100.000.000" << setw(25)
       << "$105.000.000" << endl;

  cout << endl;
  cout << endl;

  cout << "Que tipo de vivienda deseea?\n";
  cout << endl;
  cout << "\033[92m 1)\033[0m" << "De un piso colindante \n";
  cout << "\033[92m 2)\033[0m" << "De dos pisos colindante\n";
  cout << "\033[92m 3)\033[0m" << "De un piso esquinera\n";
  cout << "\033[92m 4)\033[0m" << "De dos pisos esquinera\n";
  cin >> opcionm1;

  if (opcionm1 < 0 || opcionm1 > 4) {
    cout << "\033[31mDato invalido \033[0m\n";
    cout << "Saliendo..";
    Sleep(1500);
    return (0);
  }

  cout << "Que tipo de acabados desea deseea?\n";
  cout << endl;
  cout << "\033[92m 1)\033[0m" << "En obra negra \n";
  cout << "\033[92m 2)\033[0m" << "Acabados sencillos\n";
  cout << "\033[92m 3)\033[0m" << "Acabados especiales\n";
  cin >> opcionm2;

  if (opcionm2 < 0 || opcionm2 > 3) {
    cout << "\033[31mDato invalido \033[0m\n";
    cout << "Saliendo..";
    Sleep(1500);
    return (0);
  }

  switch (opcionm1) {
    case 1: {
      switch (opcionm2) {
        case 1: {
          precioV = 75000000;
          break;
        }
        case 2: {
          precioV = 85000000;
          break;
        }
        case 3: {
          precioV = 90000000;
          break;
        }
      }
      break;
    }  // termina case 1
    case 2: {
      switch (opcionm2) {
        case 1: {
          precioV = 85000000;
          break;
        }
        case 2: {
          precioV = 95000000;
          break;
        }
        case 3: {
          precioV = 100000000;
          break;
        }
      }
      break;
    }  // termina case 2
    case 3: {
      switch (opcionm2) {
        case 1: {
          precioV = 80000000;
          break;
        }
        case 2: {
          precioV = 90000000;
          break;
        }
        case 3: {
          precioV = 95000000;
          break;
        }
      }
      cout << "�Qu� tipo de jard�n desea?\n1) Grande (15%)\n2) Peque�o (10%)\n";
      cin >> jardin;
      if (jardin == 1)  // tambien se podia usar switch es un poco menos
                        // eficiente como esta pero se dejo para variar
      {
        recargos += precioV * 0.15;
      } else if (jardin == 2) {
        recargos += precioV * 0.10;
      } else {
        cout << "\033[31mDato invalido \033[0m\n";
        cout << "Saliendo..";
        Sleep(1500);
        return (0);
      }
      cout << "�Desea vista a la piscina? (1 = S�, 0 = No): ";
      cin >> piscina;
      if (piscina == 1) {
        recargos += precioV * 0.05;
      }
      break;
    }  // termina case 3
    case 4: {
      switch (opcionm2) {
        case 1: {
          precioV = 90000000;
          break;
        }
        case 2: {
          precioV = 100000000;
          break;
        }
        case 3: {
          precioV = 105000000;
          break;
        }

      }  // termina swtich
      cout << "�Qu� tipo de jard�n desea?\n1) Grande (15%)\n2) Peque�o (10%)\n";
      cin >> jardin;
      if (jardin == 1) {
        recargos += precioV * 0.15;
      } else if (jardin == 2) {
        recargos += precioV * 0.10;
      } else {
        cout << "\033[31mDato invalido \033[0m\n";
        cout << "Saliendo..";
        Sleep(1500);
        return (0);
      }

      cout << "�Desea vista a la piscina? (1 = S�, 0 = No): ";
      cin >> piscina;
      if (piscina == 1) {
        recargos += precioV * 0.05;
      }
      break;
    }  // termina case 4

  }  // fin del switch del menu1

  cuota_inicial = precioV * 0.3;
  cout << "Ingrese la cantidad de a�os de financiacion con la que pagar�\n ( 5 "
          "a�os )\n ( 7 a�os )\n ( 10 a�os )\n ";
  cin >> tiempo_financiacion;

  if (tiempo_financiacion != 5 || tiempo_financiacion != 7 ||
      tiempo_financiacion !=
          10)  // validador de entrada de tiempo de financiacion
  {
    cout << "\033[31mDato invalido \033[0m\n";
    cout << "Saliendo..";
    Sleep(1500);
    return (0);
  }
  switch (tiempo_financiacion) {
    case 5: {
      interes_A = 0;  // temporalmente mientras se espera una respuesta de
                      // nohemy
      break;
    }
    case 7: {
      interes_A = 0;  // temporalmente mientras se espera una respuesta de
                      // nohemy
      break;
    }
    case 10: {
      interes_A = 0;  // temporalmente mientras se espera una respuesta de
                      // nohemy
      break;
    }

  }  // fin del switch de meses de financiacion

  interes_M =
      interes_A / 12;  // Calculo del interes mensual en base a el interes anual
  meses = tiempo_financiacion * 12;

  return 0;
}
