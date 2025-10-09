#include <iostream>
using namespace std;
int main(){
int n,z=0,x=1,y=0;
cout <<"ingrese n:";
cin >>n;
for (;z < n;)
{y = x+ z;

        cout<<" + "<<z<<" ";
        x = z;
        z = y;
       
}
    return 0;
}