"""
Script para convertir código C++ a pseudocódigo con llaves visibles
Solo pega tu código C++ en la variable CODIGO_CPP y ejecuta el script
"""

import re

# ============================================
# PEGA TU CÓDIGO C++ AQUÍ ENTRE LAS COMILLAS TRIPLES
# ============================================
CODIGO_CPP = """
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
        cout << "ERROR - Entrada inv�lida. Intente de nuevo.\n";
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

    cout << "\nC�lculo de puntajes completado correctamente.\n";
    system("pause");
    system("cls");
}

void registrarAspirantes(string nombres[], string ids[], int edades[], int niveles[],
                         int experiencias[], int pruebas[], int entrevistas[], float puntajes[],
                         int &cantidad, int maxAsp) {
    system("cls");
    int n = leerEnteroValidado("\n�Cu�ntos aspirantes desea registrar? (>=1): ", 1);

    for (int i = 0; i < n && cantidad < maxAsp; ++i) {
        cout << "\n--- Registro del aspirante " << (cantidad + 1) << " ---\n";

        cout << "Nombre completo: ";
        string nombre = leerCadenaNoVacia(" Nombre inv�lido. Ingrese el nombre: ");

        string id;
        bool duplicado;
        do {
            cout << "N�mero de identificaci�n: ";
            getline(cin, id);
            duplicado = false;
            
            string *ptrIds = ids;
            for (int k = 0; k < cantidad; ++k) {
                if (*(ptrIds + k) == id) {
                    cout << "  ? Identificaci�n ya registrada. Ingrese otra.\n";
                    duplicado = true;
                    break;
                }
            }
        } while (duplicado || id.empty());

        int edad = leerEnteroValidado("Edad (>=18): ", 18);
        cout << "Nivel acad�mico (1=T�cnico, 2=Tecn�logo, 3=Profesional, 4=Posgrado)\n";
        int nivel = leerEnteroValidado("Ingrese nivel (1-4): ", 1, 4);
        int exp = leerEnteroValidado("A�os de experiencia laboral (>=0): ", 0);
        int prueba = leerEnteroValidado("Puntaje prueba t�cnica (0-100): ", 0, 100);
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
    cout << "(1=T�cnico, 2=Tecn�logo, 3=Profesional, 4=Posgrado)\n\n";

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
    cout << "N�mero de identificaci�n: ";
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
        cout << "\nAspirante no encontrado con ese documento de identificaci�n.\n";
        system("pause");
        system("cls");
        return;
    }

    string nivelTexto;
    switch (*(niveles + indice)) {
        case 1: nivelTexto = "T�cnico"; break;
        case 2: nivelTexto = "Tecn�logo"; break;
        case 3: nivelTexto = "Profesional"; break;
        case 4: nivelTexto = "Posgrado"; break;
    }

    cout << "\n=== DATOS DEL ASPIRANTE ===\n";
    cout << string(50, '-') << "\n";
    cout << "Nombre completo:          " << *(nombres + indice) << "\n";
    cout << "Identificaci�n:           " << *(ids + indice) << "\n";
    cout << "Edad:                     " << *(edades + indice) << " a�os\n";
    cout << "Nivel acad�mico:          " << nivelTexto << "\n";
    cout << "A�os de experiencia:      " << *(experiencias + indice) << " a�os\n";
    cout << "Puntaje prueba t�cnica:   " << *(pruebas + indice) << "/100\n";
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
        cout << "\n=== SUBMEN�: REPORTES Y CONSULTAS ===\n";
        cout << "1. Listado general de aspirantes\n";
        cout << "2. Reporte ordenado ascendentemente por puntaje total\n";
        cout << "3. Consulta de aspirante destacado\n";
        cout << "4. Volver\n";
        op = leerEnteroValidado("Seleccione una opci�n (1-4): ", 1, 4);

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
        cout << "\n=== TechSolutions S.A. - Gesti�n de Aspirantes ===\n";
        cout << "1. Registro de aspirantes\n";
        cout << "2. C�lculo de puntaje total por aspirante\n";
        cout << "3. Reportes y consultas\n";
        cout << "4. Salir\n";

        opcion = leerEnteroValidado("Seleccione una opci�n (1-4): ", 1, 4);
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
    cout << " TechSolutions S.A. - Gesti�n de Aspirantes\n";
    cout << "=============================================\n";
    cout << "La compa�ia necesita reclutar nuevo personal de forma justa y automatizada.\n";
    cout << "Se solicita un programa que permita:\n";
    cout << "  - Registrar informaci�n de los aspirantes.\n";
    cout << "  - Calcular su puntaje total con base en criterios t�cnicos y actitudinales.\n";
    cout << "  - Generar reportes detallados de evaluaci�n.\n\n";
    cout << "\nAUTORES:\n";
    cout << "  - Samuel Cogollo Villarreal (C�d. 0222420018)\n";
    cout << "  - Manuel Esteban Arcia Pastrana (C�d. 0222420001)\n";
    cout << "  - Manuel Francisco Amell Gil (C�d. 0222421001)\n";
    cout << "\nAsignatura: Programaci�n B�sica -- Grupo B1\n";
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


"""
# ============================================

