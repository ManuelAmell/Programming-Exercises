/**
 * ╔══════════════════════════════════════════════════════════════════════════════╗
 * ║                        POO EN JAVA - INTERFACES                               ║
 * ╚══════════════════════════════════════════════════════════════════════════════╝
 * 
 * EXPLICACIÓN AL ESTILO FEYNMAN:
 * 
 * Imagina un CONTRATO. Un contrato dice:
 * "Si quieres ser [X], DEBES hacer [Y, Z, W]"
 * 
 * Ejemplo real:
 * - Para ser CONDUCTOR de autobús necesitas:
 *   ✓ Saber manejar
 *   ✓ Conocer rutas
 *   ✓ Tener licencia especial
 * 
 * - Para ser PILOTO de avión necesitas:
 *   ✓ Saber volar
 *   ✓ Conocer rutas aéreas
 *   ✓ Tener licencia de piloto
 * 
 * Cada uno IMPLEMENTA los mismos conceptos básicos pero de FORMA DIFERENTE.
 * 
 * En programación, una INTERFAZ es como un CONTRATO:
 * - Define QUÉ métodos DEBE tener una clase
 * - NO dice CÓMO implementarlos
 * - La clase que "firma" el contrato debe implementar TODO
 * 
 * ================================================================================
 *                    ¿QUÉ ES UNA INTERFAZ?
 * ================================================================================
 * 
 * INTERFAZ = Contrato que define comportamientos obligatorios.
 * 
 * Características:
 * 1. Todos los métodos son PUBLIC y ABSTRACT (implícitamente)
 * 2. Puede tener CONSTANTES (public static final)
 * 3. NO tiene constructores
 * 4. NO se puede instanciar
 * 5. Una clase IMPLEMENTA una interfaz con 'implements'
 * 6. Una clase puede implementar MÚLTIPLES interfaces
 * 7. Una interfaz puede extender otras interfaces
 * 
 * ¿Para qué sirven?
 * - Definir comportamientos comunes entre clases NO relacionadas
 * - Lograr polimorfismo sin herencia
 * - Separar QUÉ se hace de CÓMO se hace
 * - Permitir "herencia múltiple" de comportamiento
 * 
 * ================================================================================
 *                    INTERFAZ vs CLASE ABSTRACTA
 * ================================================================================
 * 
 * CLASE ABSTRACTA (IS-A):
 *   - "Animal" es una clase base
 *   - Perro ES UN Animal → herencia natural
 *   - Relación "ES UN" (taxonomía)
 * 
 * INTERFAZ (CAN-DO):
 *   - "Volador" es una capacidad
 *   - Avión PUEDE VOLAR, Pájaro PUEDE VOLAR, Superman PUEDE VOLAR
 *   - Avión NO ES UN Pájaro, pero AMBOS pueden volar
 *   - Relación "PUEDE HACER" (capacidad)
 * 
 * Ejemplo:
 *   - Animal (abstracta) → Perro, Gato, Pájaro
 *   - Volador (interfaz) → Avión, Pájaro, Superman
 *   - Nadador (interfaz) → Pez, Humano, Barco
 * 
 *   Pato HEREDA de Animal
 *   Pato IMPLEMENTA Volador (puede volar)
 *   Pato IMPLEMENTA Nadador (puede nadar)
 * 
 * ================================================================================
 *                    JAVA 8+: MÉTODOS DEFAULT Y STATIC
 * ================================================================================
 * 
 * Desde Java 8, las interfaces pueden tener:
 * 
 * - MÉTODOS DEFAULT: Implementación por defecto
 *   default void metodo() { /* implementación */ }
 *   • Las clases pueden usarlo directamente o sobrescribirlo
 * 
 * - MÉTODOS STATIC: Pertenece a la interfaz, no a implementaciones
 *   static void metodo() { /* implementación */ }
 *   • Se llama con: Interfaz.metodo()
 * 
 * Desde Java 9, también pueden tener métodos PRIVATE.
 */

// ════════════════════════════════════════════════════════════════════════════
// INTERFAZ 1 - Volador
// ════════════════════════════════════════════════════════════════════════════
interface Volador {
    // Constantes (implícitamente public static final)
    double GRAVEDAD = 9.81;  // m/s²
    int ALTURA_MAXIMA = 10000;  // metros
    
    // Métodos abstractos (implícitamente public abstract)
    void despegar();
    void volar();
    void aterrizar();
    int obtenerAltitud();
    
    // Método default (desde Java 8)
    default void hacerAcrobacia() {
        System.out.println("🛩️  Realizando acrobacia aérea...");
        System.out.println("   ¡Loop! ¡Roll! ¡Inversión!");
    }
    
