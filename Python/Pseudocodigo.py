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
using namespace std;

void cls() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int leerEnteroValidado(const string &mensaje, int minVal = INT_MIN, int maxVal = INT_MAX) {
    int x;
    while (true) {
        cout << mensaje;
        if (cin >> x) {
            if (x >= minVal && x <= maxVal) {
                return x;
            }
        }
        cout << "Entrada invalida. Intente de nuevo." << endl;
    }
}

float calcularPuntaje(int nivel, int exp, int prueba, int entrev) {
    float total = 0.0f;

    switch (nivel) {
        case 1: total += 15; break;
        case 2: total += 20; break;
        case 3: total += 25; break;
        case 4: total += 30; break;
    }

    if (exp < 1) total += 5;
    else if (exp <= 3) total += 10;
    else if (exp <= 6) total += 15;
    else total += 20;

    return total;
}

int main() {
    int opcion;
    do {
        cout << "=== Menu Principal ===" << endl;
        cout << "1. Registrar" << endl;
        cout << "2. Calcular" << endl;
        cout << "3. Salir" << endl;
        opcion = leerEnteroValidado("Opcion: ", 1, 3);
        
        switch (opcion) {
            case 1: 
                cout << "Registrando..." << endl;
                break;
            case 2: 
                cout << "Calculando..." << endl;
                break;
            case 3: 
                cout << "Saliendo..." << endl;
                break;
        }
    } while (opcion != 3);
    
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
        
        # Manejar comentarios de bloque /* */
        if '/*' in linea and '*/' not in linea:
            en_comentario_bloque = True
            comentario = linea.replace('/*', '//').strip()
            pseudocodigo.append('    ' * nivel_indentacion + comentario)
            continue
        elif '*/' in linea:
            en_comentario_bloque = False
            comentario = linea.replace('*/', '').strip()
            if comentario:
                pseudocodigo.append('    ' * nivel_indentacion + '// ' + comentario)
            continue
        elif en_comentario_bloque:
            if linea.startswith('*'):
                linea = linea[1:].strip()
            pseudocodigo.append('    ' * nivel_indentacion + '// ' + linea)
            continue
        
        # Comentarios de línea
        if linea.startswith('//'):
            pseudocodigo.append('    ' * nivel_indentacion + linea)
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
            pseudocodigo.append('    ' * nivel_indentacion + f'Funcion retorno <- {nombre_funcion_actual}({params_pseudo})')
            nivel_indentacion += 1
            continue
        
        # Declaración de función float
        if re.match(r'^float\s+(\w+)\s*\(', linea):
            match = re.search(r'float\s+(\w+)\s*\(', linea)
            nombre_funcion_actual = match.group(1)
            
            params = extraer_parametros(linea)
            params_pseudo = ', '.join(params) if params else ''
            
            pseudocodigo.append('')
            pseudocodigo.append('    ' * nivel_indentacion + f'Funcion retorno <- {nombre_funcion_actual}({params_pseudo})')
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
        
        # new (asignación dinámica)
        if 'new ' in linea and '=' in linea:
            linea_pseudo = convertir_asignacion(linea)
            linea_pseudo = linea_pseudo.replace('new', '').replace('[', '').replace(']', '')
            pseudocodigo.append('    ' * nivel_indentacion + '// ' + linea_pseudo)
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
        return f'// Definir {var} Como {tipo}'

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