/**
 * ╔══════════════════════════════════════════════════════════════════════════════╗
 * ║                      POO EN JAVA - CLASES Y OBJETOS                          ║
 * ╚══════════════════════════════════════════════════════════════════════════════╝
 * 
 * EXPLICACIÓN AL ESTILO FEYNMAN:
 * 
 * Imagina que quieres construir casas. No puedes simplemente decir "quiero una casa"
 * y que aparezca. Necesitas:
 * 
 * 1. UN PLANO (La CLASE): Es el diseño, la plantilla, el modelo que dice cómo debe
 *    ser la casa. Define QUÉ características tiene (puertas, ventanas, color) y
 *    QUÉ puede hacer (abrir puerta, encender luz).
 * 
 * 2. LA CASA CONSTRUIDA (El OBJETO): Es la casa REAL que construyes siguiendo el plano.
 *    Cada casa construida es INDEPENDIENTE de las demás.
 * 
 * En programación:
 * - La CLASE es el plano (código que defines UNA vez)
 * - El OBJETO es la instancia real (datos en memoria que creas MUCHAS veces)
 * 
 * Ejemplo del mundo real:
 * - CLASE: El concepto de "Perro"
 * - OBJETOS: "Fido", "Rex", "Luna" (perros específicos con sus propias características)
 * 
 * ================================================================================
 *                          PARTES DE UNA CLASE
 * ================================================================================
 * 
 * 1. ATRIBUTOS (Variables de instancia): Son las características/características de los objetos.
 *    Cada objeto tiene sus propios valores para estos atributos.
 * 
 * 2. MÉTODOS (Funciones): Son las acciones que pueden realizar los objetos.
 *    Son comportamientos definidos en la clase.
 * 
 * 3. CONSTRUCTOR: Método especial que se ejecuta automáticamente cuando creamos un objeto.
 *    Su trabajo es inicializar los atributos con valores válidos.
 * 
 * ================================================================================
 *                          MEMORIA EN JAVA
 * ================================================================================
 * 
 * Cuando creas un objeto con "new", Java reserva memoria en el HEAP.
 * La variable que guardas es una REFERENCIA (dirección de memoria), no el objeto mismo.
 * 
 * Ejemplo:
 *   Perro miPerro = new Perro();  // "miPerro" guarda la DIRECCIÓN donde está el objeto
 * 
 * Si haces:
 *   Perro otroPerro = miPerro;   // Ambas apuntan al MISMO objeto en memoria
 * 
 * El objeto real está en el HEAP, y las variables son punteros/referencias a él.
 */

// ============================================================================
// DECLARACIÓN DE LA CLASE
// ============================================================================
// 'public' significa que cualquier otra clase puede usar esta clase
// 'class' es la palabra clave para definir una clase
// El nombre debe empezar con mayúscula (convención CamelCase)

public class ClasesYObjetos {
    
    // ═══════════════════════════════════════════════════════════════════════
    // ATRIBUTOS (Variables de instancia)
    // ═══════════════════════════════════════════════════════════════════════
    // Son las características que tendrá cada objeto creado
    // Cada objeto tendrá su propia copia de estos valores
    // 'private' significa que solo se puede acceder desde dentro de la clase
    
    private String nombre;      // Nombre del objeto
    private int edad;           // Edad en años
    private double peso;        // Peso en kilogramos
    private boolean estaVivo;   // Estado de vida
    
    // ═══════════════════════════════════════════════════════════════════════
    // CONSTRUCTOR
    // ═══════════════════════════════════════════════════════════════════════
    // Es un método especial que tiene el MISMO nombre que la clase
    // NO tiene tipo de retorno (ni siquiera void)
    // Se ejecuta automáticamente cuando usas 'new'
    // Sirve para inicializar los atributos con valores válidos
    
    public ClasesYObjetos(String nombre, int edad, double peso) {
        // 'this' se refiere al objeto actual que se está creando
        // Usamos 'this' para distinguir entre el parámetro y el atributo
        this.nombre = nombre;   // El atributo 'nombre' recibe el valor del parámetro 'nombre'
        this.edad = edad;       // El atributo 'edad' recibe el valor del parámetro 'edad'
        this.peso = peso;       // El atributo 'peso' recibe el valor del parámetro 'peso'
        this.estaVivo = true;   // Por defecto, el objeto está vivo
    }
    
