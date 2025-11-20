// finalizado
/* ? Requerimiento Ministerio de Educación
 * ? Archivo plano con información de cada estudiante primer periodo 2025:
  ! Documento de identificación+
  ! Nombre+
  ! Programa+
  ! Semestre+
  ! Cantidad de asignaturas matriculadas+
  ! Cantidad de asignaturas reprobadas+
  ! Promedio+
  ! Estrato
 *
 * ? Para cada estudiante:
 * ! Leer las notas de cada corte: 30%, 30%, 40% respectivamente
 * ! Calcular la definitiva por asignatura
 *
// ?     Estadísticas requeridas:
*
// ? estudiantes matriculados
*
 //todo : Porcentaje de estudiantes que reprobaron mínimo 3 asignaturas
*
 //todo : Cantidad de estudiantes con promedio superior a 4.5
 *
 //todo : Cantidad de estudiantes de estrato 4 en adelante con promedio por
*
 //todo debajo de 3.5
 *
 //todo : Cantidad de estudiantes de estrato 1 con promedio a partir de 4.0
 */

#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

struct estudiante {
    long id; // 1
    char nombre[100]; // 2
    char programa[50]; // 3
    int semestre; // 4
    int cMaterias; // 5
    int cReprobadas = 0; // 6
    float promedio; // 7
    int estrato; // 8
};
int menu()
{
    int opc;
    do {
        cout << "1) leer :\n";
        cout << "2) Guardar:\n";
        cout << "3) ver estudiantes :\n";
        cout << "4) salir :\n";
        cin >> opc;
    } while (opc > 4 || opc < 1);
    return opc;
}

void calcular(estudiante estudiantes[], int j)
{
    float suma = 0;

    for (int u = 0; u < estudiantes[j].cMaterias; u++) {

        float p1, p2, p3;

        cout << "\nMateria #" << u + 1 << endl;
        cout << "Ingrese la nota del P1 (30%): ";
        cin >> p1;
        cout << "Ingrese la nota del P2 (30%): ";
        cin >> p2;
        cout << "Ingrese la nota del P3 (40%): ";
        cin >> p3;

        float definitiva = p1 * 0.3 + p2 * 0.3 + p3 * 0.4;

        if (definitiva < 3.0)
            estudiantes[j].cReprobadas++;

        suma += definitiva;
    }

    estudiantes[j].promedio = suma / estudiantes[j].cMaterias;
}

void ingresar(estudiante estudiantes[], int total)
{
    for (int i = 0; i < total; i++) {
        cin.ignore();

        cout << "Ingrese nombre del estudiante #" << i + 1 << ": ";
        cin.getline(estudiantes[i].nombre, 100);

        cout << "Ingrese Programa: ";
        cin.getline(estudiantes[i].programa, 50);

        cout << "Ingrese documento de identificación: ";
        cin >> estudiantes[i].id;

        cout << "Ingrese semestre: ";
        cin >> estudiantes[i].semestre;

        cout << "Ingrese cantidad de asignaturas matriculadas: ";
        cin >> estudiantes[i].cMaterias;
        calcular(estudiantes, i);

        cout << "Ingrese estrato: ";
        cin >> estudiantes[i].estrato;
    }
}

void guardar(estudiante estudiantes[], int total)
{
    ofstream archivo("estudiantes.txt");

    if (!archivo) {
        cout << "Error al abrir el archivo";
        return;
    }
    system("clear");
    for (int i = 0; i < total; i++) {
        archivo << "Estudiante #" << i + 1 << "\n";
        archivo << "Nombre: " << estudiantes[i].nombre << "\n";
        archivo << "Programa: " << estudiantes[i].programa << "\n";
        archivo << "Documento: " << estudiantes[i].id << "\n";
        archivo << "Semestre: " << estudiantes[i].semestre << "\n";
        archivo << "Materias matriculadas: " << estudiantes[i].cMaterias << "\n";
        archivo << "Materias reprobadas: " << estudiantes[i].cReprobadas << "\n";
        archivo << "Promedio: " << estudiantes[i].promedio << "\n";
        archivo << "Estrato: " << estudiantes[i].estrato << "\n";
        archivo << "-------------------------------------------\n";
    }

    archivo.close();
    cout << "Archivo generado correctamente.\n";
}

void ver(estudiante estudiantes[], int total)
{
    ifstream archivoEstudiantes("estudiantes.txt");
    if (!archivoEstudiantes) {
        cout << "error al leer ";
        exit(0);
    }
    string contenido;
    system("clear");
    cout << "---------------ESTUDIANTES-------------:" << endl;
    while (getline(archivoEstudiantes, contenido)) {
        cout << contenido << endl;
    }
    archivoEstudiantes.close();
    cout << " fin Archivo..." << endl;
}
int main()
{
    int total;
    cout << "ingrese la cantidad de estudiantes :";
    cin >> total;
    estudiante estudiantes[total];
    int opc;
    do {
        opc = menu();
        switch (opc) {
        case 1:
            ingresar(estudiantes, total);

            break;
        case 2:
            guardar(estudiantes, total);

            break;
        case 3: {
            ver(estudiantes, total);
        }
        }

    } while (opc != 4);

    return 0;
}