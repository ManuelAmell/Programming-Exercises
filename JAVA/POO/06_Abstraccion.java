/**
 * ╔══════════════════════════════════════════════════════════════════════════════╗
 * ║                       POO EN JAVA - ABSTRACCIÓN                                 ║
 * ╚══════════════════════════════════════════════════════════════════════════════╝
 * 
 * EXPLICACIÓN AL ESTILO FEYNMAN:
 * 
 * Imagina que vas a un restaurante. Ves un MENÚ con platos deliciosos:
 * - Hamburguesa gourmet
 * - Pasta al pesto
 * - Sushi fresco
 * 
 * ¿Necesitas saber CÓMO se cocina cada plato para pedirlo? NO.
 * ¿Necesitas ver la cocina, los ingredientes, las técnicas? NO.
 * 
 * Solo necesitas saber QUÉ es cada plato, no CÓMO se prepara.
 * El chef se encarga de los detalles internos.
 * 
 * ESO ES ABSTRACCIÓN:
 * - Mostrar la INTERFAZ (qué hace)
 * - Ocultar la IMPLEMENTACIÓN (cómo lo hace)
 * 
 * ================================================================================
 *                    ¿QUÉ ES LA ABSTRACCIÓN?
 * ================================================================================
 * 
 * ABSTRACCIÓN = Ocultar la complejidad interna y mostrar solo lo esencial.
 * 
 * Beneficios:
 * 1. Simplifica el uso: Sabes QUÉ hacer, no CÓMO funciona
 * 2. Reduce la complejidad: No te abrumas con detalles
 * 3. Facilita cambios: Puedes cambiar la implementación sin afectar usuarios
 * 4. Mejora mantenibilidad: Código más organizado
 * 
 * Ejemplos del mundo real:
 * - Un coche: Sabes acelerar, frenar, girar (interfaz)
 *            No sabes cómo funciona el motor internamente (implementación oculta)
 * 
 * - Un teléfono: Sabes hacer llamadas, enviar mensajes
 *               No sabes los protocolos de comunicación
 * 
 * ================================================================================
 *                    CLASES ABSTRACTAS EN JAVA
 * ================================================================================
 * 
 * Una CLASE ABSTRACTA es una clase que NO se puede instanciar directamente.
 * Es como un "molde" o "plantilla" incompleto que necesita ser completado.
 * 
 * Características:
 * 1. Se declara con 'abstract' antes de 'class'
 * 2. Puede tener métodos abstractos (sin implementación) y concretos (con implementación)
 * 3. Las clases hijas DEBEN implementar todos los métodos abstractos
 * 4. Puede tener constructores, atributos, métodos normales
 * 5. Una clase hija de abstracta debe implementar métodos abstractos O ser abstracta también
 * 
 * ¿Para qué sirven?
 * - Definir comportamientos COMUNES que todas las hijas deben tener
 * - Forzar a las hijas a implementar ciertos métodos
 * - Compartir código común entre hijas
 * 
 * ================================================================================
 *                    MÉTODOS ABSTRACTOS
 * ================================================================================
 * 
 * Un método abstracto:
 * - Solo tiene la DECLARACIÓN (nombre, parámetros, retorno)
 * - NO tiene implementación (sin llaves {})
 * - Termina con punto y coma ;
 * - Las clases hijas DEBEN implementarlo
 * 
 * Sintaxis:
 *   public abstract void metodoAbstracto();
 *          ↑        ↑                    ↑
 *       modificador abstract         sin cuerpo
 */

// ════════════════════════════════════════════════════════════════════════════
// CLASE ABSTRACTA - Figura Geométrica
// ════════════════════════════════════════════════════════════════════════════
// NO se puede crear: new Figura() ← ERROR DE COMPILACIÓN
// Es una plantilla para figuras específicas

abstract class Figura {
    // Atributos comunes a todas las figuras
    protected String nombre;
    protected String color;
    protected int numeroLados;
    
    // Constructor (las clases abstractas SÍ pueden tener constructores)
    public Figura(String nombre, String color, int numeroLados) {
        this.nombre = nombre;
        this.color = color;
        this.numeroLados = numeroLados;
        System.out.println("🏗️  Constructor de Figura ejecutado para: " + nombre);
    }
    
    // ═══════════════════════════════════════════════════════════════════════
    // MÉTODOS ABSTRACTOS (Sin implementación)
    // Las clases hijas DEBEN implementar estos métodos
    // ═══════════════════════════════════════════════════════════════════════
    
    /**
     * Calcular el área de la figura
     * Cada figura tiene su propia fórmula
     */
    public abstract double calcularArea();
    
