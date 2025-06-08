#include <iostream>
using namespace std;
int main(){
    int n;

    int divisores=1;
    long sd=1;
        cout << "ingrese su numero";
        cin >>n;
        for(int i=2;i <= n;i++)
        {
            if(n%i!=0){continue;}
            sd+=i;
            divisores++;
        }
        cout <<"el total de divisores es :"<<divisores<<endl;
        cout <<"la suma de los divisores es"<<sd;

        return 0;
}