// Sistema de Registro de Empleados con Archivos TXT
// Permite: agregar, mostrar, buscar, editar y eliminar empleados
// Formato: nombre;edad;puesto;salario

#include <fstream>  // Para trabajar con archivos
#include <iostream> // Para cout y cin
#include <string>   // Para usar string
using namespace std;

// Estructura para guardar datos de un empleado
struct Empleado {
  string id; // ID único del empleado
  string nombre;
  int edad;
  string puesto;
  double salario;
};

// ===== FUNCIONES DE VALIDACIÓN =====

// Verifica si el archivo existe
bool archivoExiste() {
  ifstream file("empleados.txt");
  bool existe = file.is_open();
  file.close();
  return existe;
}

// Verifica que el ID no esté vacío y no tenga punto y coma
bool validarID(string id) {
  if (id.empty()) {
    
    cout << "ERROR: El ID no puede estar vacío.\n";
    return false;
  }

  if (id.find(';') != string::npos) {
    cout << "ERROR: El ID no puede contener ';'\n";
    return false;
  }

  return true;
}

// Verifica si un ID ya existe en el archivo
bool idExiste(string id) {
  ifstream file("empleados.txt");
  string linea;

  while (getline(file, linea)) {
    size_t pos = linea.find(';');
    if (pos == string::npos)
      continue;

    string idExistente = linea.substr(0, pos);

    if (idExistente == id) {
      file.close();
      return true;
    }
  }

  file.close();
  return false;
}

// Verifica que el nombre no esté vacío y no tenga punto y coma
bool validarNombre(string nombre) {
  if (nombre.empty()) {
    cout << "ERROR: El nombre no puede estar vacío.\n";
    return false;
  }

  // El punto y coma rompe el formato del archivo
  if (nombre.find(';') != string::npos) {
    cout << "ERROR: El nombre no puede contener ';'\n";
    return false;
  }

  return true;
}

// Verifica que la edad sea válida
bool validarEdad(int edad) {
  if (edad < 18 || edad > 100) {
    cout << "ERROR: La edad debe estar entre 18 y 100 años.\n";
    return false;
  }
  return true;
}

// Verifica que el puesto no esté vacío
bool validarPuesto(string puesto) {
  if (puesto.empty()) {
    cout << "ERROR: El puesto no puede estar vacío.\n";
    return false;
  }

  if (puesto.find(';') != string::npos) {
    cout << "ERROR: El puesto no puede contener ';'\n";
    return false;
  }

  return true;
}

// Verifica que el salario sea válido
bool validarSalario(double salario) {
  if (salario < 0) {
    cout << "ERROR: El salario no puede ser negativo.\n";
    return false;
  }
  return true;
}

// ===== FUNCIONES PRINCIPALES =====

// 1. CREAR ARCHIVO (si no existe)
void crearArchivo() {
  if (archivoExiste()) {
    cout << "El archivo de empleados ya existe.\n";
    return;
  }

  ofstream file("empleados.txt");

  if (!file.is_open()) {
    cout << "ERROR: No se pudo crear el archivo.\n";
    return;
  }

  file.close();
  cout << "Archivo de empleados creado exitosamente.\n";
}

// 2. AGREGAR EMPLEADO
void agregarEmpleado() {
  if (!archivoExiste()) {
    cout << "El archivo no existe. Créalo primero (opción 1).\n";
    return;
  }

  Empleado emp;

  // Pedir y validar ID
  cout << "\nID del empleado: ";
  getline(cin, emp.id);
  if (!validarID(emp.id))
    return;

  // Verificar que el ID no exista ya
  if (idExiste(emp.id)) {
    cout << "ERROR: Ya existe un empleado con ese ID.\n";
    return;
  }

  // Pedir y validar nombre
  cout << "Nombre completo: ";
  getline(cin, emp.nombre);
  if (!validarNombre(emp.nombre))
    return;

  // Pedir y validar edad
  cout << "Edad: ";
  if (!(cin >> emp.edad)) {
    cout << "ERROR: Debes ingresar un número.\n";
    cin.clear();
    cin.ignore(10000, '\n');
    return;
  }
  cin.ignore();
  if (!validarEdad(emp.edad))
    return;

  // Pedir y validar puesto
  cout << "Puesto: ";
  getline(cin, emp.puesto);
  if (!validarPuesto(emp.puesto))
    return;

  // Pedir y validar salario
  cout << "Salario: ";
  if (!(cin >> emp.salario)) {
    cout << "ERROR: Debes ingresar un número.\n";
    cin.clear();
    cin.ignore(10000, '\n');
    return;
  }
  cin.ignore();
  if (!validarSalario(emp.salario))
    return;

  // Guardar en el archivo
  ofstream file("empleados.txt", ios::app);

  if (!file.is_open()) {
    cout << "ERROR: No se pudo abrir el archivo.\n";
    return;
  }

  // Formato: id;nombre;edad;puesto;salario
  file << emp.id << ";" << emp.nombre << ";" << emp.edad << ";" << emp.puesto
       << ";" << emp.salario << "\n";
  file.close();

  cout << "\n✓ Empleado agregado exitosamente con ID: " << emp.id << "\n";
}