    // ═══════════════════════════════════════════════════════════════════════
    // CONSTRUCTOR VACÍO (Default constructor)
    // ═══════════════════════════════════════════════════════════════════════
    // Si no escribes ningún constructor, Java crea uno automáticamente (vacío)
    // Pero si escribes un constructor con parámetros, Java YA NO crea el vacío
    // Por eso debes escribirlo manualmente si lo necesitas
    
    public ClasesYObjetos() {
        // Constructor sin parámetros - valores por defecto
        this.nombre = "Sin nombre";
        this.edad = 0;
        this.peso = 0.0;
        this.estaVivo = true;
    }
    
    // ═══════════════════════════════════════════════════════════════════════
    // MÉTODOS (Comportamientos)
    // ═══════════════════════════════════════════════════════════════════════
    // Son las acciones que el objeto puede realizar
    // 'public' significa que pueden llamarse desde fuera de la clase
    // 'void' significa que no devuelve ningún valor
    
    /**
     * Muestra información del objeto
     * Como pedirle a alguien "cuéntame sobre ti"
     */
    public void mostrarInfo() {
        System.out.println("╔════════════════════════════════════╗");
        System.out.println("║      INFORMACIÓN DEL OBJETO       ║");
        System.out.println("╚════════════════════════════════════╝");
        System.out.println("📛 Nombre: " + this.nombre);
        System.out.println("🎂 Edad: " + this.edad + " años");
        System.out.println("⚖️  Peso: " + this.peso + " kg");
        System.out.println("💓 Estado: " + (this.estaVivo ? "Vivo" : "Muerto"));
        System.out.println();
    }
    
    /**
     * El objeto "cumple años"
     * Modifica el estado interno del objeto
     */
    public void cumplirAnios() {
        this.edad++;  // Incrementa la edad en 1
        System.out.println("🎉 " + this.nombre + " ahora tiene " + this.edad + " años!");
    }
    
    /**
     * Cambia el peso del objeto
     * Los métodos pueden recibir parámetros (datos de entrada)
     */
    public void cambiarPeso(double nuevoPeso) {
        if (nuevoPeso > 0) {
            this.peso = nuevoPeso;
            System.out.println("✅ Peso actualizado a: " + this.peso + " kg");
        } else {
            System.out.println("❌ Error: El peso debe ser positivo");
        }
    }
    
    // ═══════════════════════════════════════════════════════════════════════
    // GETTERS Y SETTERS (Métodos de acceso)
    // ═══════════════════════════════════════════════════════════════════════
    // Getter: Obtiene el valor de un atributo (lectura)
    // Setter: Modifica el valor de un atributo (escritura)
    // Son necesarios cuando los atributos son private
    
    public String getNombre() {
        return this.nombre;  // Devuelve el valor del atributo
    }
    
    public void setNombre(String nombre) {
        this.nombre = nombre;  // Modifica el atributo
    }
    
    public int getEdad() {
        return this.edad;
    }
    
    public double getPeso() {
        return this.peso;
    }
    
