// Plantilla COMPLETA de manejo de archivos TXT en C++
// SIN vectores, SIN algorithm - Solo lo básico y fácil de entender
// Cada función de librería está comentada explicando para qué sirve

#include <fstream>  // Para trabajar con archivos (ifstream, ofstream)
#include <iostream> // Para entrada/salida en consola (cout, cin)
#include <string>   // Para usar el tipo string
using namespace std;

struct Persona {
  string nombre;
  int edad;
};

// --- Declaración de funciones ---
void crearArchivo();
void agregarRegistro();
void mostrarRegistros();
void buscarRegistro();
void editarRegistro();
void eliminarRegistro();
void contarRegistros();
void copiarArchivo();
void limpiarArchivo();
// Nuevos métodos
void ordenarPorNombre();
void ordenarPorEdad();
void buscarPorRangoEdad();
void exportarACSV();
void importarDesdeCSV();
void mostrarEstadisticas();
void buscarPorSubcadena();
void eliminarDuplicados();
void respaldarArchivo();
void verificarIntegridad();

int main() {
  int opcion;

  do {
    cout << "\n========== MENU ==========\n";
    cout << "1. Crear archivo\n";
    cout << "2. Agregar registro\n";
    cout << "3. Mostrar registros\n";
    cout << "4. Buscar registro\n";
    cout << "5. Editar registro\n";
    cout << "6. Eliminar registro\n";
    cout << "7. Contar registros\n";
    cout << "8. Copiar archivo\n";
    cout << "9. Limpiar archivo\n";
    cout << "10. Ordenar por nombre\n";
    cout << "11. Ordenar por edad\n";
    cout << "12. Buscar por rango de edad\n";
    cout << "13. Exportar a CSV\n";
    cout << "14. Importar desde CSV\n";
    cout << "15. Mostrar estadísticas\n";
    cout << "16. Buscar por subcadena\n";
    cout << "17. Eliminar duplicados\n";
    cout << "18. Respaldar archivo\n";
    cout << "19. Verificar integridad\n";
    cout << "0. Salir\n";
    cout << "> ";
    cin >> opcion;
    cin.ignore(); // Limpia el buffer después de leer un número

    switch (opcion) {
    case 1:
      crearArchivo();
      break;
    case 2:
      agregarRegistro();
      break;
    case 3:
      mostrarRegistros();
      break;
    case 4:
      buscarRegistro();
      break;
    case 5:
      editarRegistro();
      break;
    case 6:
      eliminarRegistro();
      break;
    case 7:
      contarRegistros();
      break;
    case 8:
      copiarArchivo();
      break;
    case 9:
      limpiarArchivo();
      break;
    case 10:
      ordenarPorNombre();
      break;
    case 11:
      ordenarPorEdad();
      break;
    case 12:
      buscarPorRangoEdad();
      break;
    case 13:
      exportarACSV();
      break;
    case 14:
      importarDesdeCSV();
      break;
    case 15:
      mostrarEstadisticas();
      break;
    case 16:
      buscarPorSubcadena();
      break;
    case 17:
      eliminarDuplicados();
      break;
    case 18:
      respaldarArchivo();
      break;
    case 19:
      verificarIntegridad();
      break;
    case 0:
      cout << "Saliendo...\n";
      break;
    default:
      cout << "Opción inválida.\n";
    }

  } while (opcion != 0);

  return 0;
}

// ==================== FUNCIONES BÁSICAS ====================

// CREAR ARCHIVO (lo crea vacío)
void crearArchivo() {
  // ofstream: Clase para ESCRIBIR en archivos (output file stream)
  ofstream file("datos.txt");

  // ERROR COMÚN: No verificar si el archivo se abrió correctamente
  // is_open(): Verifica si el archivo se pudo abrir/crear
  if (!file.is_open()) {
    cout << "ERROR: No se pudo crear el archivo.\n";
    return;
  }

  cout << "Archivo creado o sobrescrito.\n";
  file.close(); // close(): Cierra el archivo (libera recursos)
}

