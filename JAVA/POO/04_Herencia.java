/**
 * ╔══════════════════════════════════════════════════════════════════════════════╗
 * ║                         POO EN JAVA - HERENCIA                                ║
 * ╚══════════════════════════════════════════════════════════════════════════════╝
 * 
 * EXPLICACIÓN AL ESTILO FEYNMAN:
 * 
 * Imagina una familia. Los hijos HEREDAN características de sus padres:
 * - El color de ojos del papá
 * - La nariz de la mamá
 * - El tipo de sangre de ambos
 * 
 * Pero también tienen cosas ÚNICAS:
 * - Su propia personalidad
 * - Sus propios hobbies
 * - Sus propias experiencias
 * 
 * En programación, la HERENCIA funciona EXACTAMENTE igual:
 * 
 * CLASE PADRE (Superclase): La clase base que tiene características generales
 * CLASE HIJA (Subclase): Hereda del padre y añade/modifica cosas específicas
 * 
 * Ejemplo del mundo real:
 * - CLASE PADRE: Animal (respira, come, duerme)
 * - CLASE HIJA: Perro (hereda de Animal + ladra, corre)
 * - CLASE HIJA: Gato (hereda de Animal + maulla, trepa)
 * 
 * El Perro y el Gato NO tienen que volver a escribir "respira, come, duerme"
 * porque ya lo heredan de Animal. Solo añaden sus comportamientos específicos.
 * 
 * ================================================================================
 *                    ¿QUÉ SE HEREDA?
 * ================================================================================
 * 
 * ✅ SE HEREDA:
 *    - Atributos public y protected
 *    - Métodos public y protected
 *    - Constructores (indirectamente, mediante super())
 * 
 * ❌ NO SE HEREDA:
 *    - Atributos y métodos private
 *    - Constructores (se llaman con super(), no se heredan directamente)
 *    - Clases con modificador final
 * 
 * ================================================================================
 *                    PALABRA CLAVE: extends
 * ================================================================================
 * 
 * class Perro extends Animal { }
 * 
 * Significa: "Perro ES UN tipo de Animal más específico"
 * 
 * ================================================================================
 *                    PALABRA CLAVE: super
 * ================================================================================
 * 
 * 'super' se refiere al objeto padre. Se usa para:
 * 
 * 1. LLAMAR AL CONSTRUCTOR DEL PADRE: super(parametros);
 *    - Debe ser la PRIMERA línea del constructor hijo
 *    - Inicializa la parte "padre" del objeto
 * 
 * 2. ACCEDER A MÉTODOS DEL PADRE: super.metodo();
 *    - Cuando el hijo sobrescribe un método, puede llamar al original
 * 
 * 3. ACCEDER A ATRIBUTOS DEL PADRE: super.atributo;
 *    - Cuando hay variables con el mismo nombre en padre e hijo
 * 
 * ================================================================================
 *                    SOBRESCRITURA (Overriding)
 * ================================================================================
 * 
 * La clase HIJA puede "redefinir" un método del PADRE:
 * - Mismo nombre
 * - Mismos parámetros
 * - Mismo tipo de retorno (o covariante)
 * - @Override es opcional pero recomendado (verificación en compilación)
 * 
 * El hijo puede:
 * - Cambiar completamente el comportamiento
 * - Llamar al método padre con super y añadir cosas
 * - Acceder a atributos protected del padre
 */

// ════════════════════════════════════════════════════════════════════════════
// CLASE PADRE (Superclase) - Animal
// ════════════════════════════════════════════════════════════════════════════
class Animal {
    // Atributos protected: accesibles desde clases hijas
    protected String nombre;
    protected int edad;
    protected double peso;
    protected String habitat;
    
    // Atributo private: NO accesible desde hijas
    private String codigoGenetico;
    
    // Constructor del padre
    public Animal(String nombre, int edad, double peso, String habitat) {
        System.out.println("🏗️  Constructor ANIMAL ejecutado");
        this.nombre = nombre;
        this.edad = edad;
        this.peso = peso;
        this.habitat = habitat;
        this.codigoGenetico = "GEN-" + System.currentTimeMillis();
    }
    
    // Métodos que las hijas heredarán
    public void respirar() {
        System.out.println(this.nombre + " está respirando... 💨");
    }
    
