"""
Script para convertir código C++ a pseudocódigo estilo PSeInt
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

// MODIFICADA: Usa aritm�tica de punteros
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

// MODIFICADA: Usa aritm�tica de punteros
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

    // Recorrido con aritm�tica de punteros
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

// MODIFICADA: Usa aritm�tica de punteros para b�squeda de duplicados
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
            
            // Recorrido con punteros para verificar duplicados
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

        // Asignaci�n usando punteros
        *(nombres + cantidad) = nombre;
        *(ids + cantidad) = id;
        *(edades + cantidad) = edad;
        *(niveles + cantidad) = nivel;
        *(experiencias + cantidad) = exp;
        *(pruebas + cantidad) = prueba;
        *(entrevistas + cantidad) = entrevista;
        *(puntajes + cantidad) = 0.0;
        cantidad++;

        cout << "Aspirante registrado correctamente.\n";
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

    calcularPuntajes(puntajes, niveles, experiencias, pruebas, entrevistas, cantidad);
    mostrarResultados(nombres, ids, puntajes, cantidad);
}

// MODIFICADA: Usa aritm�tica de punteros para intercambio
void ordenarPorPuntajeAsc(string nombres[], string ids[], int edades[], int niveles[],
                          int experiencias[], int pruebas[], int entrevistas[], float puntajes[],
                          int cantidad) {
    for (int i = 0; i < cantidad - 1; ++i) {
        for (int j = 0; j < cantidad - i - 1; ++j) {
            // Comparaci�n usando punteros
            if (*(puntajes + j) > *(puntajes + j + 1)) {
                // Intercambio usando aritm�tica de punteros
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

// MODIFICADA: Usa aritm�tica de punteros para recorrer y buscar mayor
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

    // Recorrido con punteros
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

void menuReportes(string nombres[], string ids[], int edades[], int niveles[],
                  int experiencias[], int pruebas[], int entrevistas[], float puntajes[], int cantidad) {
    int op;
    do {
        cout << "\n=== SUBMEN�: REPORTES Y CONSULTAS ===\n";
        cout << "1. Listado general de aspirantes\n";
        cout << "2. Reporte ordenado ascendentemente por puntaje total\n";
        cout << "3. Volver\n";
        op = leerEnteroValidado("Seleccione una opci�n (1-3): ", 1, 3);

        if (op == 1) reporteGeneral(nombres, ids, edades, niveles, experiencias, pruebas, entrevistas, puntajes, cantidad);
        else if (op == 2) {
            ordenarPorPuntajeAsc(nombres, ids, edades, niveles, experiencias, pruebas, entrevistas, puntajes, cantidad);
            reporteGeneral(nombres, ids, edades, niveles, experiencias, pruebas, entrevistas, puntajes, cantidad);
        } else system("cls");

    } while (op != 3);
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
    Convierte código C++ a pseudocódigo estilo PSeInt
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
        
        # Ignorar líneas vacías y directivas del preprocesador
        if not linea or linea.startswith('#') or linea.startswith('using'):
            continue
        
        # Manejar comentarios de bloque /* */ - IGNORAR
        if '/*' in linea and '*/' not in linea:
            en_comentario_bloque = True
            continue
        elif '*/' in linea:
            en_comentario_bloque = False
            continue
        elif en_comentario_bloque:
            continue
        
        # Comentarios de línea - IGNORAR
        if linea.startswith('//'):
            continue
        
        # main
        if re.match(r'^int\s+main\s*\(', linea):
            pseudocodigo.append('')
            pseudocodigo.append('Algoritmo SistemaGestion')
            nivel_indentacion += 1
            en_main = True
            continue
        
        # Declaración de función void
        if re.match(r'^void\s+(\w+)\s*\(', linea):
            match = re.search(r'void\s+(\w+)\s*\(', linea)
            nombre_funcion_actual = match.group(1)
            
            params = extraer_parametros(linea)
            params_pseudo = ', '.join(params) if params else ''
            
            pseudocodigo.append('')
            pseudocodigo.append('    ' * nivel_indentacion + f'SubProceso {nombre_funcion_actual}({params_pseudo})')
            nivel_indentacion += 1
            continue
        
        # Declaración de función int
        if re.match(r'^int\s+(\w+)\s*\(', linea) and 'main' not in linea:
            match = re.search(r'int\s+(\w+)\s*\(', linea)
            nombre_funcion_actual = match.group(1)
            
            params = extraer_parametros(linea)
            params_pseudo = ', '.join(params) if params else ''
            
            pseudocodigo.append('')
            pseudocodigo.append('    ' * nivel_indentacion + f'Funcion {nombre_funcion_actual}({params_pseudo}) : Entero')
            nivel_indentacion += 1
            continue
        
        # Declaración de función float
        if re.match(r'^float\s+(\w+)\s*\(', linea):
            match = re.search(r'float\s+(\w+)\s*\(', linea)
            nombre_funcion_actual = match.group(1)
            
            params = extraer_parametros(linea)
            params_pseudo = ', '.join(params) if params else ''
            
            pseudocodigo.append('')
            pseudocodigo.append('    ' * nivel_indentacion + f'Funcion {nombre_funcion_actual}({params_pseudo}) : Real')
            nivel_indentacion += 1
            continue
        
        # Fin de función
        if linea == '}' and nivel_indentacion > 0:
            nivel_indentacion -= 1
            if en_main:
                pseudocodigo.append('    ' * nivel_indentacion + 'FinAlgoritmo')
                en_main = False
            elif nombre_funcion_actual:
                pseudocodigo.append('    ' * nivel_indentacion + 'FinSubProceso')
                nombre_funcion_actual = ""
            continue
        
        # Declaraciones de variables
        if re.match(r'^(int|float|string|bool|double|char)\s+', linea) and '=' in linea:
            linea_pseudo = convertir_declaracion(linea)
            pseudocodigo.append('    ' * nivel_indentacion + linea_pseudo)
            continue
        elif re.match(r'^(int|float|string|bool|double|char)\s+', linea):
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
        
        # while
        if re.match(r'^while\s*\(', linea):
            condicion = extraer_condicion(linea, 'while')
            pseudocodigo.append('    ' * nivel_indentacion + f'Mientras {condicion} Hacer')
            nivel_indentacion += 1
            continue
        
        # do-while
        if linea.startswith('do') and '{' in linea:
            pseudocodigo.append('    ' * nivel_indentacion + 'Repetir')
            nivel_indentacion += 1
            continue
        
        # Fin do-while
        if re.match(r'^\}\s*while', linea):
            nivel_indentacion -= 1
            condicion = extraer_condicion(linea, 'while')
            pseudocodigo.append('    ' * nivel_indentacion + f'Hasta Que {convertir_condicion_negada(condicion)}')
            continue
        
        # for
        if re.match(r'^for\s*\(', linea):
            linea_pseudo = convertir_for(linea)
            pseudocodigo.append('    ' * nivel_indentacion + linea_pseudo)
            nivel_indentacion += 1
            continue
        
        # if
        if re.match(r'^if\s*\(', linea):
            condicion = extraer_condicion(linea, 'if')
            pseudocodigo.append('    ' * nivel_indentacion + f'Si {condicion} Entonces')
            nivel_indentacion += 1
            continue
        
        # else if
        if re.match(r'^else\s+if\s*\(', linea) or linea.startswith('} else if'):
            if linea.startswith('}'):
                nivel_indentacion -= 1
            condicion = extraer_condicion(linea, 'if')
            pseudocodigo.append('    ' * nivel_indentacion + f'Sino Si {condicion} Entonces')
            if not linea.startswith('}'):
                nivel_indentacion += 1
            else:
                nivel_indentacion += 1
            continue
        
        # else
        if linea == 'else {' or linea.startswith('} else') or linea == 'else':
            if linea.startswith('}'):
                nivel_indentacion -= 1
            pseudocodigo.append('    ' * nivel_indentacion + 'Sino')
            nivel_indentacion += 1
            continue
        
        # switch
        if re.match(r'^switch\s*\(', linea):
            match = re.search(r'switch\s*\(\s*(\w+)\s*\)', linea)
            if match:
                var = match.group(1)
                pseudocodigo.append('    ' * nivel_indentacion + f'Segun {var} Hacer')
                nivel_indentacion += 1
            continue
        
        # case
        if re.match(r'^case\s+', linea):
            match = re.search(r'case\s+(\w+)\s*:', linea)
            if match:
                valor = match.group(1)
                pseudocodigo.append('    ' * nivel_indentacion + f'{valor}:')
                nivel_indentacion += 1
            continue
        
        # break
        if linea == 'break;':
            nivel_indentacion -= 1
            continue
        
        # return
        if linea.startswith('return'):
            valor = linea.replace('return', '').replace(';', '').strip()
            if valor and valor != '0':
                pseudocodigo.append('    ' * nivel_indentacion + f'retorno <- {valor}')
            continue
        
        # Llamadas a funciones especiales
        if 'system("pause")' in linea or 'system(\"pause\")' in linea:
            pseudocodigo.append('    ' * nivel_indentacion + 'Esperar Tecla')
            continue
        
        if 'cls()' in linea or 'system("cls")' in linea or 'system("clear")' in linea:
            pseudocodigo.append('    ' * nivel_indentacion + 'Limpiar Pantalla')
            continue
        
        # delete (liberar memoria)
        if 'delete[]' in linea or 'delete ' in linea:
            continue
        
        # new (asignación dinámica) - IGNORAR
        if 'new ' in linea and '=' in linea:
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
        param = re.sub(r'^(const\s+)?(int|float|string|bool|void|double|char)\s*[*&]*\s*', '', param)
        if param and '=' not in param:
            params.append(param)
        elif '=' in param:
            params.append(param.split('=')[0].strip())
    
    return params

def extraer_condicion(linea, palabra_clave):
    """Extrae la condición de un if, while, etc."""
    pattern = f'{palabra_clave}\\s*\\((.*)\\)'
    match = re.search(pattern, linea)
    if match:
        condicion = match.group(1).strip()
        return convertir_condicion(condicion)
    return ''

def convertir_condicion(condicion):
    """Convierte operadores de C++ a pseudocódigo"""
    condicion = condicion.replace('&&', ' Y ')
    condicion = condicion.replace('||', ' O ')
    condicion = condicion.replace('!', 'NO ')
    condicion = condicion.replace('==', '=')
    condicion = condicion.replace('true', 'Verdadero')
    condicion = condicion.replace('false', 'Falso')
    return condicion

def convertir_condicion_negada(condicion):
    """Niega una condición para do-while"""
    if condicion.startswith('NO '):
        return condicion[3:]
    return f'NO ({condicion})'

def convertir_declaracion(linea):
    """Convierte declaración de variable"""
    linea = linea.replace(';', '')
    
    tipo = ''
    if linea.startswith('int '):
        tipo = 'Entero'
        linea = linea.replace('int ', '', 1)
    elif linea.startswith('float ') or linea.startswith('double '):
        tipo = 'Real'
        linea = linea.replace('float ', '', 1).replace('double ', '', 1)
    elif linea.startswith('string '):
        tipo = 'Cadena'
        linea = linea.replace('string ', '', 1)
    elif linea.startswith('bool '):
        tipo = 'Logico'
        linea = linea.replace('bool ', '', 1)
    elif linea.startswith('char '):
        tipo = 'Caracter'
        linea = linea.replace('char ', '', 1)
    
    if '=' in linea:
        partes = linea.split('=')
        var = partes[0].strip().replace('*', '').replace('&', '')
        valor = partes[1].strip().replace(';', '').replace('f', '').replace('0.0', '0')
        return f'{var} <- {valor}'
    else:
        var = linea.strip().replace('*', '').replace('&', '').replace(';', '')
        return f'{var} : {tipo}'

def convertir_cout(linea):
    """Convierte cout a Escribir"""
    contenido = linea.split('cout')[1] if 'cout' in linea else ''
    contenido = contenido.replace(';', '').strip()
    
    if contenido.startswith('<<'):
        contenido = contenido[2:].strip()
    
    elementos = []
    partes = contenido.split('<<')
    
    for parte in partes:
        parte = parte.strip()
        if parte == 'endl' or parte == '"\\n"' or parte == '\\n':
            continue
        if parte.startswith('"') and parte.endswith('"'):
            parte = parte[1:-1]
        elementos.append(parte)
    
    if elementos:
        return 'Escribir ' + ', '.join(elementos)
    return 'Escribir ""'

def convertir_cin(linea):
    """Convierte cin a Leer"""
    match = re.search(r'cin\s*>>\s*(\w+)', linea)
    if match:
        var = match.group(1)
        return f'Leer {var}'
    return linea

def convertir_for(linea):
    """Convierte for a Para"""
    match = re.search(r'for\s*\(\s*(?:int\s+)?(\w+)\s*=\s*(\d+)\s*;\s*\1\s*([<>]=?)\s*(\w+)\s*;.*?\)', linea)
    if match:
        var = match.group(1)
        inicio = match.group(2)
        operador = match.group(3)
        fin = match.group(4)
        
        if '<' in operador and '=' not in operador:
            return f'Para {var} <- {inicio} Hasta {fin}-1 Hacer'
        elif '<=' in operador:
            return f'Para {var} <- {inicio} Hasta {fin} Hacer'
        else:
            return f'Para {var} <- {inicio} Hasta {fin} Hacer'
    return 'Para ... Hacer'

def convertir_asignacion(linea):
    """Convierte asignación"""
    linea = linea.replace(';', '').strip()
    if '=' in linea:
        partes = linea.split('=', 1)
        izq = partes[0].strip()
        der = partes[1].strip().replace('f;', '').replace('f', '')
        return f'{izq} <- {der}'
    return linea

def convertir_incremento(linea):
    """Convierte incrementos/decrementos"""
    linea = linea.replace(';', '').strip()
    if '++' in linea:
        var = linea.replace('++', '').strip()
        return f'{var} <- {var} + 1'
    elif '--' in linea:
        var = linea.replace('--', '').strip()
        return f'{var} <- {var} - 1'
    return linea

# ============================================
# EJECUCIÓN PRINCIPAL
# ============================================
if __name__ == "__main__":
    print("=" * 60)
    print("CONVERSOR C++ A PSEUDOCÓDIGO PSEINT")
    print("=" * 60)
    print()
    
    # Convierte el código
    pseudocodigo = convertir_cpp_a_pseudocodigo(CODIGO_CPP)
    
    # Muestra el resultado
    print(pseudocodigo)
    print()
    print("=" * 60)
    
    # Guarda en archivo
    try:
        with open('pseudocodigo_resultado.txt', 'w', encoding='utf-8') as f:
            f.write(pseudocodigo)
        print("✓ Guardado en: pseudocodigo_resultado.txt")
    except:
        print("✓ Conversión completada (no se pudo guardar archivo)")
    
    print("=" * 60)