// AGREGAR REGISTRO
void agregarRegistro() {
  // ios::app: Modo "append", añade al final sin borrar lo anterior
  ofstream file("datos.txt", ios::app);

  // ERROR COMÚN: Olvidar verificar si el archivo existe o se puede abrir
  if (!file.is_open()) {
    cout << "ERROR: No se pudo abrir el archivo. Créalo primero.\n";
    return;
  }

  Persona p;
  cout << "Nombre: ";
  getline(cin, p.nombre); // getline(): Lee toda la línea incluyendo espacios

  // ERROR COMÚN: No validar la entrada de edad
  cout << "Edad: ";
  if (!(cin >> p.edad)) { // Verifica si se ingresó un número válido
    cout << "ERROR: Edad inválida. Debe ser un número.\n";
    cin.clear(); // clear(): Limpia el estado de error de cin
    cin.ignore(10000,
               '\n'); // ignore(): Descarta caracteres hasta encontrar '\n'
    return;
  }
  cin.ignore();

  // ERROR COMÚN: Usar punto y coma en el nombre rompe el formato
  // find(): Busca un carácter/texto en un string. Retorna string::npos si no lo
  // encuentra
  if (p.nombre.find(';') != string::npos) {
    cout << "ERROR: El nombre no puede contener ';'\n";
    return;
  }

  file << p.nombre << ";" << p.edad << "\n";
  cout << "Registro agregado.\n";
  file.close();
}

// MOSTRAR REGISTROS
void mostrarRegistros() {
  // ifstream: Clase para LEER archivos (input file stream)
  ifstream file("datos.txt");

  // ERROR COMÚN: No verificar si el archivo existe
  if (!file.is_open()) {
    cout << "ERROR: No se pudo abrir el archivo.\n";
    return;
  }

  string linea;
  int contador = 0;

  cout << "\n=== REGISTROS ===\n";
  // getline(): Lee una línea completa del archivo
  while (getline(file, linea)) {
    // find(): Busca el carácter ';' que separa nombre y edad
    size_t pos = linea.find(';');

    // ERROR COMÚN: No verificar que el formato sea correcto
    // string::npos: Constante que indica "no encontrado"
    if (pos == string::npos) {
      cout << "ADVERTENCIA: Línea con formato incorrecto: " << linea << "\n";
      continue;
    }

    // substr(inicio, longitud): Extrae una subcadena
    string nombre = linea.substr(0, pos); // Desde 0 hasta pos

    // ERROR COMÚN: stoi() falla si no es número válido
    // stoi(): Convierte string a int (string to integer)
    try {
      int edad = stoi(linea.substr(pos + 1)); // Desde pos+1 hasta el final
      cout << ++contador << ". " << nombre << " | " << edad << " años\n";
    } catch (...) { // catch(...): Captura cualquier error
      cout << "ADVERTENCIA: Edad inválida en: " << linea << "\n";
    }
  }

  if (contador == 0) {
    cout << "No hay registros.\n";
  }

  file.close();
}

// BUSCAR POR NOMBRE EXACTO
void buscarRegistro() {
  ifstream file("datos.txt");

  if (!file.is_open()) {
    cout << "ERROR: No se pudo abrir el archivo.\n";
    return;
  }

  string buscar, linea;
  bool encontrado = false;

  cout << "Nombre a buscar: ";
  getline(cin, buscar);

  while (getline(file, linea)) {
    size_t pos = linea.find(';');
    if (pos == string::npos)
      continue; // Salta líneas mal formadas

    string nombre = linea.substr(0, pos);

    try {
      int edad = stoi(linea.substr(pos + 1));

      if (nombre == buscar) {
        cout << "Encontrado: " << nombre << " | " << edad << " años\n";
        encontrado = true;
      }
    } catch (...) {
      continue;
    }
  }

  if (!encontrado)
    cout << "No encontrado.\n";

  file.close();
}

// EDITAR REGISTRO
void editarRegistro() {
  ifstream file("datos.txt");
  ofstream temp("temp.txt"); // Archivo temporal para guardar cambios

  // ERROR COMÚN: No verificar archivos antes de usarlos
  if (!file.is_open() || !temp.is_open()) {
    cout << "ERROR: No se pudieron abrir los archivos.\n";
    return;
  }

  string buscar, linea;
  bool encontrado = false;

  cout << "Nombre a editar: ";
  getline(cin, buscar);

  while (getline(file, linea)) {
    size_t pos = linea.find(';');
    if (pos == string::npos) {
      temp << linea << "\n";
      continue;
    }

    string nombre = linea.substr(0, pos);
    int edad;

    try {
      edad = stoi(linea.substr(pos + 1));
    } catch (...) {
      temp << linea << "\n";
      continue;
    }

    if (nombre == buscar) {
      encontrado = true;
      cout << "Nuevo nombre: ";
      getline(cin, nombre);
      cout << "Nueva edad: ";
      cin >> edad;
      cin.ignore();
    }

    temp << nombre << ";" << edad << "\n";
  }

  file.close();
  temp.close();

  // ERROR COMÚN: No cerrar archivos antes de remove/rename
  // remove(): Elimina un archivo del sistema
  // rename(): Cambia el nombre de un archivo
  remove("datos.txt");
  rename("temp.txt", "datos.txt");

  if (encontrado)
    cout << "Editado.\n";
  else
    cout << "No encontrado.\n";
}

