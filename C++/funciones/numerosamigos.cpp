#include <iostream>
#include <cstdlib>
#include <limits>
using   namespace std;

void cls() {//para el que compatibilidad con windows o UNIX a quien le interese
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
int leernumero(){
    int n;
    
    do{
    cout <<"ingrese un numero:";
    cin >>n;
            if (cin.fail()) {//para datos ingresados no esperados del tipo de dato
            cin.clear(); // limpia estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); /*limpia el buffer y es la unica manera*/ 
            cout << " Error: debe ingresar un numero entero." << endl;/*confiable que encontre para que no crashe con letras*/
            n = -1; // repite el ciclo
        }
        else if (n <= 0) {
            cout << "Error: el numero debe ser positivo." << endl;
        }

    }while(n <=0);

    return n;
}


int divisores(int x){
        long y=0;

    for (int i=1;i <= x;i++){
        if (x%i==0){
            y+=i;
            //cout << i<<" + "; para ver los divisores;
        }
    }
    //cout << " = "tambien descomentar en conjunto con la linea anterior 
    return y;
}


bool amigos(int x,int y,long z,long w){
if (z==w){
    return true;
}
else {
    return false ;
}
}

int main (){


int n1=leernumero();

double y1=divisores(n1);

cout << " el numero "<<1<<" es :"<<n1<<" y la suma de sus divisores es :"<<y1<<endl; 


int n2=leernumero();

double y2=divisores(n2);
cout << " el numero "<<2<<" es :"<<n2<<" y la suma de sus divisores es :"<< y2<<endl; 


bool resultado=amigos(n1,n2,y1,y2);
cls;

if (resultado)
{
    cout <<n1<< " (n1) es amigo de "<<n2<<" (n2) por que :"<<y1<<" = "<<y2<<"  por lo tanto son amigos"<<endl ;
}
else {
    cout <<n1<< " (n1) NO es amigo de "<<n2<<" (n2) por que :"<<y1<<" != "<<y2 <<" (suma DIVISORES DE "<<n1<<" y "<<n2<<")"<<" por lo tanto no son amigos "<<endl;
}
    return 0;
}