// 3. MOSTRAR TODOS LOS EMPLEADOS
void mostrarEmpleados() {
  if (!archivoExiste()) {
    cout << "El archivo no existe. Créalo primero (opción 1).\n";
    return;
  }

  ifstream file("empleados.txt");
  string linea;
  int contador = 0;

  cout << "\n========== LISTA DE EMPLEADOS ==========\n";

  while (getline(file, linea)) {
    // Buscar los delimitadores
    size_t pos1 = linea.find(';');
    if (pos1 == string::npos)
      continue;

    size_t pos2 = linea.find(';', pos1 + 1);
    if (pos2 == string::npos)
      continue;

    size_t pos3 = linea.find(';', pos2 + 1);
    if (pos3 == string::npos)
      continue;

    size_t pos4 = linea.find(';', pos3 + 1);
    if (pos4 == string::npos)
      continue;

    // Extraer datos
    string id = linea.substr(0, pos1);
    string nombre = linea.substr(pos1 + 1, pos2 - pos1 - 1);
    string edadStr = linea.substr(pos2 + 1, pos3 - pos2 - 1);
    string puesto = linea.substr(pos3 + 1, pos4 - pos3 - 1);
    string salarioStr = linea.substr(pos4 + 1);

    contador++;

    cout << "\n[" << contador << "] ID: " << id << "\n";
    cout << "    Nombre: " << nombre << "\n";
    cout << "    Edad: " << edadStr << " años\n";
    cout << "    Puesto: " << puesto << "\n";
    cout << "    Salario: $" << salarioStr << "\n";
  }

  file.close();

  if (contador == 0) {
    cout << "No hay empleados registrados.\n";
  } else {
    cout << "\nTotal de empleados: " << contador << "\n";
  }
}

// 4. BUSCAR EMPLEADO POR NOMBRE O ID
void buscarEmpleado() {
  if (!archivoExiste()) {
    cout << "El archivo no existe. Créalo primero (opción 1).\n";
    return;
  }

  string buscar;
  cout << "\nBuscar por (nombre o ID): ";
  getline(cin, buscar);

  if (buscar.empty()) {
    cout << "ERROR: No puede estar vacío.\n";
    return;
  }

  // Convertir a minúsculas para búsqueda insensible
  string buscarMin = buscar;
  for (int i = 0; i < buscarMin.length(); i++) {
    buscarMin[i] = tolower(buscarMin[i]);
  }

  ifstream file("empleados.txt");
  string linea;
  bool encontrado = false;

  cout << "\n========== RESULTADOS ==========\n";

  while (getline(file, linea)) {
    size_t pos1 = linea.find(';');
    if (pos1 == string::npos)
      continue;

    size_t pos2 = linea.find(';', pos1 + 1);
    if (pos2 == string::npos)
      continue;

    size_t pos3 = linea.find(';', pos2 + 1);
    if (pos3 == string::npos)
      continue;

    size_t pos4 = linea.find(';', pos3 + 1);
    if (pos4 == string::npos)
      continue;

    string id = linea.substr(0, pos1);
    string nombre = linea.substr(pos1 + 1, pos2 - pos1 - 1);

    // Convertir a minúsculas para comparar
    string idMin = id;
    string nombreMin = nombre;
    for (int i = 0; i < idMin.length(); i++) {
      idMin[i] = tolower(idMin[i]);
    }
    for (int i = 0; i < nombreMin.length(); i++) {
      nombreMin[i] = tolower(nombreMin[i]);
    }

    // Buscar si contiene el texto (búsqueda parcial en nombre o ID exacto)
    if (nombreMin.find(buscarMin) != string::npos || idMin == buscarMin) {
      encontrado = true;

      string edadStr = linea.substr(pos2 + 1, pos3 - pos2 - 1);
      string puesto = linea.substr(pos3 + 1, pos4 - pos3 - 1);
      string salarioStr = linea.substr(pos4 + 1);

      cout << "\n✓ ID: " << id << "\n";
      cout << "  Nombre: " << nombre << "\n";
      cout << "  Edad: " << edadStr << " años\n";
      cout << "  Puesto: " << puesto << "\n";
      cout << "  Salario: $" << salarioStr << "\n";
    }
  }

  file.close();

  if (!encontrado) {
    cout << "No se encontraron empleados.\n";
  }
}