    /**
     * Calcular el perímetro de la figura
     * Cada figura calcula de forma diferente
     */
    public abstract double calcularPerimetro();
    
    /**
     * Dibujar la figura
     * Cada figura se dibuja de forma diferente
     */
    public abstract void dibujar();
    
    // ═══════════════════════════════════════════════════════════════════════
    // MÉTODOS CONCRETOS (Con implementación)
    // Se heredan y usan directamente
    // ═══════════════════════════════════════════════════════════════════════
    
    /**
     * Mostrar información básica
     * Todas las figuras usan este mismo método
     */
    public void mostrarInfo() {
        System.out.println("╔════════════════════════════════════╗");
        System.out.println("║      INFORMACIÓN DE FIGURA         ║");
        System.out.println("╠════════════════════════════════════╣");
        System.out.println("  📐 Nombre: " + this.nombre);
        System.out.println("  🎨 Color: " + this.color);
        System.out.println("  📏 Lados: " + this.numeroLados);
        System.out.println("╚════════════════════════════════════╝");
    }
    
    /**
     * Obtener descripción
     * Método común para todas las figuras
     */
    public String obtenerDescripcion() {
        return "Soy un " + this.nombre + " de color " + this.color;
    }
    
    /**
     * Comparar áreas con otra figura
     * Funciona con CUALQUIER tipo de figura (polimorfismo)
     */
    public void compararAreaCon(Figura otra) {
        double miArea = this.calcularArea();
        double otraArea = otra.calcularArea();
        
        System.out.println("\n📊 Comparación de áreas:");
        System.out.println("   " + this.nombre + ": " + miArea + " unidades²");
        System.out.println("   " + otra.nombre + ": " + otraArea + " unidades²");
        
        if (miArea > otraArea) {
            System.out.println("   ✅ " + this.nombre + " tiene mayor área");
        } else if (miArea < otraArea) {
            System.out.println("   ✅ " + otra.nombre + " tiene mayor área");
        } else {
            System.out.println("   ⚖️  Ambas figuras tienen la misma área");
        }
    }
    
    // Getters
    public String getNombre() { return nombre; }
    public String getColor() { return color; }
    public int getNumeroLados() { return numeroLados; }
}

// ════════════════════════════════════════════════════════════════════════════
// CLASE HIJA CONCRETA - Círculo
// ════════════════════════════════════════════════════════════════════════════
// Implementa TODOS los métodos abstractos del padre

class Circulo extends Figura {
    private double radio;
    
    // Constante PI
    private static final double PI = 3.14159;
    
    public Circulo(String color, double radio) {
        // Llamamos al constructor del padre
        super("Círculo", color, 0);  // Un círculo no tiene lados
        this.radio = radio;
    }
    
    // IMPLEMENTACIÓN OBLIGATORIA de método abstracto
    @Override
    public double calcularArea() {
        // Fórmula: π × r²
        return PI * radio * radio;
    }
    
    // IMPLEMENTACIÓN OBLIGATORIA de método abstracto
    @Override
    public double calcularPerimetro() {
        // Fórmula: 2 × π × r
        return 2 * PI * radio;
    }
    
    // IMPLEMENTACIÓN OBLIGATORIA de método abstracto
    @Override
    public void dibujar() {
        System.out.println("    ***    ");
        System.out.println("  *     *  ");
        System.out.println(" *       * ");
        System.out.println(" *       * ");
        System.out.println("  *     *  ");
        System.out.println("    ***    ");
        System.out.println("   " + nombre + " (r=" + radio + ")");
    }
    
    // Método específico de Círculo
    public double getDiametro() {
        return 2 * radio;
    }
}

// ════════════════════════════════════════════════════════════════════════════
// CLASE HIJA CONCRETA - Rectángulo
// ════════════════════════════════════════════════════════════════════════════

class Rectangulo extends Figura {
    private double largo;
    private double ancho;
    
    public Rectangulo(String color, double largo, double ancho) {
        super("Rectángulo", color, 4);
        this.largo = largo;
        this.ancho = ancho;
    }
    
    @Override
    public double calcularArea() {
        // Fórmula: largo × ancho
        return largo * ancho;
    }
    
    @Override
    public double calcularPerimetro() {
        // Fórmula: 2 × (largo + ancho)
        return 2 * (largo + ancho);
    }
    
    @Override
    public void dibujar() {
        System.out.println("┌────────────┐");
        System.out.println("│            │");
        System.out.println("│            │");
        System.out.println("└────────────┘");
        System.out.println("   " + nombre + " (" + largo + "x" + ancho + ")");
    }
    
