#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <climits>//es para usar INT_MIN y INT_MAX
using namespace std;

/*
 Función que limpia la pantalla del sistema operativo.
 Dependiendo si es Windows o Linux/Mac, ejecuta el comando correspondiente.
 En Windows usa "cls" y en sistemas Unix usa "clear".
*/
void cls() {
#ifdef _WIN32
    system("cls");  // Comando para limpiar pantalla en Windows
#else
    system("clear");  // Comando para limpiar pantalla en Unix/Linux/Mac
#endif
}

/*
  Limpia el buffer de entrada del teclado para evitar errores.
  Esto es importante cuando el usuario ingresa datos invalidos o 
  cuando se mezclan diferentes tipos de entrada (numeros y letras).
  Previene comportamientos inesperados en futuras lecturas.
*/
void buffer(){
    cin.clear();  // Limpia los flags de error del stream
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descarta todo hasta el salto de linea
}

/*
  Esta función solicita al usuario un número entero y lo valida automaticamente.
  Si el usuario ingresa algo incorrecto (como letras, caracteres especiales, 
  o un numero fuera del rango permitido), el programa vuelve a pedir el dato.
  
  Parametros:
  - mensaje: El texto que se mostrara al usuario al pedir el numero
  - minVal: Valor minimo permitido (por defecto INT_MIN)
  - maxVal: Valor maximo permitido (por defecto INT_MAX)
  
  Retorna: El numero entero validado dentro del rango especificado
*/
int leerEnteroValidado(const string &mensaje, int minVal = INT_MIN, int maxVal = INT_MAX) {
    int x;
    while (true) {  // Ciclo infinito hasta obtener entrada valida
        cout << mensaje;
        if (cin >> x) {  // Intenta leer un entero
            if (x >= minVal && x <= maxVal) {  // Verifica que este en el rango
                buffer();  // Limpia el buffer antes de retornar
                return x;
            }
        }
        // Si llega aqui, la entrada fue invalida
        cout << "  Entrada invalida. Intente de nuevo.\n";
        buffer();  // Limpia el buffer para poder pedir de nuevo
    }
}

/*
  Esta función "redimenciona" los arreglos dinamicos cuando se necesita mas espacio.
  Se usa cuando la capacidad actual ya no es suficiente y se requiere registrar
  mas aspirantes. El proceso consiste en:
  1. Crear nuevos arreglos mas grandes
  2. Copiar todos los datos antiguos a los nuevos arreglos
  3. Liberar la memoria de los arreglos antiguos
  4. Actualizar las referencias para que apunten a los nuevos arreglos
  
  Parametros: Referencias a todos los arreglos dinamicos del sistema,
  la capacidad actual y la nueva capacidad deseada.
*/
void redimensionaArreglos(string *&nombre, string *&identificacion, int *&edad, 
                        int *&nivelAcademico, int *&experiencia, int *&pruebaTecnica, 
                        int *&entrevista, float *&puntajeTotal, 
                        int capacidadActual, int nuevaCapacidad) {
    
    // Paso 1: Crear nuevos arreglos con mayor capacidad
    string *nuevoNombre = new string[nuevaCapacidad];
    string *nuevoIdentificacion = new string[nuevaCapacidad];
    int *nuevoEdad = new int[nuevaCapacidad]();  // () inicializa en cero
    int *nuevoNivelAcademico = new int[nuevaCapacidad]();
    int *nuevoExperiencia = new int[nuevaCapacidad]();
    int *nuevoPruebaTecnica = new int[nuevaCapacidad]();
    int *nuevoEntrevista = new int[nuevaCapacidad]();
    float *nuevoPuntajeTotal = new float[nuevaCapacidad]();
    
    // Paso 2: Copiar todos los datos existentes a los nuevos arreglos
    for (int i = 0; i < capacidadActual; ++i) {
        nuevoNombre[i] = nombre[i];
        nuevoIdentificacion[i] = identificacion[i];
        nuevoEdad[i] = edad[i];
        nuevoNivelAcademico[i] = nivelAcademico[i];
        nuevoExperiencia[i] = experiencia[i];
        nuevoPruebaTecnica[i] = pruebaTecnica[i];
        nuevoEntrevista[i] = entrevista[i];
        nuevoPuntajeTotal[i] = puntajeTotal[i];
    }
    
    // Paso 3: Liberar la memoria de los arreglos antiguos para evitar fugas de memoria
    delete[] nombre;
    delete[] identificacion;
    delete[] edad;
    delete[] nivelAcademico;
    delete[] experiencia;
    delete[] pruebaTecnica;
    delete[] entrevista;
    delete[] puntajeTotal;
    
    // Paso 4: Asignar los punteros a los nuevos arreglos
    nombre = nuevoNombre;
    identificacion = nuevoIdentificacion;
    edad = nuevoEdad;
    nivelAcademico = nuevoNivelAcademico;
    experiencia = nuevoExperiencia;
    pruebaTecnica = nuevoPruebaTecnica;
    entrevista = nuevoEntrevista;
    puntajeTotal = nuevoPuntajeTotal;
}