// 5. EDITAR EMPLEADO
void editarEmpleado() {
  if (!archivoExiste()) {
    cout << "El archivo no existe. Créalo primero (opción 1).\n";
    return;
  }

  string buscarID;
  cout << "\nID del empleado a editar: ";
  getline(cin, buscarID);

  if (buscarID.empty()) {
    cout << "ERROR: El ID no puede estar vacío.\n";
    return;
  }

  ifstream file("empleados.txt");
  ofstream temp("temp_empleados.txt");

  if (!temp.is_open()) {
    cout << "ERROR: No se pudo crear archivo temporal.\n";
    return;
  }

  string linea;
  bool encontrado = false;

  while (getline(file, linea)) {
    size_t pos1 = linea.find(';');
    if (pos1 == string::npos) {
      temp << linea << "\n";
      continue;
    }

    size_t pos2 = linea.find(';', pos1 + 1);
    if (pos2 == string::npos) {
      temp << linea << "\n";
      continue;
    }

    size_t pos3 = linea.find(';', pos2 + 1);
    if (pos3 == string::npos) {
      temp << linea << "\n";
      continue;
    }

    size_t pos4 = linea.find(';', pos3 + 1);
    if (pos4 == string::npos) {
      temp << linea << "\n";
      continue;
    }

    string id = linea.substr(0, pos1);

    // Si es el empleado buscado
    if (id == buscarID) {
      encontrado = true;

      string nombre = linea.substr(pos1 + 1, pos2 - pos1 - 1);

      cout << "\n===== EMPLEADO ENCONTRADO =====\n";
      cout << "ID: " << id << "\n";
      cout << "Nombre actual: " << nombre << "\n";

      Empleado emp;
      emp.id = id; // El ID no se modifica

      cout << "\nNuevo nombre (Enter para mantener): ";
      getline(cin, emp.nombre);
      if (emp.nombre.empty()) {
        emp.nombre = nombre;
      } else if (!validarNombre(emp.nombre)) {
        file.close();
        temp.close();
        remove("temp_empleados.txt");
        return;
      }

      cout << "Nueva edad: ";
      if (!(cin >> emp.edad)) {
        cout << "ERROR: Edad inválida.\n";
        cin.clear();
        cin.ignore(10000, '\n');
        file.close();
        temp.close();
        remove("temp_empleados.txt");
        return;
      }
      cin.ignore();
      if (!validarEdad(emp.edad)) {
        file.close();
        temp.close();
        remove("temp_empleados.txt");
        return;
      }

      cout << "Nuevo puesto: ";
      getline(cin, emp.puesto);
      if (!validarPuesto(emp.puesto)) {
        file.close();
        temp.close();
        remove("temp_empleados.txt");
        return;
      }

      cout << "Nuevo salario: ";
      if (!(cin >> emp.salario)) {
        cout << "ERROR: Salario inválido.\n";
        cin.clear();
        cin.ignore(10000, '\n');
        file.close();
        temp.close();
        remove("temp_empleados.txt");
        return;
      }
      cin.ignore();
      if (!validarSalario(emp.salario)) {
        file.close();
        temp.close();
        remove("temp_empleados.txt");
        return;
      }

      // Guardar datos editados
      temp << emp.id << ";" << emp.nombre << ";" << emp.edad << ";"
           << emp.puesto << ";" << emp.salario << "\n";

    } else {
      // Mantener la línea sin cambios
      temp << linea << "\n";
    }
  }

  file.close();
  temp.close();

  if (!encontrado) {
    cout << "No se encontró el empleado con ese ID.\n";
    remove("temp_empleados.txt");
    return;
  }

  // Reemplazar archivo original
  remove("empleados.txt");
  rename("temp_empleados.txt", "empleados.txt");

  cout << "\n✓ Empleado editado exitosamente.\n";
}

