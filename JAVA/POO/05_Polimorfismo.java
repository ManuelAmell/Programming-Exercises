/**
 * ╔══════════════════════════════════════════════════════════════════════════════╗
 * ║                      POO EN JAVA - POLIMORFISMO                                ║
 * ╚══════════════════════════════════════════════════════════════════════════════╝
 * 
 * EXPLICACIÓN AL ESTILO FEYNMAN:
 * 
 * Imagina un BOTÓN. Un botón es algo que puedes PRESIONAR para que pase algo.
 * 
 * Pero hay MUCHOS tipos de botones:
 * - Botón de encendido de una lámpara → Enciende luz
 * - Botón de un timbre → Hace sonar campana
 * - Botón de un ascensor → Mueve cabina
 * - Botón de un control remoto → Cambia canal
 * - Botón de un mouse → Hace click en pantalla
 * 
 * TODOS son botones (se presionan), pero CADA UNO HACE ALGO DIFERENTE.
 * 
 * En programación, POLIMORFISMO significa "muchas formas":
 * - Una misma INTERFAZ (el botón)
 * - Diferentes IMPLEMENTACIONES (lo que hace cada uno)
 * 
 * ================================================================================
 *                    ¿QUÉ ES EL POLIMORFISMO?
 * ================================================================================
 * 
 * POLIMORFISMO = La capacidad de un objeto de tomar MUCHAS FORMAS.
 * 
 * Ejemplo:
 * - Animal es la clase padre
 * - Perro, Gato, Pájaro son clases hijas
 * - Cada uno es un Animal, pero cada uno HACE COSAS DIFERENTES
 * 
 * Cuando llamas animal.hacerSonido():
 * - Si animal es Perro → Ladrido
 * - Si animal es Gato → Maullido
 * - Si animal es Pájaro → Cantar
 * 
 * EL MISMO MÉTODO, COMPORTAMIENTO DIFERENTE según el objeto real.
 * 
 * ================================================================================
 *                    TIPOS DE POLIMORFISMO
 * ================================================================================
 * 
 * 1. POLIMORFISMO DE SOBRESCRITURA (Runtime/Dinámico)
 *    - Ocurre en tiempo de ejecución
 *    - Se basa en herencia
 *    - El objeto decide qué método ejecutar según su clase real
 *    - Ejemplo: Perro y Gato sobrescriben hacerSonido()
 * 
 * 2. POLIMORFISMO DE SOBRECARGA (Compile-time/Estático)
 *    - Ocurre en tiempo de compilación
 *    - Mismo nombre, diferentes parámetros
 *    - El compilador decide cuál método usar según los argumentos
 *    - Ejemplo: varios constructores con diferentes parámetros
 * 
 * ================================================================================
 *                    UPCASTING Y DOWNCASTING
 * ================================================================================
 * 
 * UPCASTING (Casting implícito): Hijo → Padre
 *    - Perro puede guardarse como Animal
 *    - Es seguro SIEMPRE (Perro ES UN Animal)
 *    - Ejemplo: Animal a = new Perro();
 * 
 * DOWNCASTING (Casting explícito): Padre → Hijo
 *    - Animal convertido a Perro
 *    - Puede ser INSEGURO (no todo Animal es Perro)
 *    - Requiere instanceof para verificar antes
 *    - Ejemplo: Perro p = (Perro) animal;
 * 
 * ================================================================================
 *                    ENLACE DINÁMICO vs ESTÁTICO
 * ================================================================================
 * 
 * ENLACE ESTÁTICO (Compilación): El compilador decide qué método ejecutar
 *    - Métodos static, final, private
 *    - Sobrecarga de métodos
 * 
 * ENLACE DINÁMICO (Ejecución): La JVM decide en runtime qué método ejecutar
 *    - Métodos sobrescritos (override)
 *    - Basado en el objeto real, no en la referencia
 */

// ════════════════════════════════════════════════════════════════════════════
// CLASE PADRE
// ════════════════════════════════════════════════════════════════════════════
class Instrumento {
    protected String nombre;
    protected String tipo;
    
    public Instrumento(String nombre, String tipo) {
        this.nombre = nombre;
        this.tipo = tipo;
    }
    
