#include <iostream>
#include <limits>
using namespace std;

    float peso1;
    float imc_result;
    float altura1;

    void peso(){
do{
    cout <<"ingrese peso ";
    cin >>peso1;
if (cin.fail() || peso1 < 0) {
    cin.clear();
    // Descarta todos los caracteres hasta encontrar un salto de línea ('\n')
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    system("clear");
}
}while(peso1<0 || cin.fail());
}

 void altura(){
    do{
        cout << "ingrese altura ";
        cin >> altura1;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }while(altura1 < 0 || cin.fail());
}

float potencia(float base, float exponente) {
    float resultado = 1;
    for (int i = 0; i < exponente; i++) {
        resultado *= base;
        cout << "potencia altura ="<<resultado;
    }
    return resultado;
}
float imc(float peso, float altura1) {
    if (altura == 0) {
        cerr << "Error: altura no puede ser cero." << endl;
        return -1;  // Valor de error
    }
    return peso / (altura1 * altura1);
}

int main(){
    int N;
    cout << "ingrese cantidad de personas:";
    cin >>N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');//para limpiar el buffer 100%

    char nombre [50];
    for (int i=0;i < N ;i++)
    {cout << "ingrese el nombre :";
        cin.getline(nombre,50);
        peso();
        altura();
        cout <<"altura x altura = ";
        potencia(altura1,2);
        cout <<endl;
        cout << "indice de masa corporal es :";
        imc_result = imc(peso1, altura1);
        cout << imc_result << endl;
    }

    return 0;
}