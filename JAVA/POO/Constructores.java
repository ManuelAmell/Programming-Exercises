/**
 * ╔══════════════════════════════════════════════════════════════════════════════╗
 * ║                         POO EN JAVA - CONSTRUCTORES                          ║
 * ╚══════════════════════════════════════════════════════════════════════════════╝
 * 
 * EXPLICACIÓN AL ESTILO FEYNMAN:
 * 
 * Imagina que compras un mueble de IKEA. Cuando lo sacas de la caja, viene en
 * piezas sueltas. Necesitas armarlo, poner los tornillos, ajustar las partes.
 * 
 * En programación, cuando creas un objeto con "new", es como sacarlo de la caja.
 * El CONSTRUCTOR es el manual de instrucciones que se ejecuta automáticamente
 * para "armar" el objeto correctamente.
 * 
 * SIN CONSTRUCTOR: El objeto se crea vacío, sin valores iniciales
 * CON CONSTRUCTOR: El objeto se crea con valores válidos y listo para usar
 * 
 * ================================================================================
 *                    TIPOS DE CONSTRUCTORES
 * ================================================================================
 * 
 * 1. CONSTRUCTOR POR DEFECTO (Default Constructor)
 *    - Java lo crea automáticamente si NO escribes ningún constructor
 *    - No tiene parámetros
 *    - Inicializa atributos con valores por defecto (0, null, false)
 *    - Si escribes un constructor, Java YA NO crea este
 * 
 * 2. CONSTRUCTOR CON PARÁMETROS (Parameterized Constructor)
 *    - Recibe valores para inicializar los atributos
 *    - Permite crear objetos con datos específicos desde el inicio
 *    - Puedes tener MÚLTIPLES constructores con diferentes parámetros
 * 
 * 3. CONSTRUCTOR COPIA (Copy Constructor) - Opcional
 *    - Recibe otro objeto del mismo tipo y copia sus valores
 *    - Crea un nuevo objeto idéntico pero independiente
 * 
 * ================================================================================
 *                    SOBRECARGA DE CONSTRUCTORES
 * ================================================================================
 * 
 * Puedes tener MUCHOS constructores en la misma clase, siempre que sean DIFERENTES:
 * - Diferente número de parámetros
 * - Diferente tipo de parámetros
 * - Diferente orden de parámetros
 * 
 * Java decide cuál constructor usar según los argumentos que le pases.
 * 
 * Esto se llama SOBRECARGA (Overloading): mismo nombre, diferentes parámetros.
 */

public class Constructores {
    
    // ═══════════════════════════════════════════════════════════════════════
    // ATRIBUTOS DE LA CLASE
    // ═══════════════════════════════════════════════════════════════════════
    private String marca;
    private String modelo;
    private int anio;
    private double precio;
    private String color;
    private boolean esElectrico;
    
    // ═══════════════════════════════════════════════════════════════════════
    // 1. CONSTRUCTOR POR DEFECTO (Sin parámetros)
    // ═══════════════════════════════════════════════════════════════════════
    // Se llama cuando creas objeto sin argumentos: new Constructores()
    // Inicializa con valores "por defecto" razonables
    
    public Constructores() {
        // Valores por defecto cuando no se especifica nada
        this.marca = "Desconocida";
        this.modelo = "Estándar";
        this.anio = 2024;
        this.precio = 0.0;
        this.color = "Blanco";
        this.esElectrico = false;
        
        System.out.println("🏗️  Constructor por defecto ejecutado");
    }
    
    // ═══════════════════════════════════════════════════════════════════════
    // 2. CONSTRUCTOR CON PARÁMETROS BÁSICOS
    // ═══════════════════════════════════════════════════════════════════════
    // Recibe los valores mínimos necesarios
    // 'this' diferencia entre parámetros y atributos
    
    public Constructores(String marca, String modelo) {
        this.marca = marca;      // this.marca (atributo) = marca (parámetro)
        this.modelo = modelo;    // this.modelo (atributo) = modelo (parámetro)
        
        // Valores por defecto para el resto
        this.anio = 2024;
        this.precio = 0.0;
        this.color = "Blanco";
        this.esElectrico = false;
        
        System.out.println("🏗️  Constructor con 2 parámetros ejecutado");
    }
    
    // ═══════════════════════════════════════════════════════════════════════
    // 3. CONSTRUCTOR CON MÁS PARÁMETROS (Sobrecarga)
    // ═══════════════════════════════════════════════════════════════════════
    // Mismo nombre, diferente número de parámetros
    // Java elige el constructor según cuántos argumentos pasas
    
