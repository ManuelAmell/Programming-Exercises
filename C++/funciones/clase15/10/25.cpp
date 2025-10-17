#include <iostream>
#include <limits>
using namespace std;    

long long potencia(int base,int exp) {

    cout<<endl;
    int p=1;

for (int i=1;i <=exp;i++){

    cout << base<<" x "<<p<<endl;
    p*=base;
    
    }

    return p;
}
long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else {
        cout << n<<"x";
        if (n==2){
            cout << "1=";
        }
        return n * factorial(n - 1);
    }
}

int main() { 
    int opc=0;
    do{
    int base;
    int exp;
    cout << "ingrese el numero a potenciar ";
    cin >> base;
    cout << "ingrese el exponente ";
    cin >>exp; 
    cout << "resultado de "<<base <<" ^ "<<exp<<" = " <<potencia(base,exp);
        cout <<endl;
    cout <<"el factorial de "<<base<<endl;
    cout <<factorial(base)<<endl;
   

        cout << "desea ingresar otro numero? 1  :";
        cin >>opc;

        if (cin.fail()) {
            cin.clear(); // limpia el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // descarta entrada inválida
            opc = 0; // termina el programa
        }
    }while(opc==1);
    


    return 0;
}