    // Método static (desde Java 8)
    static void mostrarInformacionVuelo() {
        System.out.println("✈️  Información de vuelo:");
        System.out.println("   Gravedad: " + GRAVEDAD + " m/s²");
        System.out.println("   Altura máxima permitida: " + ALTURA_MAXIMA + " m");
    }
}

// ════════════════════════════════════════════════════════════════════════════
// INTERFAZ 2 - Nadador
// ════════════════════════════════════════════════════════════════════════════
interface Nadador {
    double DENSIDAD_AGUA = 1000.0;  // kg/m³
    
    void nadar();
    void bucear();
    void salirDelAgua();
    double obtenerProfundidadMaxima();
    
    default void flotar() {
        System.out.println("🏊 Flotando en la superficie...");
    }
}

// ════════════════════════════════════════════════════════════════════════════
// INTERFAZ 3 - Transporte
// ════════════════════════════════════════════════════════════════════════════
interface Transporte {
    int CAPACIDAD_MINIMA = 1;
    int VELOCIDAD_MAXIMA = 300;  // km/h
    
    void iniciarViaje();
    void detener();
    int obtenerCapacidad();
    double obtenerVelocidad();
    
    default boolean puedeTransportar(int pasajeros) {
        return pasajeros <= obtenerCapacidad() && pasajeros >= CAPACIDAD_MINIMA;
    }
    
    static void verificarSeguridad() {
        System.out.println("✅ Verificación de seguridad completada");
    }
}

// ════════════════════════════════════════════════════════════════════════════
// INTERFAZ 4 - Conectable (para dispositivos electrónicos)
// ════════════════════════════════════════════════════════════════════════════
interface Conectable {
    void conectar();
    void desconectar();
    boolean estaConectado();
    String obtenerEstadoConexion();
}

// ════════════════════════════════════════════════════════════════════════════
// CLASE 1: Avión (Implementa Volador y Transporte)
// ════════════════════════════════════════════════════════════════════════════
// Un avión puede VOLAR y es un TRANSPORTE

class Avion implements Volador, Transporte {
    private String modelo;
    private int capacidadPasajeros;
    private double velocidad;
    private int altitud;
    private boolean enVuelo;
    
    public Avion(String modelo, int capacidad, double velocidad) {
        this.modelo = modelo;
        this.capacidadPasajeros = capacidad;
        this.velocidad = velocidad;
        this.altitud = 0;
        this.enVuelo = false;
    }
    
    // Implementación de Volador
    @Override
    public void despegar() {
        if (!enVuelo) {
            System.out.println("✈️  " + modelo + ": Despegando...");
            System.out.println("   💨 Velocidad aumentando");
            System.out.println("   🛫 ¡Despegue exitoso!");
            enVuelo = true;
            altitud = 1000;
        } else {
            System.out.println("⚠️  Ya estamos en el aire");
        }
    }
    
    @Override
    public void volar() {
        if (enVuelo) {
            altitud = Math.min(altitud + 500, ALTURA_MAXIMA);
            System.out.println("✈️  " + modelo + " volando a " + altitud + " metros");
            System.out.println("   ☁️  Cruzando nubes...");
        } else {
            System.out.println("⚠️  Primero debes despegar");
        }
    }
    
    @Override
    public void aterrizar() {
        if (enVuelo) {
            System.out.println("✈️  " + modelo + ": Aterrizando...");
            System.out.println("   🛬 ¡Aterrizaje exitoso!");
            enVuelo = false;
            altitud = 0;
        } else {
            System.out.println("⚠️  Ya estamos en tierra");
        }
    }
    
    @Override
    public int obtenerAltitud() {
        return altitud;
    }
    
    // Implementación de Transporte
    @Override
    public void iniciarViaje() {
        System.out.println("🛫 Iniciando viaje aéreo con " + modelo);
        despegar();
    }
    
    @Override
    public void detener() {
        aterrizar();
        System.out.println("🛑 Avión detenido en la pista");
    }
    
    @Override
    public int obtenerCapacidad() {
        return capacidadPasajeros;
    }
    
    @Override
    public double obtenerVelocidad() {
        return velocidad;
    }
    
    // Método propio de Avión
    public void anunciarVuelo() {
        System.out.println("📢 Atención pasajeros del vuelo " + modelo);
        System.out.println("   Altitud actual: " + altitud + " metros");
        System.out.println("   Velocidad: " + velocidad + " km/h");
    }
}

