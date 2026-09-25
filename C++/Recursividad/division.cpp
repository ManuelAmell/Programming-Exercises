#include <iostream>
using namespace std;

int division(int n, int d){
    if (d == 0){                        // dividir entre 0 no está definido
        cout << " Error: division entre 0 ";
        return 0;
    }
    if (n < 0){                         // si n es negativo: divido con -n (positivo)
        return -division(-n, d);        // y le cambio el signo al resultado
    }
    if (d < 0){                         // lo mismo si d es negativo
        return -division(n, -d);
    }
    // A partir de aquí n >= 0 y d > 0, así que la resta sí acerca n a 0
    if (n >= d){                        // d todavía cabe en n
        return division(n - d, d) + 1;  // quito una d y cuento 1
    }
    return 0;                           // caso base: d ya no cabe en n
}

int main(){
	int n, d;
	cout << "Ingrese numero N a dividir (Numerador) :";cin >>n;
	cout <<"Ingrese numero Divisor (Denominador) :";cin >> d;
	
	cout << "Resultado "<<n <<" / "<<d<<" = "<<division(n , d);
	
	return 0;
}