    public Constructores(String marca, String modelo, int anio) {
        this.marca = marca;
        this.modelo = modelo;
        this.anio = anio;
        this.precio = 0.0;
        this.color = "Blanco";
        this.esElectrico = false;
        
        System.out.println("🏗️  Constructor con 3 parámetros ejecutado");
    }
    
    // ═══════════════════════════════════════════════════════════════════════
    // 4. CONSTRUCTOR COMPLETO (Todos los atributos)
    // ═══════════════════════════════════════════════════════════════════════
    // Permite inicializar TODOS los atributos desde el inicio
    // Ideal cuando tienes todos los datos disponibles
    
    public Constructores(String marca, String modelo, int anio, 
                       double precio, String color, boolean esElectrico) {
        this.marca = marca;
        this.modelo = modelo;
        this.anio = anio;
        this.precio = precio;
        this.color = color;
        this.esElectrico = esElectrico;
        
        System.out.println("🏗️  Constructor COMPLETO ejecutado");
    }
    
    // ═══════════════════════════════════════════════════════════════════════
    // 5. CONSTRUCTOR COPIA (Copy Constructor)
    // ═══════════════════════════════════════════════════════════════════════
    // Recibe OTRO objeto del mismo tipo
    // Copia todos los valores del objeto recibido
    // Crea un CLONE independiente (no referencia al mismo objeto)
    
    public Constructores(Constructores otro) {
        // Copiamos todos los valores del otro objeto
        this.marca = otro.marca;
        this.modelo = otro.modelo;
        this.anio = otro.anio;
        this.precio = otro.precio;
        this.color = otro.color;
        this.esElectrico = otro.esElectrico;
        
        System.out.println("🏗️  Constructor COPIA ejecutado");
    }
    
    // ═══════════════════════════════════════════════════════════════════════
    // 6. USANDO 'this()' - LLAMAR OTRO CONSTRUCTOR
    // ═══════════════════════════════════════════════════════════════════════
    // Puedes llamar a otro constructor de la misma clase con this()
    // Debe ser la PRIMERA línea del constructor
    // Evita repetir código
    
    public Constructores(String marca) {
        // Llama al constructor que recibe marca y modelo
        // Le pasamos la marca recibida y "Genérico" como modelo
        this(marca, "Genérico");  // this() debe ser la primera línea
        
        System.out.println("🏗️  Constructor con 1 parámetro (llamó al de 2)");
    }
    
    // ═══════════════════════════════════════════════════════════════════════
    // MÉTODOS PARA MOSTRAR INFORMACIÓN
    // ═══════════════════════════════════════════════════════════════════════
    public void mostrarInfo() {
        System.out.println("╔════════════════════════════════════╗");
        System.out.println("║  INFORMACIÓN DEL OBJETO            ║");
        System.out.println("╠════════════════════════════════════╣");
        System.out.println("  🏷️  Marca: " + this.marca);
        System.out.println("  🚗 Modelo: " + this.modelo);
        System.out.println("  📅 Año: " + this.anio);
        System.out.println("  💰 Precio: $" + this.precio);
        System.out.println("  🎨 Color: " + this.color);
        System.out.println("  ⚡ Eléctrico: " + (this.esElectrico ? "Sí" : "No"));
        System.out.println("╚════════════════════════════════════╝\n");
    }
    
    // Getters
    public String getMarca() { return marca; }
    public String getModelo() { return modelo; }
    public int getAnio() { return anio; }
    