    public void comer() {
        System.out.println(this.nombre + " está comiendo... 🍽️");
        this.peso += 0.1;  // Engorda un poco al comer
    }
    
    public void dormir() {
        System.out.println(this.nombre + " está durmiendo... 😴");
    }
    
    // Método que las hijas pueden sobrescribir
    public void hacerSonido() {
        System.out.println(this.nombre + " hace un sonido genérico");
    }
    
    // Método que las hijas pueden sobrescribir
    public void mostrarInfo() {
        System.out.println("╔════════════════════════════════════╗");
        System.out.println("║      INFORMACIÓN DE ANIMAL         ║");
        System.out.println("╠════════════════════════════════════╣");
        System.out.println("  📛 Nombre: " + this.nombre);
        System.out.println("  🎂 Edad: " + this.edad + " años");
        System.out.println("  ⚖️  Peso: " + this.peso + " kg");
        System.out.println("  🏠 Hábitat: " + this.habitat);
        System.out.println("╚════════════════════════════════════╝\n");
    }
    
    // Getter para atributo privado
    public String getCodigoGenetico() {
        return this.codigoGenetico;
    }
    
    // Método protected: solo accesible desde paquete e hijas
    protected void crecer() {
        this.edad++;
        System.out.println(this.nombre + " ha crecido un año más. Ahora tiene " + this.edad + " años.");
    }
}

// ════════════════════════════════════════════════════════════════════════════
// CLASE HIJA - Perro (extends Animal)
// ════════════════════════════════════════════════════════════════════════════
class Perro extends Animal {
    // Atributos específicos de Perro (NO heredados)
    private String raza;
    private boolean entrenado;
    private int nivelEnergia;
    
    // Constructor de Perro
    public Perro(String nombre, int edad, double peso, String raza, boolean entrenado) {
        // PRIMERO llamamos al constructor del PADRE con super()
        // Esto inicializa la parte "Animal" del objeto
        super(nombre, edad, peso, "Doméstico");
        
        System.out.println("🏗️  Constructor PERRO ejecutado");
        
        // Luego inicializamos los atributos específicos de Perro
        this.raza = raza;
        this.entrenado = entrenado;
        this.nivelEnergia = 100;
    }
    
    // Método específico de Perro (NO heredado)
    public void ladrar() {
        System.out.println(this.nombre + " dice: ¡¡¡GUAU GUAU!!! 🐕");
    }
    
    // Método específico de Perro
    public void moverCola() {
        System.out.println(this.nombre + " está moviendo la cola felizmente 🐕‍🦺");
    }
    
    // Método específico de Perro
    public void sentarse() {
        if (entrenado) {
            System.out.println(this.nombre + " se sentó obedientemente 🎓");
        } else {
            System.out.println(this.nombre + " te mira confundido 🤷‍♂️");
        }
    }
    
    // SOBRESCRITURA (Overriding): redefinimos hacerSonido()
    @Override  // Anotación opcional pero recomendada
    public void hacerSonido() {
        ladrar();  // El perro ladra, no hace sonido genérico
    }
    
    // SOBRESCRITURA: redefinimos mostrarInfo()
    @Override
    public void mostrarInfo() {
        // Llamamos al método del padre con super
        super.mostrarInfo();  // Muestra info básica de Animal
        
        // Añadimos info específica de Perro
        System.out.println("  🐕 Tipo: Perro");
        System.out.println("  🏆 Raza: " + this.raza);
        System.out.println("  🎓 Entrenado: " + (this.entrenado ? "Sí" : "No"));
        System.out.println("  ⚡ Energía: " + this.nivelEnergia + "%");
        System.out.println("╚════════════════════════════════════╝\n");
    }
    
    // SOBRESCRITURA: redefinimos comer()
    @Override
    public void comer() {
        super.comer();  // Llama al comer del Animal
        this.nivelEnergia = Math.min(100, this.nivelEnergia + 20);
        System.out.println(this.nombre + " recuperó energía. Nivel: " + this.nivelEnergia + "% 🦴");
    }
    
    // Perro puede usar métodos protected del padre
    public void cumplirAnios() {
        super.crecer();  // Método protected heredado
        moverCola();     // Propio de Perro
    }
}

