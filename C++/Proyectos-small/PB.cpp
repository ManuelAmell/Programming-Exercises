#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>


using namespace std;


//  nombre
const int MAX_NOMBRE = 100;

// Punteros para arreglos 
char (*nombres)[MAX_NOMBRE] = nullptr;
long long* identificaciones = nullptr;
int* edades = nullptr;
int* nivelesAcademicos = nullptr;
int* añosExperiencia = nullptr;
float* puntajesTecnicos = nullptr;
float* puntajesEntrevista = nullptr;
float* puntajesTotales = nullptr;

int capacidadActual = 0;
int totalAspirantes = 0;

// Prototipos de funciones
void menu();
void inicializarSistema();
void aumentarCapacidad();
void registrarAspirante();
void calcularPuntajeTotal();
float calcularPuntaje(int nivel, int experiencia, float pruebaTecnica, float entrevista);
void menuReportes();
void listarTodosAspirantes();
void listarOrdenadoPorPuntaje();
void consultarAspiranteDestacado();
void mostrarDatosAspirante(int indice);
string obtenerNombreNivelAcademico(int nivel);
bool validarIdentificacionUnica(long long id);
void limpiarBuffer();
void ordenarPorPuntaje(int* indices, int n);
void liberarMemoria();

int main() {
    int opcion;
    
    cout << "========================================\n";
    cout << "    TECHSOLUTIONS S.A.\n";
    cout << "  Sistema de Reclutamiento de Personal\n";
    cout << "========================================\n\n";
    
    // Inicializar el sistema
    inicializarSistema();
    
    do {
        menu();
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        if (cin.fail()) {
            cin.clear();
            limpiarBuffer();
            opcion = -1;
        }
        
        cout << "\n";
        
        switch(opcion) {
            case 1:
                registrarAspirante();
                break;
            case 2:
                calcularPuntajeTotal();
                break;
            case 3:
                menuReportes();
                break;
            case 4:
                cout << "Gracias por usar el sistema de TechSolutions S.A.\n";
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente.\n\n";
        }
        
    } while(opcion != 4);
    
    // Liberar memoria antes de salir
    liberarMemoria();
    
    return 0;
}

void inicializarSistema() {
    int capacidadInicial;
    
    cout << "Ingrese la capacidad inicial de aspirantes: ";
    cin >> capacidadInicial;
    
    while (cin.fail() || capacidadInicial <= 0) {
        cin.clear();
        limpiarBuffer();
        cout << "Valor invalido. Ingrese un numero positivo: ";
        cin >> capacidadInicial;
    }
    
    capacidadActual = capacidadInicial;
    
    // Asignar memoria dinámica para los arreglos
    nombres = new char[capacidadActual][MAX_NOMBRE];
    identificaciones = new long long[capacidadActual];
    edades = new int[capacidadActual];
    nivelesAcademicos = new int[capacidadActual];
    añosExperiencia = new int[capacidadActual];
    puntajesTecnicos = new float[capacidadActual];
    puntajesEntrevista = new float[capacidadActual];
    puntajesTotales = new float[capacidadActual];
    
    cout << "\nSistema inicializado con capacidad para " << capacidadActual << " aspirantes.\n";
    cout << "La capacidad se expandira automaticamente si es necesario.\n\n";
}