// 6. ELIMINAR EMPLEADO
void eliminarEmpleado() {
  if (!archivoExiste()) {
    cout << "El archivo no existe. Créalo primero (opción 1).\n";
    return;
  }

  string buscarID;
  cout << "\nID del empleado a eliminar: ";
  getline(cin, buscarID);

  if (buscarID.empty()) {
    cout << "ERROR: El ID no puede estar vacío.\n";
    return;
  }

  // Confirmación de seguridad
  cout << "¿Estás seguro de eliminar al empleado con ID " << buscarID
       << "? (s/n): ";
  char confirmar;
  cin >> confirmar;
  cin.ignore();

  if (confirmar != 's' && confirmar != 'S') {
    cout << "Operación cancelada.\n";
    return;
  }

  ifstream file("empleados.txt");
  ofstream temp("temp_empleados.txt");

  if (!temp.is_open()) {
    cout << "ERROR: No se pudo crear archivo temporal.\n";
    return;
  }

  string linea;
  bool eliminado = false;

  while (getline(file, linea)) {
    size_t pos1 = linea.find(';');
    if (pos1 == string::npos) {
      temp << linea << "\n";
      continue;
    }

    string id = linea.substr(0, pos1);

    // Si es el empleado a eliminar, NO lo guardamos
    if (id == buscarID) {
      eliminado = true;
      continue; // Salta esta línea (no la guarda)
    }

    // Guardar todos los demás empleados
    temp << linea << "\n";
  }

  file.close();
  temp.close();

  if (!eliminado) {
    cout << "No se encontró el empleado con ese ID.\n";
    remove("temp_empleados.txt");
    return;
  }

  // Reemplazar archivo original
  remove("empleados.txt");
  rename("temp_empleados.txt", "empleados.txt");

  cout << "\n✓ Empleado eliminado exitosamente.\n";
}

// 7. CONTAR EMPLEADOS
void contarEmpleados() {
  if (!archivoExiste()) {
    cout << "El archivo no existe. Créalo primero (opción 1).\n";
    return;
  }

  ifstream file("empleados.txt");
  string linea;
  int total = 0;

  while (getline(file, linea)) {
    if (!linea.empty())
      total++;
  }

  file.close();

  cout << "\nTotal de empleados registrados: " << total << "\n";
}

// 8. BUSCAR POR PUESTO
void buscarPorPuesto() {
  if (!archivoExiste()) {
    cout << "El archivo no existe. Créalo primero (opción 1).\n";
    return;
  }

  string puestoBuscar;
  cout << "\nPuesto a buscar: ";
  getline(cin, puestoBuscar);

  if (puestoBuscar.empty()) {
    cout << "ERROR: El puesto no puede estar vacío.\n";
    return;
  }

  // Convertir a minúsculas
  string puestoMin = puestoBuscar;
  for (int i = 0; i < puestoMin.length(); i++) {
    puestoMin[i] = tolower(puestoMin[i]);
  }

  ifstream file("empleados.txt");
  string linea;
  bool encontrado = false;
  int contador = 0;

  cout << "\n========== EMPLEADOS EN " << puestoBuscar << " ==========\n";

  while (getline(file, linea)) {
    size_t pos1 = linea.find(';');
    if (pos1 == string::npos)
      continue;

    size_t pos2 = linea.find(';', pos1 + 1);
    if (pos2 == string::npos)
      continue;

    size_t pos3 = linea.find(';', pos2 + 1);
    if (pos3 == string::npos)
      continue;

    size_t pos4 = linea.find(';', pos3 + 1);
    if (pos4 == string::npos)
      continue;

    string id = linea.substr(0, pos1);
    string nombre = linea.substr(pos1 + 1, pos2 - pos1 - 1);
    string edadStr = linea.substr(pos2 + 1, pos3 - pos2 - 1);
    string puesto = linea.substr(pos3 + 1, pos4 - pos3 - 1);
    string salarioStr = linea.substr(pos4 + 1);

    // Convertir puesto a minúsculas
    string puestoActualMin = puesto;
    for (int i = 0; i < puestoActualMin.length(); i++) {
      puestoActualMin[i] = tolower(puestoActualMin[i]);
    }

    if (puestoActualMin.find(puestoMin) != string::npos) {
      encontrado = true;
      contador++;

      cout << "\n[" << contador << "] ID: " << id << "\n";
      cout << "    Nombre: " << nombre << "\n";
      cout << "    Edad: " << edadStr << " años\n";
      cout << "    Salario: $" << salarioStr << "\n";
    }
  }

  file.close();

  if (!encontrado) {
    cout << "No se encontraron empleados en ese puesto.\n";
  } else {
    cout << "\nTotal encontrados: " << contador << "\n";
  }
}