// ════════════════════════════════════════════════════════════════════════════
// CLASE HIJA - Gato (extends Animal)
// ════════════════════════════════════════════════════════════════════════════
class Gato extends Animal {
    // Atributos específicos de Gato
    private String colorPelaje;
    private boolean esGatoSiames;
    private int vidas;  // Los gatos tienen 7 vidas ;)
    
    public Gato(String nombre, int edad, double peso, String colorPelaje, boolean esGatoSiames) {
        super(nombre, edad, peso, "Doméstico");
        System.out.println("🏗️  Constructor GATO ejecutado");
        this.colorPelaje = colorPelaje;
        this.esGatoSiames = esGatoSiames;
        this.vidas = 7;
    }
    
    // Método específico de Gato
    public void maullar() {
        System.out.println(this.nombre + " dice: ¡¡¡MIAUUU!!! 🐱");
    }
    
    // Método específico de Gato
    public void ronronear() {
        System.out.println(this.nombre + " está ronroneando... purrrr 🐱‍👤");
    }
    
    // Método específico de Gato
    public void trepar(String objeto) {
        System.out.println(this.nombre + " trepó al " + objeto + " con elegancia 🧗‍♀️");
    }
    
    // SOBRESCRITURA: redefinimos hacerSonido()
    @Override
    public void hacerSonido() {
        maullar();
    }
    
    // SOBRESCRITURA: redefinimos mostrarInfo()
    @Override
    public void mostrarInfo() {
        System.out.println("╔════════════════════════════════════╗");
        System.out.println("║      INFORMACIÓN DE GATO           ║");
        System.out.println("╠════════════════════════════════════╣");
        System.out.println("  📛 Nombre: " + this.nombre);  // Heredado de Animal
        System.out.println("  🎂 Edad: " + this.edad + " años");  // Heredado de Animal
        System.out.println("  ⚖️  Peso: " + this.peso + " kg");  // Heredado de Animal
        System.out.println("  🏠 Hábitat: " + this.habitat);  // Heredado de Animal
        System.out.println("  🐱 Tipo: Gato");
        System.out.println("  🎨 Color: " + this.colorPelaje);
        System.out.println("  👑 Siames: " + (this.esGatoSiames ? "Sí" : "No"));
        System.out.println("  ❤️  Vidas: " + this.vidas);
        System.out.println("╚════════════════════════════════════╝\n");
    }
    
    // SOBRESCRITURA: redefinimos comer()
    @Override
    public void comer() {
        super.comer();  // Llama al comer del Animal
        System.out.println(this.nombre + " se lamió las patas elegantemente 🐟");
    }
    
    // Método específico de Gato
    public void perderVida() {
        if (vidas > 0) {
            vidas--;
            System.out.println(this.nombre + " perdió una vida. Vidas restantes: " + this.vidas + " 💔");
        } else {
            System.out.println(this.nombre + " no tiene más vidas 😿");
        }
    }
}

// ════════════════════════════════════════════════════════════════════════════
// CLASE HIJA - Pez (extends Animal)
// ════════════════════════════════════════════════════════════════════════════
class Pez extends Animal {
    private String tipoAgua;  // Dulce o Salada
    private int numeroAletas;
    private boolean puedeVolar;  // Pez volador
    
    public Pez(String nombre, int edad, double peso, String tipoAgua, int numeroAletas) {
        super(nombre, edad, peso, "Acuático");
        System.out.println("🏗️  Constructor PEZ ejecutado");
        this.tipoAgua = tipoAgua;
        this.numeroAletas = numeroAletas;
        this.puedeVolar = false;
    }
    
    // Método específico de Pez
    public void nadar() {
        System.out.println(this.nombre + " está nadando graciosamente 🐟");
    }
    
    // Método específico de Pez
    public void soplarBurbujas() {
        System.out.println(this.nombre + " sopla burbujas... o.O.O.O 🫧");
    }
    
    // SOBRESCRITURA: redefinimos respirar()
    @Override
    public void respirar() {
        System.out.println(this.nombre + " respira a través de sus branquias 🫁");
    }
    
    // SOBRESCRITURA: redefinimos hacerSonido()
    @Override
    public void hacerSonido() {
        System.out.println(this.nombre + " hace: ¡Blub blub! 🫧");
    }
    
