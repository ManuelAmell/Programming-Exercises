#include <iostream>
using namespace std;
int main(){
    int n,m,a=0,b=0;
    cout <<"ingrese n";
    cin >>n;

    cout <<"ingrese m";
    cin >>m;

    while (n == m){
    cout <<"ingrese numeros diferentes\n";
    cout <<"ingrese n :";
    cin >>n;
    cout <<"ingrese m:";
    cin >>m;
    }
    for (int i=1;i <= n/2;i++){
        if(n%i==0){
            a+=i;
        }
    }
    
    for (int i=1;i <= m/2;i++){

        if (m%i==0){
            b+=i;
        }
    }
    if (a==m && b==n){
        cout<<"son pares amigables";
        return 0;
    }
    else {
        cout<<"no son pares amigables";
        return 0;
    }

    return 0;
}