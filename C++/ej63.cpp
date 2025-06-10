#include <iostream>
using namespace std;
int main (){
    for (int i=1;i < 1000;i++)
    {   
        long long cuadrado = (long long)i * i;
        int copia = i;
        bool automorfo = true;

        // Comparar los últimos dígitos de cuadrado con los dígitos de i
        while (copia > 0) {
            if (copia % 10 != cuadrado % 10) {
                automorfo = false;
                break;
            }
            copia /= 10;
            cuadrado /= 10;
        }

        if (automorfo) {
            cout << i << " es un número automorfo" << endl;
        }
    }
    return 0;
}