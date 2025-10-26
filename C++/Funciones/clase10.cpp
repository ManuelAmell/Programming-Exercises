//Primer codigo de la clase
#include <iostream>
using namespace std;

int funcion1(int x, int y){
    
    static int a=0;
    for (int j=1;j<=x;j++)
    a++;
    y+=a;
    return y;
}
int main (){
    int a=0,b=0;
    for (int x =1;x<=3;x++)
    {
        a=funcion1(x,b++);
        cout <<" a= "<<a<<" b= "<<b<<endl;
    }
    return 0;
}