// ════════════════════════════════════════════════════════════════════════════
// CLASE 2: Pato (Implementa Volador y Nadador)
// ════════════════════════════════════════════════════════════════════════════
// Un pato puede VOLAR y NADAR

class Pato implements Volador, Nadador {
    private String nombre;
    private int altitud;
    private double profundidad;
    private boolean volando;
    private boolean nadando;
    
    public Pato(String nombre) {
        this.nombre = nombre;
        this.altitud = 0;
        this.profundidad = 0;
        this.volando = false;
        this.nadando = false;
    }
    
    // Implementación de Volador
    @Override
    public void despegar() {
        if (!volando) {
            System.out.println("🦆 " + nombre + ": ¡Aleteo fuerte!");
            System.out.println("   🪽 ¡Despegando!");
            volando = true;
            altitud = 5;
        }
    }
    
    @Override
    public void volar() {
        if (volando) {
            altitud = Math.min(altitud + 2, 50);  // Los patos no vuelan muy alto
            System.out.println("🦆 " + nombre + " volando a " + altitud + " metros");
        }
    }
    
    @Override
    public void aterrizar() {
        if (volando) {
            System.out.println("🦆 " + nombre + ": Aterrizando en el agua...");
            System.out.println("   💦 ¡Splash!");
            volando = false;
            altitud = 0;
        }
    }
    
    @Override
    public int obtenerAltitud() {
        return altitud;
    }
    
    // Implementación de Nadador
    @Override
    public void nadar() {
        if (!nadando) {
            System.out.println("🦆 " + nombre + ": ¡A nadar!");
            System.out.println("   🏊 Pato nadando elegantemente...");
            nadando = true;
        }
    }
    
    @Override
    public void bucear() {
        if (nadando) {
            profundidad = Math.min(profundidad + 0.5, 2);
            System.out.println("🦆 " + nombre + " buceando a " + profundidad + " metros");
            System.out.println("   🐟 Buscando comida...");
        }
    }
    
    @Override
    public void salirDelAgua() {
        if (nadando) {
            System.out.println("🦆 " + nombre + ": Saliendo del agua...");
            System.out.println("   🪶 Sacudiendo plumas");
            nadando = false;
            profundidad = 0;
        }
    }
    
    @Override
    public double obtenerProfundidadMaxima() {
        return 2.0;  // metros
    }
    
    // Método propio de Pato
    public void graznar() {
        System.out.println("🦆 ¡Cuac cuac cuac!");
    }
}

// ════════════════════════════════════════════════════════════════════════════
// CLASE 3: Barco (Implementa Nadador y Transporte)
// ════════════════════════════════════════════════════════════════════════════
// Un barco puede NADAR y es un TRANSPORTE

class Barco implements Nadador, Transporte {
    private String nombre;
    private int capacidad;
    private double velocidad;
    private double profundidad;
    private boolean navegando;
    
    public Barco(String nombre, int capacidad, double velocidad) {
        this.nombre = nombre;
        this.capacidad = capacidad;
        this.velocidad = velocidad;
        this.profundidad = 0;
        this.navegando = false;
    }
    
    // Implementación de Nadador
    @Override
    public void nadar() {
        if (!navegando) {
            System.out.println("🚢 " + nombre + ": ¡Zarpando!");
            System.out.println("   🌊 Navegando en aguas abiertas");
            navegando = true;
        }
    }
    
    @Override
    public void bucear() {
        System.out.println("🚢 Los barcos no bucean, navegan en superficie");
    }
    
    @Override
    public void salirDelAgua() {
        System.out.println("🚢 El barco necesita un astillero para salir del agua");
    }
    
    @Override
    public double obtenerProfundidadMaxima() {
        return 0;  // Navega en superficie
    }
    
    // Implementación de Transporte
    @Override
    public void iniciarViaje() {
        System.out.println("🚢 Iniciando travesía marítima");
        nadar();
    }
    
    @Override
    public void detener() {
        System.out.println("🚢 " + nombre + ": Fondeando anclas");
        System.out.println("   ⚓ Barco detenido");
        navegando = false;
    }
    
    @Override
    public int obtenerCapacidad() {
        return capacidad;
    }
    
    @Override
    public double obtenerVelocidad() {
        return velocidad;
    }
}

// ════════════════════════════════════════════════════════════════════════════
// CLASE 4: Dron (Implementa Volador y Conectable)
// ════════════════════════════════════════════════════════════════════════════
// Un dron puede VOLAR y es un dispositivo CONECTABLE

class Dron implements Volador, Conectable {
    private String modelo;
    private int altitud;
    private boolean volando;
    private boolean conectado;
    private String redWiFi;
    
