#include <iostream>
#include <windows.h> // Para usar SetConsoleOutputCP y forzar UTF-8
#include <clocale>   // Para usar setlocale y poder usar acentos
#include <cstdlib>   // Para system("cls") y system("pause")

int main() {
    using std::cout;
    using std::cin;
    using std::string;
    using std::endl;
    using std::getline;
    

    SetConsoleOutputCP(65001);         
    setlocale(LC_ALL, "Spanish");  
     

    int d1=0, d2=0, d3=0;
    char l1, l2, l3, n1, n2, n3;
    char tipov;

    cout << "Ingrese el tipo de vehículo (C para carro, M para moto): ";
    cin >> tipov;

    if (tipov == 'C' || tipov == 'c') 
    {
        cout << "El vehículo es un carro" << endl;
        cout << "Ingrese la placa del vehículo (3 letras y 3 números): ";
        cin >> l1 >> l2 >> l3 >> n1 >> n2 >> n3;

        cout << "La placa del vehículo es: " << l1 << l2 << l3 << n1 << n2 << n3 << endl;
        
        if (
            ((l1 >= 'A' && l1 <= 'Z') || (l1 >= 'a' && l1 <= 'z')) &&
            ((l2 >= 'A' && l2 <= 'Z') || (l2 >= 'a' && l2 <= 'z')) &&
            ((l3 >= 'A' && l3 <= 'Z') || (l3 >= 'a' && l3 <= 'z')) &&
            (n1 >= '0' && n1 <= '9') &&
            (n2 >= '0' && n2 <= '9') &&
            (n3 >= '0' && n3 <= '9')
        ) {
            cout << "La placa es correcta" << endl;
            //conversion de caracteres a enteros con codigo ascii
            d1 = n1 - '0';
            d2 = n2 - '0'; 
            d3 = n3 - '0';
            cout << "Los números de la placa son: " << d1 << d2 << d3 << endl;

            // Valida pico y placa según el ultimo digito (n3 convertido)
            if (d3 == 1 || d3 == 2)
            {
                cout << "Pico y placa: Lunes y Sabado" << endl;
            }
            else if (d3 == 3 || d3 == 4)
            {
                cout << "Pico y placa: Martes y Sabado" << endl;
            }
            else if (d3 == 5 || d3 == 6)
            {
                cout << "Pico y placa: Miércoles y Sabado" << endl;
            }
            else if (d3 == 7 || d3 == 8)
            {
                cout << "Pico y placa: Jueves y Sabado" << endl;
            }
            else if (d3 == 0 || d3 == 9)
            {
                cout << "Pico y placa: Viernes y Sabado" << endl;
            }
                if ((n1 +n2) % 2 == 0)
                {
                    cout << "no podra circular en la mañana de 07:00 a 09:00"<<endl;
                }
                else 
                cout << "no podra circular en la mañana de  09:00 a 11:00"<<endl;
                if((n2 +n3) % 2 == 0)
                {
                    cout << "no podra circular en el medio dia de 11:00 a 13:00"<<endl;
                }
                else
                cout << "no podra circular en el medio dia de 13:00 a 15:00"<<endl;
                if (n2 % 2 == 0)
                {
                    cout << "no podra circular en la noche de 18:00 a 19:00"<<endl;
                }
                else
                cout << "no podra circular en la noche de 19:00 a 20:00"<<endl;
        }
         else {
            cout << "La placa es incorrecta" << endl;
            return 0;
        }

    } 
    
    else if (tipov == 'M' || tipov == 'm') 

    {
        cout << "El vehículo es una moto" << endl;
        cout << "Ingrese la placa del vehículo (3 letras y 2 números): ";
        cin >> l1 >> l2 >> l3 >> n1 >> n2;

        if (
            ((l1 >= 'A' && l1 <= 'Z') || (l1 >= 'a' && l1 <= 'z')) &&
            ((l2 >= 'A' && l2 <= 'Z') || (l2 >= 'a' && l2 <= 'z')) &&
            ((l3 >= 'A' && l3 <= 'Z') || (l3 >= 'a' && l3 <= 'z')) &&
            (n1 >= '0' && n1 <= '9') &&
            (n2 >= '0' && n2 <= '9')
            ) 
        
        {
            cout << "La placa es correcta" << endl;


                 if (d1 == 1 || d1 == 2)
                 {
                cout << "Pico y placa: Lunes y Sabado" << endl;
            }
            else if (d1 == 3 || d1 == 4)
            {
                cout << "Pico y placa: Martes y Sabado" << endl;
            }
            else if (d1 == 5 || d1 == 6)
            {
                cout << "Pico y placa: Miércoles y Sabado" << endl;
            }
            else if (d1 == 7 || d1 == 8)
            {
                cout << "Pico y placa: Jueves y Sabado" << endl;
            }
            else if (d1 == 0 || d1 == 9)
            {
                cout << "Pico y placa: Viernes y Sabado" << endl;
            }

              
                if (n1 % 2 == 0)
                {
                    cout <<"no podra circular en la mañana de 07:00 a 09:00"<<endl;
                }
                else
                {
                cout <<"no podra circular en la mañana de 09:00 a 11:00"<<endl;
                }
                if (n2 % 2 == 0)
                {
                    cout <<"no podra circular en la tarde de 11:00 a 13:00"<<endl;
                }
                else 
                cout <<"no podra circular en la tarde de 13:00 a 15:00"<<endl;

                if ((n1 + n2) % 2 == 0)
                {
                    cout <<"no podra circular en la noche de 18:00 a 19:00"<<endl;
                }
                else
                {
                cout <<"no podra circular en la noche de 19:00 a 20:00"<<endl;
                }
        }
        
        else 
        {
            cout << "La placa es incorrecta" << endl;
            return 0;
        }

    } 
    
    else
    
    {
        cout << "Tipo de vehículo no válido" << endl;
        return 0;
    }

    return 0;
}