    // Método que las clases hijas SOBRESCRIBIRÁN
    public void tocar() {
        System.out.println("🎵 El instrumento " + nombre + " está haciendo un sonido");
    }
    
    // Método que las clases hijas SOBRESCRIBIRÁN
    public void afinar() {
        System.out.println("🎼 Afinando instrumento...");
    }
    
    // Método que usarán todas las clases hijas (sin sobrescribir)
    public void mostrarInfo() {
        System.out.println("╔════════════════════════════════════╗");
        System.out.println("║      INFORMACIÓN DE INSTRUMENTO    ║");
        System.out.println("╠════════════════════════════════════╣");
        System.out.println("  🎵 Nombre: " + this.nombre);
        System.out.println("  🎸 Tipo: " + this.tipo);
        System.out.println("╚════════════════════════════════════╝");
    }
}

// ════════════════════════════════════════════════════════════════════════════
// CLASE HIJA 1 - Guitarra
// ════════════════════════════════════════════════════════════════════════════
class Guitarra extends Instrumento {
    private int numeroCuerdas;
    private boolean esElectrica;
    
    public Guitarra(String nombre, int numeroCuerdas, boolean esElectrica) {
        super(nombre, "Cuerda");
        this.numeroCuerdas = numeroCuerdas;
        this.esElectrica = esElectrica;
    }
    
    @Override
    public void tocar() {
        // Cada instrumento toca diferente
        String tipoGuitarra = esElectrica ? "eléctrica" : "acústica";
        System.out.println("🎸 " + nombre + " (" + tipoGuitarra + ") toca:");
        System.out.println("   🎶 Strum strum... ¡Twaaang! 🎶");
        System.out.println("   🎸 Rasgueo con " + numeroCuerdas + " cuerdas");
    }
    
    @Override
    public void afinar() {
        System.out.println("🎸 Afinando guitarra:");
        System.out.println("   E-A-D-G-B-E ✓");
        System.out.println("   Cuerdas tensadas correctamente ✓");
    }
    
    // Método específico de Guitarra
    public void hacerRasgueo() {
        System.out.println("🎸 ¡Rasgueo rápido! Strum-strum-strum!");
    }
}

// ════════════════════════════════════════════════════════════════════════════
// CLASE HIJA 2 - Piano
// ════════════════════════════════════════════════════════════════════════════
class Piano extends Instrumento {
    private int numeroTeclas;
    private boolean esDeCola;
    
    public Piano(String nombre, int numeroTeclas, boolean esDeCola) {
        super(nombre, "Teclado");
        this.numeroTeclas = numeroTeclas;
        this.esDeCola = esDeCola;
    }
    
    @Override
    public void tocar() {
        String tipoPiano = esDeCola ? "de cola" : "vertical";
        System.out.println("🎹 " + nombre + " (" + tipoPiano + ") toca:");
        System.out.println("   🎵 Plin plin plaan... 🎵");
        System.out.println("   🎹 Melodía con " + numeroTeclas + " teclas");
    }
    
    @Override
    public void afinar() {
        System.out.println("🎹 Afinando piano:");
        System.out.println("   Afinando cuerdas internas...");
        System.out.println("   Martillos ajustados ✓");
        System.out.println("   Pedales calibrados ✓");
    }
    
    // Método específico de Piano
    public void tocarAcorde(String nota) {
        System.out.println("🎹 Tocando acorde de " + nota + ":");
        System.out.println("   🎵 ¡SONIDO ARMONIOSO! 🎵");
    }
}

// ════════════════════════════════════════════════════════════════════════════
// CLASE HIJA 3 - Batería
// ════════════════════════════════════════════════════════════════════════════
class Bateria extends Instrumento {
    private int numeroTambores;
    private boolean tienePlatillos;
    
    public Bateria(String nombre, int numeroTambores, boolean tienePlatillos) {
        super(nombre, "Percusión");
        this.numeroTambores = numeroTambores;
        this.tienePlatillos = tienePlatillos;
    }
    
