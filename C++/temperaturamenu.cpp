#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    cout <<fixed<<setprecision(2);
    float mes[30],dias=0,s1=0,s2=0,s3=0,s4=0;
    for (int i=0;i < 30;i++){
        cout <<"ingrese la cantidad de horas para el dia "<<i+1<<" :";
        cin >> mes[i];
        dias+=mes[i];

        if (i < 7){
            s1+=mes[i];
        }
        else if (i <14){
            s2+=mes[i];
        }
        else if (i <21)
        {
            s3+=mes[i];
        }
        else {
            s4+=mes[i];
        }
    }
    cout << "1) TEMERATURA PROMEDIO SEMANA :\n"
         << "--SEMANA 1"<<setw(10)<<s1/7<<"\n"
         << "--SEMANA 2"<<setw(10)<<s2/7<<"\n"
         << "--SEMANA 3"<<setw(10)<<s3/7<<"\n"
         << "--SEMANA 4"<<setw(10)<<s4/9<<"\n"
         << "2) TEMPERATURA PROMEDIO :"<<setw(10)<<dias/(sizeof(mes)/sizeof(mes[0]));
    return 0;
}