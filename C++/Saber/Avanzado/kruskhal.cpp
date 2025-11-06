/*
ALGORITMO DE KRUSKAL
====================
Complejidad: O(E log E) donde E = número de aristas
Uso: Encontrar Árbol de Expansión Mínima (Minimum Spanning Tree - MST)

Kruskal ordena las aristas por peso y las agrega una por una si no forman ciclo.
Usa Union-Find (Disjoint Set Union) para detectar ciclos eficientemente.
*/

#include <iostream>
#include <algorithm>
#define MAXN 100
#define MAXE 10000

using namespace std;

// Estructura para representar una arista
struct Arista {
    int origen;
    int destino;
    int peso;
};

Arista aristas[MAXE];
int num_aristas;

// Arrays para Union-Find
int padre[MAXN];
int rango[MAXN];

// Aristas del MST resultante
Arista mst[MAXN];
int num_aristas_mst;

// ========== UNION-FIND (Disjoint Set Union) ==========

// Inicializa el Union-Find
void inicializar_uf(int n) {
    for (int i = 0; i < n; i++) {
        padre[i] = i;     // Cada nodo es su propio padre
        rango[i] = 0;     // Rango inicial es 0
    }
}

// Encuentra el representante (raíz) del conjunto - con compresión de camino
int find(int x) {
    if (padre[x] != x) {
        padre[x] = find(padre[x]);  // Compresión de camino
    }
    return padre[x];
}

// Une dos conjuntos - con unión por rango
bool union_set(int x, int y) {
    int raiz_x = find(x);
    int raiz_y = find(y);
    
    // Si ya están en el mismo conjunto, formar ciclo
    if (raiz_x == raiz_y) {
        return false;
    }
    
    // Unión por rango: el árbol más pequeño se cuelga del más grande
    if (rango[raiz_x] < rango[raiz_y]) {
        padre[raiz_x] = raiz_y;
    }
    else if (rango[raiz_x] > rango[raiz_y]) {
        padre[raiz_y] = raiz_x;
    }
    else {
        padre[raiz_y] = raiz_x;
        rango[raiz_x]++;
    }
    
    return true;
}

// ========== ALGORITMO DE KRUSKAL ==========

// Función de comparación para ordenar aristas por peso
bool comparar_aristas(Arista a, Arista b) {
    return a.peso < b.peso;
}

// Algoritmo de Kruskal
int kruskal(int n) {
    // Ordenamos las aristas por peso
    sort(aristas, aristas + num_aristas, comparar_aristas);
    
    // Inicializamos Union-Find
    inicializar_uf(n);
    
    num_aristas_mst = 0;
    int peso_total = 0;
    
    // Procesamos cada arista en orden de peso
    for (int i = 0; i < num_aristas; i++) {
        int u = aristas[i].origen;
        int v = aristas[i].destino;
        int peso = aristas[i].peso;
        
        // Si la arista no forma ciclo, la agregamos al MST
        if (union_set(u, v)) {
            mst[num_aristas_mst++] = aristas[i];
            peso_total += peso;
            
            // Si ya tenemos n-1 aristas, el MST está completo
            if (num_aristas_mst == n - 1) {
                break;
            }
        }
    }
    
    return peso_total;
}

// Imprime el MST resultante
void imprimir_mst() {
    cout << "Aristas del Árbol de Expansión Mínima:" << endl;
    for (int i = 0; i < num_aristas_mst; i++) {
        cout << mst[i].origen << " -- " << mst[i].destino 
             << " (peso: " << mst[i].peso << ")" << endl;
    }
}

// Verifica si el grafo es conexo (si el MST tiene n-1 aristas)
bool es_conexo(int n) {
    return num_aristas_mst == n - 1;
}