// ELIMINAR REGISTRO
void eliminarRegistro() {
  ifstream file("datos.txt");
  ofstream temp("temp.txt");

  if (!file.is_open() || !temp.is_open()) {
    cout << "ERROR: No se pudieron abrir los archivos.\n";
    return;
  }

  string buscar, linea;
  bool eliminado = false;

  cout << "Nombre a eliminar: ";
  getline(cin, buscar);

  while (getline(file, linea)) {
    size_t pos = linea.find(';');
    if (pos == string::npos) {
      temp << linea << "\n";
      continue;
    }

    string nombre = linea.substr(0, pos);
    int edad;

    try {
      edad = stoi(linea.substr(pos + 1));
    } catch (...) {
      temp << linea << "\n";
      continue;
    }

    if (nombre == buscar) {
      eliminado = true;
      continue; // continue: Salta a la siguiente iteración (no lo guarda)
    }

    temp << nombre << ";" << edad << "\n";
  }

  file.close();
  temp.close();
  remove("datos.txt");
  rename("temp.txt", "datos.txt");

  if (eliminado)
    cout << "Eliminado.\n";
  else
    cout << "No encontrado.\n";
}

// CONTAR REGISTROS
void contarRegistros() {
  ifstream file("datos.txt");

  if (!file.is_open()) {
    cout << "ERROR: No se pudo abrir el archivo.\n";
    return;
  }

  string linea;
  int contador = 0;

  while (getline(file, linea))
    contador++;

  cout << "Total de registros: " << contador << "\n";
  file.close();
}

// COPIAR ARCHIVO
void copiarArchivo() {
  ifstream file("datos.txt");
  ofstream copia("datos_copia.txt");

  if (!file.is_open() || !copia.is_open()) {
    cout << "ERROR: No se pudieron abrir los archivos.\n";
    return;
  }

  // ERROR COMÚN: rdbuf() copia todo, incluso líneas corruptas
  // rdbuf(): Retorna el buffer del archivo (todo su contenido)
  copia << file.rdbuf();

  cout << "Archivo copiado a 'datos_copia.txt'.\n";
  file.close();
  copia.close();
}

// LIMPIAR ARCHIVO
void limpiarArchivo() {
  // ERROR COMÚN: Olvidar confirmar antes de borrar datos
  char confirmar;
  cout << "¿Estás seguro de vaciar el archivo? (s/n): ";
  cin >> confirmar;
  cin.ignore();

  if (confirmar != 's' && confirmar != 'S') {
    cout << "Operación cancelada.\n";
    return;
  }

  // ios::trunc: Modo "truncate", borra todo el contenido al abrir
  ofstream file("datos.txt", ios::trunc);

  if (!file.is_open()) {
    cout << "ERROR: No se pudo abrir el archivo.\n";
    return;
  }

  cout << "Archivo vaciado.\n";
  file.close();
}

// ==================== FUNCIONES AVANZADAS ====================

