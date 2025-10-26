#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n ;
    bool primo;
    cout <<" ingrese un numero :";
    cin >> n;
    for (int i=2;i <= n;i++){
        primo=true;
        for (int x=2;x <= sqrt(i);x++)
        {
            if (i %x==0){
                 primo=false;break;
                //cout <<"el numero "<<i<<"es compuesto"<<endl;
            }
        }
            
      if (primo){
                
                cout<<i<<"es primo"<<endl;
            }
            else {;
                cout <<i<<"es compuesto"<<endl;
            }  
    }

    return 0;
}