/*
COMBINATORIA Y MATEMÁTICAS DISCRETAS
====================================
Incluye: Factorial, Permutaciones, Combinaciones, Coeficientes Binomiales,
Números de Catalan, Principio de Inclusión-Exclusión

La combinatoria estudia cómo contar y enumerar configuraciones.
*/

#include <iostream>
#include <cstring>
#define MAXN 1005
#define MOD 1000000007  // 10^9 + 7 (número primo común para módulo)

using namespace std;

// Tablas para memoización
long long factorial_memo[MAXN];
long long C[MAXN][MAXN];  // Triángulo de Pascal para combinaciones
bool calculado_pascal = false;

// ========== FACTORIAL ==========

// Factorial simple (cuidado con overflow para n > 20)
// El factorial es como preguntar: ¿de cuántas formas puedo ordenar n cosas?
// Si tienes 3 libros, puedes ordenarlos de 3! = 6 formas diferentes
// Primer libro: 3 opciones, segundo: 2 opciones, tercero: 1 opción -> 3*2*1
long long factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

// Factorial iterativo
long long factorial_iterativo(int n) {
    long long resultado = 1;
    for (int i = 2; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

// Factorial con módulo (para números grandes)
// ¿Por qué módulo? Porque el factorial crece SÚPER rápido
// 20! ya no cabe en un long long. Entonces guardamos solo el "residuo"
// Es como un reloj: después de las 12, volvemos a 1
long long factorial_mod(int n, long long mod) {
    long long resultado = 1;
    for (int i = 2; i <= n; i++) {
        resultado = (resultado * i) % mod;  // Guardamos solo el residuo
    }
    return resultado;
}

// Precalcula factoriales hasta MAXN
void precalcular_factoriales() {
    factorial_memo[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        factorial_memo[i] = (factorial_memo[i-1] * i) % MOD;
    }
}

// ========== PERMUTACIONES ==========

// Permutaciones P(n, r) = n! / (n-r)!
// Número de formas de ordenar r elementos tomados de n elementos
// Piensa: tienes n personas y r sillas. ¿De cuántas formas se pueden sentar?
// Ejemplo: 5 personas, 2 sillas: P(5,2) = 5*4 = 20
// Primera silla: 5 opciones, segunda: 4 opciones (ya usamos 1)
long long permutaciones(int n, int r) {
    if (r > n) return 0;  // No puedes elegir más de lo que tienes
    if (r == 0) return 1;  // Una forma de elegir nada: no elegir nada
    
    long long resultado = 1;
    // Multiplicamos: n * (n-1) * (n-2) * ... * (n-r+1)
    for (int i = n; i > n - r; i--) {
        resultado *= i;
    }
    return resultado;
}

// Permutaciones con repetición
// Si tienes elementos REPETIDOS, no todas las permutaciones son diferentes
// Ejemplo: La palabra "AAB" solo tiene 3 permutaciones únicas: AAB, ABA, BAA
// (no 6 como tendría "ABC")
// Fórmula: n! / (r1! * r2! * ... * rk!)
// donde r1, r2, ... son las cantidades de cada elemento repetido
long long permutaciones_con_repeticion(int n, int repeticiones[], int k) {
    long long numerador = factorial_iterativo(n);
    long long denominador = 1;
    
    // Dividimos por el factorial de cada repetición
    for (int i = 0; i < k; i++) {
        denominador *= factorial_iterativo(repeticiones[i]);
    }
    
    return numerador / denominador;
}

// ========== COMBINACIONES ==========

// Combinaciones C(n, r) = n! / (r! * (n-r)!)
// ¿De cuántas formas puedo ELEGIR r elementos de n? (sin importar el orden)
// LA GRAN DIFERENCIA con permutaciones: aquí {A,B} = {B,A} (son lo mismo)
// Ejemplo: C(5,2) = 10. De 5 personas, elegir 2 para un equipo (sin líder)
// Piensa en una lotería: elegir 6 números de 49, el orden NO importa
long long combinaciones(int n, int r) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;
    if (r > n - r) r = n - r;  // Truco: C(n,r) = C(n,n-r), elegimos el menor
    
    long long resultado = 1;
    // Calculamos de forma eficiente: (n * (n-1) * ... * (n-r+1)) / (1 * 2 * ... * r)
    for (int i = 0; i < r; i++) {
        resultado *= (n - i);
        resultado /= (i + 1);
    }
    
    return resultado;
}

// Triángulo de Pascal para precalcular combinaciones
// C[n][r] = C[n-1][r-1] + C[n-1][r]
// ¡Es como magia! Cada número es la suma de los dos que están arriba
// Visual:
//       1
//      1 1
//     1 2 1
//    1 3 3 1
//   1 4 6 4 1
// 
// ¿Por qué funciona? Imagina elegir r de n elementos. O incluyes el último
// elemento (y eliges r-1 de n-1), o NO lo incluyes (eliges r de n-1)
void precalcular_pascal(int max_n) {
    for (int n = 0; n <= max_n; n++) {
        C[n][0] = 1;  // Siempre hay 1 forma de elegir 0 elementos
        C[n][n] = 1;  // Siempre hay 1 forma de elegir todos los elementos
        for (int r = 1; r < n; r++) {
            C[n][r] = (C[n-1][r-1] + C[n-1][r]) % MOD;
        }
    }
    calculado_pascal = true;
}

// Combinaciones con módulo usando Pascal
long long combinaciones_mod(int n, int r) {
    if (!calculado_pascal) precalcular_pascal(MAXN - 1);
    return C[n][r];
}

// ========== NÚMEROS DE CATALAN ==========

// Números de Catalan: Cat(n) = C(2n, n) / (n+1)
// Son SUPER importantes y aparecen en MUCHOS problemas:
// 1. ¿Cuántos árboles binarios diferentes con n nodos? -> Cat(n)
// 2. ¿Cuántas formas de parentizar n+1 números? -> Cat(n)
//    Ejemplo: (ab)c, a(bc) son las 2 formas para n=2
// 3. ¿Cuántos caminos en una cuadrícula n×n que NO cruzan la diagonal? -> Cat(n)
// 4. ¿Cuántas formas de triangular un polígono de n+2 lados? -> Cat(n)
long long catalan(int n) {
    return combinaciones(2 * n, n) / (n + 1);
}

// Catalan usando programación dinámica
// Otra forma de pensar en Catalan: Cat(n) = suma de Cat(i) * Cat(n-1-i)
// Es como dividir un árbol en subárbol izquierdo (i nodos) y derecho (n-1-i nodos)
long long catalan_dp(int n) {
    long long cat[n + 1];
    cat[0] = cat[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        cat[i] = 0;
        // Probamos todas las divisiones posibles
        for (int j = 0; j < i; j++) {
            cat[i] += cat[j] * cat[i - 1 - j];
        }
    }
    
    return cat[n];
}

// ========== NÚMEROS DE STIRLING ==========

// Stirling de segunda especie S(n, k)
// Número de formas de particionar n elementos en k subconjuntos no vacíos
// Imagina que tienes n pelotas y k cajas. ¿De cuántas formas puedes meter
// las pelotas en las cajas de modo que NINGUNA caja quede vacía?
// Ejemplo: S(3,2) = 3. Con pelotas {A,B,C} y 2 cajas:
//   Caja1={A,B} Caja2={C}, Caja1={A,C} Caja2={B}, Caja1={A} Caja2={B,C}
long long stirling2[MAXN][MAXN];

void precalcular_stirling(int max_n) {
    stirling2[0][0] = 1;
    
    for (int n = 1; n <= max_n; n++) {
        for (int k = 1; k <= n; k++) {
            // La fórmula dice: o el elemento n va a una caja existente (k opciones)
            // o creamos una nueva caja para él
            stirling2[n][k] = k * stirling2[n-1][k] + stirling2[n-1][k-1];
        }
    }
}

// ========== NÚMEROS DE FIBONACCI ==========

// Fibonacci: cada número es la suma de los dos anteriores
// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ...
// Aparece en la NATURALEZA: pétalos de flores, espirales de caracoles, etc.
// En programación: análisis de algoritmos, estructuras de datos
long long fib[MAXN];

void precalcular_fibonacci(int max_n) {
    fib[0] = 0;  // Por definición
    fib[1] = 1;  // Por definición
    
    for (int i = 2; i <= max_n; i++) {
        fib[i] = (fib[i-1] + fib[i-2]) % MOD;
    }
}

// Fibonacci con matriz (O(log n))
// ¡TRUCO GENIAL! Fibonacci se puede calcular usando matrices
// [F(n+1)]   [1 1]^n   [1]
// [F(n)  ] = [1 0]   * [0]
// 
// ¿Por qué importa? Porque podemos elevar la matriz usando exponenciación
// binaria (como calcular 2^100 haciendo solo ~7 multiplicaciones)
void multiplicar_matrices(long long A[2][2], long long B[2][2]) {
    long long temp[2][2];
    temp[0][0] = (A[0][0] * B[0][0] + A[0][1] * B[1][0]) % MOD;
    temp[0][1] = (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % MOD;
    temp[1][0] = (A[1][0] * B[0][0] + A[1][1] * B[1][0]) % MOD;
    temp[1][1] = (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % MOD;
    
    A[0][0] = temp[0][0];
    A[0][1] = temp[0][1];
    A[1][0] = temp[1][0];
    A[1][1] = temp[1][1];
}

long long fibonacci_rapido(long long n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    long long resultado[2][2] = {{1, 0}, {0, 1}};  // Matriz identidad
    long long base[2][2] = {{1, 1}, {1, 0}};       // Matriz de Fibonacci
    
    // Exponenciación binaria: si n=13 (binario 1101), calculamos base^8 * base^4 * base^1
    n--;
    while (n > 0) {
        if (n & 1) {  // Si el bit actual es 1
            multiplicar_matrices(resultado, base);
        }
        multiplicar_matrices(base, base);  // base = base^2
        n >>= 1;  // Siguiente bit
    }
    
    return resultado[0][0];
}

// ========== PRINCIPIO DE INCLUSIÓN-EXCLUSIÓN ==========

// Cuenta elementos que cumplen AL MENOS una de varias propiedades
// Piensa en un diagrama de Venn con 3 círculos A, B, C:
// |A∪B∪C| = |A| + |B| + |C| - |A∩B| - |B∩C| - |A∩C| + |A∩B∩C|
// 
// ¿Por qué los signos? Sumamos individuales, restamos intersecciones dobles
// (porque las contamos 2 veces), y sumamos la triple (porque la restamos 3 veces)
// 
// Ejemplo práctico: ¿Cuántos números del 1 al 100 son divisibles por 2, 3 o 5?
long long inclusion_exclusion_3(long long n, long long a, long long b, long long c) {
    long long gcd_ab = __gcd(a, b);
    long long gcd_bc = __gcd(b, c);
    long long gcd_ac = __gcd(a, c);
    long long lcm_ab = (a / gcd_ab) * b;  // LCM = a*b / GCD(a,b)
    long long lcm_bc = (b / gcd_bc) * c;
    long long lcm_ac = (a / gcd_ac) * c;
    
    long long gcd_abc = __gcd(gcd_ab, c);
    long long lcm_abc = (lcm_ab / __gcd(lcm_ab, c)) * c;
    
    // Fórmula de inclusión-exclusión
    return (n/a) + (n/b) + (n/c) - (n/lcm_ab) - (n/lcm_bc) - (n/lcm_ac) + (n/lcm_abc);
}

// ========== DERANGEMENTS (Desarreglos) ==========

// Número de permutaciones donde NINGÚN elemento está en su posición original
// Imagina: tienes n cartas numeradas y n sobres numerados. ¿De cuántas formas
// puedes meter las cartas en sobres de modo que NINGUNA carta esté en su sobre?
// 
// Ejemplo con 3 cartas {1,2,3}:
//   Válido: {2,3,1} y {3,1,2}  -> D(3) = 2
//   Inválido: {1,3,2} (el 1 está en su lugar), {2,1,3} (el 3 está en su lugar)
// 
// Fórmula recursiva: D(n) = (n-1) * [D(n-1) + D(n-2)]
// Intuición: el elemento n puede ir a cualquiera de n-1 posiciones.
// Si va a la posición i, o intercambiamos n con i (D(n-2) casos),
// o no (D(n-1) casos donde i debe ir a otra parte)
long long derangements(int n) {
    if (n == 0) return 1;  // Una forma de desordenar nada
    if (n == 1) return 0;  // Imposible desordenar 1 elemento
    if (n == 2) return 1;  // Solo {2,1}
    
    long long d[n + 1];
    d[0] = 1;
    d[1] = 0;
    d[2] = 1;
    
    for (int i = 3; i <= n; i++) {
        d[i] = (i - 1) * (d[i-1] + d[i-2]);
    }
    
    return d[n];
}

int main() {
    cout << "=== COMBINATORIA Y MATEMÁTICAS DISCRETAS ===" << endl;
    
    // Factoriales
    cout << "\n--- Factoriales ---" << endl;
    for (int i = 0; i <= 10; i++) {
        cout << i << "! = " << factorial_iterativo(i) << endl;
    }
    
    // Permutaciones
    cout << "\n--- Permutaciones P(n, r) ---" << endl;
    cout << "P(5, 2) = " << permutaciones(5, 2) << " (5*4 = 20)" << endl;
    cout << "P(6, 3) = " << permutaciones(6, 3) << " (6*5*4 = 120)" << endl;
    
    // Permutaciones con repetición
    cout << "\n--- Permutaciones con repetición ---" << endl;
    // Palabra "MISSISSIPPI" tiene 11 letras: M(1), I(4), S(4), P(2)
    int reps[] = {1, 4, 4, 2};
    cout << "Permutaciones de MISSISSIPPI: " 
         << permutaciones_con_repeticion(11, reps, 4) << endl;
    
    // Combinaciones
    cout << "\n--- Combinaciones C(n, r) ---" << endl;
    cout << "C(5, 2) = " << combinaciones(5, 2) << " (10 formas)" << endl;
    cout << "C(10, 3) = " << combinaciones(10, 3) << " (120 formas)" << endl;
    cout << "C(52, 5) = " << combinaciones(52, 5) << " (manos de poker)" << endl;
    
    // Triángulo de Pascal
    cout << "\n--- Triángulo de Pascal (primeras 7 filas) ---" << endl;
    precalcular_pascal(10);
    for (int n = 0; n <= 6; n++) {
        for (int r = 0; r <= n; r++) {
            cout << C[n][r] << " ";
        }
        cout << endl;
    }
    
    // Números de Catalan
    cout << "\n--- Números de Catalan ---" << endl;
    for (int i = 0; i <= 10; i++) {
        cout << "Cat(" << i << ") = " << catalan_dp(i) << endl;
    }
    
    // Fibonacci
    cout << "\n--- Números de Fibonacci ---" << endl;
    precalcular_fibonacci(20);
    for (int i = 0; i <= 15; i++) {
        cout << "Fib(" << i << ") = " << fib[i] << endl;
    }
    
    cout << "\nFibonacci(100) con método rápido: " << fibonacci_rapido(100) << endl;
    
    // Derangements
    cout << "\n--- Derangements (Desarreglos) ---" << endl;
    for (int i = 0; i <= 10; i++) {
        cout << "D(" << i << ") = " << derangements(i) << endl;
    }
    
    // Principio de Inclusión-Exclusión
    cout << "\n--- Principio de Inclusión-Exclusión ---" << endl;
    long long n = 100;
    long long divisibles = inclusion_exclusion_3(n, 2, 3, 5);
    cout << "Números del 1 al " << n << " divisibles por 2, 3 o 5: " 
         << divisibles << endl;
    
    return 0;
}