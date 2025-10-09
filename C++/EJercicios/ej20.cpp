#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "Spanish");//Permite usar caracteres especiales del español como la ñ o las tildes
    
        float promediog,promediof,promedioq,promediom;
        float examenmatematicas,examenfisica,examenquimica;
        float t1,t2,t3;

        cout << "Programa que calcula el promedio de tres materias"<<endl;
        cout << "Introduzca la nota del examen matemáticas: ";
        cin >> examenmatematicas;       
        cout << "nota de tarea 1 matemáticas: ";
        cin >> t1;
        cout << "nota de tarea 2 matemáticas: ";
        cin >> t2;
        cout  <<"nota tarea 3 matemáticas: ";
        cin >> t3;

        examenmatematicas = examenmatematicas * 0.9;
        promediom=((t1+t2+t3)/3)*0.1;

        cout << "nota definitiva de matematicas :"<<examenmatematicas+promediom<<endl;

        cout << "Introduzca la nota del examen física: ";
        cin >> examenfisica;

        cout << "nota de tarea 1 física: ";
        cin >> t1;
        cout << "nota de tarea 2 física: ";
        cin >> t2;

        examenfisica = examenfisica * 0.8;

        promediof=((t1+t2)/2)*0.2;


        cout << "nota definitiva de fisica :"<<examenfisica+promediof<<endl;

        cout << "Introduzca la nota del examen quimica: ";

        cin >> examenquimica;


        cout << "nota de tarea 1 química: ";
        cin >> t1;
        cout << "nota de tarea 2 química: ";
        cin >> t2;
        cout << "nota de tarea 3 química: ";
        cin >> t3;

        examenquimica=examenquimica*0.85;

        promedioq=((t1+t2+t3)/3)*0.15;

        cout << "nota definitiva de quimica:"<<examenquimica+promedioq<<endl;

        promediog=(examenmatematicas+promediom+examenfisica+promediof+examenquimica+promedioq)/3;

        cout << "promedio general:"<<promediog;
        return 0;
        
} 