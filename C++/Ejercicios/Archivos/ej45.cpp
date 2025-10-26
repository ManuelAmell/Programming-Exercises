#include <iostream>

using namespace std;
int main(){
    int p,q,a=0;
    for (int i=0;i < 5;i++){
        cout <<"ingrese su peso anterior persona # "<<i+1<<endl;
        cin >>q;
        for (int x=0;x < 10;x++){
            
            cout <<"persona ("<<i+1<<")ingrse su peso #"<<x+1<<endl;
            cin>>p;
            a+=p;
        }
        cout <<"la persona #"<<i+1;
        if((a/10) > q){
            cout <<"subio de peso\n";
            
        }
        else if (a/10 ==q){
            cout <<"se mantubo en su peso\n";
        }
        else {
            cout <<"bajo de peso\n";
        }
        cout <<"el balance fue :"<<a/10-q<<endl;
        system("pause");
        a=0;
    }
    return 0;
}