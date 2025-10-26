#include <iostream>
#include <clocale>  // Para usar setlocale y poder usar acentos y otros caracteres
#include <cstdlib>// Para usar system("cls")
#include <ctime>// Para usar time y localtime
#include <windows.h>
#include <fstream>// Para usar ofstream

using namespace std;

// Función para obtener la fecha y hora actual en formato "YYYY-MM-DD HH:MM:SS"
string obtenerFechaHora() {// Función para obtener la fecha y hora actual
    // en formato "YYYY-MM-DD HH:MM:SS"
    //time_t ahora = time(0);
    time_t ahora = time(0);
    tm *tiempo = localtime(&ahora);
    char buffer[20];

    strftime(buffer, 20, "%Y-%m-%d %H:%M:%S", tiempo);// Formato de fecha y hora
    //strftime convierte la fecha y hora en una cadena de caracteres
    //en el formato especificado
    //strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tiempo);
    //buffer es el búfer donde se almacenará la cadena de caracteres
    //sizeof(buffer) es el tamaño del búfer
    //"%Y-%m-%d %H:%M:%S" es el formato de fecha y hora
    //tiempo es un puntero a una estructura tm que contiene la fecha y hora
    //localtime convierte el tiempo en segundos desde la época (1 de enero de 1970)
    //en una estructura tm que contiene la fecha y hora local

    return string(buffer);// Devuelve la cadena de caracteres
}

int main() {
    SetConsoleOutputCP(65001); // Fuerza UTF-8 para imprimir ñ y tildes
    srand(time(0));  // Semilla para números aleatorios

    int longitud;
    char incluirMayus, incluirMinus, incluirNum, incluirSimbolos;
    
    cout << "Longitud de la contraseña: "<<endl;
    cin >> longitud;

    cout << "¿Incluir mayúsculas? (s/n): "<<endl;
    cin >> incluirMayus;
    cout << "¿Incluir minúsculas? (s/n): "<<endl;
    cin >> incluirMinus;
    cout << "¿Incluir números? (s/n): "<<endl;
    cin >> incluirNum;
    cout << "¿Incluir símbolos? (s/n): "<<endl;
    cin >> incluirSimbolos;

    string caracteres = "";
    if (incluirMayus == 's' || incluirMayus == 'S') caracteres += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";// Agrega mayúsculas

    if (incluirMinus == 's' || incluirMinus == 'S') caracteres += "abcdefghijklmnopqrstuvwxyz";// Agrega minúsculas
    if (incluirNum == 's' || incluirNum == 'S') caracteres += "0123456789";// Agrega números
    if (incluirSimbolos == 's' || incluirSimbolos == 'S') caracteres += "!@#$%^&*";// Agrega símbolos

    if (caracteres.empty()) {// Verifica si no se seleccionó ningún tipo de carácter
        cout << "Debes seleccionar al menos un tipo de carácter." << endl;// Verifica si no se seleccionó ningún tipo de carácter
        return 1;
    }

    string password = "";// Inicializa la contraseña como una cadena vacía
    for (int i = 0; i < longitud; i++) {
        password += caracteres[rand() % caracteres.length()];// Genera un carácter aleatorio
        //rand() genera un número aleatorio entre 0 y RAND_MAX
        //rand() % caracteres.length() genera un número aleatorio entre 0 y la longitud de la cadena de caracteres
    }

    cout << "Contraseña generada: " << password << endl;

    // Guardar en archivo con fecha y hora
    ofstream archivo("passwords.txt", ios::app);// Abre el archivo en modo de adición
    //ios::app abre el archivo en modo de adición
    //si el archivo no existe, se crea
    //si el archivo existe, se agrega al final del archivo
    //ofstream archivo("passwords.txt", ios::out | ios::app);// Abre el archivo en modo de adición
    //ios::out abre el archivo en modo de escritura
    //ios::app abre el archivo en modo de adición
    //ios::out | ios::app abre el archivo en modo de escritura y adición
    //ofstream archivo("passwords.txt", ios::out | ios::trunc);// Abre el archivo en modo de escritura
    //ios::out abre el archivo en modo de escritura

    if (archivo.is_open()) {// Verifica si el archivo se abrió correctamente
        archivo << obtenerFechaHora() << " - " << password << endl;// Escribe la fecha y hora y la contraseña en el archivo
        archivo.close();// Cierra el archivo
        cout << "Contraseña guardada en passwords.txt" << endl;
    } else {
        cerr << "Error al abrir el archivo" << endl;
    }
return 0;  
}
