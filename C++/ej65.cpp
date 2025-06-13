#include <bits/stdc++.h>
using namespace std;
int main(){
int N;
float sumatoria=0,promedio=0,cantesmayp=0;
cout <<"ingrese la cantidad de estudiantes :";
cin >>N;
cout <<endl<<endl;
float notas[N];//recordar que sino se declara aqui se guarda basura digital
string nombres[N];
for (int x=0;x < N;x++)
{   cout << "Ingrese el nombre del estudiante : ";
    fflush(stdin);getline(cin,nombres[x]);
    cout << "ingrese un valor para el estudiante #"<<x+1<<" : ";cin >>notas[x];
    cout << notas[x]<<endl;

    sumatoria+=notas[x];

}
promedio=sumatoria / N;
cout << "el promedio es :"<<promedio <<endl;
for (int x=0;x < N;x++)
{
    if (notas[x]>promedio){
        cantesmayp++;
    }
    cout <<notas[x]<<" ";

}
cout << endl;
cout << "la cantidad de estudiantes mayor al promedio es :"<<cantesmayp<<endl;
cout << "porcentaje de estudiantes con notas mayor al promedio :"<<cantesmayp*100.0/N<<"%"<<endl;
for (int actual=0;actual < N-1;actual++)//n -1 por que al finalizar el arreglo estaria en n-2 por que los arreglos comienzan es 0
{
    int aux;
    string aux1;
    for (int siguiente = actual + 1 ;siguiente  < N ;siguiente++)
    {  
         if(notas[siguiente] > notas [actual]){
        aux =notas [actual];
        notas [actual]= notas [siguiente];
        notas [siguiente] = aux;
        
        aux1 = nombres[actual];
        nombres[actual] =nombres[siguiente];
        nombres[siguiente] =aux1;
        }
    }
}
for (int x=0;x < N;x++)
{cout <<setw(30)<<nombres[x]<<endl;
    cout <<setw(30) << notas[x]<<endl;
}

    return 0;
}