    @Override
    public void tocar() {
        System.out.println("🥁 " + nombre + " toca:");
        System.out.println("   🎵 ¡BUM TSS BUM-BUM TSS! 🎵");
        System.out.println("   🥁 Ritmo con " + numeroTambores + " tambores");
        if (tienePlatillos) {
            System.out.println("   🔔 ¡CLASH! Platillos incluidos");
        }
    }
    
    @Override
    public void afinar() {
        System.out.println("🥁 Afinando batería:");
        System.out.println("   Piel de tambores tensada ✓");
        System.out.println("   Soportes ajustados ✓");
        if (tienePlatillos) {
            System.out.println("   Platillos limpios ✓");
        }
    }
    
    // Método específico de Batería
    public void hacerRitmo(int velocidad) {
        String intensidad = velocidad > 100 ? "¡RÁPIDO!" : "Ritmo normal";
        System.out.println("🥁 " + intensidad + " ¡Bum-tss-bum-tss!");
    }
}

// ════════════════════════════════════════════════════════════════════════════
// CLASE HIJA 4 - Violín
// ════════════════════════════════════════════════════════════════════════════
class Violin extends Instrumento {
    private String tipoArco;
    
    public Violin(String nombre, String tipoArco) {
        super(nombre, "Cuerda");
        this.tipoArco = tipoArco;
    }
    
    @Override
    public void tocar() {
        System.out.println("🎻 " + nombre + " toca:");
        System.out.println("   🎵 Screee... ♪♫♪... 🎵");
        System.out.println("   🎻 Melodía delicada con arco de " + tipoArco);
    }
    
    @Override
    public void afinar() {
        System.out.println("🎻 Afinando violín:");
        System.out.println("   G-D-A-E ✓");
        System.out.println("   Clavijas ajustadas ✓");
        System.out.println("   Arco con resina de " + tipoArco + " ✓");
    }
    
    // Método específico de Violín
    public void hacerVibrato() {
        System.out.println("🎻 ¡Vibrato emotivo! ♫♪♫");
    }
}

// ════════════════════════════════════════════════════════════════════════════
// CLASE PRINCIPAL - Demostración
// ════════════════════════════════════════════════════════════════════════════
public class Polimorfismo {
    