void aumentarCapacidad() {
    int nuevaCapacidad = capacidadActual * 2;
    
    cout << "Expandiendo capacidad de " << capacidadActual << " a " << nuevaCapacidad << " aspirantes...\n";
    
    // Crear nuevos arreglos con mayor capacidad
    char (*nuevosNombres)[MAX_NOMBRE] = new char[nuevaCapacidad][MAX_NOMBRE];
    long long* nuevasIdentificaciones = new long long[nuevaCapacidad];
    int* nuevasEdades = new int[nuevaCapacidad];
    int* nuevosNiveles = new int[nuevaCapacidad];
    int* nuevasExperiencias = new int[nuevaCapacidad];
    float* nuevosPuntajesTecnicos = new float[nuevaCapacidad];
    float* nuevosPuntajesEntrevista = new float[nuevaCapacidad];
    float* nuevosPuntajesTotales = new float[nuevaCapacidad];
    
    // Copiar datos existentes usando aritmética de punteros
    for (int i = 0; i < totalAspirantes; i++) {
        strcpy(*(nuevosNombres + i), *(nombres + i));
        *(nuevasIdentificaciones + i) = *(identificaciones + i);
        *(nuevasEdades + i) = *(edades + i);
        *(nuevosNiveles + i) = *(nivelesAcademicos + i);
        *(nuevasExperiencias + i) = *(añosExperiencia + i);
        *(nuevosPuntajesTecnicos + i) = *(puntajesTecnicos + i);
        *(nuevosPuntajesEntrevista + i) = *(puntajesEntrevista + i);
        *(nuevosPuntajesTotales + i) = *(puntajesTotales + i);
    }
    
    // Liberar memoria antigua
    delete[] nombres;
    delete[] identificaciones;
    delete[] edades;
    delete[] nivelesAcademicos;
    delete[] añosExperiencia;
    delete[] puntajesTecnicos;
    delete[] puntajesEntrevista;
    delete[] puntajesTotales;
    
    // Asignar nuevos arreglos
    nombres = nuevosNombres;
    identificaciones = nuevasIdentificaciones;
    edades = nuevasEdades;
    nivelesAcademicos = nuevosNiveles;
    añosExperiencia = nuevasExperiencias;
    puntajesTecnicos = nuevosPuntajesTecnicos;
    puntajesEntrevista = nuevosPuntajesEntrevista;
    puntajesTotales = nuevosPuntajesTotales;
    
    capacidadActual = nuevaCapacidad;
    
    cout << "Capacidad expandida exitosamente.\n\n";
}

void menu() {
    cout << "========================================\n";
    cout << "           MENU PRINCIPAL\n";
    cout << "========================================\n";
    cout << "Aspirantes: " << totalAspirantes << "/" << capacidadActual << "\n";
    cout << "========================================\n";
    cout << "1. Registro de datos de aspirantes\n";
    cout << "2. Calculo del puntaje total\n";
    cout << "3. Reportes y consultas\n";
    cout << "4. Salir\n";
    cout << "========================================\n";
}

