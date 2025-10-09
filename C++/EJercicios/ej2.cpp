#include <iostream>

using namespace std;

int main() {
    int horas, minutos, segundos;
    
    // Entrada de datos
    cout << "Ingrese las horas: ";
    cin >> horas;
    cout << "Ingrese los minutos: ";
    cin >> minutos;
    cout << "Ingrese los segundos: ";
    cin >> segundos;
    
    // Normalización del tiempo
    minutos += segundos / 60;
    segundos %= 60;
    horas += minutos / 60;
    minutos %= 60;
    
    // Mostrar resultado
    cout << "Tiempo normalizado: " << horas << "h " << minutos << "m " << segundos << "s" << endl;
    
    return 0;
}