def convertir_cpp_a_pseudocodigo(codigo_cpp):
    """
    Convierte código C++ a pseudocódigo manteniendo las llaves visibles
    """
    lineas = codigo_cpp.split('\n')
    pseudocodigo = []
    nivel_indentacion = 0
    en_comentario_bloque = False
    nombre_funcion_actual = ""
    en_main = False
    
    for linea in lineas:
        linea_original = linea
        linea = linea.strip()
        
        # Ignorar líneas vacías
        if not linea:
            pseudocodigo.append('')
            continue
            
        # Ignorar directivas del preprocesador
        if linea.startswith('#') or linea.startswith('using'):
            continue
        
        # Manejar comentarios de bloque /* */
        if '/*' in linea and '*/' not in linea:
            en_comentario_bloque = True
            pseudocodigo.append('    ' * nivel_indentacion + linea)
            continue
        elif '*/' in linea:
            en_comentario_bloque = False
            pseudocodigo.append('    ' * nivel_indentacion + linea)
            continue
        elif en_comentario_bloque:
            pseudocodigo.append('    ' * nivel_indentacion + linea)
            continue
        
        # Comentarios de línea - MANTENER
        if linea.startswith('//'):
            pseudocodigo.append('    ' * nivel_indentacion + linea)
            continue
        
        # main
        if re.match(r'^int\s+main\s*\(', linea):
            pseudocodigo.append('')
            pseudocodigo.append('Algoritmo main()')
            en_main = True
            continue
        
        # Declaración de función void
        if re.match(r'^void\s+(\w+)\s*\(', linea):
            match = re.search(r'void\s+(\w+)\s*\(', linea)
            nombre_funcion_actual = match.group(1)
            
            params = extraer_parametros(linea)
            params_pseudo = ', '.join(params) if params else ''
            
            pseudocodigo.append('')
            pseudocodigo.append('    ' * nivel_indentacion + f'Procedimiento {nombre_funcion_actual}({params_pseudo})')
            continue
        
        # Declaración de función int
        if re.match(r'^int\s+(\w+)\s*\(', linea) and 'main' not in linea:
            match = re.search(r'int\s+(\w+)\s*\(', linea)
            nombre_funcion_actual = match.group(1)
            
            params = extraer_parametros(linea)
            params_pseudo = ', '.join(params) if params else ''
            
            pseudocodigo.append('')
            pseudocodigo.append('    ' * nivel_indentacion + f'Funcion {nombre_funcion_actual}({params_pseudo}) : Entero')
            continue
        
        # Declaración de función float
        if re.match(r'^float\s+(\w+)\s*\(', linea):
            match = re.search(r'float\s+(\w+)\s*\(', linea)
            nombre_funcion_actual = match.group(1)
            
            params = extraer_parametros(linea)
            params_pseudo = ', '.join(params) if params else ''
            
            pseudocodigo.append('')
            pseudocodigo.append('    ' * nivel_indentacion + f'Funcion {nombre_funcion_actual}({params_pseudo}) : Real')
            continue
        
        # Declaración de función string
        if re.match(r'^string\s+(\w+)\s*\(', linea):
            match = re.search(r'string\s+(\w+)\s*\(', linea)
            nombre_funcion_actual = match.group(1)
            
            params = extraer_parametros(linea)
            params_pseudo = ', '.join(params) if params else ''
            
            pseudocodigo.append('')
            pseudocodigo.append('    ' * nivel_indentacion + f'Funcion {nombre_funcion_actual}({params_pseudo}) : Cadena')
            continue
        
        # Llave de apertura sola
        if linea == '{':
            pseudocodigo.append('    ' * nivel_indentacion + '{')
            nivel_indentacion += 1
            continue
        
        # Llave de cierre sola
        if linea == '}':
            nivel_indentacion -= 1
            pseudocodigo.append('    ' * nivel_indentacion + '}')
            continue
        
        # Declaraciones const
        if linea.startswith('const '):
            linea_pseudo = convertir_declaracion(linea)
            pseudocodigo.append('    ' * nivel_indentacion + linea_pseudo)
            continue
        
        # Declaraciones de variables
        if re.match(r'^(int|float|string|bool|double|char)\s+', linea):
            linea_pseudo = convertir_declaracion(linea)
            pseudocodigo.append('    ' * nivel_indentacion + linea_pseudo)
            continue
        
        # cout (salida)
        if 'cout' in linea:
            linea_pseudo = convertir_cout(linea)
            pseudocodigo.append('    ' * nivel_indentacion + linea_pseudo)
            continue
        
        # cin (entrada)
        if 'cin' in linea and '>>' in linea:
            linea_pseudo = convertir_cin(linea)
            pseudocodigo.append('    ' * nivel_indentacion + linea_pseudo)
            continue
        
        # getline (entrada de texto)
        if 'getline' in linea:
            match = re.search(r'getline\s*\(\s*cin\s*,\s*(\w+)\s*\)', linea)
            if match:
                var = match.group(1)
                pseudocodigo.append('    ' * nivel_indentacion + f'Leer {var}')
            continue
        
        # while con llave
        if re.match(r'^while\s*\(', linea):
            condicion = extraer_condicion(linea, 'while')
            if '{' in linea:
                pseudocodigo.append('    ' * nivel_indentacion + f'Mientras ({condicion}) ' + '{')
                nivel_indentacion += 1
            else:
                pseudocodigo.append('    ' * nivel_indentacion + f'Mientras ({condicion})')
            continue
        
        # do-while
        if linea.startswith('do') and '{' in linea:
            pseudocodigo.append('    ' * nivel_indentacion + 'Hacer {')
            nivel_indentacion += 1
            continue
        elif linea == 'do':
            pseudocodigo.append('    ' * nivel_indentacion + 'Hacer')
            continue
        
        # Fin do-while
        if re.match(r'^\}\s*while', linea):
            nivel_indentacion -= 1
            condicion = extraer_condicion(linea, 'while')
            pseudocodigo.append('    ' * nivel_indentacion + f'}} Mientras ({condicion});')
            continue
        
        # for con llave
        if re.match(r'^for\s*\(', linea):
            linea_pseudo = convertir_for(linea)
            if '{' in linea:
                pseudocodigo.append('    ' * nivel_indentacion + linea_pseudo + ' {')
                nivel_indentacion += 1
            else:
                pseudocodigo.append('    ' * nivel_indentacion + linea_pseudo)
            continue
        
        # if con llave
        if re.match(r'^if\s*\(', linea):
            condicion = extraer_condicion(linea, 'if')
            if '{' in linea:
                pseudocodigo.append('    ' * nivel_indentacion + f'Si ({condicion}) ' + '{')
                nivel_indentacion += 1
            else:
                pseudocodigo.append('    ' * nivel_indentacion + f'Si ({condicion})')
            continue
        
        # else if
        if re.match(r'^else\s+if\s*\(', linea) or linea.startswith('} else if'):
            if linea.startswith('}'):
                nivel_indentacion -= 1
                condicion = extraer_condicion(linea, 'if')
                if '{' in linea:
                    pseudocodigo.append('    ' * nivel_indentacion + f'}} Sino Si ({condicion}) ' + '{')
                    nivel_indentacion += 1
                else:
                    pseudocodigo.append('    ' * nivel_indentacion + f'}} Sino Si ({condicion})')
                    nivel_indentacion += 1
            else:
                condicion = extraer_condicion(linea, 'if')
                if '{' in linea:
                    pseudocodigo.append('    ' * nivel_indentacion + f'Sino Si ({condicion}) ' + '{')
                    nivel_indentacion += 1
                else:
                    pseudocodigo.append('    ' * nivel_indentacion + f'Sino Si ({condicion})')
            continue
        
        # else
        if linea == 'else {' or linea.startswith('} else'):
            if linea.startswith('}'):
                nivel_indentacion -= 1
                if '{' in linea:
                    pseudocodigo.append('    ' * nivel_indentacion + '} Sino {')
                    nivel_indentacion += 1
                else:
                    pseudocodigo.append('    ' * nivel_indentacion + '} Sino')
            else:
                if '{' in linea:
                    pseudocodigo.append('    ' * nivel_indentacion + 'Sino {')
                    nivel_indentacion += 1
                else:
                    pseudocodigo.append('    ' * nivel_indentacion + 'Sino')
            continue
        elif linea == 'else':
            pseudocodigo.append('    ' * nivel_indentacion + 'Sino')
            continue
        
        # switch
        if re.match(r'^switch\s*\(', linea):
            match = re.search(r'switch\s*\(\s*(\w+)\s*\)', linea)
            if match:
                var = match.group(1)
                if '{' in linea:
                    pseudocodigo.append('    ' * nivel_indentacion + f'Segun ({var}) ' + '{')
                    nivel_indentacion += 1
                else:
                    pseudocodigo.append('    ' * nivel_indentacion + f'Segun ({var})')
            continue
        
        # case
        if re.match(r'^case\s+', linea):
            match = re.search(r'case\s+(.+?):', linea)
            if match:
                valor = match.group(1).strip()
                pseudocodigo.append('    ' * nivel_indentacion + f'Caso {valor}:')
                # No incrementar indentación para mantener estructura
            continue
        
        # break
        if linea == 'break;':
            pseudocodigo.append('    ' * nivel_indentacion + 'Romper')
            continue
        
        # return
        if linea.startswith('return'):
            valor = linea.replace('return', '').replace(';', '').strip()
            if valor and valor != '0':
                pseudocodigo.append('    ' * nivel_indentacion + f'Retornar {valor}')
            else:
                pseudocodigo.append('    ' * nivel_indentacion + 'Retornar 0')
            continue
        
        # Llamadas a funciones especiales
        if 'system("pause")' in linea or 'system(\"pause\")' in linea:
            pseudocodigo.append('    ' * nivel_indentacion + 'system("pause")')
            continue
        
        if 'system("cls")' in linea or 'system("clear")' in linea:
            pseudocodigo.append('    ' * nivel_indentacion + 'system("cls")')
            continue
        
        if 'setlocale' in linea:
            pseudocodigo.append('    ' * nivel_indentacion + linea)
            continue
        
        # Asignaciones y otras operaciones
        if '=' in linea and not '==' in linea and not '!=' in linea and not '<=' in linea and not '>=' in linea:
            linea_pseudo = convertir_asignacion(linea)
            pseudocodigo.append('    ' * nivel_indentacion + linea_pseudo)
            continue
        
        # Incrementos/Decrementos
        if '++' in linea or '--' in linea:
            linea_pseudo = convertir_incremento(linea)
            pseudocodigo.append('    ' * nivel_indentacion + linea_pseudo)
            continue
        
        # Llamadas a función
        if re.search(r'\w+\s*\([^)]*\)\s*;', linea):
            linea_pseudo = linea.replace(';', '')
            pseudocodigo.append('    ' * nivel_indentacion + linea_pseudo)
            continue
        
        # Cualquier otra línea
        pseudocodigo.append('    ' * nivel_indentacion + linea)
    
    return '\n'.join(pseudocodigo)

