/*
ALGORITMO DE DIJKSTRA
=====================
Complejidad: O(V²) con esta implementación simple
Uso: Camino más corto desde un origen a todos los demás nodos
RESTRICCIÓN: No funciona con pesos NEGATIVOS

Dijkstra encuentra el camino más corto en grafos con pesos positivos.
Selecciona siempre el nodo no visitado con menor distancia.
*/

#include <iostream>
#include <climits>
#define MAXN 100
#define INF INT_MAX

using namespace std;

int grafo[MAXN][MAXN];  // Matriz de adyacencia con pesos
int distancia[MAXN];
int padre[MAXN];
bool visitado[MAXN];

// Encuentra el nodo no visitado con menor distancia
int nodo_minima_distancia(int n) {
    int min_dist = INF;
    int min_nodo = -1;
    
    for (int i = 0; i < n; i++) {
        if (!visitado[i] && distancia[i] < min_dist) {
            min_dist = distancia[i];
            min_nodo = i;
        }
    }
    
    return min_nodo;
}

// Algoritmo de Dijkstra básico
void dijkstra(int n, int inicio) {
    // Inicializamos distancias y padres
    for (int i = 0; i < n; i++) {
        distancia[i] = INF;
        padre[i] = -1;
        visitado[i] = false;
    }
    
    distancia[inicio] = 0;
    
    // Procesamos todos los nodos
    for (int count = 0; count < n - 1; count++) {
        // Seleccionamos el nodo no visitado con menor distancia
        int u = nodo_minima_distancia(n);
        
        if (u == -1) break;  // No hay más nodos alcanzables
        
        visitado[u] = true;
        
        // Actualizamos distancias de los vecinos
        for (int v = 0; v < n; v++) {
            // Si hay arista, no está visitado y encontramos un camino más corto
            if (grafo[u][v] != 0 && !visitado[v] && distancia[u] != INF) {
                int nueva_dist = distancia[u] + grafo[u][v];
                
                if (nueva_dist < distancia[v]) {
                    distancia[v] = nueva_dist;
                    padre[v] = u;
                }
            }
        }
    }
}

// Imprime las distancias desde el nodo de inicio
void imprimir_distancias(int n, int inicio) {
    cout << "Distancias desde nodo " << inicio << ":" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Nodo " << i << ": ";
        if (distancia[i] == INF) {
            cout << "INALCANZABLE" << endl;
        } else {
            cout << distancia[i] << endl;
        }
    }
}

// Reconstruye y muestra el camino desde inicio hasta destino
void imprimir_camino(int destino) {
    if (padre[destino] == -1) {
        cout << destino;
        return;
    }
    
    imprimir_camino(padre[destino]);
    cout << " -> " << destino;
}

void mostrar_camino_completo(int inicio, int destino) {
    if (distancia[destino] == INF) {
        cout << "No hay camino de " << inicio << " a " << destino << endl;
        return;
    }
    
    cout << "Camino de " << inicio << " a " << destino 
         << " (distancia " << distancia[destino] << "): ";
    imprimir_camino(destino);
    cout << endl;
}

// Versión optimizada para un destino específico (termina al encontrarlo)
int dijkstra_destino_especifico(int n, int inicio, int destino) {
    // Inicializamos
    for (int i = 0; i < n; i++) {
        distancia[i] = INF;
        padre[i] = -1;
        visitado[i] = false;
    }
    
    distancia[inicio] = 0;
    
    for (int count = 0; count < n; count++) {
        int u = nodo_minima_distancia(n);
        
        if (u == -1 || u == destino) break;  // Terminamos si alcanzamos el destino
        
        visitado[u] = true;
        
        for (int v = 0; v < n; v++) {
            if (grafo[u][v] != 0 && !visitado[v] && distancia[u] != INF) {
                int nueva_dist = distancia[u] + grafo[u][v];
                
                if (nueva_dist < distancia[v]) {
                    distancia[v] = nueva_dist;
                    padre[v] = u;
                }
            }
        }
    }
    
    return distancia[destino];
}

// Encuentra el segundo camino más corto
void segundo_camino_mas_corto(int n, int inicio, int destino) {
    // Primero encontramos el camino más corto
    dijkstra(n, inicio);
    
    if (distancia[destino] == INF) {
        cout << "No hay camino" << endl;
        return;
    }
    
    int camino_original = distancia[destino];
    int segundo_camino = INF;
    
    // Guardamos el camino original
    int camino[MAXN];
    int long_camino = 0;
    int actual = destino;
    
    while (actual != -1) {
        camino[long_camino++] = actual;
        actual = padre[actual];
    }
    
    // Probamos eliminando cada arista del camino original
    for (int i = 0; i < long_camino - 1; i++) {
        int u = camino[i+1];
        int v = camino[i];
        
        // Guardamos y eliminamos la arista
        int peso_original = grafo[u][v];
        grafo[u][v] = 0;
        
        // Calculamos nueva distancia
        int dist = dijkstra_destino_especifico(n, inicio, destino);
        
        if (dist != INF && dist > camino_original) {
            segundo_camino = min(segundo_camino, dist);
        }
        
        // Restauramos la arista
        grafo[u][v] = peso_original;
    }
    
    if (segundo_camino == INF) {
        cout << "No existe segundo camino más corto" << endl;
    } else {
        cout << "Segundo camino más corto: " << segundo_camino << endl;
    }
}

int main() {
    int n = 6;  // Número de nodos
    
    // Inicializamos el grafo (0 = sin arista)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grafo[i][j] = 0;
        }
    }
    
    // Agregamos aristas con pesos (grafo dirigido)
    // Grafo de ejemplo:
    //      1
    //   4→ | ↓5
    //  ↗   ↓ ↓
    // 0    3→5
    // ↓2   ↑8
    //  →2→4
    
    grafo[0][1] = 4;
    grafo[0][2] = 2;
    grafo[1][3] = 5;
    grafo[2][3] = 8;
    grafo[2][4] = 10;
    grafo[3][5] = 2;
    grafo[4][3] = 2;
    grafo[4][5] = 6;
    
    // Dijkstra desde nodo 0
    dijkstra(n, 0);
    
    // Mostramos todas las distancias
    imprimir_distancias(n, 0);
    
    // Mostramos camino específico
    cout << endl;
    mostrar_camino_completo(0, 5);
    mostrar_camino_completo(0, 3);
    
    // Probamos con grafo no dirigido (agregando aristas inversas)
    cout << "\n--- Grafo No Dirigido ---" << endl;
    
    // Reiniciamos
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grafo[i][j] = 0;
        }
    }
    
    // Agregamos aristas bidireccionales
    grafo[0][1] = grafo[1][0] = 4;
    grafo[0][2] = grafo[2][0] = 2;
    grafo[1][3] = grafo[3][1] = 5;
    grafo[2][4] = grafo[4][2] = 10;
    grafo[3][4] = grafo[4][3] = 3;
    grafo[3][5] = grafo[5][3] = 2;
    grafo[4][5] = grafo[5][4] = 6;
    
    dijkstra(n, 0);
    imprimir_distancias(n, 0);
    
    cout << endl;
    mostrar_camino_completo(0, 5);
    
    return 0;
}