/*
  Función principal para registrar nuevos aspirantes en el sistema.
  Permite ingresar multiples aspirantes de una sola vez.
  
  Procesos que realiza:
  1. Pregunta cuantos aspirantes se van a registrar
  2. Verifica si hay suficiente espacio, si no, redimenciona los arreglos
  3. Para cada aspirante, solicita y valida todos sus datos
  4. Verifica que la identificacion no este duplicada
  5. Incrementa el contador total de aspirantes
  
  Parametros: Referencias a todos los arreglos del sistema, el total actual
  de aspirantes y la capacidad de los arreglos.
*/
void registrarAspirantes(string *&nombre, string *&identificacion, int *&edad, 
                        int *&nivelAcademico, int *&experiencia, int *&pruebaTecnica, 
                        int *&entrevista, float *&puntajeTotal, 
                        int &totalAspirantes, int &capacidad) {
    cls();  // Limpia la pantalla para mejor visualizacion
    
    // Pregunta cuantos aspirantes se van a registrar (minimo 1)
    int n = leerEnteroValidado("\n¿Cuantos aspirantes desea registrar? (>=1): ", 1);

    // Verifica si hay suficiente espacio en los arreglos
    if (totalAspirantes + n > capacidad) {
        // Calcula nueva capacidad con margen adicional de 10 espacios
        int nuevaCapacidad = totalAspirantes + n + 10;
        redimensionaArreglos(nombre, identificacion, edad, nivelAcademico, 
                           experiencia, pruebaTecnica, entrevista, puntajeTotal, 
                           totalAspirantes, nuevaCapacidad);
        capacidad = nuevaCapacidad;
        cout << "Arrays redimenzionados a capacidad: " << capacidad << "\n";  // Error: "redimenzionados"
    }

    // Ciclo para registrar cada uno de los nuevos aspirantes
    for (int i = 0; i < n; ++i) {
        int idx = totalAspirantes;  // Indice donde se guardara este aspirante
        cout << "\n--- Rejistro del aspirante " << (totalAspirantes + 1) << " ---\n";  // Error: "Rejistro"

        // Solicita el nombre completo del aspirante
        cout << "Nombre completo: ";
        getline(cin, nombre[idx]);  // Lee linea completa para permitir espacios
        // Valida que no este vacio
        while (nombre[idx].empty()) {
            cout << "  Nombre invalido. Ingrese el nombre: ";
            getline(cin, nombre[idx]);
        }

        // Solicita y valida el numero de identificacion (debe ser unico)
        bool duplicado;
        do {
            duplicado = false;
            cout << "Numero de identificacion: ";
            getline(cin, identificacion[idx]);
            
            // Verifica que no este vacio
            if (identificacion[idx].empty()) {
                cout << "  Identificacion invalida. Intente de nuevo.\n";
                duplicado = true;
                continue;
            }
            
            // Verifica que no exista ya en el sistema
            for (int j = 0; j < totalAspirantes; ++j) {
                if (identificacion[j] == identificacion[idx]) {
                    cout << "  Identificacion ya rejistrada. Ingrese otra.\n";  // Error: "rejistrada"
                    duplicado = true;
                    break;
                }
            }
        } while (duplicado);  // Repite hasta obtener una identificacion valida y unica

        // Solicita la edad (debe ser mayor o igual a 18)
        edad[idx] = leerEnteroValidado("Edad (>=18): ", 18);

        // Solicita el nivel academico del aspirante
        cout << "Nivel academico (1=Tecnico, 2=Tecnologo, 3=Profesional, 4=Posgrado)\n";
        nivelAcademico[idx] = leerEnteroValidado("Ingrese nivel (1-4): ", 1, 4);

        // Solicita los años de experiencia laboral
        experiencia[idx] = leerEnteroValidado("Años de eksperiencia (>=0): ", 0);  // Error: "eksperiencia"
        
        // Solicita el puntaje de la prueba tecnica (0 a 100)
        pruebaTecnica[idx] = leerEnteroValidado("Puntaje prueba tecnica (0-100): ", 0, 100);
        
        // Solicita el puntaje de la entrevista (0 a 100)
        entrevista[idx] = leerEnteroValidado("Puntaje entrevista (0-100): ", 0, 100);

        // Inicializa el puntaje total en 0 (se calculara despues)
        puntajeTotal[idx] = 0.0f;
        
        // Incrementa el contador total de aspirantes
        totalAspirantes++;

        cout << "Aspirante registrado correctamente.\n";
    }

    system("pause");  // Pausa para que el usuario vea el resultado
    cls();  // Limpia la pantalla
}

