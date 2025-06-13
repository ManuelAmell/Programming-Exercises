#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
   // cout << "Ingrese un número: ";
    //cin >> n;
for (int n=1;n < 1000;n++)
{
	

    // Calcular cuadrado y cubo
    long long cuadrado = (long long)n * n;
    long long cubo = (long long)n * n * n;

    // Contar dígitos de n
    int cifras = 0, temp = n;
    while (temp > 0) {
        cifras++;
        temp /= 10;
    }

    // Obtener últimos 'cifras' dígitos del cuadrado y del cubo
    long long modulo = pow(10, cifras);
    long long ultimos_cuadrado = cuadrado % modulo;
    long long ultimos_cubo = cubo % modulo;

    // Verificar y mostrar resultados
    //cout << "Cuadrado de " << n << " = " << cuadrado << endl;
  

     if (ultimos_cuadrado == n){
	 
        cout << n << " es AUTOMORFICO (su cuadrado termina en " << n << ")";
		if (ultimos_cubo == n){
		
        cout << n << "  Y es TRIMORFICO (su cubo termina en " << n << ")";
		 cout << endl;continue;
							}
								
							}
    //else
        //cout << n << " NO es automórfico" << endl;

    //cout << "Cubo de " << n << " = " << cubo << endl;
    if (ultimos_cubo == n)
        cout << n << " es TRIMORFICO (su cubo termina en " << n << ")" << endl;
   // else
       // cout << n << " NO es trimórfico" << endl;
    }

    return 0;
}