void registrarAspirante() {
    // Verificar si necesitamos expandir la capacidad
    if (totalAspirantes >= capacidadActual) {
        aumentarCapacidad();
    }
    
    cout << "=== REGISTRO DE ASPIRANTE ===\n\n";
    
    // Nombre completo
    cout << "Ingrese nombre completo: ";
    limpiarBuffer();
    cin.get(*(nombres + totalAspirantes), MAX_NOMBRE);
    
    // Identificación
    long long id;
    bool idValida = false;
    do {
        cout << "Ingrese numero de identificacion: ";
        cin >> id;
        
        if (cin.fail() || id <= 0) {
            cin.clear();
            limpiarBuffer();
            cout << "Identificacion invalida. Debe ser un numero positivo.\n";
        } else if (!validarIdentificacionUnica(id)) {
            cout << "Esta identificacion ya esta registrada. Ingrese otra.\n";
        } else {
            idValida = true;
        }
    } while (!idValida);
    
    *(identificaciones + totalAspirantes) = id;
    
    // Edad
    int edad;
    do {
        cout << "Ingrese edad: ";
        cin >> edad;
        
        if (cin.fail() || edad < 18) {
            cin.clear();
            limpiarBuffer();
            cout << "Edad invalida. Debe ser mayor o igual a 18 años.\n";
        }
    } while (cin.fail() || edad < 18);
    
    *(edades + totalAspirantes) = edad;
    
    // Nivel académico
    int nivel;
    do {
        cout << "\nNivel academico:\n";
        cout << "1. Tecnico\n";
        cout << "2. Tecnologo\n";
        cout << "3. Profesional\n";
        cout << "4. Posgrado\n";
        cout << "Seleccione (1-4): ";
        cin >> nivel;
        
        if (cin.fail() || nivel < 1 || nivel > 4) {
            cin.clear();
            limpiarBuffer();
            cout << "Opcion invalida. Ingrese un numero entre 1 y 4.\n";
        }
    } while (cin.fail() || nivel < 1 || nivel > 4);
    
    *(nivelesAcademicos + totalAspirantes) = nivel;
    
    // Años de experiencia
    int experiencia;
    do {
        cout << "Ingrese años de experiencia laboral: ";
        cin >> experiencia;
        
        if (cin.fail() || experiencia < 0) {
            cin.clear();
            limpiarBuffer();
            cout << "Experiencia invalida. Debe ser un numero positivo o cero.\n";
        }
    } while (cin.fail() || experiencia < 0);
    
    *(añosExperiencia + totalAspirantes) = experiencia;
    
    // Puntaje prueba técnica
    float puntajeTecnico;
    do {
        cout << "Ingrese puntaje en prueba tecnica (0-100): ";
        cin >> puntajeTecnico;
        
        if (cin.fail() || puntajeTecnico < 0 || puntajeTecnico > 100) {
            cin.clear();
            limpiarBuffer();
            cout << "Puntaje invalido. Debe estar entre 0 y 100.\n";
        }
    } while (cin.fail() || puntajeTecnico < 0 || puntajeTecnico > 100);
    
    *(puntajesTecnicos + totalAspirantes) = puntajeTecnico;
    
    // Puntaje entrevista
    float puntajeEntr;
    do {
        cout << "Ingrese puntaje en entrevista (0-100): ";
        cin >> puntajeEntr;
        
        if (cin.fail() || puntajeEntr < 0 || puntajeEntr > 100) {
            cin.clear();
            limpiarBuffer();
            cout << "Puntaje invalido. Debe estar entre 0 y 100.\n";
        }
    } while (cin.fail() || puntajeEntr < 0 || puntajeEntr > 100);
    
    *(puntajesEntrevista + totalAspirantes) = puntajeEntr;
    
    // Inicializar puntaje total en 0 (se calculará después)
    *(puntajesTotales + totalAspirantes) = 0;
    
    totalAspirantes++;
    
    cout << "\n¡Aspirante registrado exitosamente!\n";
    cout << "Total de aspirantes registrados: " << totalAspirantes << "\n";
    cout << "Capacidad disponible: " << (capacidadActual - totalAspirantes) << " espacios\n\n";
}

float calcularPuntaje(int nivel, int experiencia, float pruebaTecnica, float entrevista) {
    float puntajeTotal = 0;
    
    // Puntaje por nivel académico (máx. 30 puntos)
    switch(nivel) {
        case 1: puntajeTotal += 15; break; // Técnico
        case 2: puntajeTotal += 20; break; // Tecnólogo
        case 3: puntajeTotal += 25; break; // Profesional
        case 4: puntajeTotal += 30; break; // Posgrado
    }
    
    // Puntaje por experiencia (máx. 20 puntos)
    if (experiencia < 1) {
        puntajeTotal += 5;
    } else if (experiencia >= 1 && experiencia <= 3) {
        puntajeTotal += 10;
    } else if (experiencia >= 4 && experiencia <= 6) {
        puntajeTotal += 15;
    } else {
        puntajeTotal += 20;
    }
    
    // Puntaje por prueba técnica (máx. 30 puntos)
    if (pruebaTecnica < 60) {
        puntajeTotal += 10;
    } else if (pruebaTecnica >= 60 && pruebaTecnica <= 79) {
        puntajeTotal += 20;
    } else if (pruebaTecnica >= 80 && pruebaTecnica <= 89) {
        puntajeTotal += 25;
    } else {
        puntajeTotal += 30;
    }
    
    // Puntaje por entrevista (máx. 20 puntos)
    if (entrevista < 60) {
        puntajeTotal += 5;
    } else if (entrevista >= 60 && entrevista <= 79) {
        puntajeTotal += 10;
    } else if (entrevista >= 80 && entrevista <= 89) {
        puntajeTotal += 15;
    } else {
        puntajeTotal += 20;
    }
    
    return puntajeTotal;
}