// 9. CALCULAR SALARIO PROMEDIO
void calcularPromedioSalarios() {
  if (!archivoExiste()) {
    cout << "El archivo no existe. Créalo primero (opción 1).\n";
    return;
  }

  ifstream file("empleados.txt");
  string linea;
  double sumaTotal = 0;
  int contador = 0;
  double mayor = 0;
  double menor = 999999999;

  while (getline(file, linea)) {
    size_t pos4 = linea.rfind(';'); // Busca el último punto y coma
    if (pos4 == string::npos)
      continue;

    string salarioStr = linea.substr(pos4 + 1);

    // Convertir string a double
    double salario = 0;
    int puntoPos = -1;
    for (int i = 0; i < salarioStr.length(); i++) {
      if (salarioStr[i] == '.') {
        puntoPos = i;
        break;
      }
    }

    if (puntoPos == -1) {
      for (int i = 0; i < salarioStr.length(); i++) {
        if (salarioStr[i] >= '0' && salarioStr[i] <= '9') {
          salario = salario * 10 + (salarioStr[i] - '0');
        }
      }
    } else {
      for (int i = 0; i < puntoPos; i++) {
        if (salarioStr[i] >= '0' && salarioStr[i] <= '9') {
          salario = salario * 10 + (salarioStr[i] - '0');
        }
      }
      double decimal = 0;
      double divisor = 10;
      for (int i = puntoPos + 1; i < salarioStr.length(); i++) {
        if (salarioStr[i] >= '0' && salarioStr[i] <= '9') {
          decimal += (salarioStr[i] - '0') / divisor;
          divisor *= 10;
        }
      }
      salario += decimal;
    }

    sumaTotal += salario;
    contador++;

    if (salario > mayor)
      mayor = salario;
    if (salario < menor)
      menor = salario;
  }

  file.close();

  if (contador == 0) {
    cout << "No hay empleados registrados.\n";
    return;
  }

  double promedio = sumaTotal / contador;

  cout << "\n========== ESTADÍSTICAS DE SALARIOS ==========\n";
  cout << "Total de empleados: " << contador << "\n";
  cout << "Salario promedio: $" << promedio << "\n";
  cout << "Salario más alto: $" << mayor << "\n";
  cout << "Salario más bajo: $" << menor << "\n";
  cout << "Suma total de salarios: $" << sumaTotal << "\n";
}

