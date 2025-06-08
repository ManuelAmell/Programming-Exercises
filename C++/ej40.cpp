#include <iostream> 
using namespace std;
int main(){
 
       int numero;
       cout <<"ingrese el numero :";cin>>numero;

    for (int i = 1;i <= numero;i++)
    {
        for(int x=1 ; x <= i ;x++)
        {
            cout <<"*";
        }
        cout <<endl;
    }
    return 0;
}