    public static void main(String[] args) {
        System.out.println("╔══════════════════════════════════════════════════════════════╗");
        System.out.println("║           DEMOSTRACIÓN: POLIMORFISMO                           ║");
        System.out.println("╚══════════════════════════════════════════════════════════════╝\n");
        
        // ═══════════════════════════════════════════════════════════════════
        // DEMO 1: UPCASTING (Cast implícito)
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("=== DEMO 1: UPCASTING ===");
        System.out.println("Guardando objetos hijos en referencias de tipo padre\n");
        
        // ¡Esto es polimorfismo! Una referencia Instrumento puede apuntar a CUALQUIER instrumento
        Instrumento inst1 = new Guitarra("Gibson", 6, true);    // Guitarra es Instrumento
        Instrumento inst2 = new Piano("Yamaha", 88, true);       // Piano es Instrumento
        Instrumento inst3 = new Bateria("Pearl", 5, true);     // Bateria es Instrumento
        Instrumento inst4 = new Violin("Stradivarius", "madera"); // Violin es Instrumento
        
        // ═══════════════════════════════════════════════════════════════════
        // DEMO 2: ENLACE DINÁMICO (Polimorfismo en acción)
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("=== DEMO 2: ENLACE DINÁMICO ===");
        System.out.println("Llamando al mismo método, cada objeto responde diferente:\n");
        
        // Todos son "Instrumento", pero cada uno toca diferente
        System.out.println("🎵 Método tocar() en cada instrumento:");
        inst1.tocar();  // Ejecuta Guitarra.tocar()
        inst2.tocar();  // Ejecuta Piano.tocar()
        inst3.tocar();  // Ejecuta Bateria.tocar()
        inst4.tocar();  // Ejecuta Violin.tocar()
        
        System.out.println("\n🎼 Método afinar() en cada instrumento:");
        inst1.afinar();  // Guitarra.afinar()
        inst2.afinar();  // Piano.afinar()
        inst3.afinar();  // Bateria.afinar()
        inst4.afinar();  // Violin.afinar()
        
        // ═══════════════════════════════════════════════════════════════════
        // DEMO 3: ARRAY POLIMÓRFICO
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("\n=== DEMO 3: ARRAY POLIMÓRFICO ===");
        System.out.println("Array de Instrumentos con diferentes objetos reales:\n");
        
        Instrumento[] orquesta = new Instrumento[4];
        orquesta[0] = new Guitarra("Fender", 6, false);
        orquesta[1] = new Piano("Steinway", 88, true);
        orquesta[2] = new Bateria("Tama", 4, true);
        orquesta[3] = new Violin("Guarneri", "sintético");
        
        // ¡Ciclo polimórfico! Cada uno toca diferente
        System.out.println("🎺 ¡ORQUESTA COMPLETA! 🎺\n");
        for (int i = 0; i < orquesta.length; i++) {
            System.out.println("🎵 Instrumento " + (i + 1) + ":");
            orquesta[i].tocar();
            System.out.println();
        }
        
        // ═══════════════════════════════════════════════════════════════════
        // DEMO 4: Método que acepta cualquier Instrumento (paramétrico)
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("=== DEMO 4: MÉTODO POLIMÓRFICO ===");
        System.out.println("Método que trabaja con CUALQUIER tipo de Instrumento:\n");
        
        tocarEnConcierto(new Guitarra("Epiphone", 6, true));
        tocarEnConcierto(new Piano("Casio", 61, false));
        tocarEnConcierto(new Bateria("Ludwig", 6, true));
        
        // ═══════════════════════════════════════════════════════════════════
        // DEMO 5: DOWNCASTING
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("\n=== DEMO 5: DOWNCASTING ===");
        System.out.println("Convirtiendo referencia de padre a hijo (con cuidado):\n");
        
        Instrumento instrumentoGenerico = new Guitarra("Ibanez", 7, true);
        
        // Verificamos el tipo antes de convertir
        if (instrumentoGenerico instanceof Guitarra) {
            System.out.println("✅ Es una Guitarra, hacemos downcasting:");
            Guitarra guitarraReal = (Guitarra) instrumentoGenerico;
            guitarraReal.hacerRasgueo();  // Ahora podemos usar métodos específicos
        }
        
        // Intentar downcast incorrecto (sin verificar) → ClassCastException
        // Piano piano = (Piano) instrumentoGenerico;  // ¡ERROR! No es un Piano
        
        // ═══════════════════════════════════════════════════════════════════
        // DEMO 6: instanceof
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("\n=== DEMO 6: OPERADOR instanceof ===");
        System.out.println("Verificando tipos de objetos:\n");
        
        Instrumento[] banda = {
            new Guitarra("PRS", 6, true),
            new Piano("Roland", 76, false),
            new Bateria("DW", 5, true),
            new Violin("Cremona", "tradicional")
        };
        
        for (Instrumento inst : banda) {
            System.out.print("🎵 " + inst.nombre + " es: ");
            
            if (inst instanceof Guitarra) {
                System.out.println("Guitarra 🎸");
                Guitarra g = (Guitarra) inst;
                g.hacerRasgueo();
            } else if (inst instanceof Piano) {
                System.out.println("Piano 🎹");
                Piano p = (Piano) inst;
                p.tocarAcorde("Do Mayor");
            } else if (inst instanceof Bateria) {
                System.out.println("Batería 🥁");
                Bateria b = (Bateria) inst;
                b.hacerRitmo(120);
            } else if (inst instanceof Violin) {
                System.out.println("Violín 🎻");
                Violin v = (Violin) inst;
                v.hacerVibrato();
            }
            System.out.println();
        }
        
        // ═══════════════════════════════════════════════════════════════════
        // DEMO 7: Sobrecarga (Polimorfismo estático)
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("=== DEMO 7: SOBRECARGA DE MÉTODOS ===");
        System.out.println("Mismo nombre, diferentes parámetros:\n");
        
        reproducirMusica("Canción A");
        reproducirMusica("Canción B", 3);
        reproducirMusica(orquesta[0], "Canción C");
        
        // ═══════════════════════════════════════════════════════════════════
        // RESUMEN
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("\n╔══════════════════════════════════════════════════════════════╗");
        System.out.println("║                     FIN DE LA DEMOSTRACIÓN                   ║");
        System.out.println("╚══════════════════════════════════════════════════════════════╝");
        
        System.out.println("\n📚 RESUMEN DE POLIMORFISMO:");
        System.out.println("   • Un objeto puede tomar muchas formas");
        System.out.println("   • Referencia padre → Objeto hijo (Upcasting)");
        System.out.println("   • Mismo método → Comportamiento diferente (Override)");
        System.out.println("   • Java decide en runtime qué método ejecutar");
        System.out.println("   • Permite escribir código genérico y reutilizable");
        System.out.println("\n💡 VENTAJAS:");
        System.out.println("   • Extensibilidad: Agregar nuevos tipos sin modificar código existente");
        System.out.println("   • Mantenibilidad: Código más limpio y organizado");
        System.out.println("   • Flexibilidad: Arrays y métodos polimórficos");
    }
    
