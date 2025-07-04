/*
En un concurso de belleza hay N participantes a cada una se le debe registrar cada uno
en uno los siguientes datos:

 Nombre
 Puntos por inteligencia
 Puntos por Cultura general
 Puntos por Belleza
Se necesita informar por pantalla:
Nombre de la concursante de mayor puntaje general
Puntaje acumulado por todas las participantes en Cultura general, en Inteligencia y en
Belleza*/
#include <iostream>
#include <iomanip>
using namespace std;
int main (){
int n;

do{
cout << " PARTICIPANTES :";
cin >>n;
}while(n <= 0);
string nombres[n];
long long acumuladoiq=0,acumuladobe=0,acumuladocg=0;
double iq[n],be[n],cg[n],promedio[n];
for(int x=0;x < n; x++){
    cout << "nombre para la participante #"<<x+1;
    cin >>nombres[x];
    
    cout << "ingrese la inteligencia para la participante #"<<x+1<<" :"<<endl;
    cin>>iq[x];acumuladoiq+=iq[x];
    cout << "ingrese la belleza para la participante #"<<x+1<<" :"<<endl;
    cin >>be[x];acumuladobe+=be[x];
    cout << "ingrese la cultura para la participante #"<<x+1<<" :"<<endl;
    cin >>cg[x];acumuladocg+=cg[x];
    promedio[x]=(iq[x]+be[x]+cg[x])/3.0;
}

for (int i=0;i < n-1;i++){

    for (int x=0;x < n-i-1;x++){

        if (promedio[x]<promedio[x+1]){
        
        int aux=promedio[x];//copia 0
        string auxn=nombres[x];//copia nombres 0
        double auxiq =iq[x];//copia iq
        double auxbe =be[x];//copia be
        double auxcg =cg[x];//copia cg

        promedio[x]=promedio[x+1];
        promedio[x+1]=aux;

        nombres[x]=nombres[x+1];
        nombres[x+1]=auxn;

        iq[x]= iq[x+1];
        iq[x+1]= auxiq;
        be[x]= be[x+1];
        be[x+1]=auxbe;
        cg[x]= cg[x+1];
        cg[x+1]=auxcg;
        }
    }
}
for (int i=0; i < n; i++){
    cout <<i+1<< " participante "<<nombres[i]<<setw(10)<<" puntaje general : "<< setw(5)<<promedio[i]<< setw(10) <<"belleza :"<<setw(5)<<be[i]<<setw(10)<<"inteligencia :"<<setw(5)<<iq[i]<<"cultura general :"<<setw (5)<<cg[i]<<endl;
}cout << endl;
cout << " belleza acumulado :"<<setw (6)<<acumuladobe<<setw (10)
     << " inteligencia :"<<setw (6)<<acumuladoiq<<setw(10)
     << " cultura general :"<<setw (6)<<acumuladocg<<setw(10);
    return 0;
}