#include <iostream>
using namespace std;

/* ============================================================
   CÓDIGOS DE COLOR ANSI
   ============================================================ */
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"
#define BOLD    "\033[1m"

/* ============================================================
   FUNCIONES MATEMÁTICAS BÁSICAS
   ============================================================ */

// Raíz cuadrada aproximada (sin <cmath>), usando método de Newton
double raiz(double x) {
    if (x <= 0) return 0;
    double r = x;
    for (int i = 0; i < 10; ++i)
        r = 0.5 * (r + x / r);
    return r;
}

/* ============================================================
   OPERACIONES CON VECTORES
   ============================================================ */

// Producto punto entre dos vectores
double dot(double a[], double b[], int n) {
    double suma = 0.0;
    cout << CYAN << "\nCálculo del producto punto:\n" << RESET;
    for (int i = 0; i < n; ++i) {
        cout << "  " << a[i] << " * " << b[i] << " = "
             << GREEN << a[i]*b[i] << RESET << endl;
        suma += a[i] * b[i];
    }
    cout << YELLOW << "Suma total = " << suma << RESET << endl;
    return suma;
}

// Norma (longitud) de un vector
double norm(double a[], int n) {
    double suma = 0.0;
    cout << CYAN << "\nCálculo de la norma del vector:\n" << RESET;
    for (int i = 0; i < n; ++i) {
        cout << "  a[" << i << "]² = " << a[i]*a[i] << endl;
        suma += a[i] * a[i];
    }
    cout << YELLOW << "Suma de cuadrados = " << suma << RESET << endl;
    double resultado = raiz(suma);
    cout << GREEN << "Norma aproximada = " << resultado << RESET << endl;
    return resultado;
}

// Suma de vectores: c = a + b
void sumaVectores(double a[], double b[], double c[], int n) {
    cout << CYAN << "\nSuma de vectores:\n" << RESET;
    for (int i = 0; i < n; ++i) {
        c[i] = a[i] + b[i];
        cout << "  c[" << i << "] = " << a[i] << " + " << b[i]
             << " = " << GREEN << c[i] << RESET << endl;
    }
}

// Imprimir vector
void printVector(double a[], int n) {
    cout << "[ ";
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << "]\n";
}

/* ============================================================
   OPERACIONES CON MATRICES
   ============================================================ */

// Multiplicación de matrices cuadradas
void multiply(double A[][10], double B[][10], double C[][10], int n) {
    cout << CYAN << "\nMultiplicación de matrices:\n" << RESET;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            C[i][j] = 0;
            cout << "C[" << i << "][" << j << "] = ";
            for (int k = 0; k < n; ++k) {
                double mult = A[i][k] * B[k][j];
                C[i][j] += mult;
                cout << "(" << A[i][k] << "*" << B[k][j] << ")";
                if (k < n - 1) cout << " + ";
            }
            cout << " = " << GREEN << C[i][j] << RESET << endl;
        }
}

// Multiplicación matriz × vector
void matVec(double A[][10], double x[], double y[], int n) {
    cout << CYAN << "\nMultiplicación matriz × vector:\n" << RESET;
    for (int i = 0; i < n; ++i) {
        y[i] = 0;
        cout << "y[" << i << "] = ";
        for (int j = 0; j < n; ++j) {
            double mult = A[i][j] * x[j];
            y[i] += mult;
            cout << "(" << A[i][j] << "*" << x[j] << ")";
            if (j < n - 1) cout << " + ";
        }
        cout << " = " << GREEN << y[i] << RESET << endl;
    }
}

// Imprimir matriz
void printMatrix(double M[][10], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << M[i][j] << " ";
        cout << endl;
    }
}

/* ============================================================
   ELIMINACIÓN DE GAUSS PARA Ax = b
   ============================================================ */
