#include <iostream> //funcion iterativa suma de digitos
using namespace std;
int suma (int u)
{
    if (u==0){
        return u;
    }
    else {
        return u%10;
    }

}
int mail(){
    int nro ;
    int opc;
    do {
        cout << "ingrese un numero para calcular la sumatoria de los digitos :";
        cin >> nro;
        cout << "suma de nro" <<nro <<" = "<< suma(nro)<<endl;
        cout << "continuar =1"<<endl;
        cin >> opc;
    }while (opc ==1);

    return 0;
}