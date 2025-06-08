#include <iostream>
#include <iomanip>
using namespace std;
int main (){

    int f=0,n=0,e=0,s=0;
    int dr,madr=-1,medr=99999;
    int tipo,preciot,recargot;
    string ncliente ,mecliente,macliente;
    
    int  cliente;
    long double total=0,totalt=0,tdiasr=0,nrecargo=0;

    do{
    cout <<"ingrese el total de clientes :";
    cin >> cliente;
     cin.ignore();
    }
    while(cliente <= 0);
    for(int i=0; i< cliente;i++){
        cout <<"ingrese el nombre del cliente :";
        getline(cin,ncliente);
       

         // Encabezado
    cout << left
         << setw(10) << "CODIGO"
         << setw(20) << "CATEGORIA"
         << setw(15) << "PRECIO"
         << setw(25) << "RECARGO/DIA DE ATRASO" << endl;

    // Datos
    cout << left
         << setw(10) << "1"
         << setw(20) << "FAVORITOS"
         << setw(15) << "$2500"
         << setw(25) << "$500" << endl;

    cout << left
         << setw(10) << "2"
         << setw(20) << "NUEVOS"
         << setw(15) << "$3000"
         << setw(25) << "$750" << endl;

    cout << left
         << setw(10) << "3"
         << setw(20) << "ESTRENOS"
         << setw(15) << "$3500"
         << setw(25) << "$1000" << endl;

    cout << left
         << setw(10) << "4"
         << setw(20) << "SUPER ESTRENOS"
         << setw(15) << "$4000"
         << setw(25) << "$1500" << endl;

         cin >>tipo;
         while (tipo <0 || tipo >4)
         {
               // Encabezado
    cout << left
         << setw(10) << "CODIGO"
         << setw(20) << "CATEGORIA"
         << setw(15) << "PRECIO"
         << setw(25) << "RECARGO/DIA DE ATRASO" << endl;

    // Datos
    cout << left
         << setw(10) << "1"
         << setw(20) << "FAVORITOS"
         << setw(15) << "$2500"
         << setw(25) << "$500" << endl;

    cout << left
         << setw(10) << "2"
         << setw(20) << "NUEVOS"
         << setw(15) << "$3000"
         << setw(25) << "$750" << endl;

    cout << left
         << setw(10) << "3"
         << setw(20) << "ESTRENOS"
         << setw(15) << "$3500"
         << setw(25) << "$1000" << endl;

    cout << left
         << setw(10) << "4"
         << setw(20) << "SUPER ESTRENOS"
         << setw(15) << "$4000"
         << setw(25) << "$1500" << endl;
         cout <<"ingrese correctamente el tipo pls :";
         cin >>tipo;
         }
         switch(tipo){

             case 1:{
                preciot=2500;
                recargot=500;
                f++;
                break;
             }
             case 2:{
                preciot=3000;
                recargot=750;
                n++;
                break;
             }
             case 3:{
                preciot=3500;
                recargot=1000;
                e++;
                break;
             }
             case 4:{
                preciot=4000;
                recargot=1500;
                s++;
                break;
             }

             totalt+=preciot;
             cout <<"ingrese la cantidad de dias para la devolucion :";
             cin >>dr;
            

             if (medr<dr) {
                medr =dr;
                mecliente=ncliente;
             }
             if (dr >medr){
                madr=dr;
                macliente=ncliente;
             }

             tdiasr+=dr;
             nrecargo+=(dr*recargot);
         }
    }

    cout <<"clientes que alquilaron:\n";
    cout <<"Favoritos :"<<f<<endl;
    cout <<"Nuevos :"<<n<<endl;
    cout <<"Estrenos :"<<e<<endl;
    cout << "Super estrenos :"<<s<<endl;

    cout << "total recaudado :"<<totalt+nrecargo<<endl;
    cout << "total de clientes :"<<cliente<<endl;
    cout << "porcentaje de clientes que solicitaron peliculas de super estrenos :"<<(s/cliente)*100<<endl;
    cout << "menor cantidad de dias de retraso:"<<medr<<"cliente :"<<mecliente<<endl;
    cout << "mayor cantidad de dias de retraso :"<<madr<<"cliente :"<<macliente<<endl;
    cout <<"total recaudado por diaz de atraso :"<<nrecargo;

    return 0;
}