#include <iostream>
using namespace std;
int main() {
                    // Función principal
float promediog;
float matematicase,fisicae,quimicae;
float matematicasa,fisicasa,quimicasa;

float matematicast1,matematicast2,matematicast3;
float fisicat1,fisicat2;
float quimicat1,quimicat2,quimicat3;

cout << "Introduzca la nota del examen matemáticas: ";
cin >> matematicase;

cout << "nota de tarea 1 matemáticas: ";
cin >> matematicast1;
cout << "nota de tarea 2 matemáticas: ";
cin >> matematicast2;
cout  <<"nota tarea 3 matemáticas: ";
cin >> matematicast3;

cout << "Introduzca la nota del examen física: ";
cin >> fisicae;

cout << "nota de tarea 1 física: ";
cin >> fisicat1;
cout << "nota de tarea 2 física: "; 
cin >> fisicat2;


cout << "Introduzca la nota del examen química: ";
cin >> quimicae;

cout << "nota de tarea 1 química: ";
cin >> quimicat1;   
cout << "nota de tarea 2 química: ";
cin >> quimicat2;
cout << "nota de tarea 3 química: ";
cin >> quimicat3;
//calculo de notas
matematicase = matematicase * 0.9;
matematicasa=((matematicast1+matematicast2+matematicast3)/3)*0.1;

fisicae = fisicae * 0.8;
fisicasa=((fisicat1+fisicat2)/2)*0.2;

quimicae=quimicae*0.85;
quimicasa=((quimicat1+quimicat2+quimicat3)/3)*0.15;


cout << "nota definitiva de matematicas :"<<matematicase+matematicasa<<endl;
cout << "nota definitiva de fisica :"<<fisicae+fisicasa<<endl;
cout << "nota definitiva de quimica:"<<quimicae+quimicasa;
cout <<endl;
promediog=(matematicase+matematicasa+fisicae+fisicasa+quimicae+quimicasa)/3;
cout << "promedio general:"<<promediog; 
return 0;
    }