    // SOBRESCRITURA: redefinimos mostrarInfo()
    @Override
    public void mostrarInfo() {
        System.out.println("╔════════════════════════════════════╗");
        System.out.println("║      INFORMACIÓN DE PEZ            ║");
        System.out.println("╠════════════════════════════════════╣");
        System.out.println("  📛 Nombre: " + this.nombre);
        System.out.println("  🎂 Edad: " + this.edad + " años");
        System.out.println("  ⚖️  Peso: " + this.peso + " kg");
        System.out.println("  🐠 Tipo: Pez");
        System.out.println("  🌊 Agua: " + this.tipoAgua);
        System.out.println("  🐟 Aletas: " + this.numeroAletas);
        System.out.println("  🪽 Vuela: " + (this.puedeVolar ? "Sí" : "No"));
        System.out.println("╚════════════════════════════════════╝\n");
    }
    
    // Pez no puede dormir como otros animales
    @Override
    public void dormir() {
        System.out.println(this.nombre + " está " + (this.tipoAgua.equals("Salada") ? "flotando" : "reposando") + " 🐡");
        System.out.println("   (Los peces duermen con los ojos abiertos!)");
    }
}

// ════════════════════════════════════════════════════════════════════════════
// CLASE PRINCIPAL - Demostración
// ════════════════════════════════════════════════════════════════════════════
public class Herencia {
    
    public static void main(String[] args) {
        System.out.println("╔══════════════════════════════════════════════════════════════╗");
        System.out.println("║              DEMOSTRACIÓN: HERENCIA                            ║");
        System.out.println("╚══════════════════════════════════════════════════════════════╝\n");
        
        // ═══════════════════════════════════════════════════════════════════
        // DEMO 1: Crear objetos de las clases hijas
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("=== DEMO 1: Creando animales ===");
        System.out.println("Orden de constructores:\n");
        
        System.out.println("Creando Perro:");
        Perro miPerro = new Perro("Fido", 3, 15.5, "Labrador", true);
        System.out.println();
        
        System.out.println("Creando Gato:");
        Gato miGato = new Gato("Luna", 2, 4.2, "Naranja", false);
        System.out.println();
        
        System.out.println("Creando Pez:");
        Pez miPez = new Pez("Nemo", 1, 0.1, "Salada", 5);
        System.out.println();
        
        // ═══════════════════════════════════════════════════════════════════
        // DEMO 2: Métodos heredados vs específicos
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("=== DEMO 2: Métodos heredados ===");
        
        System.out.println("\nPerro usando métodos HEREDADOS de Animal:");
        miPerro.respirar();   // Heredado de Animal
        miPerro.comer();      // Sobrescrito en Perro (llama al padre + añade)
        miPerro.dormir();     // Heredado de Animal
        
        System.out.println("\nPerro usando métodos ESPECÍFICOS de Perro:");
        miPerro.ladrar();      // Solo existe en Perro
        miPerro.moverCola();   // Solo existe en Perro
        miPerro.sentarse();    // Solo existe en Perro
        
        System.out.println("\nGato usando métodos ESPECÍFICOS de Gato:");
        miGato.maullar();      // Solo existe en Gato
        miGato.ronronear();    // Solo existe en Gato
        miGato.trepar("árbol"); // Solo existe en Gato
        
        System.out.println("\nPez usando métodos ESPECÍFICOS de Pez:");
        miPez.nadar();         // Solo existe en Pez
        miPez.soplarBurbujas(); // Solo existe en Pez
        miPez.dormir();        // Sobrescrito en Pez
        
        // ═══════════════════════════════════════════════════════════════════
        // DEMO 3: Sobrescritura de métodos
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("=== DEMO 3: Sobrescritura de métodos ===");
        
        System.out.println("\nhacerSonido() en cada animal:");
        System.out.println("Animal genérico:");
        Animal animalGenerico = new Animal("Genérico", 1, 1.0, "Desconocido");
        animalGenerico.hacerSonido();
        
        System.out.println("\nPerro:");
        miPerro.hacerSonido();  // Llama a ladrar()
        
        System.out.println("\nGato:");
        miGato.hacerSonido();   // Llama a maullar()
        
        System.out.println("\nPez:");
        miPez.hacerSonido();    // Llama a su implementación específica
        
        // ═══════════════════════════════════════════════════════════════════
        // DEMO 4: Uso de super y protected
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("\n=== DEMO 4: Uso de super y protected ===");
        miPerro.cumplirAnios();  // Usa crecer() que es protected
        
        // ═══════════════════════════════════════════════════════════════════
        // DEMO 5: Información de cada animal
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("\n=== DEMO 5: Información de cada animal ===");
        miPerro.mostrarInfo();
        miGato.mostrarInfo();
        miPez.mostrarInfo();
        
        // ═══════════════════════════════════════════════════════════════════
        // DEMO 6: Referencias de tipo padre apuntando a hijos
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("=== DEMO 6: Polimorfismo básico (referencias) ===");
        
        // Podemos guardar un objeto Perro en una variable Animal
        // Porque "Perro ES UN Animal"
        Animal animal1 = new Perro("Rex", 5, 20.0, "Pastor Alemán", false);
        Animal animal2 = new Gato("Michi", 1, 3.5, "Negro", true);
        
        System.out.println("\nReferencia Animal apuntando a Perro:");
        animal1.hacerSonido();  // Ejecuta ladrar() (enlace dinámico)
        
        System.out.println("\nReferencia Animal apuntando a Gato:");
        animal2.hacerSonido();  // Ejecuta maullar() (enlace dinámico)
        
        // ═══════════════════════════════════════════════════════════════════
        // RESUMEN
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("\n╔══════════════════════════════════════════════════════════════╗");
        System.out.println("║                     FIN DE LA DEMOSTRACIÓN                   ║");
        System.out.println("╚══════════════════════════════════════════════════════════════╝");
        
        System.out.println("\n📚 RESUMEN DE HERENCIA:");
        System.out.println("   extends → Establece relación padre-hijo");
        System.out.println("   super() → Llama constructor del padre");
        System.out.println("   @Override → Indica sobrescritura de método");
        System.out.println("   protected → Visible en padre e hijas");
        System.out.println("   private → Solo visible en la clase que lo define");
        System.out.println("\n💡 REGLAS:");
        System.out.println("   • super() debe ser la primera línea del constructor");
        System.out.println("   • Java soporta herencia SIMPLE (una clase padre)");
        System.out.println("   • Los métodos sobrescritos deben tener misma firma");
    }
}