/*
  Calcula el puntaje final de un aspirante basandose en 4 criterios:
  1. Nivel academico (15 a 30 puntos)
  2. Años de experiencia (5 a 20 puntos)
  3. Puntaje de prueba tecnica (10 a 30 puntos)
  4. Puntaje de entrevista (5 a 20 puntos)
  
  El puntaje maximo posible es 100 puntos.
  
  Parametros:
  - nivel: Nivel academico del aspirante (1 a 4)
  - exp: Años de experiencia laboral
  - prueba: Puntaje obtenido en la prueba tecnica
  - entrev: Puntaje obtenido en la entrevista
  
  Retorna: El puntaje total calculado
*/
float calcularPuntaje(int nivel, int exp, int prueba, int entrev) {
    float total = 0.0f;

    // Calcula puntos según nivel académico
    // Técnico (1) = 15 pts, Tecnólogo (2) = 20 pts, 
    // Profesional (3) = 25 pts, Posgrado (4) = 30 pts
    switch (nivel) {
        case 1: total += 15; break;
        case 2: total += 20; break;
        case 3: total += 25; break;
        case 4: total += 30; break;
    }

    // Calcula puntos según años de experiencia
    // Menos de 1 año = 5 pts, 1-3 años = 10 pts,
    // 4-6 años = 15 pts, Más de 6 años = 20 pts
    if (exp < 1) total += 5;
    else if (exp <= 3) total += 10;
    else if (exp <= 6) total += 15;
    else total += 20;

    // Calcula puntos según puntaje de prueba técnica
    // Menos de 60 = 10 pts, 60-79 = 20 pts,
    // 80-89 = 25 pts, 90-100 = 30 pts
    if (prueba < 60) total += 10;
    else if (prueba <= 79) total += 20;
    else if (prueba <= 89) total += 25;
    else total += 30;

    // Calcula puntos según puntaje de entrevista
    // Menos de 60 = 5 pts, 60-79 = 10 pts,
    // 80-89 = 15 pts, 90-100 = 20 pts
    if (entrev < 60) total += 5;
    else if (entrev <= 79) total += 10;
    else if (entrev <= 89) total += 15;
    else total += 20;

    return total;  // Retorna el puntaje total calculado
}

/*
  Recorre todos los aspirantes registrados y calcula sus puntajes totales.
  Utiliza la función calcularPuntaje para cada aspirante y guarda el resultado
  en el arreglo puntajeTotal.
  
  Parametros: Todos los arreglos del sistema y el total de aspirantes.
*/
void calcularPuntajes(string *nombre, string *identificacion, int *edad, 
                     int *nivelAcademico, int *experiencia, int *pruebaTecnica, 
                     int *entrevista, float *puntajeTotal, int totalAspirantes) {
    cls();  // Limpia la pantalla
    
    // Verifica si hay aspirantes registrados
    if (totalAspirantes == 0) {
        cout << "\nNo hay aspirantes rejistrados.\n";  // Error: "rejistrados"
        system("pause");
        cls();
        return;
    }

    cout << "\n=== Calculando puntajes totales ===\n";
    
    // Recorre cada aspirante y calcula su puntaje
    for (int i = 0; i < totalAspirantes; ++i) {
        puntajeTotal[i] = calcularPuntaje(nivelAcademico[i], experiencia[i], 
                                         pruebaTecnica[i], entrevista[i]);
    }
    
    cout << "Puntajes calculados para " << totalAspirantes << " aspirantes.\n";

    system("pause");  // Pausa para que el usuario vea el resultado
    cls();
}

