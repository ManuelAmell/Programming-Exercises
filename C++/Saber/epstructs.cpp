#include <iostream>
#include <cstring> // Para strcpy(), strcmp()
using namespace std;

// ===========================================================
// 🔹 ESTRUCTURA BASE
// ===========================================================
struct Persona {
    int id;
    char nombre[30];
    int edad;
};

// ===========================================================
// 🔹 FUNCIONES DE OPERACIONES CON STRUCT
// ===========================================================

// 1️⃣ Crear y mostrar un struct básico
void ejemploBasico() {
    Persona p1;
    p1.id = 1;
    strcpy(p1.nombre, "Juan Perez");
    p1.edad = 25;

    cout << "\n[1] Estructura básica creada:\n";
    cout << "ID: " << p1.id << "\n";
    cout << "Nombre: " << p1.nombre << "\n";
    cout << "Edad: " << p1.edad << "\n";
}

// 2️⃣ Leer datos de una persona
void leerPersona(Persona &p) {
    cout << "\n[2] Ingresar datos de una persona\n";
    cout << "ID: ";
    cin >> p.id;
    cin.ignore();
    cout << "Nombre: ";
    cin.getline(p.nombre, 30);
    cout << "Edad: ";
    cin >> p.edad;
}

// 3️⃣ Mostrar persona
void mostrarPersona(const Persona &p) {
    cout << "--------------------------\n";
    cout << "ID: " << p.id << "\n";
    cout << "Nombre: " << p.nombre << "\n";
    cout << "Edad: " << p.edad << "\n";
    cout << "--------------------------\n";
}

// 4️⃣ Copiar structs
void copiarStruct() {
    Persona a = {1, "Carlos", 20};
    Persona b;
    b = a; // Copia directa

    cout << "\n[4] Copia de struct:\n";
    cout << "Persona A -> " << a.nombre << "\n";
    cout << "Persona B -> " << b.nombre << "\n";
}

// 5️⃣ Comparar structs
bool compararPersonas(const Persona &a, const Persona &b) {
    return (a.id == b.id && strcmp(a.nombre, b.nombre) == 0 && a.edad == b.edad);
}

// 6️⃣ Arreglo de structs
void ejemploArregloStructs() {
    Persona grupo[3] = {
        {1, "Ana", 19},
        {2, "Luis", 22},
        {3, "Maria", 20}
    };

    cout << "\n[6] Arreglo de structs:\n";
    for (int i = 0; i < 3; i++) {
        mostrarPersona(grupo[i]);
    }
}

// 7️⃣ Punteros a structs
void ejemploPunteros() {
    Persona p = {1, "Lucia", 21};
    Persona *ptr = &p;

    cout << "\n[7] Punteros a struct:\n";
    cout << "Acceso normal: " << p.nombre << "\n";
    cout << "Acceso con puntero -> " << ptr->nombre << "\n";
    cout << "Edad (puntero): " << ptr->edad << "\n";
}

// 8️⃣ Structs dinámicos (tamaño conocido en ejecución)
void ejemploDinamico() {
    int n;
    cout << "\n[8] ¿Cuántas personas desea registrar?: ";
    cin >> n;

    // Crear arreglo dinámico
    Persona* lista = new Persona[n];

    for (int i = 0; i < n; i++) {
        cout << "\nPersona #" << i + 1 << "\n";
        leerPersona(lista[i]);
    }

    cout << "\n📋 Personas registradas:\n";
    for (int i = 0; i < n; i++) {
        mostrarPersona(lista[i]);
    }

    delete[] lista; // 🔥 Importante: liberar memoria
}

// 9️⃣ Modificar un struct
void modificarPersona(Persona &p) {
    cout << "\n[9] Modificar persona (ID " << p.id << ")\n";
    cin.ignore();
    cout << "Nuevo nombre: ";
    cin.getline(p.nombre, 30);
    cout << "Nueva edad: ";
    cin >> p.edad;
}

// ===========================================================
// 🔹 MENÚ PRINCIPAL
// ===========================================================
int main() {
    Persona persona;
    Persona a = {1, "Pedro", 30};
    Persona b = {1, "Pedro", 30};

    int opcion;
    do {
        cout << "\n========== 🧠 CHULETA DE STRUCTS EN C++ ==========\n";
        cout << "1. Crear y mostrar un struct\n";
        cout << "2. Leer una persona\n";
        cout << "3. Mostrar persona actual\n";
        cout << "4. Copiar structs\n";
        cout << "5. Comparar structs\n";
        cout << "6. Arreglo de structs\n";
        cout << "7. Punteros a structs\n";
        cout << "8. Structs dinámicos (memoria dinámica)\n";
        cout << "9. Modificar persona\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                ejemploBasico();
                break;
            case 2:
                leerPersona(persona);
                break;
            case 3:
                mostrarPersona(persona);
                break;
            case 4:
                copiarStruct();
                break;
            case 5:
                cout << "\n[5] Comparación de structs: "
                     << (compararPersonas(a, b) ? "Son iguales" : "Son diferentes") << "\n";
                break;
            case 6:
                ejemploArregloStructs();
                break;
            case 7:
                ejemploPunteros();
                break;
            case 8:
                ejemploDinamico();
                break;
            case 9:
                modificarPersona(persona);
                break;
            case 0:
                cout << "\n✅ Saliendo del programa...\n";
                break;
            default:
                cout << "\n❌ Opción no válida\n";
        }
    } while (opcion != 0);

    return 0;
}
    