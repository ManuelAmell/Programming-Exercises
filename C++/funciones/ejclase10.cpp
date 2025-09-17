#include <iostream>
#include <cstdlib>
//hacer con parametros por referencia
using   namespace std;

void contarcolor (int color){
    
static int rojo=0;
static int blancos=0;
static int verde=0;

if (color==1){
    rojo++;
}
else if (color==2){
    blancos++;
}
else if (color==3){
    verde++;
}
system("clear");

}

int leernumero(){
    int n;
    do {
    cout <<"ingrese n :";
    cin >> n;

    }while (n <=0);
    return n;
}
int main (){
    
    int n=leernumero(),color;
   do{
    for (int i=0; i< n;i++){
        cout << "ingrese el color de focos 1)rojo 2)blancos 3 )verde :";
        cin >>color;
    }
    }while(color<1 || color >3);
        contarcolor(color);
    
    

return 0;
} 