    // Método específico de Rectángulo
    public boolean esCuadrado() {
        return largo == ancho;
    }
}

// ════════════════════════════════════════════════════════════════════════════
// CLASE HIJA CONCRETA - Triángulo
// ════════════════════════════════════════════════════════════════════════════

class Triangulo extends Figura {
    private double base;
    private double altura;
    private double lado1;
    private double lado2;
    private double lado3;
    
    public Triangulo(String color, double base, double altura, 
                     double lado1, double lado2, double lado3) {
        super("Triángulo", color, 3);
        this.base = base;
        this.altura = altura;
        this.lado1 = lado1;
        this.lado2 = lado2;
        this.lado3 = lado3;
    }
    
    @Override
    public double calcularArea() {
        // Fórmula: (base × altura) / 2
        return (base * altura) / 2;
    }
    
    @Override
    public double calcularPerimetro() {
        // Suma de los tres lados
        return lado1 + lado2 + lado3;
    }
    
    @Override
    public void dibujar() {
        System.out.println("      /\\      ");
        System.out.println("     /  \\     ");
        System.out.println("    /    \\    ");
        System.out.println("   /      \\   ");
        System.out.println("  /________\\  ");
        System.out.println("   " + nombre);
    }
    
    // Método específico de Triángulo
    public String clasificarPorLados() {
        if (lado1 == lado2 && lado2 == lado3) {
            return "Equilátero";
        } else if (lado1 == lado2 || lado2 == lado3 || lado1 == lado3) {
            return "Isósceles";
        } else {
            return "Escaleno";
        }
    }
}

// ════════════════════════════════════════════════════════════════════════════
// CLASE PRINCIPAL - Demostración
// ════════════════════════════════════════════════════════════════════════════
public class Abstraccion {
    
    public static void main(String[] args) {
        System.out.println("╔══════════════════════════════════════════════════════════════╗");
        System.out.println("║           DEMOSTRACIÓN: ABSTRACCIÓN                            ║");
        System.out.println("╚══════════════════════════════════════════════════════════════╝\n");
        
        // ═══════════════════════════════════════════════════════════════════
        // DEMO 1: Intentar crear objeto de clase abstracta (ERROR)
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("=== DEMO 1: Clases Abstractas NO se instancian ===");
        System.out.println("Intentando: Figura figura = new Figura(\"genérica\", \"rojo\", 4);");
        System.out.println("❌ ERROR: Cannot instantiate the type Figura");
        System.out.println("   Las clases abstractas son plantillas, no objetos reales\n");
        
        // ═══════════════════════════════════════════════════════════════════
        // DEMO 2: Crear objetos de clases hijas concretas
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("=== DEMO 2: Creando objetos de clases concretas ===\n");
        
        // SÍ podemos crear objetos de las clases hijas
        Circulo circulo = new Circulo("Rojo", 5.0);
        Rectangulo rectangulo = new Rectangulo("Azul", 10.0, 5.0);
        Triangulo triangulo = new Triangulo("Verde", 6.0, 4.0, 5.0, 5.0, 6.0);
        
        // ═══════════════════════════════════════════════════════════════════
        // DEMO 3: Uso de métodos abstractos implementados
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("=== DEMO 3: Métodos abstractos implementados ===\n");
        
        System.out.println("Círculo:");
        circulo.mostrarInfo();
        System.out.println("   📏 Área: " + circulo.calcularArea());
        System.out.println("   📐 Perímetro: " + circulo.calcularPerimetro());
        circulo.dibujar();
        
        System.out.println("\nRectángulo:");
        rectangulo.mostrarInfo();
        System.out.println("   📏 Área: " + rectangulo.calcularArea());
        System.out.println("   📐 Perímetro: " + rectangulo.calcularPerimetro());
        rectangulo.dibujar();
        
        System.out.println("\nTriángulo:");
        triangulo.mostrarInfo();
        System.out.println("   📏 Área: " + triangulo.calcularArea());
        System.out.println("   📐 Perímetro: " + triangulo.calcularPerimetro());
        System.out.println("   🔺 Tipo: " + triangulo.clasificarPorLados());
        triangulo.dibujar();
        
        // ═══════════════════════════════════════════════════════════════════
        // DEMO 4: Polimorfismo con clases abstractas
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("\n=== DEMO 4: Polimorfismo con referencia abstracta ===");
        System.out.println("Array de Figuras con diferentes tipos reales:\n");
        
        Figura[] figuras = new Figura[3];
        figuras[0] = new Circulo("Amarillo", 3.0);
        figuras[1] = new Rectangulo("Naranja", 8.0, 4.0);
        figuras[2] = new Triangulo("Morado", 5.0, 3.0, 4.0, 4.0, 5.0);
        
        // Cada figura calcula su área de forma diferente
        System.out.println("📊 Calculando áreas:");
        for (Figura figura : figuras) {
            System.out.println("   " + figura.getNombre() + ": " + 
                             figura.calcularArea() + " unidades²");
        }
        
        // ═══════════════════════════════════════════════════════════════════
        // DEMO 5: Uso de métodos concretos heredados
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("\n=== DEMO 5: Métodos concretos heredados ===");
        
        System.out.println("Descripción de cada figura:");
        for (Figura figura : figuras) {
            System.out.println("   " + figura.obtenerDescripcion());
        }
        
        // ═══════════════════════════════════════════════════════════════════
        // DEMO 6: Comparación de áreas (método en clase abstracta)
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("\n=== DEMO 6: Comparación de figuras ===");
        figuras[0].compararAreaCon(figuras[1]);
        
        // ═══════════════════════════════════════════════════════════════════
        // DEMO 7: Dibujar todas las figuras
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("\n=== DEMO 7: Dibujando todas las figuras ===\n");
        for (Figura figura : figuras) {
            System.out.println("🎨 " + figura.getNombre() + ":");
            figura.dibujar();
            System.out.println();
        }
        
        // ═══════════════════════════════════════════════════════════════════
        // RESUMEN
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("╔══════════════════════════════════════════════════════════════╗");
        System.out.println("║                     FIN DE LA DEMOSTRACIÓN                   ║");
        System.out.println("╚══════════════════════════════════════════════════════════════╝");
        
        System.out.println("\n📚 RESUMEN DE ABSTRACCIÓN:");
        System.out.println("   • Clase abstracta: No se puede instanciar");
        System.out.println("   • Método abstracto: Solo declaración, sin implementación");
        System.out.println("   • Las hijas DEBEN implementar métodos abstractos");
        System.out.println("   • Permite definir comportamientos comunes");
        System.out.println("   • Oculta complejidad, muestra solo lo esencial");
        System.out.println("\n💡 DIFERENCIA CLAVE:");
        System.out.println("   • Herencia: 'ES UN' (Perro ES UN Animal)");
        System.out.println("   • Abstracción: Define QUÉ hacer, no CÓMO");
        System.out.println("   • La implementación específica va en las clases hijas");
    }
}