// ORDENAR POR NOMBRE (Método de burbuja simple)
void ordenarPorNombre() {
  // Primero leemos cuántos registros hay
  ifstream contador("datos.txt");
  if (!contador.is_open()) {
    cout << "ERROR: No se pudo abrir el archivo.\n";
    return;
  }

  int total = 0;
  string linea;
  while (getline(contador, linea))
    total++;
  contador.close();

  if (total == 0) {
    cout << "No hay registros para ordenar.\n";
    return;
  }

  // Crear arrays para almacenar datos
  string nombres[100]; // Máximo 100 registros
  int edades[100];

  // Leer todos los registros
  ifstream file("datos.txt");
  int i = 0;
  while (getline(file, linea) && i < 100) {
    size_t pos = linea.find(';');
    if (pos == string::npos)
      continue;

    nombres[i] = linea.substr(0, pos);
    try {
      edades[i] = stoi(linea.substr(pos + 1));
      i++;
    } catch (...) {
      continue;
    }
  }
  file.close();
  total = i;

  // Ordenar con método de burbuja
  // Compara cada elemento con todos los siguientes
  for (int i = 0; i < total - 1; i++) {
    for (int j = i + 1; j < total; j++) {
      // Si nombres[i] es mayor alfabéticamente, intercambia
      if (nombres[i] > nombres[j]) {
        // Intercambiar nombres
        string tempNombre = nombres[i];
        nombres[i] = nombres[j];
        nombres[j] = tempNombre;

        // Intercambiar edades correspondientes
        int tempEdad = edades[i];
        edades[i] = edades[j];
        edades[j] = tempEdad;
      }
    }
  }

  // Guardar ordenado
  ofstream salida("datos.txt");
  for (int i = 0; i < total; i++) {
    salida << nombres[i] << ";" << edades[i] << "\n";
  }
  salida.close();

  cout << "Registros ordenados por nombre.\n";
}

// ORDENAR POR EDAD (Método de burbuja)
void ordenarPorEdad() {
  ifstream contador("datos.txt");
  if (!contador.is_open()) {
    cout << "ERROR: No se pudo abrir el archivo.\n";
    return;
  }

  int total = 0;
  string linea;
  while (getline(contador, linea))
    total++;
  contador.close();

  if (total == 0) {
    cout << "No hay registros para ordenar.\n";
    return;
  }

  string nombres[100];
  int edades[100];

  ifstream file("datos.txt");
  int i = 0;
  while (getline(file, linea) && i < 100) {
    size_t pos = linea.find(';');
    if (pos == string::npos)
      continue;

    nombres[i] = linea.substr(0, pos);
    try {
      edades[i] = stoi(linea.substr(pos + 1));
      i++;
    } catch (...) {
      continue;
    }
  }
  file.close();
  total = i;

  // Ordenar por edad de menor a mayor
  for (int i = 0; i < total - 1; i++) {
    for (int j = i + 1; j < total; j++) {
      if (edades[i] > edades[j]) {
        // Intercambiar edades
        int tempEdad = edades[i];
        edades[i] = edades[j];
        edades[j] = tempEdad;

        // Intercambiar nombres
        string tempNombre = nombres[i];
        nombres[i] = nombres[j];
        nombres[j] = tempNombre;
      }
    }
  }

  ofstream salida("datos.txt");
  for (int i = 0; i < total; i++) {
    salida << nombres[i] << ";" << edades[i] << "\n";
  }
  salida.close();

  cout << "Registros ordenados por edad.\n";
}

// BUSCAR POR RANGO DE EDAD
void buscarPorRangoEdad() {
  ifstream file("datos.txt");

  if (!file.is_open()) {
    cout << "ERROR: No se pudo abrir el archivo.\n";
    return;
  }

  int minimo, maximo;
  cout << "Edad mínima: ";
  cin >> minimo;
  cout << "Edad máxima: ";
  cin >> maximo;
  cin.ignore();

  // ERROR COMÚN: No validar que mínimo <= máximo
  if (minimo > maximo) {
    cout << "ERROR: El mínimo no puede ser mayor que el máximo.\n";
    return;
  }

  string linea;
  int encontrados = 0;

  cout << "\n=== RESULTADOS ===\n";
  while (getline(file, linea)) {
    size_t pos = linea.find(';');
    if (pos == string::npos)
      continue;

    string nombre = linea.substr(0, pos);

    try {
      int edad = stoi(linea.substr(pos + 1));

      // Verifica si está en el rango
      if (edad >= minimo && edad <= maximo) {
        cout << nombre << " | " << edad << " años\n";
        encontrados++;
      }
    } catch (...) {
      continue;
    }
  }

  if (encontrados == 0) {
    cout << "No se encontraron registros en ese rango.\n";
  } else {
    cout << "\nTotal encontrados: " << encontrados << "\n";
  }

  file.close();
}