/**
 * RESUMEN AL ESTILO FEYNMAN:
 * 
 * 🔑 CONCEPTOS CLAVE:
 * 
 * 1. HERENCIA = Relación "ES UN"
 *    - Perro ES UN Animal
 *    - Gato ES UN Animal
 *    - La hija HEREDA características del padre
 * 
 * 2. EXTENDS = Establece la relación
 *    - class Perro extends Animal
 *    - Perro obtiene todo lo public y protected de Animal
 * 
 * 3. SUPER = Referencia al padre
 *    - super() → Llama al constructor del padre
 *    - super.metodo() → Llama a método del padre
 *    - super.atributo → Accede a atributo del padre
 * 
 * 4. SOBRESCRITURA (Overriding) = Redefinir comportamiento
 *    - Mismo nombre, mismos parámetros
 *    - @Override es buena práctica
 *    - super permite llamar al método original
 * 
 * 5. PROTECTED = Acceso especial para herencia
 *    - Visible en clase actual
 *    - Visible en clases hijas
 *    - No visible desde fuera
 * 
 * 💡 ANÁLOGÍA FINAL:
 * 
 * La FAMILIA REAL:
 * - El REY (clase padre) tiene características: corona, poder, castillo
 * - El PRÍNCIPE (clase hija) HEREDA: corona, poder, castillo
 * - Pero el príncipe también tiene sus propias cosas: educación moderna, redes sociales
 * 
 * El príncipe puede:
 * - Usar lo que heredó del rey (atributos y métodos heredados)
 * - Añadir cosas nuevas (atributos y métodos propios)
 * - Modificar cómo usa lo heredado (sobrescritura)
 * - Consultar al rey cuando quiere (super)
 * 
 * Si el rey dice "tengo una corona de oro" (private), el príncipe no puede tocarla
 * directamente, pero puede pedirla al rey (getter público).
 * 
 * Esta jerarquía permite organizar el código de forma natural,
 * reutilizando lo común y especializando lo específico.
 */