// 10. GENERAR REPORTE COMPLETO
void generarReporte() {
  if (!archivoExiste()) {
    cout << "El archivo no existe. Créalo primero (opción 1).\n";
    return;
  }

  // Crear archivo de reporte
  ofstream reporte("reporte_empleados.txt");

  if (!reporte.is_open()) {
    cout << "ERROR: No se pudo crear el archivo de reporte.\n";
    return;
  }

  ifstream file("empleados.txt");
  string linea;

  // Variables para estadísticas
  int totalEmpleados = 0;
  double sumaTotal = 0;
  double salarioMayor = 0;
  double salarioMenor = 999999999;
  string nombreMayor = "";
  string nombreMenor = "";

  // Contar empleados por edad
  int jovenes = 0; // 18-30
  int adultos = 0; // 31-50
  int mayores = 0; // 51+

  // ===== ESCRIBIR ENCABEZADO =====
  reporte << "===============================================\n";
  reporte << "     REPORTE GENERAL DE EMPLEADOS\n";
  reporte << "===============================================\n\n";

  reporte << "--- LISTA DE EMPLEADOS ---\n\n";

  // Leer y escribir cada empleado
  while (getline(file, linea)) {
    size_t pos1 = linea.find(';');
    if (pos1 == string::npos)
      continue;

    size_t pos2 = linea.find(';', pos1 + 1);
    if (pos2 == string::npos)
      continue;

    size_t pos3 = linea.find(';', pos2 + 1);
    if (pos3 == string::npos)
      continue;

    // Extraer datos
    string nombre = linea.substr(0, pos1);
    string edadStr = linea.substr(pos1 + 1, pos2 - pos1 - 1);
    string puesto = linea.substr(pos2 + 1, pos3 - pos2 - 1);
    string salarioStr = linea.substr(pos3 + 1);

    totalEmpleados++;

    // Escribir datos del empleado en el reporte
    reporte << "[" << totalEmpleados << "] " << nombre << "\n";
    reporte << "    Edad: " << edadStr << " años\n";
    reporte << "    Puesto: " << puesto << "\n";
    reporte << "    Salario: $" << salarioStr << "\n";
    reporte << "    ---\n";

    // Convertir edad para estadísticas
    int edad = 0;
    for (int i = 0; i < edadStr.length(); i++) {
      if (edadStr[i] >= '0' && edadStr[i] <= '9') {
        edad = edad * 10 + (edadStr[i] - '0');
      }
    }

    // Clasificar por edad
    if (edad >= 18 && edad <= 30)
      jovenes++;
    else if (edad >= 31 && edad <= 50)
      adultos++;
    else
      mayores++;

    // Convertir salario
    double salario = 0;
    int puntoPos = -1;

    // Buscar punto decimal
    for (int i = 0; i < salarioStr.length(); i++) {
      if (salarioStr[i] == '.') {
        puntoPos = i;
        break;
      }
    }

    // Convertir parte entera
    if (puntoPos == -1) {
      // No tiene decimales
      for (int i = 0; i < salarioStr.length(); i++) {
        if (salarioStr[i] >= '0' && salarioStr[i] <= '9') {
          salario = salario * 10 + (salarioStr[i] - '0');
        }
      }
    } else {
      // Tiene decimales
      for (int i = 0; i < puntoPos; i++) {
        if (salarioStr[i] >= '0' && salarioStr[i] <= '9') {
          salario = salario * 10 + (salarioStr[i] - '0');
        }
      }
      // Parte decimal
      double decimal = 0;
      double divisor = 10;
      for (int i = puntoPos + 1; i < salarioStr.length(); i++) {
        if (salarioStr[i] >= '0' && salarioStr[i] <= '9') {
          decimal += (salarioStr[i] - '0') / divisor;
          divisor *= 10;
        }
      }
      salario += decimal;
    }

    sumaTotal += salario;

    // Verificar si es el mayor o menor salario
    if (salario > salarioMayor) {
      salarioMayor = salario;
      nombreMayor = nombre;
    }

    if (salario < salarioMenor) {
      salarioMenor = salario;
      nombreMenor = nombre;
    }
  }

  file.close();

  if (totalEmpleados == 0) {
    reporte << "No hay empleados registrados.\n";
    reporte.close();
    cout << "No hay empleados para generar reporte.\n";
    return;
  }

  double promedio = sumaTotal / totalEmpleados;

  // ===== ESCRIBIR ESTADÍSTICAS =====

  reporte << "\n--- RESUMEN GENERAL ---\n";
  reporte << "Total de empleados: " << totalEmpleados << "\n";
  reporte << "Suma total de salarios: $" << sumaTotal << "\n";
  reporte << "Salario promedio: $" << promedio << "\n\n";

  reporte << "--- EMPLEADO CON MAYOR SALARIO ---\n";
  reporte << "Nombre: " << nombreMayor << "\n";
  reporte << "Salario: $" << salarioMayor << "\n\n";

  reporte << "--- EMPLEADO CON MENOR SALARIO ---\n";
  reporte << "Nombre: " << nombreMenor << "\n";
  reporte << "Salario: $" << salarioMenor << "\n\n";

  reporte << "--- DISTRIBUCIÓN POR EDAD ---\n";
  reporte << "Jóvenes (18-30): " << jovenes << " empleados\n";
  reporte << "Adultos (31-50): " << adultos << " empleados\n";
  reporte << "Mayores (51+): " << mayores << " empleados\n\n";

  reporte << "===============================================\n";
  reporte << "         FIN DEL REPORTE\n";
  reporte << "===============================================\n";

  reporte.close();

  // Mostrar confirmación
  cout << "\n✓ Reporte generado: 'reporte_empleados.txt'\n";
  cout << "\n¿Ver reporte en pantalla? (s/n): ";
  char ver;
  cin >> ver;
  cin.ignore();

  if (ver == 's' || ver == 'S') {
    // Mostrar el reporte
    ifstream leerReporte("reporte_empleados.txt");
    string lineaReporte;

    cout << "\n";
    while (getline(leerReporte, lineaReporte)) {
      cout << lineaReporte << "\n";
    }

    leerReporte.close();
  }
}

