#include <iostream>
using namespace std;
int main (){
    int opc; 
    string dias[]={"lunes","martes","mierccoles","jueves","viernes","sabado","domingo"};
    float n[4][7];
    double s=0;


    for (int x=0; x < 4;x++){

    
    for (int i=0;i < 7;i++){
        cout << "ingrese la temperatura de el dia #"<<i+1<<" :";
        cin >> n[x][i];
    }

     }
     do{
        cout << "1) temperatura promedio x semana  "
             << "2) temperatura promedio diaria "
             << "3) salir \n";
             cin >> opc;
     }while (opc>3 || opc < 1);
     switch (opc)
     {
        case 1:{
                for (int x=0; x < 4;x++){
                    s=0;
                for (int i=0;i < 7;i++){
                s+=n[x][i];
                }
                 cout <<" temperatura promedio semana"<<x+1<<" = " << s /7;
                 s=0;
            }
           
            break;
        }
        case 2 :{
            for (int i =0;i < 7;i++){
                for (int x=0;x < 4;x++){
                        s+=n[x][i];
                }
                float promedio=s/4;
                cout << "temperatura promedio el dia "<<dias[i]<<" : "<<promedio<<endl;
                s=0;
            }
            break;
        }
        default :
        break;
    
     }
 
    return 0;
}