    // ═══════════════════════════════════════════════════════════════════════
    // MÉTODO MAIN - Demostración
    // ═══════════════════════════════════════════════════════════════════════
    public static void main(String[] args) {
        System.out.println("╔══════════════════════════════════════════════════════════════╗");
        System.out.println("║              DEMOSTRACIÓN: CONSTRUCTORES                     ║");
        System.out.println("╚══════════════════════════════════════════════════════════════╝\n");
        
        // ═══════════════════════════════════════════════════════════════════
        // DEMO 1: Constructor por defecto
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("=== DEMO 1: Constructor por defecto ===");
        Constructores objeto1 = new Constructores();
        objeto1.mostrarInfo();
        
        // ═══════════════════════════════════════════════════════════════════
        // DEMO 2: Constructor con 2 parámetros
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("=== DEMO 2: Constructor con 2 parámetros ===");
        Constructores objeto2 = new Constructores("Toyota", "Corolla");
        objeto2.mostrarInfo();
        
        // ═══════════════════════════════════════════════════════════════════
        // DEMO 3: Constructor con 3 parámetros
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("=== DEMO 3: Constructor con 3 parámetros ===");
        Constructores objeto3 = new Constructores("Honda", "Civic", 2023);
        objeto3.mostrarInfo();
        
        // ═══════════════════════════════════════════════════════════════════
        // DEMO 4: Constructor completo
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("=== DEMO 4: Constructor COMPLETO ===");
        Constructores objeto4 = new Constructores("Tesla", "Model 3", 2024, 45000.0, "Rojo", true);
        objeto4.mostrarInfo();
        
        // ═══════════════════════════════════════════════════════════════════
        // DEMO 5: Constructor que llama a otro con this()
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("=== DEMO 5: Constructor que usa this() ===");
        Constructores objeto5 = new Constructores("Ford");
        objeto5.mostrarInfo();
        
        // ═══════════════════════════════════════════════════════════════════
        // DEMO 6: Constructor copia
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("=== DEMO 6: Constructor COPIA ===");
        System.out.println("Original:");
        Constructores original = new Constructores("BMW", "X5", 2023, 60000.0, "Negro", false);
        original.mostrarInfo();
        
        System.out.println("Copia:");
        Constructores copia = new Constructores(original);  // Constructor copia
        copia.mostrarInfo();
        
        System.out.println("=== Verificación: ¿Son independientes? ===");
        System.out.println("Cambiando año de la copia...");
        // Nota: Para modificar necesitaríamos un setter
        // Pero demostramos que son objetos diferentes en memoria
        System.out.println("HashCode original: " + System.identityHashCode(original));
        System.out.println("HashCode copia: " + System.identityHashCode(copia));
        System.out.println("✅ Son objetos DIFERENTES en memoria\n");
        
        // ═══════════════════════════════════════════════════════════════════
        // RESUMEN DE CONSTRUCTORES DISPONIBLES
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("=== RESUMEN DE CONSTRUCTORES ===");
        System.out.println("1️⃣  new Constructores()                              → Constructor por defecto");
        System.out.println("2️⃣  new Constructores(String marca)                   → Llama al de 2 parámetros");
        System.out.println("3️⃣  new Constructores(String, String)                → 2 parámetros básico");
        System.out.println("4️⃣  new Constructores(String, String, int)           → 3 parámetros");
        System.out.println("5️⃣  new Constructores(String, String, int, double, String, boolean) → Completo");
        System.out.println("6️⃣  new Constructores(otroObjeto)                    → Constructor copia\n");
        
        System.out.println("╔══════════════════════════════════════════════════════════════╗");
        System.out.println("║                     FIN DE LA DEMOSTRACIÓN                   ║");
        System.out.println("╚══════════════════════════════════════════════════════════════╝");
    }
}

/**
 * RESUMEN AL ESTILO FEYNMAN:
 * 
 * 🔑 CONCEPTOS CLAVE:
 * 
 * 1. CONSTRUCTOR = Método especial que se ejecuta automáticamente al crear objeto
 *    - Mismo nombre que la clase
 *    - No tiene tipo de retorno
 *    - Se ejecuta con 'new'
 * 
 * 2. CONSTRUCTOR POR DEFECTO
 *    - Java lo crea automáticamente si NO escribes ninguno
 *    - Si escribes uno, Java YA NO crea el por defecto
 *    - Debes escribirlo manualmente si lo necesitas
 * 
 * 3. SOBRECARGA DE CONSTRUCTORES
 *    - Puedes tener múltiples constructores
 *    - Deben tener DIFERENTES parámetros (número, tipo o orden)
 *    - Java elige el apropiado según los argumentos
 * 
 * 4. this() - Reutilización de código
 *    - Llama a otro constructor de la misma clase
 *    - Debe ser la PRIMERA línea
 *    - Evita repetir código de inicialización
 * 
 * 5. CONSTRUCTOR COPIA
 *    - Recibe objeto del mismo tipo
 *    - Crea copia independiente
 *    - Útil para clonar objetos
 * 
 * 💡 ANÁLOGÍA FINAL:
 * 
 * Piensa en un formulario de registro:
 * - Formulario CORTO: Solo nombre y email (2 campos)
 * - Formulario MEDIO: Nombre, email, teléfono (3 campos)
 * - Formulario COMPLETO: Todos los datos personales (10 campos)
 * 
 * Cada formulario es diferente, pero todos crean el mismo tipo de cuenta.
 * Tú eliges qué formulario usar según la información que tengas disponible.
 * 
 * Los constructores funcionan igual: diferentes formas de crear el mismo tipo de objeto.
 */