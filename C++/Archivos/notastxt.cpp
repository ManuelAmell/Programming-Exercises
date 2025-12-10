#include <fstream>
#include <iostream>
using namespace std;

struct Estudiante {
  string documento;
  string nombre;
  string programa;
  int semestre;
  int numAsignaturas;
  int numReprobadas;
  float promedio;
  int estrato;
};

float calcularDefinitiva() {
  float corte1, corte2, corte3;
  cout << "Ingrese nota corte 1 (30%): ";
  cin >> corte1;
  cout << "Ingrese nota corte 2 (30%): ";
  cin >> corte2;
  cout << "Ingrese nota corte 3 (40%): ";
  cin >> corte3;

  return corte1 * 0.3 + corte2 * 0.3 + corte3 * 0.4;
}

int main() {
  ofstream archivo("estudiantes2025.txt");
  if (!archivo.is_open()) {
    cout << "Error al abrir el archivo\n";
    return 1;
  }

  int totalEstudiantes;
  cout << "Ingrese total de estudiantes: ";
  cin >> totalEstudiantes;
  cin.ignore();  // limpiar buffer

  // Variables para estadísticas
  int estudiantesReprobaron3 = 0;
  int estudiantesPromedio45 = 0;
  int estrato4PromedioBajo = 0;
  int estrato1PromedioAlto = 0;

  for (int i = 0; i < totalEstudiantes; i++) {
    Estudiante est;

    cout << "\nEstudiante #" << i + 1 << endl;
    cout << "Documento: ";
    getline(cin, est.documento);
    cout << "Nombre: ";
    getline(cin, est.nombre);
    cout << "Programa: ";
    getline(cin, est.programa);
    cout << "Semestre: ";
    cin >> est.semestre;
    cout << "Cantidad de asignaturas: ";
    cin >> est.numAsignaturas;
    cout << "Estrato: ";
    cin >> est.estrato;
    cin.ignore();  // limpiar buffer

    int reprobadas = 0;
    float sumaNotas = 0;

    for (int j = 0; j < est.numAsignaturas; j++) {
      cout << "\nAsignatura #" << j + 1 << endl;
      float definitiva = calcularDefinitiva();
      sumaNotas += definitiva;
      if (definitiva < 3.0) reprobadas++;
    }

    est.numReprobadas = reprobadas;
    est.promedio = sumaNotas / est.numAsignaturas;

    // Actualizar estadísticas
    if (reprobadas >= 3) estudiantesReprobaron3++;
    if (est.promedio >= 4.5) estudiantesPromedio45++;
    if (est.estrato >= 4 && est.promedio < 3.5) estrato4PromedioBajo++;
    if (est.estrato == 1 && est.promedio >= 4.0) estrato1PromedioAlto++;

    // Guardar registro en archivo
    archivo << est.documento << "," << est.nombre << "," << est.programa << ","
            << est.semestre << "," << est.numAsignaturas << ","
            << est.numReprobadas << "," << est.promedio << "," << est.estrato
            << "\n";
  }

  // Guardar estadísticas al final
  archivo << "\nTotal estudiantes: " << totalEstudiantes << "\n";
  archivo << "Porcentaje estudiantes que reprobaron 3 o más asignaturas: "
          << (estudiantesReprobaron3 * 100.0 / totalEstudiantes) << "%\n";
  archivo << "Cantidad de estudiantes con promedio >= 4,5: "
          << estudiantesPromedio45 << "\n";
  archivo << "Cantidad de estudiantes estrato >=4 con promedio < 3,5: "
          << estrato4PromedioBajo << "\n";
  archivo << "Cantidad de estudiantes estrato 1 con promedio >= 4,0: "
          << estrato1PromedioAlto << "\n";

  archivo.close();
  cout << "\nArchivo generado correctamente.\n";

  return 0;
}