// EXPORTAR A CSV (formato con comas)
void exportarACSV() {
  ifstream file("datos.txt");
  ofstream csv("datos.csv");

  if (!file.is_open() || !csv.is_open()) {
    cout << "ERROR: No se pudieron abrir los archivos.\n";
    return;
  }

  // Escribir encabezado del CSV
  csv << "Nombre,Edad\n";

  string linea;
  while (getline(file, linea)) {
    size_t pos = linea.find(';');
    if (pos == string::npos)
      continue;

    string nombre = linea.substr(0, pos);
    string edad = linea.substr(pos + 1);

    // ERROR COMÚN: No escapar comas en los datos
    // Solución: encerrar entre comillas
    csv << "\"" << nombre << "\"," << edad << "\n";
  }

  file.close();
  csv.close();

  cout << "Datos exportados a 'datos.csv'.\n";
}

// IMPORTAR DESDE CSV
void importarDesdeCSV() {
  ifstream csv("datos.csv");

  if (!csv.is_open()) {
    cout << "ERROR: No se encontró 'datos.csv'.\n";
    return;
  }

  // ios::app para añadir sin borrar datos existentes
  ofstream file("datos.txt", ios::app);

  string linea;
  getline(csv, linea); // Salta la primera línea (encabezado)

  int importados = 0;
  while (getline(csv, linea)) {
    size_t pos = linea.find(',');
    if (pos == string::npos)
      continue;

    string nombre = linea.substr(0, pos);

    // ERROR COMÚN: No limpiar comillas si existen
    // length(): Retorna el tamaño del string
    if (!nombre.empty() && nombre[0] == '"') {
      nombre = nombre.substr(1, nombre.length() - 2);
    }

    string edad = linea.substr(pos + 1);

    file << nombre << ";" << edad << "\n";
    importados++;
  }

  csv.close();
  file.close();

  cout << "Importados " << importados << " registros.\n";
}

// MOSTRAR ESTADÍSTICAS (promedio, menor, mayor)
void mostrarEstadisticas() {
  ifstream file("datos.txt");

  if (!file.is_open()) {
    cout << "ERROR: No se pudo abrir el archivo.\n";
    return;
  }

  int edades[100];
  int total = 0;
  string linea;

  while (getline(file, linea) && total < 100) {
    size_t pos = linea.find(';');
    if (pos == string::npos)
      continue;

    try {
      edades[total] = stoi(linea.substr(pos + 1));
      total++;
    } catch (...) {
      continue;
    }
  }
  file.close();

  if (total == 0) {
    cout << "No hay registros para analizar.\n";
    return;
  }

  // Calcular estadísticas
  int suma = 0, menor = edades[0], mayor = edades[0];

  for (int i = 0; i < total; i++) {
    suma += edades[i];
    if (edades[i] < menor)
      menor = edades[i];
    if (edades[i] > mayor)
      mayor = edades[i];
  }

  // static_cast<double>: Convierte int a double para división decimal
  double promedio = static_cast<double>(suma) / total;

  cout << "\n=== ESTADÍSTICAS ===\n";
  cout << "Total de registros: " << total << "\n";
  cout << "Edad promedio: " << promedio << " años\n";
  cout << "Edad menor: " << menor << " años\n";
  cout << "Edad mayor: " << mayor << " años\n";
}

// BUSCAR POR SUBCADENA (busca en cualquier parte del nombre)
void buscarPorSubcadena() {
  ifstream file("datos.txt");

  if (!file.is_open()) {
    cout << "ERROR: No se pudo abrir el archivo.\n";
    return;
  }

  string buscar, linea;
  cout << "Texto a buscar: ";
  getline(cin, buscar);

  // Convertir búsqueda a minúsculas para comparación insensible
  // ERROR COMÚN: No convertir a minúsculas, hace búsqueda sensible
  for (int i = 0; i < buscar.length(); i++) {
    // tolower(): Convierte un carácter a minúscula
    buscar[i] = tolower(buscar[i]);
  }

  int encontrados = 0;
  cout << "\n=== RESULTADOS ===\n";

  while (getline(file, linea)) {
    size_t pos = linea.find(';');
    if (pos == string::npos)
      continue;

    string nombre = linea.substr(0, pos);
    string nombreMin = nombre;

    // Convertir nombre a minúsculas
    for (int i = 0; i < nombreMin.length(); i++) {
      nombreMin[i] = tolower(nombreMin[i]);
    }

    // find(): Si encuentra, retorna la posición; si no, retorna string::npos
    if (nombreMin.find(buscar) != string::npos) {
      try {
        int edad = stoi(linea.substr(pos + 1));
        cout << nombre << " | " << edad << " años\n";
        encontrados++;
      } catch (...) {
        continue;
      }
    }
  }

  if (encontrados == 0) {
    cout << "No se encontraron coincidencias.\n";
  } else {
    cout << "\nTotal encontrados: " << encontrados << "\n";
  }

  file.close();
}

