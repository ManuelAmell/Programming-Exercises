#include <windows.h>  // Para usar SetConsoleOutputCP y forzar UTF-8

#include <clocale>  // Para usar setlocale y poder usar acentos y otros caracteres
#include <cstdlib>  // Para usar system("cls") y limpiar pantalla y system("pause") para pausar la
#include <ctime>    // Para usar time y localtime
#include <fstream>  // Para usar ofstream
#include <iomanip>  // Para usar setprecision y fixed
#include <iostream>
#include <string>
int main() {
  using std::cin;
  using std::cout;
  using std::endl;
  using std::fixed;
  using std::getline;
  using std::ofstream;  // Para usar ofstream
  using std::setprecision;
  using std::string;

  SetConsoleOutputCP(65001);     // Para que se vean ñ y tildes
  setlocale(LC_ALL, "Spanish");  // Para usar acentos y caracteres especiales
  srand(time(NULL));  // Inicializa la semilla para números aleatorios
  cout << fixed << setprecision(2);
  string nv, nc;
  int opcion, c, v = rand() % 9000 + 1000, v1 = 0;

  cout << "ingrese el nombre del venedor: ";
  getline(cin, nv);
  cout << "ingrese el nombre del cliente: ";
  getline(cin, nc);

  cout << "Bienvenido al sistema de ventas de dlores" << endl;
  cout << "Vendedor: " << nv << endl;
  cout << "Cliente: " << nc << endl;
  cout << "Seleccione una opcion:" << endl;
  cout << "1.ROSAS x 1000" << endl;
  cout << "2.LIRIOS x 2000" << endl;
  cout << "3.TULIPANES x 5000" << endl;
  cout << "4.ORQUIDEAS x 3000" << endl;
  cout << "5.GERBERAS x 4000" << endl;
  cin >> opcion;
  switch (opcion) {
    case 1:
      cout << "Seleccionaste ROSAS" << endl;
      v1 = 1000;
      break;
    case 2:
      cout << "Seleccionaste LIRIOS" << endl;
      v1 = 2000;
      break;
    case 3:
      cout << "Seleccionaste TULIPANES" << endl;
      v1 = 5000;
      break;
    case 4:
      cout << "Seleccionaste ORQUIDEAS" << endl;
      v1 = 3000;
      break;
    case 5:
      cout << "Seleccionaste GERBERAS" << endl;
      v1 = 4000;
      break;
    default:
      cout << "Opcion no valida" << endl;
      return (0);
  }
  cout << "cantidad de cajas" << endl;
  cin >> c;
  system("cls");                   // Limpiar pantalla
  ofstream archivo("ventas.txt");  // Abrir el archivo en modo append
  cout << "floristeria" << endl;
  cout << "vendedor: " << nv << endl;
  cout << "cliente: " << nc << endl;

  cout << "numero de compra: " << v << endl;
  cout << "tipo de flor: ";
  switch (opcion) {
    case 1:
      cout << " ROSAS" << endl;
      break;
    case 2:
      cout << "LIRIOS" << endl;
      break;
    case 3:
      cout << "TULIPANES" << endl;
      break;
    case 4:
      cout << " ORQUIDEAS" << endl;
      break;
    case 5:
      cout << " GERBERAS" << endl;
      break;
  }
  cout << "valor de la flor: " << v1 << endl;
  cout << "cantidad de venta: " << c << endl;
  cout << "valor de la venta: " << c * v1 << endl;
  archivo << "floristeria" << endl;
  archivo << "vendedor: " << nv << endl;
  archivo << "cliente: " << nc << endl;
  archivo << "numero de compra: " << v << endl;

  archivo.close();  // Cerrar el archivo
  cout << "Los datos se han guardado en el archivo ventas.txt" << endl;
}