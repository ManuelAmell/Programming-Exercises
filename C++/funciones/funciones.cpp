    #include <iostream>
    using namespace std;

    // Prototipos de funciones
    void saludar();
    int sumar(int a, int b);
    float dividir(float a, float b);

    int main() {
        saludar();

        int x = 5, y = 10;
        cout << "La suma de " << x << " y " << y << " es: " << sumar(x, y) << endl;

        float num1 = 10.0, num2 = 2.0;
        cout << "La división de " << num1 << " entre " << num2 << " es: " << dividir(num1, num2) << endl;

        return 0;
    }

    // Definición de funciones
    void saludar() {
        cout << "¡Hola! Bienvenido a la calculadora." << endl;
    }

    int sumar(int a, int b) {
        return a + b;
    }

    float dividir(float a, float b) {
        if (b != 0) {
            return a / b;
        } else {
            cerr << "Error: División por cero no permitida." << endl;
            return 0;
        }
    }