/*
  Muestra un reporte general con todos los aspirantes registrados en el sistema.
  Presenta una tabla formateada con todos los datos de cada aspirante:
  nombre, identificacion, edad, nivel academico, experiencia, puntajes y total.
  
  Utiliza la libreria iomanip para alinear correctamente las columnas.
  
  Parametros: Todos los arreglos del sistema y el total de aspirantes.
*/
void reporteGeneral(string *nombre, string *identificacion, int *edad, 
                   int *nivelAcademico, int *experiencia, int *pruebaTecnica, 
                   int *entrevista, float *puntajeTotal, int totalAspirantes) {
    cls();
    
    // Verifica si hay datos para mostrar
    if (totalAspirantes == 0) {
        cout << "\nNo hay aspirantes registrados.\n";
        system("pause");
        cls();
        return;
    }

    // Muestra el encabezado del reporte
    cout << "\n=== LISTADO JENERAL DE ASPIRANTES ===\n";  // Error: "JENERAL"
    
    // Muestra los encabezados de las columnas con formato alineado
    cout << left << setw(20) << "Nombre" << setw(12) << "ID" << setw(6) << "Edad"
         << setw(6) << "Niv" << setw(8) << "Exp" << setw(8) << "Prueba"
         << setw(10) << "Entrev" << setw(10) << "Puntaje" << "\n";
    
    // Linea separadora
    cout << string(80, '-') << "\n";

    // Recorre e imprime los datos de cada aspirante
    for (int i = 0; i < totalAspirantes; ++i) {
        cout << left << setw(20) << nombre[i]
             << setw(12) << identificacion[i]
             << setw(6) << edad[i]
             << setw(6) << nivelAcademico[i]
             << setw(8) << experiencia[i]
             << setw(8) << pruebaTecnica[i]
             << setw(10) << entrevista[i]
             << setw(10) << puntajeTotal[i] << "\n";
    }

    system("pause");  // Espera que el usuario presione una tecla
    cls();
}

/*
  Muestra un reporte de aspirantes ordenados por puntaje total de mayor a menor.
  No modifica los arreglos originales, sino que crea un arreglo de indices
  y ordena ese arreglo segun los puntajes.
  
  Utiliza el algoritmo de ordenamiento burbuja (bubble sort).
  
  Parametros: Todos los arreglos del sistema y el total de aspirantes.
*/
void reporteOrdenado(string *nombre, string *identificacion, int *edad, 
                    int *nivelAcademico, int *experiencia, int *pruebaTecnica, 
                    int *entrevista, float *puntajeTotal, int totalAspirantes) {
    cls();
    
    // Verifica si hay datos para ordenar
    if (totalAspirantes == 0) {
        cout << "\nNo hay aspirantes registrados.\n";
        system("pause");
        cls();
        return;
    }

    // Crea un arreglo dinamico de indices
    int *indices = new int[totalAspirantes];
    for (int i = 0; i < totalAspirantes; ++i) {
        indices[i] = i;  // Inicializa cada indice con su posicion original
    }
    
    // Ordena los indices basandose en los puntajes (descendente - mayor a menor)
    // Utiliza algoritmo de ordenamiento burbuja
    for (int i = 0; i < totalAspirantes - 1; ++i) {
        for (int j = 0; j < totalAspirantes - i - 1; ++j) {
            // Compara puntajes y intercambia indices si es necesario
            if (puntajeTotal[indices[j]] < puntajeTotal[indices[j + 1]]) {
                int temp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp;
            }
        }
    }

    // Muestra el reporte ordenado
    cout << "\n=== ASPIRANTES ORDENADOS POR PUNTAJE (DESC) ===\n";
    for (int i = 0; i < totalAspirantes; ++i) {
        int idx = indices[i];  // Obtiene el indice ordenado
        cout << left << setw(20) << nombre[idx]
             << " ID:" << setw(10) << identificacion[idx]
             << " Puntaje: " << puntajeTotal[idx] << "\n";
    }

    delete[] indices;  // Libera la memoria del arreglo de indices
    system("pause");
    cls();
}