void gauss(double A[][10], double b[], double x[], int n) {
    cout << CYAN << "\n=== Eliminación de Gauss ===\n" << RESET;

    // Eliminación hacia adelante
    for (int i = 0; i < n - 1; ++i) {
        cout << MAGENTA << "\nPivote en fila " << i
             << " (A[" << i << "][" << i << "]=" << A[i][i] << ")\n" << RESET;
        for (int k = i + 1; k < n; ++k) {
            double factor = A[k][i] / A[i][i];
            cout << YELLOW << "  Factor para fila " << k << " = "
                 << factor << RESET << endl;
            for (int j = i; j < n; ++j) {
                cout << "    A[" << k << "][" << j << "] = " << A[k][j];
                A[k][j] -= factor * A[i][j];
                cout << " - " << factor << "*" << A[i][j]
                     << " = " << GREEN << A[k][j] << RESET << endl;
            }
            b[k] -= factor * b[i];
            cout << "    b[" << k << "] actualizado a "
                 << GREEN << b[k] << RESET << endl;
        }
    }

    // Sustitución hacia atrás
    for (int i = n - 1; i >= 0; --i) {
        double suma = 0.0;
        for (int j = i + 1; j < n; ++j)
            suma += A[i][j] * x[j];
        x[i] = (b[i] - suma) / A[i][i];
        cout << MAGENTA << "\nx[" << i << "] = (" << b[i] << " - " << suma
             << ") / " << A[i][i] << " = " << GREEN << x[i] << RESET << endl;
    }
}

/* ============================================================
   MENÚ PRINCIPAL
   ============================================================ */
int main() {
    int opcion;

    do {
        cout << BOLD << BLUE << "\n===== MENU DE ALGEBRA LINEAL (C++ PURO) =====\n" << RESET;
        cout << YELLOW
             << "1. Producto punto entre vectores\n"
             << "2. Norma de un vector\n"
             << "3. Suma de vectores\n"
             << "4. Multiplicacion de matrices cuadradas\n"
             << "5. Multiplicacion matriz × vector\n"
             << "6. Resolver sistema Ax = b (Eliminacion de Gauss)\n"
             << "0. Salir\n" << RESET;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            int n;
            cout << "Tamaño del vector: ";
            cin >> n;
            double a[10], b[10];
            cout << "Ingrese vector A:\n";
            for (int i = 0; i < n; ++i) cin >> a[i];
            cout << "Ingrese vector B:\n";
            for (int i = 0; i < n; ++i) cin >> b[i];
            double resultado = dot(a, b, n);
            cout << BOLD << GREEN << "\nProducto punto final = " << resultado << RESET << endl;

        } else if (opcion == 2) {
            int n;
            cout << "Tamaño del vector: ";
            cin >> n;
            double a[10];
            cout << "Ingrese el vector:\n";
            for (int i = 0; i < n; ++i) cin >> a[i];
            double resultado = norm(a, n);
            cout << BOLD << GREEN << "\nNorma final = " << resultado << RESET << endl;

        } else if (opcion == 3) {
            int n;
            cout << "Tamaño del vector: ";
            cin >> n;
            double a[10], b[10], c[10];
            cout << "Ingrese vector A:\n";
            for (int i = 0; i < n; ++i) cin >> a[i];
            cout << "Ingrese vector B:\n";
            for (int i = 0; i < n; ++i) cin >> b[i];
            sumaVectores(a, b, c, n);
            cout << BOLD << GREEN << "Vector resultante A + B = ";
            printVector(c, n);
            cout << RESET;

        } else if (opcion == 4) {
            int n;
            cout << "Dimension de las matrices cuadradas (max 10): ";
            cin >> n;
            double A[10][10], B[10][10], C[10][10];
            cout << "Ingrese matriz A:\n";
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    cin >> A[i][j];
            cout << "Ingrese matriz B:\n";
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    cin >> B[i][j];
            multiply(A, B, C, n);
            cout << BOLD << GREEN << "\nMatriz resultado A * B =\n";
            printMatrix(C, n);
            cout << RESET;

        } else if (opcion == 5) {
            int n;
            cout << "Dimension de la matriz cuadrada (max 10): ";
            cin >> n;
            double A[10][10], x[10], y[10];
            cout << "Ingrese matriz A:\n";
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    cin >> A[i][j];
            cout << "Ingrese vector x:\n";
            for (int i = 0; i < n; ++i)
                cin >> x[i];
            matVec(A, x, y, n);
            cout << BOLD << GREEN << "\nResultado A * x = ";
            printVector(y, n);
            cout << RESET;

        } else if (opcion == 6) {
            int n;
            cout << "Dimension del sistema (n x n, max 10): ";
            cin >> n;
            double A[10][10], b[10], x[10];
            cout << "Ingrese matriz A:\n";
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    cin >> A[i][j];
            cout << "Ingrese vector b:\n";
            for (int i = 0; i < n; ++i)
                cin >> b[i];
            gauss(A, b, x, n);
            cout << BOLD << GREEN << "\nSolución final x = ";
            printVector(x, n);
            cout << RESET;
        }

    } while (opcion != 0);

    cout << BOLD << BLUE << "\nFin del programa.\n" << RESET;
    return 0;
}
