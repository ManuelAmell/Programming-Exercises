#include <iostream>
using namespace std;
int main(){
int n,n2;
int aux=0;
int p=0,c=0;
    cout <<"ingrese cuantos numeros desea ingresar para saber su especialidad";
    cin >>n;

    for (int i=1;i <= n;i++){
        cout <<"ingrese su numero :?\n";
        cin>>n2;
        if (n2 <=1){
            continue;
        }
        for (int x=1;x <=n2;x++)
        {
            if (n2%x==0)
            {
                aux++;
            }
        }
                 if  (aux==2)
                     {
                         p++;
                    }
                 else 
                     {
                        c++;
                     }
                        aux=0;
            }
            cout <<"cantidad de primos :"<<p<<endl;
            cout <<"cantidad de compuestos:"<<c;
    return 0;
}