    // ═══════════════════════════════════════════════════════════════════════
    // MÉTODO POLIMÓRFICO - Acepta cualquier Instrumento
    // ═══════════════════════════════════════════════════════════════════════
    public static void tocarEnConcierto(Instrumento instrumento) {
        System.out.println("🎤 ¡En concierto!");
        System.out.println("🎵 Presentando: " + instrumento.nombre);
        instrumento.tocar();  // Cada instrumento toca a su manera
        System.out.println("👏 ¡Aplausos!\n");
    }
    
    // ═══════════════════════════════════════════════════════════════════════
    // SOBRECARGA DE MÉTODOS - Mismo nombre, diferentes parámetros
    // ═══════════════════════════════════════════════════════════════════════
    public static void reproducirMusica(String cancion) {
        System.out.println("🎵 Reproduciendo: " + cancion);
    }
    
    public static void reproducirMusica(String cancion, int veces) {
        System.out.println("🎵 Reproduciendo: " + cancion + " (" + veces + " veces)");
    }
    
    public static void reproducirMusica(Instrumento instrumento, String cancion) {
        System.out.println("🎵 " + instrumento.nombre + " interpreta: " + cancion);
        instrumento.tocar();
    }
}

/**
 * RESUMEN AL ESTILO FEYNMAN:
 * 
 * 🔑 CONCEPTOS CLAVE:
 * 
 * 1. POLIMORFISMO = "Muchas formas"
 *    - Una referencia puede apuntar a diferentes objetos
 *    - El mismo método puede comportarse diferente
 *    - El objeto real decide qué código ejecutar
 * 
 * 2. UPCASTING = Hijo → Padre (implícito)
 *    - Siempre seguro
 *    - Instrumento i = new Guitarra();
 *    - Pierdes acceso a métodos específicos del hijo
 * 
 * 3. DOWNCASTING = Padre → Hijo (explícito)
 *    - Requiere verificación con instanceof
 *    - Guitarra g = (Guitarra) instrumento;
 *    - Puede lanzar ClassCastException si no verificas
 * 
 * 4. ENLACE DINÁMICO = Decisión en runtime
 *    - JVM mira el objeto real
 *    - Ejecuta el método correspondiente
 *    - Diferente a enlace estático (sobrecarga)
 * 
 * 5. SOBRECARGA = Mismo nombre, diferente firma
 *    - Diferente número de parámetros
 *    - Diferente tipo de parámetros
 *    - El compilador decide cuál usar
 * 
 * 💡 ANÁLOGÍA FINAL:
 * 
 * El MANDO UNIVERSAL de TV:
 * - Un solo mando controla MUCHOS aparatos (TV, DVD, Sonido)
 * - Botón "Encender": cada aparato responde diferente
 *   - TV: se enciende la pantalla
 *   - DVD: se abre la bandeja
 *   - Sonido: se activan los altavoces
 * - Es el MISMO BOTÓN pero CADA APARATO hace su propia acción
 * 
 * El mando no sabe qué aparato está controlando,
 * solo sabe que todos tienen un botón "encender".
 * 
 * Cada aparato IMPLEMENTA "encender" a su manera.
 * 
 * Así funciona el polimorfismo: código genérico que trabaja
 * con objetos específicos sin saber exactamente de qué tipo son.
 */