    public Dron(String modelo) {
        this.modelo = modelo;
        this.altitud = 0;
        this.volando = false;
        this.conectado = false;
    }
    
    // Implementación de Volador
    @Override
    public void despegar() {
        if (!volando && conectado) {
            System.out.println("🚁 " + modelo + ": Motores iniciando...");
            System.out.println("   🎮 Control remoto conectado");
            System.out.println("   🚁 ¡Despegue!");
            volando = true;
            altitud = 2;
        } else if (!conectado) {
            System.out.println("⚠️  Debes conectar el dron primero");
        }
    }
    
    @Override
    public void volar() {
        if (volando) {
            altitud = Math.min(altitud + 5, 400);
            System.out.println("🚁 " + modelo + " volando a " + altitud + " metros");
            System.out.println("   📸 Tomando fotos aéreas...");
        }
    }
    
    @Override
    public void aterrizar() {
        if (volando) {
            System.out.println("🚁 " + modelo + ": Aterrizando...");
            System.out.println("   🛬 Aterrizaje suave completado");
            volando = false;
            altitud = 0;
        }
    }
    
    @Override
    public int obtenerAltitud() {
        return altitud;
    }
    
    // Implementación de Conectable
    @Override
    public void conectar() {
        if (!conectado) {
            System.out.println("🚁 " + modelo + ": Conectando a WiFi...");
            System.out.println("   📡 Señal establecida");
            conectado = true;
            redWiFi = "DronNetwork";
        }
    }
    
    @Override
    public void desconectar() {
        if (conectado) {
            System.out.println("🚁 " + modelo + ": Desconectando...");
            System.out.println("   📡 Conexión cerrada");
            conectado = false;
            redWiFi = null;
        }
    }
    
    @Override
    public boolean estaConectado() {
        return conectado;
    }
    
    @Override
    public String obtenerEstadoConexion() {
        return conectado ? "Conectado a " + redWiFi : "Desconectado";
    }
}

// ════════════════════════════════════════════════════════════════════════════
// CLASE PRINCIPAL - Demostración
// ════════════════════════════════════════════════════════════════════════════
public class Interfaces {
    
    public static void main(String[] args) {
        System.out.println("╔══════════════════════════════════════════════════════════════╗");
        System.out.println("║           DEMOSTRACIÓN: INTERFACES                             ║");
        System.out.println("╚══════════════════════════════════════════════════════════════╝\n");
        
        // ═══════════════════════════════════════════════════════════════════
        // DEMO 1: Crear objetos que implementan interfaces
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("=== DEMO 1: Objetos implementando interfaces ===\n");
        
        Avion avion = new Avion("Boeing 747", 400, 900);
        Pato pato = new Pato("Donald");
        Barco barco = new Barco("Titanic", 2000, 40);
        Dron dron = new Dron("DJI Phantom");
        
        // ═══════════════════════════════════════════════════════════════════
        // DEMO 2: Usar métodos de las interfaces
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("=== DEMO 2: Voladores en acción ===\n");
        
        System.out.println("Avión:");
        avion.despegar();
        avion.volar();
        avion.hacerAcrobacia();  // Método default de Volador
        avion.aterrizar();
        
        System.out.println("\nPato:");
        pato.despegar();
        pato.volar();
        pato.graznar();
        pato.aterrizar();
        
        System.out.println("\nDron:");
        dron.conectar();  // De Conectable
        dron.despegar();
        dron.volar();
        dron.aterrizar();
        
        // ═══════════════════════════════════════════════════════════════════
        // DEMO 3: Nadadores en acción
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("\n=== DEMO 3: Nadadores en acción ===\n");
        
        System.out.println("Pato:");
        pato.nadar();
        pato.bucear();
        pato.flotar();  // Método default de Nadador
        pato.salirDelAgua();
        
        System.out.println("\nBarco:");
        barco.nadar();
        barco.bucear();  // Implementación especial
        barco.detener();  // De Transporte
        
        // ═══════════════════════════════════════════════════════════════════
        // DEMO 4: Polimorfismo con interfaces
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("\n=== DEMO 4: Polimorfismo con interfaces ===");
        System.out.println("Array de Voladores:\n");
        
        Volador[] voladores = new Volador[3];
        voladores[0] = avion;
        voladores[1] = pato;
        voladores[2] = dron;
        
        for (Volador v : voladores) {
            v.despegar();
            v.volar();
            System.out.println("   Altitud: " + v.obtenerAltitud() + " metros\n");
        }
        
        // ═══════════════════════════════════════════════════════════════════
        // DEMO 5: Transportes
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("=== DEMO 5: Transportes ===\n");
        
        Transporte[] transportes = new Transporte[2];
        transportes[0] = avion;
        transportes[1] = barco;
        
        for (Transporte t : transportes) {
            System.out.println("Transporte:");
            System.out.println("   Capacidad: " + t.obtenerCapacidad() + " pasajeros");
            System.out.println("   Velocidad: " + t.obtenerVelocidad() + " km/h");
            System.out.println("   ¿Puede transportar 100?: " + t.puedeTransportar(100));
            System.out.println();
        }
        
        // ═══════════════════════════════════════════════════════════════════
        // DEMO 6: Métodos estáticos de interfaces
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("=== DEMO 6: Métodos estáticos de interfaces ===\n");
        
        Volador.mostrarInformacionVuelo();
        System.out.println();
        Transporte.verificarSeguridad();
        
        // ═══════════════════════════════════════════════════════════════════
        // DEMO 7: Múltiples interfaces (Pato implementa dos)
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("\n=== DEMO 7: Múltiples interfaces ===");
        System.out.println("Un Pato puede VOLAR y NADAR:\n");
        
        // Tratar al pato como Volador
        Volador patoVolador = pato;
        patoVolador.despegar();
        patoVolador.volar();
        
        // Tratar al pato como Nadador
        Nadador patoNadador = pato;
        patoNadador.nadar();
        patoNadador.flotar();
        
        // ═══════════════════════════════════════════════════════════════════
        // RESUMEN
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("\n╔══════════════════════════════════════════════════════════════╗");
        System.out.println("║                     FIN DE LA DEMOSTRACIÓN                   ║");
        System.out.println("╚══════════════════════════════════════════════════════════════╝");
        
        System.out.println("\n📚 RESUMEN DE INTERFACES:");
        System.out.println("   • interface: Define contrato/comportamiento");
        System.out.println("   • implements: Clase implementa interfaz");
        System.out.println("   • Todos los métodos son public abstract (implícito)");
        System.out.println("   • Puede haber métodos default y static");
        System.out.println("   • Una clase puede implementar MÚLTIPLES interfaces");
        System.out.println("   • Una interfaz puede extender otras interfaces");
        System.out.println("\n💡 DIFERENCIAS:");
        System.out.println("   • Clase abstracta: IS-A (es un) → taxonomía");
        System.out.println("   • Interface: CAN-DO (puede hacer) → capacidad");
        System.out.println("   • Java permite herencia simple + múltiples interfaces");
    }
}

