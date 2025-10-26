#include <iostream>  // para usar printf/scanf
#include <cstdio>    // incluye scanf y printf
using namespace std;

int main() {
    int i;
    long l;
    char c;
    float f;
    double d;

    // Leer datos
    scanf("%d %ld %c %f %lf", &i, &l, &c, &f, &d);

    // Imprimir uno por 
    printf("%d\n", i);         // imprime el int
    printf("%ld\n", l);        // imprime el long
    printf("%c\n", c);         // imprime el char
    printf("%.3f\n", f);       // imprime float con 3 decimales
    printf("%.9lf\n", d);      // imprime double con 9 decimales

    return 0;
}
