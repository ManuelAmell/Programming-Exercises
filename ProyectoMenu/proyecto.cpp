#include <iostream> //libreria estandar 
#include <windows.h> // Para usar SetConsoleOutputCP y forzar UTF-8 en la terminal
#include <string>   // Para usar string y empty
#include <cstdlib>  //para usar system("cls") y limpiar pantalla y system("pause") para pausar la //ejecucion del programa 
#include <iomanip>  // Para usar setprecision
#include <clocale>  //para usar setlocale y poder usar acentos y otros caracteres

    //no se usa using namespace std; por que es una mala practica y puede causar conflictos de nombres

    using std::cout;// Para usar cout <<
    using std::cin;// Para usar cin >>
    using std::string;// Para usar string 
    using std::endl;// Para usar endl 
    using std::fixed;// Para usar fixed
    using std::setprecision;// Para usar setprecision (numero de decimales)
    using std::getline;// Para usar getline 
    using std::setw;//para predefinir con espacios
    using std::left;//para alinear ala izquierda

int main(){
    int opcionm1;
    string nombrec;
    SetConsoleOutputCP(65001); // Fuerza UTF-8 para imprimir ñ y tildes

    cout << "\033[32mMY HOME\033[0m\n";
    cout << "bienvenido \n";
    cout << "Ingrese nombre del cliente :";
    getline(cin,nombrec);

    if (nombrec.empty())
    {
        cout << "\033[31mnombre invalido \033[0m\n";
        cout <<"Saliendo..";
        Sleep(1500);
        exit (0);
    }
    cout << "bienvenido SR@ " << "\033[94m" << nombrec << "\033[0m\n";

    // Encabezados
    cout << left << setw(30) << "Tipo de vivienda"
         << setw(20) << "En obra negra"
         << setw(25) << "Acabados sencillos"
         << setw(25) << "Acabados especiales" << endl;

    cout << string(100, '-') << endl;

    // Filas de la tabla
    cout << left << setw(30) << "1) De un piso colindante"
         << setw(20) << "$75.000.000"
         << setw(25) << "$85.000.000"
         << setw(25) << "$90.000.000" << endl;

    cout << left << setw(30) << "2) De dos pisos colindante"
         << setw(20) << "$85.000.000"
         << setw(25) << "$95.000.000"
         << setw(25) << "$100.000.000" << endl;

    cout << left << setw(30) << "3) De un piso esquinera"
         << setw(20) << "$80.000.000"
         << setw(25) << "$90.000.000"
         << setw(25) << "$95.000.000" << endl;

    cout << left << setw(30) << "4) De dos pisos esquinera"
         << setw(20) << "$90.000.000"
         << setw(25) << "$100.000.000"
         << setw(25) << "$105.000.000" << endl;

         cout <<endl;
         cout <<endl;

         cout << "Que tipo de vivienda deseea?\n";
         cout <<endl;
         cout << "\033[92m 1)\033[0m"<<"De un piso colindante \n";
         cout << "\033[92m 2)\033[0m"<<"De dos pisos colindante\n";
         cout << "\033[92m 3)\033[0m"<<"De un piso esquinera\n";
         cout << "\033[92m 4)\033[0m"<<"De dos pisos esquinera\n";
         cin >> opcionm1;

         if (opcionm1 < 0 || opcionm1 > 4)
         {
            cout << "\033[31mDato invalido \033[0m\n";
            cout <<"Saliendo..";
            Sleep(1500);
            exit (0);
         }

         switch (opcionm1)
         {

         case 1:
         {

            break;
         }
         case 2:
         {

            break;
         }
         case 3:
         {

            break;
         }
         case 4:
         {

            break;
         }
        }//fin del switch del menu1



    return 0;
}