def extraer_parametros(linea):
    """Extrae parámetros de una declaración de función"""
    match = re.search(r'\((.*?)\)', linea)
    if not match:
        return []
    
    params_str = match.group(1).strip()
    if not params_str or params_str == 'void':
        return []
    
    params = []
    for param in params_str.split(','):
        param = param.strip()
        # Mantener más información del parámetro
        param_limpio = re.sub(r'^(const\s+)?', '', param)
        if param_limpio and '=' not in param_limpio:
            params.append(param_limpio)
        elif '=' in param_limpio:
            params.append(param_limpio.split('=')[0].strip())
    
    return params

def extraer_condicion(linea, palabra_clave):
    """Extrae la condición de un if, while, etc."""
    pattern = f'{palabra_clave}\\s*\\((.*)\\)'
    match = re.search(pattern, linea)
    if match:
        condicion = match.group(1).strip()
        # Remover la llave si está al final
        condicion = condicion.rstrip('{').strip()
        return condicion
    return ''

def convertir_declaracion(linea):
    """Convierte declaración de variable manteniendo sintaxis similar"""
    linea_original = linea
    linea = linea.replace(';', '').strip()
    
    # Mantener const si existe
    es_const = 'const ' if linea.startswith('const ') else ''
    linea = linea.replace('const ', '')
    
    tipo_map = {
        'int': 'Entero',
        'float': 'Real',
        'double': 'Real',
        'string': 'Cadena',
        'bool': 'Logico',
        'char': 'Caracter'
    }
    
    tipo_original = ''
    for tipo_cpp, tipo_pseudo in tipo_map.items():
        if linea.startswith(tipo_cpp + ' '):
            tipo_original = tipo_cpp
            break
    
    if not tipo_original:
        return linea_original
    
    linea = linea[len(tipo_original):].strip()
    
    if '=' in linea:
        partes = linea.split('=', 1)
        var = partes[0].strip()
        valor = partes[1].strip()
        return f'{es_const}{tipo_map[tipo_original]} {var} = {valor}'
    else:
        var = linea
        if '[' in var:  # Es un arreglo
            return f'{es_const}{tipo_map[tipo_original]} {var}'
        return f'{es_const}{tipo_map[tipo_original]} {var}'