/**
 * RESUMEN AL ESTILO FEYNMAN:
 * 
 * 🔑 CONCEPTOS CLAVE:
 * 
 * 1. CLASE ABSTRACTA = Molde incompleto
 *    - No se puede crear objetos directamente
 *    - Define comportamientos que DEBEN existir
 *    - Deja la implementación a las clases hijas
 * 
 * 2. MÉTODO ABSTRACTO = Promesa de implementación
 *    - Solo tiene firma (nombre, parámetros, retorno)
 *    - Sin cuerpo { }
 *    - Las hijas DEBEN implementarlo
 * 
 * 3. MÉTODO CONCRETO = Comportamiento compartido
 *    - Tiene implementación completa
 *    - Todas las hijas lo heredan igual
 *    - Evita duplicar código
 * 
 * 4. ABSTRACCIÓN = Simplificación
 *    - Sabes QUÉ hace, no CÓMO lo hace
 *    - Interfaz clara, implementación oculta
 *    - Facilita el uso y mantenimiento
 * 
 * 💡 ANÁLOGÍA FINAL:
 * 
 * El CONTROL REMOTO de una casa inteligente:
 * 
 * CLASE ABSTRACTA: "DispositivoInteligente"
 * - Métodos abstractos:
 *   • encender()     ← Cada dispositivo enciende diferente
 *   • apagar()       ← Cada dispositivo apaga diferente
 *   • obtenerEstado() ← Cada dispositivo reporta diferente
 * 
 * - Métodos concretos:
 *   • conectarWifi()   ← Todos conectan igual
 *   • mostrarInfo()    ← Formato común para todos
 *   • diagnosticar()   ← Proceso común de diagnóstico
 * 
 * CLASES HIJAS CONCRETAS:
 * - Luz: implementa encender() → enciende bombilla
 * - Termostato: implementa encender() → activa calefacción
 * - Alarma: implementa encender() → activa sensores
 * 
 * El control remoto (código cliente) solo sabe que puede:
 * - Llamar encender() a CUALQUIER dispositivo
 * - No necesita saber SI es luz, termostato o alarma
 * - Cada dispositivo implementa a su manera
 * 
 * La abstracción permite que agregues nuevos dispositivos
 * (Cortinas, Cámaras, etc.) sin cambiar el control remoto.
 */