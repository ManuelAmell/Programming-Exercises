#include <fstream>
#include <iostream>
using namespace std;

struct Estudiante {
  char documento[20];
  char nombre[50];
  char programa[50];
  int semestre;
  int numAsignaturas;
  int numReprobadas;
  float promedio;
  int estrato;
};

// Función para calcular la definitiva de una asignatura
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
  fstream archivo("estudiantes2025.bin", ios::out | ios::binary);
  if (!archivo.is_open()) {
    cout << "Error al abrir el archivo\n";
    return 1;
  }

  int totalEstudiantes;
  cout << "Ingrese total de estudiantes: ";
  cin >> totalEstudiantes;
  cin.ignore();

  // Estadísticas
  int estudiantesReprobaron3 = 0;
  int estudiantesPromedio45 = 0;
  int estrato4PromedioBajo = 0;
  int estrato1PromedioAlto = 0;

  for (int i = 0; i < totalEstudiantes; i++) {
    Estudiante est;

    cout << "\nEstudiante #" << i + 1 << endl;
    cout << "Documento: ";
    cin.getline(est.documento, 20);
    cout << "Nombre: ";
    cin.getline(est.nombre, 50);
    cout << "Programa: ";
    cin.getline(est.programa, 50);
    cout << "Semestre: ";
    cin >> est.semestre;
    cout << "Cantidad de asignaturas: ";
    cin >> est.numAsignaturas;
    cout << "Estrato: ";
    cin >> est.estrato;
    cin.ignore();

    int reprobadas = 0;
    float sumaNotas = 0;

    for (int j = 0; j < est.numAsignaturas; j++) {
      cout << "\nAsignatura #" << j + 1 << endl;
      float definitiva = calcularDefinitiva();
      sumaNotas += definitiva;
      if (definitiva < 3.0)
        reprobadas++;
    }

    est.numReprobadas = reprobadas;
    est.promedio = sumaNotas / est.numAsignaturas;

    // Actualizar estadísticas
    if (reprobadas >= 3)
      estudiantesReprobaron3++;
    if (est.promedio >= 4.5)
      estudiantesPromedio45++;
    if (est.estrato >= 4 && est.promedio < 3.5)
      estrato4PromedioBajo++;
    if (est.estrato == 1 && est.promedio >= 4.0)
      estrato1PromedioAlto++;

    // Guardar en archivo binario
    archivo.write(reinterpret_cast<char *>(&est), sizeof(Estudiante));
  }

  archivo.close();

  // Mostrar estadísticas
  cout << "\nArchivo binario generado correctamente.\n";
  cout << "Total estudiantes: " << totalEstudiantes << endl;
  cout << "Porcentaje que reprobaron 3 o más asignaturas: "
       << (estudiantesReprobaron3 * 100.0 / totalEstudiantes) << "%" << endl;
  cout << "Cantidad con promedio >= 4.5: " << estudiantesPromedio45 << endl;
  cout << "Cantidad estrato >=4 con promedio < 3.5: " << estrato4PromedioBajo
       << endl;
  cout << "Cantidad estrato 1 con promedio >= 4.0: " << estrato1PromedioAlto
       << endl;

  return 0;
}