/*
  Permite consultar la informacion detallada de un aspirante especifico
  mediante su numero de identificacion.
  
  Busca el aspirante en el sistema y muestra todos sus datos si lo encuentra.
  Si no existe, informa al usuario que no se encontro.
  
  Parametros: Todos los arreglos del sistema y el total de aspirantes.
*/
void consultaAspirante(string *nombre, string *identificacion, int *edad, 
                      int *nivelAcademico, int *experiencia, int *pruebaTecnica, 
                      int *entrevista, float *puntajeTotal, int totalAspirantes) {
    cls();
    
    // Verifica si hay aspirantes en el sistema
    if (totalAspirantes == 0) {
        cout << "\nNo hay aspirantes registrados.\n";
        system("pause");
        cls();
        return;
    }

    // Solicita la identificacion a buscar
    cout << "\nIngrese identificasion a consultar: ";  // Error: "identificasion"
    string id;
    buffer();  // Limpia el buffer antes de leer
    getline(cin, id);  // Lee la identificacion
    
    bool encontrado = false;
    
    // Busca el aspirante en el sistema
    for (int i = 0; i < totalAspirantes; ++i) {
        if (identificacion[i] == id) {
            encontrado = true;
            
            // Muestra toda la informacion del aspirante encontrado
            cout << "\n=== DETALLE DEL ASPIRANTE ===\n";
            cout << "Nombre: " << nombre[i] << "\n";
            cout << "ID: " << identificacion[i] << "\n";
            cout << "Edad: " << edad[i] << "\n";
            cout << "Nivel academico: " << nivelAcademico[i] << "\n";
            cout << "Experiencia: " << experiencia[i] << " años\n";
            cout << "Prueba tecnica: " << pruebaTecnica[i] << "\n";
            cout << "Entrevista: " << entrevista[i] << "\n";
            cout << "Puntaje total: " << puntajeTotal[i] << "\n";
            break;  // Sale del ciclo al encontrar el aspirante
        }
    }
    
    // Si no se encontro, informa al usuario
    if (!encontrado) 
        cout << "No se encontro aspirante con ID: " << id << "\n";

    system("pause");
    cls();
}

/*
  Submenu de reportes y consultas.
  Presenta opciones para ver diferentes reportes y realizar consultas
  sobre los aspirantes registrados:
  1. Listado general (todos los aspirantes)
  2. Reporte ordenado por puntaje
  3. Consulta por identificacion
  4. Volver al menu principal
  
  Parametros: Todos los arreglos del sistema y el total de aspirantes.
*/
void menuReportes(string *nombre, string *identificacion, int *edad, 
                 int *nivelAcademico, int *experiencia, int *pruebaTecnica, 
                 int *entrevista, float *puntajeTotal, int totalAspirantes) {
    int op;
    do {
        // Muestra las opciones del submenu
        cout << "\n=== SUBMENU: REPORTES Y CONSULTAS ===\n";
        cout << "1. Listado general de aspirantes\n";
        cout << "2. Reporte ordenado por puntaje\n";
        cout << "3. Consulta por identificacion\n";
        cout << "4. Volver\n";
        op = leerEnteroValidado("Seleccione una opcion (1-4): ", 1, 4);

        // Ejecuta la opcion seleccionada
        switch (op) {
            case 1: 
                // Muestra listado completo de todos los aspirantes
                reporteGeneral(nombre, identificacion, edad, nivelAcademico, 
                               experiencia, pruebaTecnica, entrevista, puntajeTotal, totalAspirantes); 
                break;
            case 2: 
                // Muestra aspirantes ordenados por puntaje
                reporteOrdenado(nombre, identificacion, edad, nivelAcademico, 
                                experiencia, pruebaTecnica, entrevista, puntajeTotal, totalAspirantes); 
                break;
            case 3: 
                // Permite consultar un aspirante especifico
                consultaAspirante(nombre, identificacion, edad, nivelAcademico, 
                                  experiencia, pruebaTecnica, entrevista, puntajeTotal, totalAspirantes); 
                break;
            case 4: 
                cls();  // Limpia pantalla al volver
                break;
        }
    } while (op != 4);  // Repite hasta que el usuario elija volver
}