def convertir_cout(linea):
    """Convierte cout manteniendo formato similar"""
    return linea.replace('cout', 'Escribir').replace('<<', ',').replace('endl', '')

def convertir_cin(linea):
    """Convierte cin a Leer"""
    match = re.search(r'cin\s*>>\s*(\w+)', linea)
    if match:
        var = match.group(1)
        return f'Leer {var}'
    return linea

def convertir_for(linea):
    """Convierte for manteniendo sintaxis C++"""
    # Mantener el for original pero traducir la palabra
    linea = linea.replace('for', 'Para')
    return linea.rstrip('{').strip()

def convertir_asignacion(linea):
    """Convierte asignación manteniendo formato"""
    return linea.replace(';', '')

def convertir_incremento(linea):
    """Convierte incrementos/decrementos"""
    return linea.replace(';', '')

# ============================================
# EJECUCIÓN PRINCIPAL
# ============================================
if __name__ == "__main__":
    print("=" * 60)
    print("CONVERSOR C++ A PSEUDOCÓDIGO (CON LLAVES)")
    print("=" * 60)
    print()
    
    if not CODIGO_CPP.strip():
        print("⚠ No hay código para convertir.")
        print("Por favor, pega tu código C++ en la variable CODIGO_CPP")
    else:
        # Convierte el código
        pseudocodigo = convertir_cpp_a_pseudocodigo(CODIGO_CPP)
        
        # Muestra el resultado
        print(pseudocodigo)
        print()
        print("=" * 60)
        
        # Guarda en archivo
        try:
            with open('pseudocodigo_con_llaves.txt', 'w', encoding='utf-8') as f:
                f.write(pseudocodigo)
            print("✓ Guardado en: pseudocodigo_con_llaves.txt")
        except:
            print("✓ Conversión completada (no se pudo guardar archivo)")
    
    print("=" * 60)