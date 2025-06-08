#include <iostream>
using namespace std;
int main (){
    long n,m1,m2,m3,m4;
    cout <<"ingrese un numero de 4 cifras :";
    cin >>n;
    for(int i=0;i < 2;i++){
        m1=n%10;cout <<"m1="<<m1<<endl;

        m2=n%100/10;cout <<"m2="<<m2<<endl;

        m3=n/100%10;cout <<"m3="<<m3<<endl;

        m4 =n/1000;cout <<"m4="<<m4<<endl;
    
        if(m3+m1==m2+m4){
            cout <<"es divisible por 11";break;
        }
        else {
            cout <<"no es divisible por 11";break;
        }
        }
    
    
    return 0;
}