/**
 * RESUMEN AL ESTILO FEYNMAN:
 * 
 * 🔑 CONCEPTOS CLAVE:
 * 
 * 1. INTERFAZ = Contrato
 *    - Define QUÉ métodos DEBE tener una clase
 *    - NO dice CÓMO implementarlos
 *    - La clase debe cumplir TODO el contrato
 * 
 * 2. IMPLEMENTS = "Firma" el contrato
 *    - class X implements Interfaz
 *    - La clase PROMETE implementar todos los métodos
 *    - Puede implementar MÚLTIPLES interfaces
 * 
 * 3. POLIMORFISMO CON INTERFACES
 *    - Volador[] puede contener Avión, Pato, Dron
 *    - Cada uno vuela a su manera
 *    - Código genérico trabaja con cualquier Volador
 * 
 * 4. VENTAJAS DE LAS INTERFACES
 *    - Herencia múltiple de comportamiento
 *    - Separar interfaz de implementación
 *    - Facilitar pruebas y mantenimiento
 *    - Permitir evolución del código
 * 
 * 💡 ANÁLOGÍA FINAL:
 * 
 * La COCINA de un restaurante:
 * 
 * INTERFAZ "Cocinero":
 *   - prepararPlato()
 *   - limpiarEstación()
 *   - inventariarIngredientes()
 * 
 * CLASES que implementan:
 *   - ChefItaliano: prepara pasta, pizza
 *   - ChefJapones: prepara sushi, ramen
 *   - ChefMexicano: prepara tacos, enchiladas
 * 
   - AyudanteCocina: también implementa la interfaz
 * 
 * El GERENTE del restaurante no necesita saber:
 *   - SI es italiano, japonés o mexicano
 *   - CÓMO prepara cada plato
 * 
 * Solo necesita saber que PUEDE:
 *   - prepararPlato()
 *   - limpiarEstación()
 * 
 * Si contrata un ChefFrances, el código del gerente
 * NO necesita cambiar, porque todos siguen el mismo
 * contrato (interfaz).
 * 
 * Las interfaces permiten que el código sea FLEXIBLE
 * y EXTENSIBLE sin modificar lo que ya funciona.
 */