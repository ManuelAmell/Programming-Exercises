#include <iostream> //libreria estandar 
#include <windows.h> // Para usar SetConsoleOutputCP y forzar UTF-8 en la terminal
#include <string>   // Para usar string y empty
#include <cstdlib>  //para usar system("cls") y limpiar pantalla y system("pause") para pausar la //ejecucion del programa 
#include <iomanip>  // Para usar setprecision
#include <clocale>  //para usar setlocale y poder usar acentos y otros caracteres
  
int main(){
    //no se usa using namespace std; por que es una mala practica y puede causar conflictos de nombres
    //en proyectos grandes, en este caso no es necesario pero es mejor no usarlo
    
    using std::cout;// Para usar cout <<
    using std::cin;// Para usar cin >>
    using std::string;// Para usar string 
    using std::endl;// Para usar endl 
    using std::fixed;// Para usar fixed
    using std::setprecision;// Para usar setprecision (numero de decimales)
    using std::getline;// Para usar getline 
   
  
    string nombre;
    double sueldo;

    SetConsoleOutputCP(65001); // Fuerza UTF-8 para imprimir ñ y tildes

    cout << "Ingrese su nombre: ";
    getline(cin, nombre); // Cambiado a getline para permitir espacios en el nombre// Permite espacios 

    if( (nombre.empty() || nombre.find_first_not_of(' ') == string::npos)) {// Verifica si el nombre está vacío o solo contiene espacios
        //empty() verifica si el string está vacío y find_first_not_of(' ') verifica si solo contiene espacios
         // Verifica si el nombre está vacío, viene con <string>

        cout << "No se ingresó un nombre válido." << endl;

        return 1; // Salir del programa si no se ingresó un nombre
    }

    system("cls");  // Limpia pantalla (solo en Windows) viene con <cstdlib>
  

    cout << "Hola, " << nombre << "! Bienvenido al programa." << endl;

    cout << "Ingrese su sueldo: ";
    cin >> sueldo;

    if (cin.fail() || sueldo < 0) {

        cout << "Sueldo inválido. Asegúrese de ingresar un número positivo." << endl;
        //cin.fail() verifica si la entrada es válida y sueldo < 0 verifica si el sueldo es negativo
        //.fail() verifica si la entrada es válida y sueldo < 0 verifica si el sueldo es negativo
        // Verifica si la entrada es válida y si el sueldo es negativo
        //Cuando esperas un número pero el usuario mete texto;
        //viene con <iostream> y no es necesario incluir una librería adicional

        cin.clear();               // Limpia el error
        //clear() limpia el estado de error del flujo de entrada
        //viene con <iostream> y no es necesario incluir una librería adicional

        cin.ignore(1000, '\n');    // Limpia el búfer de entrada
        //cin.ignore() descarta los caracteres no válidos en el búfer de entrada,ignora hasta 1000 caracteres o hasta un salto de línea
        //viene con <iostream> y no es necesario incluir una librería adicional
        return 1;
    }

    system("cls");  // Limpia pantalla (Windows)//viene con <cstdlib>

    cout << "Hola, " << nombre << "! Bienvenido al programa." << endl;

    cout << "Su sueldo es: " << fixed << setprecision(2) << sueldo << " pesos." << endl;// Muestra el sueldo con 2 decimales con setprecision(2) y fixed para que no muestre en notacion cientifica


   

    system("pause"); 
    // viene con <cstdlib>
    //system("pause"); // Pausa la consola antes de salir (solo en Windows)
    // Pausa la consola antes de salir//system("clear"); // Limpia pantalla (solo en Linux o Mac)
    //system("read -n 1 -s -p \"Presione cualquier tecla para continuar...\""); // Pausa la consola antes de salir (solo en Linux o Mac)
    
    return 0;
    }