#include <iostream>
#include <cstring> // Para strcpy(), strcmp()
using namespace std;

// ===========================================================
// 🔹 DEFINICIÓN DE UN STRUCT
// ===========================================================
// Un struct (estructura) agrupa varios datos de distinto tipo bajo un solo nombre.
struct Persona {
    int id;
    char nombre[30];
    int edad;
};

// ===========================================================
// 🔹 1. CREAR Y ASIGNAR DATOS A UN STRUCT
// ===========================================================
void ejemploBasico() {
    Persona p1; // Se crea una variable del tipo struct Persona

    // Asignar valores directamente
    p1.id = 1;
    strcpy(p1.nombre, "Juan Perez"); // strcpy se usa con char[], no con string
    p1.edad = 25;

    cout << "\n[1] Estructura básica creada:\n";
    cout << "ID: " << p1.id << "\n";
    cout << "Nombre: " << p1.nombre << "\n";
    cout << "Edad: " << p1.edad << "\n";
}

// ===========================================================
// 🔹 2. LEER DATOS DESDE EL USUARIO
// ===========================================================
void leerPersona(Persona &p) {
    cout << "\n[2] Ingresar datos de una persona\n";
    cout << "ID: ";
    cin >> p.id;
    cin.ignore(); // Limpiar buffer para evitar problemas con getline
    cout << "Nombre: ";
    cin.getline(p.nombre, 30);
    cout << "Edad: ";
    cin >> p.edad;
}

// ===========================================================
// 🔹 3. MOSTRAR DATOS (POR REFERENCIA)
// ===========================================================
void mostrarPersona(const Persona &p) {
    cout << "--------------------------\n";
    cout << "ID: " << p.id << "\n";
    cout << "Nombre: " << p.nombre << "\n";
    cout << "Edad: " << p.edad << "\n";
    cout << "--------------------------\n";
}

// ===========================================================
// 🔹 4. COPIAR UN STRUCT
// ===========================================================
void copiarStruct() {
    Persona a = {1, "Carlos", 20};
    Persona b;

    // Copiar campo por campo o directamente con "="
    b = a;

    cout << "\n[4] Copia de struct:\n";
    cout << "Persona A -> " << a.nombre << "\n";
    cout << "Persona B -> " << b.nombre << "\n";
}

// ===========================================================
// 🔹 5. COMPARAR DOS STRUCTS
// ===========================================================
// Nota: No se puede usar "==" directamente si tiene cadenas char[]
bool compararPersonas(const Persona &a, const Persona &b) {
    return (a.id == b.id && strcmp(a.nombre, b.nombre) == 0 && a.edad == b.edad);
}

// ===========================================================
// 🔹 6. ARREGLOS DE STRUCTS
// ===========================================================
void ejemploArregloStructs() {
    Persona grupo[3]; // Arreglo estático (tamaño fijo)

    // Llenar datos manualmente
    grupo[0] = {1, "Ana", 19};
    grupo[1] = {2, "Luis", 22};
    grupo[2] = {3, "Maria", 20};

    cout << "\n[6] Arreglo de structs:\n";
    for (int i = 0; i < 3; i++) {
        mostrarPersona(grupo[i]);
    }
}

// ===========================================================
// 🔹 7. USAR PUNTEROS A STRUCTS
// ===========================================================
void ejemploPunteros() {
    Persona p = {1, "Lucia", 21};
    Persona *ptr = &p; // Puntero que apunta al struct

    cout << "\n[7] Punteros a struct:\n";
    cout << "Acceso normal: " << p.nombre << "\n";
    cout << "Acceso con puntero -> " << ptr->nombre << "\n";
    cout << "Edad (puntero): " << ptr->edad << "\n";
}

// ===========================================================
// 🔹 8. MEMORIA DINÁMICA (STRUCTS EN TIEMPO DE EJECUCIÓN)
// ===========================================================
void ejemploDinamico() {
    int n;
    cout << "\n[8] ¿Cuántas personas desea registrar?: ";
    cin >> n;

    // Crear arreglo dinámico de structs
    Persona* lista = new Persona[n];

    // Llenar datos
    for (int i = 0; i < n; i++) {
        cout << "\nPersona #" << i + 1 << "\n";
        leerPersona(lista[i]);
    }

    // Mostrar datos
    cout << "\nPersonas registradas:\n";
    for (int i = 0; i < n; i++) {
        mostrarPersona(lista[i]);
    }

    // Liberar memoria
    delete[] lista;
}

// ===========================================================
// 🔹 9. MODIFICAR UN STRUCT (por ID o posición)
// ===========================================================
void modificarPersona(Persona &p) {
    cout << "\n[9] Modificar persona (ID " << p.id << ")\n";
    cout << "Nuevo nombre: ";
    cin.ignore();
    cin.getline(p.nombre, 30);
    cout << "Nueva edad: ";
    cin >> p.edad;
}

// ===========================================================
// 🔹 PROGRAMA PRINCIPAL
// ===========================================================
int main() {
    cout << "========== CHULETA DE STRUCTS EN C++ ==========\n";

    // 1️⃣ Crear y asignar valores
    ejemploBasico();

    // 2️⃣ Leer datos de una persona
    Persona personaLeida;
    leerPersona(personaLeida);
    mostrarPersona(personaLeida);

    // 3️⃣ Copiar structs
    copiarStruct();

    // 4️⃣ Comparar structs
    Persona a = {1, "Pedro", 30};
    Persona b = {1, "Pedro", 30};
    cout << "\n[5] Comparación de structs: "
         << (compararPersonas(a, b) ? "Son iguales" : "Son diferentes") << "\n";

    // 5️⃣ Arreglo de structs
    ejemploArregloStructs();

    // 6️⃣ Punteros a structs
    ejemploPunteros();

    // 7️⃣ Structs dinámicos
    ejemploDinamico();

    // 8️⃣ Modificar un struct
    modificarPersona(personaLeida);
    mostrarPersona(personaLeida);

    cout << "\n✅ Fin de la demostración de operaciones con structs\n";
    return 0;
}