void calcularPuntajeTotal() {
    if (totalAspirantes == 0) {
        cout << "No hay aspirantes registrados. Primero registre aspirantes.\n\n";
        return;
    }
    
    cout << "=== CALCULANDO PUNTAJES TOTALES ===\n\n";
    
    // Usar aritmética de punteros para recorrer los arreglos
    int* pNivel = nivelesAcademicos;
    int* pExperiencia = añosExperiencia;
    float* pTecnico = puntajesTecnicos;
    float* pEntrevista = puntajesEntrevista;
    float* pTotal = puntajesTotales;
    
    for (int i = 0; i < totalAspirantes; i++) {
        *(pTotal + i) = calcularPuntaje(*(pNivel + i), *(pExperiencia + i), 
                                        *(pTecnico + i), *(pEntrevista + i));
    }
    
    cout << "Puntajes totales calculados para " << totalAspirantes << " aspirante(s).\n\n";
}

void menuReportes() {
    if (totalAspirantes == 0) {
        cout << "No hay aspirantes registrados. Primero registre aspirantes.\n\n";
        return;
    }
    
    int opcion;
    
    do {
        cout << "========================================\n";
        cout << "       REPORTES Y CONSULTAS\n";
        cout << "========================================\n";
        cout << "1. Listado general de aspirantes\n";
        cout << "2. Reporte ordenado por puntaje total\n";
        cout << "3. Consulta de aspirante destacado\n";
        cout << "4. Volver al menu principal\n";
        cout << "========================================\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        if (cin.fail()) {
            cin.clear();
            limpiarBuffer();
            opcion = -1;
        }
        
        cout << "\n";
        
        switch(opcion) {
            case 1:
                listarTodosAspirantes();
                break;
            case 2:
                listarOrdenadoPorPuntaje();
                break;
            case 3:
                consultarAspiranteDestacado();
                break;
            case 4:
                cout << "Volviendo al menu principal...\n\n";
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente.\n\n";
        }
        
    } while(opcion != 4);
}

void listarTodosAspirantes() {
    cout << "========================================\n";
    cout << "   LISTADO GENERAL DE ASPIRANTES\n";
    cout << "========================================\n\n";
    
    // Encontrar aspirante con mayor puntaje usando aritmética de punteros
    float* pTotal = puntajesTotales;
    int indiceMayor = 0;
    float mayorPuntaje = *pTotal;
    
    for (int i = 1; i < totalAspirantes; i++) {
        if (*(pTotal + i) > mayorPuntaje) {
            mayorPuntaje = *(pTotal + i);
            indiceMayor = i;
        }
    }
    
    // Mostrar todos los aspirantes
    for (int i = 0; i < totalAspirantes; i++) {
        cout << "--- Aspirante #" << (i + 1) << " ---\n";
        mostrarDatosAspirante(i);
        cout << "\n";
    }
    
    cout << "========================================\n";
    cout << "ASPIRANTE CON MAYOR PUNTAJE:\n";
    cout << "Nombre: " << *(nombres + indiceMayor) << "\n";
    cout << "Identificacion: " << *(identificaciones + indiceMayor) << "\n";
    cout << "Puntaje Total: " << fixed << setprecision(2) << mayorPuntaje << "\n";
    cout << "========================================\n\n";
}

void ordenarPorPuntaje(int* indices, int n) {
    // Ordenamiento burbuja usando aritmética de punteros
    float* pTotal = puntajesTotales;
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (*(pTotal + *(indices + j)) > *(pTotal + *(indices + j + 1))) {
                int temp = *(indices + j);
                *(indices + j) = *(indices + j + 1);
                *(indices + j + 1) = temp;
            }
        }
    }
}

