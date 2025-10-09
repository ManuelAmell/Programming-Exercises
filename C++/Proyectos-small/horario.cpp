#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
using namespace std;

#define DIAS 7
#define HORAS 24
#define ANCHO 12
#define MAX_TEXTO 40

// Estructura principal
struct Horario {
    char datos[DIAS][HORAS][MAX_TEXTO];
};  

// Colores ANSI
char VERDE[] = "\033[32m";
char AZUL[]  = "\033[34m";
char BLANCO[] = "\033[37m";
char RESET[] = "\033[0m";

// Nombres de los días
char dias[DIAS][10] = {
    "Lunes","Martes","Miercoles","Jueves","Viernes","Sabado","Domingo"
};

// ---------------- FUNCIONES ----------------
void inicializar(Horario *h){
    for(int d=0; d<DIAS; d++)
        for(int ho=0; ho<HORAS; ho++)
            strcpy(h->datos[d][ho], "");
}

void guardar(Horario *h){
    ofstream f("horario.txt");
    if(!f) return;
    for(int d=0; d<DIAS; d++){
        for(int ho=0; ho<HORAS; ho++){
            f << d << " " << ho << " " << h->datos[d][ho] << "\n";
        }
    }
    f.close();
}

void cargar(Horario *h){
    ifstream f("horario.txt");
    if(!f) return;
    int d,ho;
    char linea[200];
    while(f >> d >> ho){
        f.get(); // espacio
        f.getline(linea,200);
        strcpy(h->datos[d][ho], linea);
    }
    f.close();
}

void borde(){
    cout << "+";
    cout << setw(ANCHO) << left << setfill('-') << "-" << "+";
    for(int d=0; d<DIAS; d++)
        cout << setw(ANCHO) << "-" << "+";
    cout << setfill(' ') << "\n";
}

void mostrar(Horario *h){
    cout << "\n" << VERDE;
    cout << setw((ANCHO*(DIAS+1))/2) << "HORARIO SEMANAL" << RESET << "\n\n";

    borde();
    cout << "|" << setw(ANCHO) << left << "Hora" << "|";
    for(int d=0; d<DIAS; d++)
        cout << VERDE << setw(ANCHO) << left << dias[d] << RESET << "|";
    cout << "\n";
    borde();

    for(int ho=0; ho<HORAS; ho++){
        char etiqueta[10];
        sprintf(etiqueta,"%02d:00",ho);
        cout << "|" << AZUL << setw(ANCHO) << left << etiqueta << RESET << "|";
        for(int d=0; d<DIAS; d++)
            cout << BLANCO << setw(ANCHO) << left << h->datos[d][ho] << RESET << "|";
        cout << "\n";
        borde();
    }
}

void editar(Horario *h){
    int d,ho;
    cout << "Dia (0=Lunes..6=Domingo): "; cin >> d;
    cout << "Hora (0..23): "; cin >> ho;
    if(d<0||d>=DIAS||ho<0||ho>=HORAS){ cout<<"Invalido\n"; return;}
    cin.ignore();
    cout << "Texto: ";
    cin.getline(h->datos[d][ho],MAX_TEXTO);
}

void borrar(Horario *h){
    int d,ho;
    cout << "Dia (0=Lunes..6=Domingo): "; cin >> d;
    cout << "Hora (0..23): "; cin >> ho;
    if(d<0||d>=DIAS||ho<0||ho>=HORAS){ cout<<"Invalido\n"; return;}
    strcpy(h->datos[d][ho], "");
    cout<<"Celda borrada.\n";
}

// ---------------- MAIN ----------------
int main(){
    Horario h;
    inicializar(&h);
    cargar(&h);

    int op;
    do{
        cout << "\n--- MENU ---\n";
        cout << "1. Ver horario\n";
        cout << "2. Editar celda\n";
        cout << "3. Borrar celda\n";
        cout << "4. Guardar\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> op;

        switch(op){
            case 1: mostrar(&h); break;
            case 2: editar(&h); break;
            case 3: borrar(&h); break;
            case 4: guardar(&h); cout<<"Guardado.\n"; break;
            case 0: guardar(&h); cout<<"Saliendo...\n"; break;
            default: cout<<"Opcion invalida\n";
        }
    }while(op!=0);

    return 0;
}