// ELIMINAR DUPLICADOS (mantiene solo la primera aparición)
void eliminarDuplicados() {
  ifstream file("datos.txt");

  if (!file.is_open()) {
    cout << "ERROR: No se pudo abrir el archivo.\n";
    return;
  }

  string nombres[100];
  int edades[100];
  int total = 0;
  int eliminados = 0;
  string linea;

  while (getline(file, linea) && total < 100) {
    size_t pos = linea.find(';');
    if (pos == string::npos)
      continue;

    string nombre = linea.substr(0, pos);

    try {
      int edad = stoi(linea.substr(pos + 1));

      // Verificar si ya existe este nombre
      bool duplicado = false;
      for (int i = 0; i < total; i++) {
        if (nombres[i] == nombre) {
          duplicado = true;
          eliminados++;
          break;
        }
      }

      // Si no es duplicado, guardarlo
      if (!duplicado) {
        nombres[total] = nombre;
        edades[total] = edad;
        total++;
      }
    } catch (...) {
      continue;
    }
  }
  file.close();

  // Guardar sin duplicados
  ofstream salida("datos.txt");
  for (int i = 0; i < total; i++) {
    salida << nombres[i] << ";" << edades[i] << "\n";
  }
  salida.close();

  cout << "Se eliminaron " << eliminados << " registros duplicados.\n";
}

// RESPALDAR ARCHIVO (crear copia de seguridad)
void respaldarArchivo() {
  ifstream file("datos.txt");

  if (!file.is_open()) {
    cout << "ERROR: No se pudo abrir el archivo.\n";
    return;
  }

  string nombreRespaldo = "datos_respaldo.txt";
  ofstream respaldo(nombreRespaldo);

  if (!respaldo.is_open()) {
    cout << "ERROR: No se pudo crear el respaldo.\n";
    return;
  }

  // Copiar todo el contenido
  respaldo << file.rdbuf();

  file.close();
  respaldo.close();

  cout << "Respaldo creado: " << nombreRespaldo << "\n";
}

// VERIFICAR INTEGRIDAD (detecta líneas con errores)
void verificarIntegridad() {
  ifstream file("datos.txt");

  if (!file.is_open()) {
    cout << "ERROR: No se pudo abrir el archivo.\n";
    return;
  }

  string linea;
  int lineaNum = 0, errores = 0, correctas = 0;

  cout << "\n=== VERIFICACIÓN DE INTEGRIDAD ===\n";

  while (getline(file, linea)) {
    lineaNum++;
    size_t pos = linea.find(';');

    // Verificar que tenga el delimitador
    if (pos == string::npos) {
      cout << "Línea " << lineaNum << ": ERROR - Falta delimitador ';'\n";
      errores++;
      continue;
    }

    string nombre = linea.substr(0, pos);
    string edadStr = linea.substr(pos + 1);

    // empty(): Retorna true si el string está vacío
    if (nombre.empty()) {
      cout << "Línea " << lineaNum << ": ERROR - Nombre vacío\n";
      errores++;
      continue;
    }

    try {
      int edad = stoi(edadStr);
      // Verificar rangos razonables
      if (edad < 0 || edad > 150) {
        cout << "Línea " << lineaNum
             << ": ADVERTENCIA - Edad fuera de rango: " << edad << "\n";
      }
      correctas++;
    } catch (...) {
      cout << "Línea " << lineaNum << ": ERROR - Edad no es un número válido: '"
           << edadStr << "'\n";
      errores++;
    }
  }

  file.close();

  cout << "\n=== RESUMEN ===\n";
  cout << "Líneas correctas: " << correctas << "\n";
  cout << "Líneas con errores: " << errores << "\n";

  if (errores == 0) {
    cout << "¡El archivo está íntegro!\n";
  } else {
    cout << "Se recomienda corregir los errores.\n";
  }
}