void listarOrdenadoPorPuntaje() {
    cout << "========================================\n";
    cout << "  REPORTE ORDENADO POR PUNTAJE TOTAL\n";
    cout << "========================================\n\n";
    
    // Crear arreglo dinámico de índices
    int* indices = new int[totalAspirantes];
    int* pIndices = indices;
    
    for (int i = 0; i < totalAspirantes; i++) {
        *(pIndices + i) = i;
    }
    
    // Ordenar índices según puntaje
    ordenarPorPuntaje(indices, totalAspirantes);
    
    // Mostrar aspirantes ordenados
    for (int i = 0; i < totalAspirantes; i++) {
        int idx = *(pIndices + i);
        cout << "--- Posicion #" << (i + 1) << " ---\n";
        mostrarDatosAspirante(idx);
        cout << "\n";
    }
    
    // Calcular promedio usando aritmética de punteros
    float* pTotal = puntajesTotales;
    float suma = 0;
    
    for (int i = 0; i < totalAspirantes; i++) {
        suma += *(pTotal + i);
    }
    
    float promedio = suma / totalAspirantes;
    
    // Contar aspirantes por encima del promedio
    int countSobrePromedio = 0;
    for (int i = 0; i < totalAspirantes; i++) {
        if (*(pTotal + i) > promedio) {
            countSobrePromedio++;
        }
    }
    
    float porcentajeSobrePromedio = (countSobrePromedio * 100.0) / totalAspirantes;
    
    cout << "========================================\n";
    cout << "ESTADISTICAS:\n";
    cout << "Promedio general: " << fixed << setprecision(2) << promedio << "\n";
    cout << "Aspirantes sobre el promedio: " << countSobrePromedio << "\n";
    cout << "Porcentaje sobre el promedio: " << fixed << setprecision(2) 
         << porcentajeSobrePromedio << "%\n";
    cout << "========================================\n\n";
    
    // Liberar memoria del arreglo de índices
    delete[] indices;
}

void consultarAspiranteDestacado() {
    long long id;
    
    cout << "=== CONSULTA DE ASPIRANTE ===\n";
    cout << "Ingrese numero de identificacion: ";
    cin >> id;
    
    if (cin.fail()) {
        cin.clear();
        limpiarBuffer();
        cout << "Identificacion invalida.\n\n";
        return;
    }
    
    // Buscar aspirante usando aritmética de punteros
    long long* pId = identificaciones;
    bool encontrado = false;
    int indice = -1;
    
    for (int i = 0; i < totalAspirantes; i++) {
        if (*(pId + i) == id) {
            encontrado = true;
            indice = i;
            break;
        }
    }
    
    cout << "\n";
    
    if (encontrado) {
        cout << "========================================\n";
        cout << "       DATOS DEL ASPIRANTE\n";
        cout << "========================================\n";
        mostrarDatosAspirante(indice);
        cout << "========================================\n\n";
    } else {
        cout << "No se encontro ningun aspirante con esa identificacion.\n\n";
    }
}

void mostrarDatosAspirante(int indice) {
    cout << "Nombre: " << *(nombres + indice) << "\n";
    cout << "Identificacion: " << *(identificaciones + indice) << "\n";
    cout << "Edad: " << *(edades + indice) << " años\n";
    cout << "Nivel academico: " << obtenerNombreNivelAcademico(*(nivelesAcademicos + indice)) << "\n";
    cout << "Años de experiencia: " << *(añosExperiencia + indice) << " años\n";
    cout << "Puntaje prueba tecnica: " << fixed << setprecision(2) << *(puntajesTecnicos + indice) << "\n";
    cout << "Puntaje entrevista: " << fixed << setprecision(2) << *(puntajesEntrevista + indice) << "\n";
    cout << "Puntaje Total: " << fixed << setprecision(2) << *(puntajesTotales + indice) << "\n";
}

string obtenerNombreNivelAcademico(int nivel) {
    switch(nivel) {
        case 1: return "Tecnico";
        case 2: return "Tecnologo";
        case 3: return "Profesional";
        case 4: return "Posgrado";
        default: return "Desconocido";
    }
}

bool validarIdentificacionUnica(long long id) {
    long long* pId = identificaciones;
    
    for (int i = 0; i < totalAspirantes; i++) {
        if (*(pId + i) == id) {
            return false;
        }
    }
    
    return true;
}

void limpiarBuffer() {
    cin.ignore(10000, '\n');
}

void liberarMemoria() {
    if (nombres != nullptr) delete[] nombres;
    if (identificaciones != nullptr) delete[] identificaciones;
    if (edades != nullptr) delete[] edades;
    if (nivelesAcademicos != nullptr) delete[] nivelesAcademicos;
    if (añosExperiencia != nullptr) delete[] añosExperiencia;
    if (puntajesTecnicos != nullptr) delete[] puntajesTecnicos;
    if (puntajesEntrevista != nullptr) delete[] puntajesEntrevista;
    if (puntajesTotales != nullptr) delete[] puntajesTotales;
}