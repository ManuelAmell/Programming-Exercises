#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n;
    bool primo=true;
    cout <<"ingrese un numero :";
    cin>>n;
    for (int i =2;i <=sqrt(n);i++){
        if (n%i==0){
            primo=false;break;
        }
        
    }
    if (primo==true){
        cout <<"esprimes";
    }
    else {
        cout <<"no esprimes";
    }
    return 0;
}