// 11. MOSTRAR EMPLEADO CON MAYOR SALARIO
void mostrarEmpleadoMayorSalario() {
  if (!archivoExiste()) {
    cout << "El archivo no existe. Créalo primero (opción 1).\n";
    return;
  }

  ifstream file("empleados.txt");
  string linea;
  double salarioMayor = 0;
  string nombreMayor = "";
  int edadMayor = 0;
  string puestoMayor = "";

  while (getline(file, linea)) {
    size_t pos1 = linea.find(';');
    if (pos1 == string::npos)
      continue;

    size_t pos2 = linea.find(';', pos1 + 1);
    if (pos2 == string::npos)
      continue;

    size_t pos3 = linea.find(';', pos2 + 1);
    if (pos3 == string::npos)
      continue;

    string nombre = linea.substr(0, pos1);
    string edadStr = linea.substr(pos1 + 1, pos2 - pos1 - 1);
    string puesto = linea.substr(pos2 + 1, pos3 - pos2 - 1);
    string salarioStr = linea.substr(pos3 + 1);

    // Convertir salario
    double salario = 0;
    int puntoPos = -1;

    for (int i = 0; i < salarioStr.length(); i++) {
      if (salarioStr[i] == '.') {
        puntoPos = i;
        break;
      }
    }

    if (puntoPos == -1) {
      for (int i = 0; i < salarioStr.length(); i++) {
        if (salarioStr[i] >= '0' && salarioStr[i] <= '9') {
          salario = salario * 10 + (salarioStr[i] - '0');
        }
      }
    } else {
      for (int i = 0; i < puntoPos; i++) {
        if (salarioStr[i] >= '0' && salarioStr[i] <= '9') {
          salario = salario * 10 + (salarioStr[i] - '0');
        }
      }
      double decimal = 0;
      double divisor = 10;
      for (int i = puntoPos + 1; i < salarioStr.length(); i++) {
        if (salarioStr[i] >= '0' && salarioStr[i] <= '9') {
          decimal += (salarioStr[i] - '0') / divisor;
          divisor *= 10;
        }
      }
      salario += decimal;
    }

    // Si este salario es mayor, guardarlo
    if (salario > salarioMayor) {
      salarioMayor = salario;
      nombreMayor = nombre;
      puestoMayor = puesto;

      // Convertir edad
      edadMayor = 0;
      for (int i = 0; i < edadStr.length(); i++) {
        if (edadStr[i] >= '0' && edadStr[i] <= '9') {
          edadMayor = edadMayor * 10 + (edadStr[i] - '0');
        }
      }
    }
  }

  file.close();

  if (nombreMayor.empty()) {
    cout << "No hay empleados registrados.\n";
    return;
  }

  cout << "\n========== EMPLEADO CON MAYOR SALARIO ==========\n";
  cout << "Nombre: " << nombreMayor << "\n";
  cout << "Edad: " << edadMayor << " años\n";
  cout << "Puesto: " << puestoMayor << "\n";
  cout << "Salario: $" << salarioMayor << "\n";
}

// 12. MOSTRAR EMPLEADO CON MENOR SALARIO
void mostrarEmpleadoMenorSalario() {
  if (!archivoExiste()) {
    cout << "El archivo no existe. Créalo primero (opción 1).\n";
    return;
  }

  ifstream file("empleados.txt");
  string linea;
  double salarioMenor = 999999999;
  string nombreMenor = "";
  int edadMenor = 0;
  string puestoMenor = "";

  while (getline(file, linea)) {
    size_t pos1 = linea.find(';');
    if (pos1 == string::npos)
      continue;

    size_t pos2 = linea.find(';', pos1 + 1);
    if (pos2 == string::npos)
      continue;

    size_t pos3 = linea.find(';', pos2 + 1);
    if (pos3 == string::npos)
      continue;

    string nombre = linea.substr(0, pos1);
    string edadStr = linea.substr(pos1 + 1, pos2 - pos1 - 1);
    string puesto = linea.substr(pos2 + 1, pos3 - pos2 - 1);
    string salarioStr = linea.substr(pos3 + 1);

    // Convertir salario
    double salario = 0;
    int puntoPos = -1;

    for (int i = 0; i < salarioStr.length(); i++) {
      if (salarioStr[i] == '.') {
        puntoPos = i;
        break;
      }
    }

    if (puntoPos == -1) {
      for (int i = 0; i < salarioStr.length(); i++) {
        if (salarioStr[i] >= '0' && salarioStr[i] <= '9') {
          salario = salario * 10 + (salarioStr[i] - '0');
        }
      }
    } else {
      for (int i = 0; i < puntoPos; i++) {
        if (salarioStr[i] >= '0' && salarioStr[i] <= '9') {
          salario = salario * 10 + (salarioStr[i] - '0');
        }
      }
      double decimal = 0;
      double divisor = 10;
      for (int i = puntoPos + 1; i < salarioStr.length(); i++) {
        if (salarioStr[i] >= '0' && salarioStr[i] <= '9') {
          decimal += (salarioStr[i] - '0') / divisor;
          divisor *= 10;
        }
      }
      salario += decimal;
    }

    // Si este salario es menor, guardarlo
    if (salario < salarioMenor) {
      salarioMenor = salario;
      nombreMenor = nombre;
      puestoMenor = puesto;

      // Convertir edad
      edadMenor = 0;
      for (int i = 0; i < edadStr.length(); i++) {
        if (edadStr[i] >= '0' && edadStr[i] <= '9') {
          edadMenor = edadMenor * 10 + (edadStr[i] - '0');
        }
      }
    }
  }

  file.close();

  if (nombreMenor.empty()) {
    cout << "No hay empleados registrados.\n";
    return;
  }

  cout << "\n========== EMPLEADO CON MENOR SALARIO ==========\n";
  cout << "Nombre: " << nombreMenor << "\n";
  cout << "Edad: " << edadMenor << " años\n";
  cout << "Puesto: " << puestoMenor << "\n";
  cout << "Salario: $" << salarioMenor << "\n";
}

