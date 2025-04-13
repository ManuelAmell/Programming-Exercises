#include <iostream>
using namespace std;
int main(){
    long long presupuesto;
    double ginecologia,traumatologia,pediatria;
    cout << "ingrese el monto presupuestal :";
    cin >>presupuesto;

    ginecologia=presupuesto*0.4;
    traumatologia=presupuesto*0.3;
    pediatria=presupuesto*0.3;

    cout <<"presupuesto para ginecologia :"<<ginecologia<<endl;
    cout << "presupuesto para traumatologia :"<<traumatologia<<endl;
    cout <<"presupuesto para pediatria :"<<pediatria;
    
    return 0;
}