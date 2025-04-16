
#include <iostream>
#include <locale.h>
using namespace std;
int main() {
    setlocale(LC_ALL, "Spanish");//Permite usar caracteres especiales del español como la ñ o las tildes
int numero,numeroe1,numeroe2;
cout << "Programa que muestra el número de la izquierda y de la derecha de un número de tres cifras y la suma de los números individualmente"<<endl;
cout << "Introduzca un número: ";
cin >> numero;

while(numero>=1000 or numero<=0)
{
    cout << "Introduzca un número de tres cifras positivo: ";
    cin >> numero;
}
numeroe1= numero %10;
numeroe2 =numero/100;


cout << "El número izquierda es: " << numeroe2<<endl;
cout << "El número derecha es: " << numeroe1<<endl;
cout << "suma de numeros individualmente:"<<(numero/100)+((numero/10)%10)+(numero%10);
return 0;


}
