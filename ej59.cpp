#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
    long long  n,p;
    bool primo;
    do {
       cout << "ingrese n";
       cin >>n;
        primo = true;
        if (n<2){
            primo=false;
            cout <<"ingrese un numero mayor que  1 "<<endl;
        }
        
        for (int i = 2;i <= sqrt(n);i++){
            
            if (n % i== 0){
                primo =false;
            }

        }
        if (!primo){
            cout <<"el numero ingresado no es primo"<<endl;
        }
        }while(!primo);

         p=(pow (2,n)-1);
         primo = true;
       
        for(long long x = 2; x <= sqrt(p);x++){
            if (p % x == 0){
                primo = false;break;
            }
        }
        if (primo){
            cout << "es un primo de mersenne:"<<p;;
        }
        else {
            cout << "no es un primo de mersenne";
        }
    
    return 0;
}