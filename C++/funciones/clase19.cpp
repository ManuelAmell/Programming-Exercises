#include <iostream>
using namespace std;

void salario(int *he,int *vr,int *ho){

}
int main(){
    int empleados=0;
    int u;
    
    float he;//horas extraas
    float ho;//horas ordinarias
    float vr;//valor hora

    cout << "Numero de empleados :";
    cin >>u;
    int n[u][4];

    for (int i=0; i < 4; i++){

        for (int x=0; x <= empleados;x++){
            cout <<"el empleado N° "<<i+1<<endl;
            cout <<"Ingrese el valor de su hora de trabajo :";
            cin >>n[i][0];//VALOR HORA

            cout <<"ingrese su cantidad de horas trabajadas :";
            cin >>n[i][1];//CANTIDAD HORAS

            cout << "ingrese la cantidad de horas extras :";
            cin >> n[i][2];//HORAS EXTRAS

            cout << "horas de ausencia :";
            cin >> n[i][3];//HORAS AUSENCIA

                if (n[i][1]>48 && n[i][2]>0){
                
                    n[i][2]=n[i][2]-n[i][3];
                }

                else if  (n[i][1]>48){
                
                    n[i][2]=n[i][2]-n[i][3];
                }

            }
        }
    


    return 0;
}