// Encuentra el segundo MST
int segundo_mst(int n) {
    int primer_mst_peso = kruskal(n);
    
    if (!es_conexo(n)) {
        return -1;  // No hay MST
    }
    
    // Guardamos las aristas del primer MST
    Arista primer_mst[MAXN];
    int num_primer_mst = num_aristas_mst;
    for (int i = 0; i < num_primer_mst; i++) {
        primer_mst[i] = mst[i];
    }
    
    int segundo_peso = 999999;
    
    // Probamos eliminando cada arista del primer MST
    for (int excluir = 0; excluir < num_primer_mst; excluir++) {
        // Creamos lista de aristas sin la arista a excluir
        Arista temp_aristas[MAXE];
        int temp_num = 0;
        
        for (int i = 0; i < num_aristas; i++) {
            bool es_excluida = (aristas[i].origen == primer_mst[excluir].origen &&
                               aristas[i].destino == primer_mst[excluir].destino &&
                               aristas[i].peso == primer_mst[excluir].peso);
            
            if (!es_excluida) {
                temp_aristas[temp_num++] = aristas[i];
            }
        }
        
        // Guardamos aristas originales
        Arista backup[MAXE];
        int backup_num = num_aristas;
        for (int i = 0; i < num_aristas; i++) {
            backup[i] = aristas[i];
        }
        
        // Usamos las aristas temporales
        for (int i = 0; i < temp_num; i++) {
            aristas[i] = temp_aristas[i];
        }
        num_aristas = temp_num;
        
        // Ejecutamos Kruskal
        int peso = kruskal(n);
        
        if (es_conexo(n) && peso > primer_mst_peso) {
            segundo_peso = min(segundo_peso, peso);
        }
        
        // Restauramos aristas originales
        num_aristas = backup_num;
        for (int i = 0; i < backup_num; i++) {
            aristas[i] = backup[i];
        }
    }
    
    // Restauramos el primer MST
    kruskal(n);
    
    return (segundo_peso == 999999) ? -1 : segundo_peso;
}

// Cuenta el número de componentes conexos
int contar_componentes(int n) {
    kruskal(n);
    
    int componentes = 0;
    bool contado[MAXN] = {false};
    
    for (int i = 0; i < n; i++) {
        int raiz = find(i);
        if (!contado[raiz]) {
            contado[raiz] = true;
            componentes++;
        }
    }
    
    return componentes;
}

int main() {
    int n = 6;  // Número de nodos
    num_aristas = 0;
    
    // Agregamos aristas (grafo no dirigido)
    // Formato: origen, destino, peso
    
    // Grafo de ejemplo:
    //     1---5
    //    /|\ /|
    //   4 | X |8
    //  /  |/ \|
    // 0---2---3
    //  \     /
    //   6   7
    //    \ /
    //     4
    
    aristas[num_aristas++] = {0, 1, 4};
    aristas[num_aristas++] = {0, 2, 3};
    aristas[num_aristas++] = {0, 4, 6};
    aristas[num_aristas++] = {1, 2, 2};
    aristas[num_aristas++] = {1, 3, 5};
    aristas[num_aristas++] = {1, 5, 1};
    aristas[num_aristas++] = {2, 3, 6};
    aristas[num_aristas++] = {2, 5, 4};
    aristas[num_aristas++] = {3, 4, 7};
    aristas[num_aristas++] = {3, 5, 8};
    
    // Ejecutamos Kruskal
    int peso_total = kruskal(n);
    
    cout << "=== ALGORITMO DE KRUSKAL ===" << endl;
    cout << "\nPeso total del MST: " << peso_total << endl;
    cout << endl;
    
    // Imprimimos el MST
    imprimir_mst();
    
    // Verificamos si es conexo
    if (es_conexo(n)) {
        cout << "\nEl grafo es conexo" << endl;
    } else {
        cout << "\nEl grafo NO es conexo" << endl;
        int componentes = contar_componentes(n);
        cout << "Número de componentes: " << componentes << endl;
    }
    
    // Ejemplo de grafo no conexo
    cout << "\n--- Grafo No Conexo ---" << endl;
    n = 7;
    num_aristas = 0;
    
    // Componente 1: nodos 0, 1, 2
    aristas[num_aristas++] = {0, 1, 3};
    aristas[num_aristas++] = {1, 2, 4};
    aristas[num_aristas++] = {0, 2, 5};
    
    // Componente 2: nodos 3, 4
    aristas[num_aristas++] = {3, 4, 2};
    
    // Componente 3: nodos 5, 6
    aristas[num_aristas++] = {5, 6, 1};
    
    peso_total = kruskal(n);
    cout << "Peso total: " << peso_total << endl;
    imprimir_mst();
    
    int componentes = contar_componentes(n);
    cout << "\nNúmero de componentes conexos: " << componentes << endl;
    
    return 0;
}