    // ═══════════════════════════════════════════════════════════════════════
    // MÉTODO MAIN - Punto de entrada del programa
    // ═══════════════════════════════════════════════════════════════════════
    public static void main(String[] args) {
        System.out.println("╔══════════════════════════════════════════════════════════════╗");
        System.out.println("║           DEMOSTRACIÓN: CLASES Y OBJETOS                     ║");
        System.out.println("╚══════════════════════════════════════════════════════════════╝\n");
        
        // ═══════════════════════════════════════════════════════════════════
        // CREAR OBJETOS (Instanciación)
        // ═══════════════════════════════════════════════════════════════════
        // Usamos 'new' para crear un nuevo objeto en memoria
        // El constructor se ejecuta automáticamente
        
        System.out.println("=== CREANDO OBJETOS ===\n");
        
        // Objeto 1: Usando constructor con parámetros
        ClasesYObjetos objeto1 = new ClasesYObjetos("Juan", 25, 70.5);
        System.out.println("✅ Objeto1 creado: " + objeto1.getNombre());
        
        // Objeto 2: Otro objeto con diferentes valores
        ClasesYObjetos objeto2 = new ClasesYObjetos("Maria", 30, 55.0);
        System.out.println("✅ Objeto2 creado: " + objeto2.getNombre());
        
        // Objeto 3: Usando constructor vacío
        ClasesYObjetos objeto3 = new ClasesYObjetos();
        System.out.println("✅ Objeto3 creado con valores por defecto\n");
        
        // ═══════════════════════════════════════════════════════════════════
        // USAR LOS OBJETOS (Llamar métodos)
        // ═══════════════════════════════════════════════════════════════════
        
        System.out.println("=== USANDO LOS OBJETOS ===\n");
        
        // Mostrar información de cada objeto
        objeto1.mostrarInfo();  // Muestra los datos de Juan
        objeto2.mostrarInfo();  // Muestra los datos de Maria
        objeto3.mostrarInfo();    // Muestra los datos por defecto
        
        // Modificar objeto1
        System.out.println("\n=== MODIFICANDO OBJETO1 ===\n");
        objeto1.cumplirAnios();           // Juan cumple años
        objeto1.cambiarPeso(72.0);         // Cambiamos su peso
        objeto1.mostrarInfo();              // Vemos los cambios
        
        // ═══════════════════════════════════════════════════════════════════
        // DEMOSTRACIÓN: Objetos independientes
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("\n=== OBJETOS SON INDEPENDIENTES ===\n");
        System.out.println("Cambiamos el peso de objeto1...");
        objeto1.cambiarPeso(75.0);
        
        System.out.println("\n¿Afectó esto a objeto2?");
        System.out.println("Peso de objeto2: " + objeto2.getPeso() + " kg");
        System.out.println("❌ NO, cada objeto tiene sus propios datos independientes!\n");
        
        // ═══════════════════════════════════════════════════════════════════
        // DEMOSTRACIÓN: Referencias a objetos
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("=== DEMOSTRACIÓN DE REFERENCIAS ===\n");
        
        ClasesYObjetos referencia1 = new ClasesYObjetos("Carlos", 40, 80.0);
        ClasesYObjetos referencia2 = referencia1;  // ¡Ambas apuntan al mismo objeto!
        
        System.out.println("referencia1 y referencia2 apuntan al mismo objeto");
        System.out.println("Nombre desde referencia1: " + referencia1.getNombre());
        System.out.println("Nombre desde referencia2: " + referencia2.getNombre());
        
        System.out.println("\nCambiamos nombre usando referencia2...");
        referencia2.setNombre("Carlos Modificado");
        
        System.out.println("Nombre desde referencia1: " + referencia1.getNombre());
        System.out.println("✅ ¡Cambió también! Porque ambas referencias apuntan al mismo objeto\n");
        
        System.out.println("╔══════════════════════════════════════════════════════════════╗");
        System.out.println("║           FIN DE LA DEMOSTRACIÓN                            ║");
        System.out.println("╚══════════════════════════════════════════════════════════════╝");
    }
}

/**
 * RESUMEN AL ESTILO FEYNMAN:
 * 
 * 🔑 CONCEPTOS CLAVE:
 * 
 * 1. CLASE = Plano/Plantilla/Modelo
 *    - Define qué características tiene algo
 *    - Define qué acciones puede hacer
 *    - Solo se escribe UNA vez
 * 
 * 2. OBJETO = Instancia real en memoria
 *    - Se crea con 'new'
 *    - Ocupa espacio en memoria (HEAP)
 *    - Cada objeto es independiente
 * 
 * 3. ATRIBUTOS = Características
 *    - Son variables que pertenecen al objeto
 *    - Cada objeto tiene sus propios valores
 * 
 * 4. MÉTODOS = Acciones/Comportamientos
 *    - Son funciones que pertenecen al objeto
 *    - Pueden leer y modificar atributos
 * 
 * 5. CONSTRUCTOR = Inicializador
 *    - Se ejecuta automáticamente con 'new'
 *    - Pone valores iniciales a los atributos
 *    - Tiene el mismo nombre que la clase
 * 
 * 💡 ANÁLOGÍA FINAL:
 * 
 * Piensa en una fábrica de galletas:
 * - El MOLDE (cortador) es la CLASE: define la forma
 * - Cada GALLETA cortada es un OBJETO: tiene la forma del molde
 * - El SABOR y COLOR son ATRIBUTOS: cada galleta puede ser diferente
 * - COMER la galleta es un MÉTODO: es algo que puede hacer
 * - El cortar con el molde es el CONSTRUCTOR: crea la galleta con forma
 * 
 * El molde no es una galleta, solo define cómo hacer galletas.
 * Cada galleta es una instancia única, aunque todas vengan del mismo molde.
 */