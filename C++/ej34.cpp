#include <iostream>
#include <string>
#include <windows.h> // Para usar SetConsoleOutputCP y forzar UTF-8
#include <iomanip> // Para usar setprecision y fixed
#include <clocale>  // Para usar setlocale y poder usar acentos y otros caracteres
#include <cstdlib>// Para usar system("cls") y limpiar pantalla y system("pause") para pausar la
int main(){
    using std::cout;
    using std::cin;
    using std::string;
    using std::endl;
    using std::fixed;
    using std::getline;
    using std::setprecision;
    
    string nombre,nombrec;
    int opcion,precio;
    SetConsoleOutputCP(65001); // Para que se vean ñ y tildes
    int v=rand() %9999 +1000;
    int cantidad=0;

    cout << "Ingrese el nombre del vendedor: ";
    getline(cin,nombre);
    cout << "Ingrese el nombre del cliente: ";
    getline(cin,nombrec);
    cout << "Bienvenido al sistema de ventas de abarrotes" << endl;
    cout << "Vendedor: " << nombre << endl; 
    cout << "Cliente: " << nombrec << endl;
    cout << "Seleccione una opcion:" << endl;
    cout <<"1)platos x 1000" << endl;
    cout <<"2)tazas x 2000" << endl;
    cout <<"3)cubiertos x 5000" << endl;
    cout <<"4)cucharas x 3000" << endl;
    cout <<"5)tenedores x 4000" << endl;
    cin >> opcion;
    switch (opcion) {
        case 1:
            cout << "Seleccionaste platos" << endl;
            precio=1000;
            break;
        case 2:
            cout << "Seleccionaste tazas" << endl;
            precio=2000;
            break;
        case 3:
            cout << "Seleccionaste cubiertos" << endl;
            precio=5000;
            break;
        case 4:
            cout << "Seleccionaste cucharas" << endl;
            precio=3000;
            break;
        case 5:
            cout << "Seleccionaste tenedores" << endl;
            precio=4000;
            break;
        default:
            cout << "Opcion no valida" << endl;
            system("pause"); // Pausa el programa para que el usuario vea el mensaje
            return 1; // Salir del programa si la opcion no es valida
             // Salir del programa si la opcion no es valida
    }
    cout <<"cantidad: ";
    cin >> cantidad;
    system("cls");
    cout <<"TIENDA DE ABARROTES" << endl;
    cout << "Vendedor: " << nombre << endl;
    cout << "Cliente: " << nombrec << endl;
    cout << "Numero de venta: " << v << endl;
    cout << "Cantidad de UNIDADES: " << cantidad << endl;
    cout << "El precio unitario es: " << fixed << setprecision(2) << precio  << endl;
    cout << "IVA : " << fixed << setprecision(2) <<(precio*cantidad)*0.19<< endl;
    cout << "El precio total es: " << fixed << setprecision(2) << (precio * cantidad)*1.19  << endl;
    return 0;
}