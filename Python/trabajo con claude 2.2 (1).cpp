#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <climits>
#include <clocale>
using namespace std;

int leerEnteroValidado(const string &mensaje, int minVal = INT_MIN, int maxVal = INT_MAX) {
    int x;
    while (true) {
        cout << mensaje;
        if (cin >> x) {
            if (x >= minVal && x <= maxVal) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return x;
            }
        }
        cout << "ERROR - Entrada inválida. Intente de nuevo.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

string leerCadenaNoVacia(const string &mensaje) {
    string s;
    getline(cin, s);
    while (s.empty()) {
        cout << mensaje;
        getline(cin, s);
    }
    return s;
}

float calcularPuntajeTotal(int nivelAcademico, int experiencia, int pruebaTecnica, int entrevista) {
    float total = 0.0f;

    switch (nivelAcademico) {
        case 1: total += 10; break;
        case 2: total += 15; break;
        case 3: total += 20; break;
        case 4: total += 25; break;
    }

    if (experiencia < 1) total += 5;
    else if (experiencia <= 3) total += 10;
    else if (experiencia <= 6) total += 20;
    else total += 25;

    total += (pruebaTecnica * 25.0f / 100.0f);
    total += (entrevista * 25.0f / 100.0f);

    return total;
}

void calcularPuntajes(float puntajes[], int niveles[], int experiencias[],
                      int pruebas[], int entrevistas[], int cantidad) {
    float *ptrPuntajes = puntajes;
    int *ptrNiveles = niveles;
    int *ptrExperiencias = experiencias;
    int *ptrPruebas = pruebas;
    int *ptrEntrevistas = entrevistas;
    
    for (int i = 0; i < cantidad; ++i) {
        *(ptrPuntajes + i) = calcularPuntajeTotal(*(ptrNiveles + i), *(ptrExperiencias + i), 
                                                   *(ptrPruebas + i), *(ptrEntrevistas + i));
    }
}

void mostrarResultados(string nombres[], string ids[], float puntajes[], int cantidad) {
    system("cls");
    if (cantidad == 0) {
        cout << "\nNo hay aspirantes registrados.\n";
        system("pause");
        system("cls");
        return;
    }

    cout << "\n=== RESULTADOS DE PUNTAJES TOTALES ===\n";
    cout << "(Puntaje total calculado sobre 100 puntos)\n\n";
    cout << left << setw(22) << "Nombre"
         << setw(14) << "ID"
         << setw(10) << "Puntaje" << "\n";
    cout << string(45, '-') << "\n";

    string *ptrNombres = nombres;
    string *ptrIds = ids;
    float *ptrPuntajes = puntajes;
    
    for (int i = 0; i < cantidad; ++i) {
        cout << left << setw(22) << *(ptrNombres + i)
             << setw(14) << *(ptrIds + i)
             << setw(10) << fixed << setprecision(2) << *(ptrPuntajes + i) << "\n";
    }

    cout << "\nCálculo de puntajes completado correctamente.\n";
    system("pause");
    system("cls");
}

void registrarAspirantes(string nombres[], string ids[], int edades[], int niveles[],
                         int experiencias[], int pruebas[], int entrevistas[], float puntajes[],
                         int &cantidad, int maxAsp) {
    system("cls");
    int n = leerEnteroValidado("\n¿Cuántos aspirantes desea registrar? (>=1): ", 1);

    for (int i = 0; i < n && cantidad < maxAsp; ++i) {
        cout << "\n--- Registro del aspirante " << (cantidad + 1) << " ---\n";

        cout << "Nombre completo: ";
        string nombre = leerCadenaNoVacia(" Nombre inválido. Ingrese el nombre: ");

        string id;
        bool duplicado;
        do {
            cout << "Número de identificación: ";
            getline(cin, id);
            duplicado = false;
            
            string *ptrIds = ids;
            for (int k = 0; k < cantidad; ++k) {
                if (*(ptrIds + k) == id) {
                    cout << "  ? Identificación ya registrada. Ingrese otra.\n";
                    duplicado = true;
                    break;
                }
            }
        } while (duplicado || id.empty());

        int edad = leerEnteroValidado("Edad (>=18): ", 18);
        cout << "Nivel académico (1=Técnico, 2=Tecnólogo, 3=Profesional, 4=Posgrado)\n";
        int nivel = leerEnteroValidado("Ingrese nivel (1-4): ", 1, 4);
        int exp = leerEnteroValidado("Años de experiencia laboral (>=0): ", 0);
        int prueba = leerEnteroValidado("Puntaje prueba técnica (0-100): ", 0, 100);
        int entrevista = leerEnteroValidado("Puntaje entrevista (0-100): ", 0, 100);

        *(nombres + cantidad) = nombre;
        *(ids + cantidad) = id;
        *(edades + cantidad) = edad;
        *(niveles + cantidad) = nivel;
        *(experiencias + cantidad) = exp;
        *(pruebas + cantidad) = prueba;
        *(entrevistas + cantidad) = entrevista;
        
        *(puntajes + cantidad) = calcularPuntajeTotal(nivel, exp, prueba, entrevista);
        cantidad++;

        cout << "Aspirante registrado correctamente.\n";
        cout << "Puntaje calculado: " << fixed << setprecision(2) 
             << *(puntajes + cantidad - 1) << " puntos\n";
    }

    system("pause");
    system("cls");
}

void calcularPuntajesTotales(string nombres[], string ids[], int niveles[], int experiencias[],
                             int pruebas[], int entrevistas[], float puntajes[], int cantidad) {
    if (cantidad == 0) {
        cout << "\nNo hay aspirantes registrados.\n";
        system("pause");
        system("cls");
        return;
    }

    mostrarResultados(nombres, ids, puntajes, cantidad);
}

void ordenarPorPuntajeAsc(string nombres[], string ids[], int edades[], int niveles[],
                          int experiencias[], int pruebas[], int entrevistas[], float puntajes[],
                          int cantidad) {
    for (int i = 0; i < cantidad - 1; ++i) {
        for (int j = 0; j < cantidad - i - 1; ++j) {
        	
            if (*(puntajes + j) > *(puntajes + j + 1)) {
                string auxNombre = *(nombres + j);
                string auxId = *(ids + j);
                int auxEdad = *(edades + j);
                int auxNivel = *(niveles + j);
                int auxExp = *(experiencias + j);
                int auxPrueba = *(pruebas + j);
                int auxEntrevista = *(entrevistas + j);
                float auxPuntaje = *(puntajes + j);

                *(nombres + j) = *(nombres + j + 1);
                *(ids + j) = *(ids + j + 1);
                *(edades + j) = *(edades + j + 1);
                *(niveles + j) = *(niveles + j + 1);
                *(experiencias + j) = *(experiencias + j + 1);
                *(pruebas + j) = *(pruebas + j + 1);
                *(entrevistas + j) = *(entrevistas + j + 1);
                *(puntajes + j) = *(puntajes + j + 1);

                *(nombres + j + 1) = auxNombre;
                *(ids + j + 1) = auxId;
                *(edades + j + 1) = auxEdad;
                *(niveles + j + 1) = auxNivel;
                *(experiencias + j + 1) = auxExp;
                *(pruebas + j + 1) = auxPrueba;
                *(entrevistas + j + 1) = auxEntrevista;
                *(puntajes + j + 1) = auxPuntaje;
            }
        }
    }
}

void reporteGeneral(string nombres[], string ids[], int edades[], int niveles[],
                    int experiencias[], int pruebas[], int entrevistas[], float puntajes[], int cantidad) {
    system("cls");
    if (cantidad == 0) {
        cout << "\nNo hay aspirantes registrados.\n";
        system("pause");
        system("cls");
        return;
    }

    cout << "\n=== LISTADO GENERAL DE ASPIRANTES ===\n";
    cout << "(1=Técnico, 2=Tecnólogo, 3=Profesional, 4=Posgrado)\n\n";

    cout << left << setw(22) << "Nombre" << setw(14) << "ID" << setw(6) << "Edad"
         << setw(6) << "Niv" << setw(6) << "Exp" << setw(8) << "Prueba"
         << setw(9) << "Entrev" << setw(8) << "Puntaje" << "\n";
    cout << string(90, '-') << "\n";

    float mayor = -1.0;
    int idxMayor = 0;

    string *ptrNombres = nombres;
    string *ptrIds = ids;
    int *ptrEdades = edades;
    int *ptrNiveles = niveles;
    int *ptrExperiencias = experiencias;
    int *ptrPruebas = pruebas;
    int *ptrEntrevistas = entrevistas;
    float *ptrPuntajes = puntajes;

    for (int i = 0; i < cantidad; ++i) {
        cout << left << setw(22) << *(ptrNombres + i)
             << setw(14) << *(ptrIds + i)
             << setw(6) << *(ptrEdades + i)
             << setw(6) << *(ptrNiveles + i)
             << setw(6) << *(ptrExperiencias + i)
             << setw(8) << *(ptrPruebas + i)
             << setw(9) << *(ptrEntrevistas + i)
             << setw(8) << fixed << setprecision(2) << *(ptrPuntajes + i) << "\n";
        
        if (*(ptrPuntajes + i) > mayor) {
            mayor = *(ptrPuntajes + i);
            idxMayor = i;
        }
    }

    cout << "\nAspirante con mayor puntaje: " << *(ptrNombres + idxMayor)
         << " (ID: " << *(ptrIds + idxMayor)
         << ") - Puntaje: " << fixed << setprecision(2) << mayor << "\n";

    system("pause");
    system("cls");
}

void consultarAspiranteDestacado(string nombres[], string ids[], int edades[], int niveles[],
                                 int experiencias[], int pruebas[], int entrevistas[], 
                                 float puntajes[], int cantidad) {
    system("cls");
    if (cantidad == 0) {
        cout << "\nNo hay aspirantes registrados.\n";
        system("pause");
        system("cls");
        return;
    }

    cout << "\n=== CONSULTA DE ASPIRANTE DESTACADO ===\n";
    cout << "Número de identificación: ";
    string idBuscar;
    getline(cin, idBuscar);

    int indice = -1;
    string *ptrIds = ids;
    for (int i = 0; i < cantidad; ++i) {
        if (*(ptrIds + i) == idBuscar) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        cout << "\nAspirante no encontrado con ese documento de identificación.\n";
        system("pause");
        system("cls");
        return;
    }

    string nivelTexto;
    switch (*(niveles + indice)) {
        case 1: nivelTexto = "Técnico"; break;
        case 2: nivelTexto = "Tecnólogo"; break;
        case 3: nivelTexto = "Profesional"; break;
        case 4: nivelTexto = "Posgrado"; break;
    }

    cout << "\n=== DATOS DEL ASPIRANTE ===\n";
    cout << string(50, '-') << "\n";
    cout << "Nombre completo:          " << *(nombres + indice) << "\n";
    cout << "Identificación:           " << *(ids + indice) << "\n";
    cout << "Edad:                     " << *(edades + indice) << " años\n";
    cout << "Nivel académico:          " << nivelTexto << "\n";
    cout << "Años de experiencia:      " << *(experiencias + indice) << " años\n";
    cout << "Puntaje prueba técnica:   " << *(pruebas + indice) << "/100\n";
    cout << "Puntaje entrevista:       " << *(entrevistas + indice) << "/100\n";
    cout << "Puntaje total:            " << fixed << setprecision(2) 
         << *(puntajes + indice) << "/100\n";
    cout << string(50, '-') << "\n";

    system("pause");
    system("cls");
}

void menuReportes(string nombres[], string ids[], int edades[], int niveles[],
                  int experiencias[], int pruebas[], int entrevistas[], float puntajes[], int cantidad) {
    int op;
    do {
        cout << "\n=== SUBMENÚ: REPORTES Y CONSULTAS ===\n";
        cout << "1. Listado general de aspirantes\n";
        cout << "2. Reporte ordenado ascendentemente por puntaje total\n";
        cout << "3. Consulta de aspirante destacado\n";
        cout << "4. Volver\n";
        op = leerEnteroValidado("Seleccione una opción (1-4): ", 1, 4);

        if (op == 1) {
            reporteGeneral(nombres, ids, edades, niveles, experiencias, pruebas, entrevistas, puntajes, cantidad);
        } else if (op == 2) {
            ordenarPorPuntajeAsc(nombres, ids, edades, niveles, experiencias, pruebas, entrevistas, puntajes, cantidad);
            reporteGeneral(nombres, ids, edades, niveles, experiencias, pruebas, entrevistas, puntajes, cantidad);
        } else if (op == 3) {
            consultarAspiranteDestacado(nombres, ids, edades, niveles, experiencias, pruebas, entrevistas, puntajes, cantidad);
        } else {
            system("cls");
        }

    } while (op != 4);
}

void menuPrincipal(string nombres[], string ids[], int edades[], int niveles[],
                   int experiencias[], int pruebas[], int entrevistas[], float puntajes[],
                   int &cantidad, int maxAsp) {
    int opcion;
    do {
        cout << "\n=== TechSolutions S.A. - Gestión de Aspirantes ===\n";
        cout << "1. Registro de aspirantes\n";
        cout << "2. Cálculo de puntaje total por aspirante\n";
        cout << "3. Reportes y consultas\n";
        cout << "4. Salir\n";

        opcion = leerEnteroValidado("Seleccione una opción (1-4): ", 1, 4);
        system("cls");

        if (opcion == 1)
            registrarAspirantes(nombres, ids, edades, niveles, experiencias, pruebas, entrevistas, puntajes, cantidad, maxAsp);
        else if (opcion == 2)
            calcularPuntajesTotales(nombres, ids, niveles, experiencias, pruebas, entrevistas, puntajes, cantidad);
        else if (opcion == 3)
            menuReportes(nombres, ids, edades, niveles, experiencias, pruebas, entrevistas, puntajes, cantidad);

    } while (opcion != 4);

    cout << "Saliendo del sistema.";
}

int main() {
    setlocale(LC_ALL, "Spanish");
    
    cout << "=============================================\n";
    cout << " TechSolutions S.A. - Gestión de Aspirantes\n";
    cout << "=============================================\n";
    cout << "La compañia necesita reclutar nuevo personal de forma justa y automatizada.\n";
    cout << "Se solicita un programa que permita:\n";
    cout << "  - Registrar información de los aspirantes.\n";
    cout << "  - Calcular su puntaje total con base en criterios técnicos y actitudinales.\n";
    cout << "  - Generar reportes detallados de evaluación.\n\n";
    cout << "\nAUTORES:\n";
    cout << "  - Samuel Cogollo Villarreal (Cód. 0222420018)\n";
    cout << "  - Manuel Esteban Arcia Pastrana (Cód. 0222420001)\n";
    cout << "  - Manuel Francisco Amell Gil (Cód. 0222421001)\n";
    cout << "\nAsignatura: Programación Básica -- Grupo B1\n";
    cout << "=============================================\n\n";
    system("pause");
    system("cls");
    
    const int MAX_Aspirantes = 100;
    string nombres[MAX_Aspirantes];
    string ids[MAX_Aspirantes];
    int edades[MAX_Aspirantes];
    int niveles[MAX_Aspirantes];
    int experiencias[MAX_Aspirantes];
    int pruebas[MAX_Aspirantes];
    int entrevistas[MAX_Aspirantes];
    float puntajes[MAX_Aspirantes];
    int cantidad = 0;

    menuPrincipal(nombres, ids, edades, niveles, experiencias, pruebas, entrevistas, puntajes, cantidad, MAX_Aspirantes);
    return 0;
}
