#include <iostream>
using namespace std;
void menu(int &opc){
    do{
    cout<<"1) cargar arreglo :"<<endl;
    cout <<"2) imprimir arreglo "<<endl;
    cout <<" 3) imprimir el arreglo alreves :"<<endl;
    cout <<"4) Buscar elemento  :"<<endl;
    cout <<"5) ordenar arreglo :"<<endl;
    cout <<"6 )calcular estadisticas  :"<<endl;
    cin>>opc;
    }while(opc <1 && opc >6);
}

void CargarArreglo(int arr[],int n){
for (int i=0; i < n;i++)
{
    cout << "elemento #"<<i+1<<" :";
    cin >>arr[i];
}

}
void ImprimirArreglo(int arr[],int n){
    for (int i=0;i < n;i++)
    {
        cout << arr[i]<<"  ";
    }
    cout << endl;
}
void ImprimirArregloAlrevez(int arr[],int n){
    for (int i=n-1; i>=0;i--)
    {
        cout << arr[i]<< " ";
    }
    cout<<endl;
}


int main (){
int n;
int opc;
cout <<" ingrese n :";
cin>>n;
int arreglo[n];
do{
    menu(opc);

switch (opc)
{
case 1:
    CargarArreglo(arreglo,n);break;

case 2:ImprimirArreglo(arreglo,n);break;

case 3:ImprimirArregloAlrevez(arreglo,n);break;

case 4:
break;
case 5:break;

case 6:
break;
case 7:
break;

}
}while(opc !=7);


    return 0;
}