/*
  Menu principal del sistema de gestion de aspirantes de TechSolutions S.A.
  
  Esta funcion inicializa todos los arreglos dinamicos necesarios y presenta
  el menu principal con las siguientes opciones:
  1. Registro de aspirantes
  2. Calculo de puntaje total
  3. Reportes y consultas
  4. Salir del sistema
  
  Utiliza memoria dinamica para manejar los datos de forma eficiente y
  permite redimensionar los arreglos automaticamente cuando sea necesario.
  
  Al finalizar, libera toda la memoria dinamica utilizada.
*/
void menuPrincipal() {
    // Configuracion inicial de los arreglos
    int capacidadInicial = 1;  // Inicia con capacidad para 1 aspirante (actualisable)
    int capacidad = capacidadInicial;
    int totalAspirantes = 0;  // Contador de aspirantes registrados
    
    // Creacion de arreglos dinamicos con capacidad inicial
    // Estos arreglos almacenaran toda la informacion de los aspirantes
    string *nombre = new string[capacidad];
    string *identificacion = new string[capacidad];
    int *edad = new int[capacidad]();  // () inicializa en 0
    int *nivelAcademico = new int[capacidad]();
    int *experiencia = new int[capacidad]();
    int *pruebaTecnica = new int[capacidad]();
    int *entrevista = new int[capacidad]();
    float *puntajeTotal = new float[capacidad]();
    
    int opcion;
    do {
        // Muestra el menu principal con informacion de capacidad y registros
        cout << "\n=== TechSolutions S.A. - Gestion de Aspirantes ===\n";
        cout << "Capacidad actual: " << capacidad << " | Registrados: " << totalAspirantes << "\n";
        cout << "1. Rejistro de aspirantes\n";  // Error: "Rejistro"
        cout << "2. Calculo de puntaje total\n";
        cout << "3. Reportes y consultas\n";
        cout << "4. Salir\n";
        opcion = leerEnteroValidado("Seleccione una opcion (1-4): ", 1, 4);

        cls();  // Limpia la pantalla antes de ejecutar la opcion
        
        // Ejecuta la opcion seleccionada por el usuario
        switch (opcion) {
            case 1: 
                // Permite registrar nuevos aspirantes en el sistema
                registrarAspirantes(nombre, identificacion, edad, nivelAcademico, 
                                   experiencia, pruebaTecnica, entrevista, puntajeTotal, 
                                   totalAspirantes, capacidad); 
                break;
            case 2: 
                // Calcula los puntajes totales de todos los aspirantes
                calcularPuntajes(nombre, identificacion, edad, nivelAcademico, 
                                experiencia, pruebaTecnica, entrevista, puntajeTotal, totalAspirantes); 
                break;
            case 3: 
                // Abre el submenu de reportes y consultas
                menuReportes(nombre, identificacion, edad, nivelAcademico, 
                            experiencia, pruebaTecnica, entrevista, puntajeTotal, totalAspirantes); 
                break;
            case 4: 
                // Mensaje de despedida al salir del sistema
                cout << "Saliendo del sistema. Hasta luego!\n"; 
                break;
        }
    } while (opcion != 4);  // El ciclo continua hasta que el usuario elija salir
    
    // IMPORTANTE: Liberacion de toda la memoria dinamica utilizada
    // Esto previene fugas de memoria (memory leaks)
    delete[] nombre;
    delete[] identificacion;
    delete[] edad;
    delete[] nivelAcademico;
    delete[] experiencia;
    delete[] pruebaTecnica;
    delete[] entrevista;
    delete[] puntajeTotal;
}

/*
  Funcion principal del programa.
  Punto de entrada de la aplicacion.
  Llama al menu principal para iniciar el sistema.
*/
int main() {
    menuPrincipal();  // Inicia el sistema de gestion de aspirantes
    return 0;  // Retorna 0 indicando ejecucion exitosa
}