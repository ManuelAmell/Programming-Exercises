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
void BuscarElemento(int arr[],int &n,int &encontrar){
    bool encontrado=false;
    for(int i =0; i < n;i++){
        if (encontrar==arr[i]){
        encontrado=true;
            cout << " el numero "<<encontrar<<" fue encontradoe en la posicion "<<i+1<<endl;
        }
    }
    if (!encontrado){ cout << " el numero "<<encontrar<<" no pertenece al arreglo"<<endl;}
}
void OrdenarAscendente(int arreglo[],int &n){
    cout << " arreglo original:"<<endl;
    for (int i=0;i < n;i++){
        cout <<"["<<arreglo[i]<<"]  ";
    }
    cout << endl;
     for ( int i=0;i < n-1 ;i++ )
    {
        bool orden=false;
        
        for ( int x=0;x < n-i-1;x++ )
        {
            if (arreglo[x] > arreglo[x+1]) // el signo determina el orden si es mayor o menor
            {   //swap(arr[x],arr[x+1]);//no valido en clase y mas facil
                int aux= arreglo[x];
                arreglo[x]= arreglo[x+1];
                arreglo[x+1]= aux;
                orden=true;
            }
        }
        if (!orden){
                break;
            }
    }
    cout<< " arreglo ordenado :"<<endl;
    for (int i=0;i < n;i++){
        cout <<"["<<arreglo[i]<<"]  ";
    }
    cout << endl;
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

case 3:
ImprimirArregloAlrevez(arreglo,n);break;

case 4:
int encontrar;
cout << "Numero a buscar :";
cin>> encontrar;
BuscarElemento(arreglo,n,encontrar);break;
break;

case 5:OrdenarAscendente(arreglo,n);break;
break;
case 6:
break;
}
}while(opc !=7);


    return 0;
}