// ===== MENÚ PRINCIPAL =====

int main() {
  int opcion;

  cout << "=======================================\n";
  cout << "  SISTEMA DE REGISTRO DE EMPLEADOS    \n";
  cout << "=======================================\n";

  do {
    cout << "\n========== MENÚ ==========\n";
    cout << "1. Crear archivo\n";
    cout << "2. Agregar empleado\n";
    cout << "3. Mostrar todos los empleados\n";
    cout << "4. Buscar empleado por nombre\n";
    cout << "5. Editar empleado\n";
    cout << "6. Eliminar empleado\n";
    cout << "7. Contar empleados\n";
    cout << "8. Buscar por puesto\n";
    cout << "9. Calcular salarios (promedio, mayor, menor)\n";
    cout << "10. Generar reporte completo\n";
    cout << "11. Mostrar empleado con mayor salario\n";
    cout << "12. Mostrar empleado con menor salario\n";
    cout << "0. Salir\n";
    cout << "> ";

    cin >> opcion;
    cin.ignore(); // Limpiar buffer

    switch (opcion) {
    case 1:
      crearArchivo();
      break;
    case 2:
      agregarEmpleado();
      break;
    case 3:
      mostrarEmpleados();
      break;
    case 4:
      buscarEmpleado();
      break;
    case 5:
      editarEmpleado();
      break;
    case 6:
      eliminarEmpleado();
      break;
    case 7:
      contarEmpleados();
      break;
    case 8:
      buscarPorPuesto();
      break;
    case 9:
      calcularPromedioSalarios();
      break;
    case 10:
      generarReporte();
      break;
    case 11:
      mostrarEmpleadoMayorSalario();
      break;
    case 12:
      mostrarEmpleadoMenorSalario();
      break;
    case 0:
      cout << "\n¡Hasta luego!\n";
      break;
    default:
      cout << "Opción inválida.\n";
    }

  } while (opcion != 0);

  return 0;
}

/*
===== FORMATO DRL ARCHIVO =====

Cada empleado se guarda en una línea con este formato:
id;nombre;edad;puesto;salario

Ejemplo:
E001;Juan Perez;30;Gerente;5000.50
E002;Maria Lopez;25;Desarrolladora;3500.00
E003;Carlos Gomez;40;Contador;4000.75

===== VALIDACIONES INCLUIDAS =====

✓ ID único (no se pueden repetir)
✓ ID no puede estar vacío ni tener ';'
✓ Nombre no puede estar vacío ni tener ';'
✓ Edad debe estar entre 18 y 100
✓ Puesto no puede estar vacío ni tener ';'
✓ Salario no puede ser negativo
✓ Pide confirmación antes de eliminar
✓ Usa archivos temporales para no perder datos

===== FUNCIONES IMPLEMENTADAS =====

1. Crear archivo de empleados
2. Agregar nuevo empleado con ID único
3. Mostrar lista completa con IDs
4. Buscar por nombre o ID
5. Editar datos de un empleado (el ID no cambia)
6. Eliminar empleado por ID
7. Contar total de empleados
8. Buscar empleados por puesto
9. Calcular estadísticas de salarios
10. Generar reporte completo con IDs
11. Mostrar empleado con mayor salario
12. Mostrar empleado con menor salario

===== CÓMO FUNCIONA =====

- Los datos se guardan en "empleados.txt"
- Para editar/eliminar se usa archivo temporal
- Si algo falla, el archivo original no se pierde
- Las búsquedas son insensibles a mayúsculas
- Se pueden buscar nombres parciales (ej: "Juan" encuentra "Juan Perez")
*/