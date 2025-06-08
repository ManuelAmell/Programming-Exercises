    #include <iostream>
    using namespace std;
    int main(){

        int ingreso;
        long t = 0;
        for (int i=1;i<13;i++){
            cout <<"ingrese el dinero ahorrado para el mes "<<i<<":\n";
            cin >>ingreso;
            
            t+=ingreso;
        }
        cout <<"el total ahorrado en los 12 meses es "<<t;
        
        return 0;
    }