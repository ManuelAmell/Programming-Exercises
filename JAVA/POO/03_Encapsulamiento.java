/**
 * ╔══════════════════════════════════════════════════════════════════════════════╗
 * ║                      POO EN JAVA - ENCAPSULAMIENTO                           ║
 * ╚══════════════════════════════════════════════════════════════════════════════╝
 * 
 * EXPLICACIÓN AL ESTILO FEYNMAN:
 * 
 * Imagina que tienes una caja fuerte. La caja tiene:
 * - Contenido VALIOSO (dinero, joyas) dentro
 * - Una PUERTA con CERRADURA de combinación
 * - Un panel EXTERIOR con botones
 * 
 * ¿Puedes acceder directamente al dinero? NO.
 * ¿Puedes meter la mano por las paredes? NO.
 * 
 * Lo que SÍ puedes hacer:
 * - Usar el panel de botones para interactuar CON LA CERRADURA
 * - Si conoces la combinación correcta, la caja te permite ver o modificar el contenido
 * - Si no la conoces, la caja te lo niega
 * 
 * ENCAPSULAMIENTO en programación es EXACTAMENTE lo mismo:
 * 
 * 1. Los ATRIBUTOS son el dinero (datos) - están PROTEGIDOS
 * 2. Los MÉTODOS son el panel de botones (interfaz pública) - son ACCESIBLES
 * 3. Los MODIFICADORES DE ACCESO son la cerradura - controlan QUIÉN puede acceder
 * 
 * ================================================================================
 *                    MODIFICADORES DE ACCESO (La "Cerradura")
 * ================================================================================
 * 
 * 1. PRIVATE (El más restrictivo)
 *    - Solo accesible DENTRO de la misma clase
 *    - Nadie fuera de la clase puede ver ni modificar
 *    - Es como el contenido de la caja fuerte
 * 
 * 2. PUBLIC (El menos restrictivo)
 *    - Accesible desde CUALQUIER parte del programa
 *    - Cualquiera puede usarlo
 *    - Es como el panel de botones de la caja fuerte
 * 
 * 3. PROTECTED (Restricción intermedia)
 *    - Accesible DENTRO de la misma clase
 *    - Accesible desde clases en el MISMO paquete
 *    - Accesible desde clases HIJAS (herencia)
 *    - Es como dar permiso a familia y amigos cercanos
 * 
 * 4. DEFAULT (Sin modificador - Restricción paquete)
 *    - Accesible DENTRO de la misma clase
 *    - Accesible desde clases en el MISMO paquete
 *    - NO accesible desde fuera del paquete
 *    - Es como solo permitir a compañeros de oficina
 * 
 * ================================================================================
 *                    GETTERS Y SETTERS (El "Panel de Control")
 * ================================================================================
 * 
 * GETTER (Accesor): Método que DEVUELVE el valor de un atributo privado
 *    - Permite LEER el valor
 *    - Controla CÓMO se devuelve (puede modificar formato)
 *    - Puede agregar VALIDACIÓN antes de devolver
 * 
 * SETTER (Mutador): Método que MODIFICA el valor de un atributo privado
 *    - Permite ESCRIBIR el valor
 *    - Puede VALIDAR el nuevo valor antes de asignar
 *    - Puede rechazar valores inválidos
 * 
 * ¿POR QUÉ USARLOS?
 * - Validación: Evitar datos incorrectos (edad negativa, saldo negativo)
 * - Control: Solo lectura (getter sin setter) o solo escritura
 * - Flexibilidad: Cambiar implementación interna sin afectar código externo
 * - Seguridad: Proteger datos sensibles
 */

public class Encapsulamiento {
    
    // ═══════════════════════════════════════════════════════════════════════
    // ATRIBUTOS PRIVATE (Protegidos/Capsulados)
    // ═══════════════════════════════════════════════════════════════════════
    // Estos atributos NO son accesibles directamente desde fuera de la clase
    // Es como el dinero dentro de la caja fuerte
    
    private String numeroCuenta;      // Número de cuenta bancaria (sensible)
    private double saldo;            // Dinero en la cuenta (protegido)
    private String titular;           // Dueño de la cuenta
    private String pin;               // Contraseña (ultra-sensible)
    private boolean activa;           // Estado de la cuenta
    
    // Atributo PUBLIC (Accesible para todos)
    // Generalmente pocos atributos son públicos
    public String nombreBanco;        // Nombre del banco (información pública)
    
    // Atributo PROTECTED (Para herencia)
    protected String tipoCuenta;     // Tipo: Ahorro, Corriente, etc.
    
    // ═══════════════════════════════════════════════════════════════════════
    // CONSTRUCTOR
    // ═══════════════════════════════════════════════════════════════════════
    public Encapsulamiento(String numeroCuenta, String titular, String pin, double saldoInicial) {
        this.numeroCuenta = numeroCuenta;
        this.titular = titular;
        this.pin = pin;  // En producción esto debería estar hasheado
        this.saldo = saldoInicial;
        this.activa = true;
        this.nombreBanco = "Banco Central";
        this.tipoCuenta = "Ahorros";
    }
    
    // ═══════════════════════════════════════════════════════════════════════
    // GETTERS (Accesores - Para LEER atributos privados)
    // ═══════════════════════════════════════════════════════════════════════
    
    /**
     * GETTER para saldo
     * Permite ver el saldo actual
     */
    public double getSaldo() {
        // Podemos agregar lógica aquí (ej: formato de moneda)
        return this.saldo;
    }
    
    /**
     * GETTER para titular
     */
    public String getTitular() {
        return this.titular;
    }
    
    /**
     * GETTER para número de cuenta
     * Podemos ocultar parte del número por seguridad
     */
    public String getNumeroCuenta() {
        // Ocultamos los primeros dígitos por seguridad
        // "1234567890" → "****7890"
        if (numeroCuenta.length() > 4) {
            return "****" + numeroCuenta.substring(numeroCuenta.length() - 4);
        }
        return numeroCuenta;
    }
    
    /**
     * GETTER para estado de cuenta
     */
    public boolean isActiva() {  // Para booleanos se usa "is" en lugar de "get"
        return this.activa;
    }
    
    /**
     * GETTER para tipo de cuenta (protected)
     * Accesible desde el mismo paquete y clases hijas
     */
    protected String getTipoCuenta() {
        return this.tipoCuenta;
    }
    
    // ═══════════════════════════════════════════════════════════════════════
    // SETTERS (Mutadores - Para MODIFICAR atributos privados)
    // ═══════════════════════════════════════════════════════════════════════
    
    /**
     * SETTER para titular
     * Valida que el nombre no esté vacío
     */
    public void setTitular(String nuevoTitular) {
        if (nuevoTitular != null && !nuevoTitular.trim().isEmpty()) {
            this.titular = nuevoTitular;
            System.out.println("✅ Titular actualizado a: " + nuevoTitular);
        } else {
            System.out.println("❌ Error: El nombre del titular no puede estar vacío");
        }
    }
    
    /**
     * SETTER para PIN
     * Valida que el PIN tenga exactamente 4 dígitos
     */
    public void setPin(String pinActual, String nuevoPin) {
        // Primero verificamos el PIN actual (autenticación)
        if (!this.pin.equals(pinActual)) {
            System.out.println("❌ Error: PIN actual incorrecto");
            return;
        }
        
        // Validamos el nuevo PIN
        if (nuevoPin != null && nuevoPin.matches("\\d{4}")) {
            this.pin = nuevoPin;
            System.out.println("✅ PIN cambiado exitosamente");
        } else {
            System.out.println("❌ Error: El PIN debe tener exactamente 4 dígitos numéricos");
        }
    }
    
    /**
     * NO hay setter para saldo directo
     * El saldo solo cambia mediante depósitos y retiros (métodos controlados)
     * Esto evita que alguien haga: cuenta.saldo = -999999 (hackeo)
     */
    
    // ═══════════════════════════════════════════════════════════════════════
    // MÉTODOS DE NEGOCIO (Lógica controlada)
    // ═══════════════════════════════════════════════════════════════════════
    // Estos métodos son la ÚNICA forma de modificar el saldo
    // Permiten validaciones y reglas de negocio
    
    /**
     * Depositar dinero
     * Valida que el monto sea positivo
     */
    public void depositar(double monto) {
        if (!activa) {
            System.out.println("❌ Error: La cuenta está inactiva");
            return;
        }
        
        if (monto > 0) {
            this.saldo += monto;
            System.out.println("✅ Depósito exitoso: +$" + monto);
            System.out.println("   Saldo actual: $" + this.saldo);
        } else {
            System.out.println("❌ Error: El monto debe ser positivo");
        }
    }
    
    /**
     * Retirar dinero
     * Valida que haya saldo suficiente y que el monto sea válido
     */
    public void retirar(double monto) {
        if (!activa) {
            System.out.println("❌ Error: La cuenta está inactiva");
            return;
        }
        
        if (monto <= 0) {
            System.out.println("❌ Error: El monto debe ser positivo");
            return;
        }
        
        if (monto > this.saldo) {
            System.out.println("❌ Error: Saldo insuficiente");
            System.out.println("   Saldo disponible: $" + this.saldo);
            System.out.println("   Monto solicitado: $" + monto);
            return;
        }
        
        this.saldo -= monto;
        System.out.println("✅ Retiro exitoso: -$" + monto);
        System.out.println("   Saldo actual: $" + this.saldo);
    }
    
    /**
     * Transferir a otra cuenta
     * Método complejo que involucra dos cuentas
     */
    public void transferir(Encapsulamiento cuentaDestino, double monto) {
        System.out.println("\n🏦 Iniciando transferencia...");
        System.out.println("   De: " + this.getNumeroCuenta());
        System.out.println("   A: " + cuentaDestino.getNumeroCuenta());
        System.out.println("   Monto: $" + monto);
        
        // Verificamos saldo
        if (monto > this.saldo) {
            System.out.println("❌ Transferencia cancelada: Saldo insuficiente\n");
            return;
        }
        
        // Realizamos la transferencia
        this.saldo -= monto;
        cuentaDestino.saldo += monto;  // Accedemos directamente porque estamos en la misma clase
        
        System.out.println("✅ Transferencia completada exitosamente\n");
    }
    
    /**
     * Mostrar información de la cuenta
     */
    public void mostrarInfo() {
        System.out.println("╔════════════════════════════════════╗");
        System.out.println("║      INFORMACIÓN DE CUENTA         ║");
        System.out.println("╠════════════════════════════════════╣");
        System.out.println("🏦 Banco: " + this.nombreBanco);  // Público
        System.out.println("👤 Titular: " + this.getTitular());
        System.out.println("💳 Cuenta: " + this.getNumeroCuenta());  // Ocultamos parte
        System.out.println("📊 Tipo: " + this.getTipoCuenta());      // Protected
        System.out.println("💰 Saldo: $" + this.getSaldo());
        System.out.println("🟢 Estado: " + (this.isActiva() ? "Activa" : "Inactiva"));
        System.out.println("╚════════════════════════════════════╝\n");
    }
    
    // ═══════════════════════════════════════════════════════════════════════
    // MÉTODO MAIN - Demostración
    // ═══════════════════════════════════════════════════════════════════════
    public static void main(String[] args) {
        System.out.println("╔══════════════════════════════════════════════════════════════╗");
        System.out.println("║           DEMOSTRACIÓN: ENCAPSULAMIENTO                      ║");
        System.out.println("╚══════════════════════════════════════════════════════════════╝\n");
        
        // Crear cuentas
        Encapsulamiento cuenta1 = new Encapsulamiento("1234567890", "Juan Pérez", "1234", 1000.0);
        Encapsulamiento cuenta2 = new Encapsulamiento("0987654321", "María García", "5678", 500.0);
        
        // ═══════════════════════════════════════════════════════════════════
        // DEMO 1: Acceso a atributos públicos
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("=== DEMO 1: Atributos PÚBLICOS ===");
        System.out.println("Nombre del banco (público): " + cuenta1.nombreBanco);
        cuenta1.nombreBanco = "Banco Internacional";
        System.out.println("Nuevo nombre: " + cuenta1.nombreBanco + "\n");
        
        // ═══════════════════════════════════════════════════════════════════
        // DEMO 2: Intentar acceso a atributos privados (ERROR)
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("=== DEMO 2: Intentar acceso directo a PRIVADOS ===");
        System.out.println("Intentando: cuenta1.saldo = 999999;");
        System.out.println("❌ ERROR DE COMPILACIÓN: 'saldo' has private access");
        System.out.println("El compilador NO permite acceso directo\n");
        
        // Usamos getters en su lugar
        System.out.println("Usando getter: cuenta1.getSaldo() = $" + cuenta1.getSaldo() + "\n");
        
        // ═══════════════════════════════════════════════════════════════════
        // DEMO 3: Validación con setters
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("=== DEMO 3: Validación en SETTERS ===");
        
        System.out.println("Intentando poner titular vacío:");
        cuenta1.setTitular("");  // Debería fallar
        
        System.out.println("\nIntentando poner titular válido:");
        cuenta1.setTitular("Juan Pérez Actualizado");  // Debería funcionar
        
        System.out.println("\nIntentando cambiar PIN con PIN incorrecto:");
        cuenta1.setPin("9999", "4321");  // PIN actual equivocado
        
        System.out.println("\nIntentando cambiar PIN con PIN correcto pero inválido:");
        cuenta1.setPin("1234", "12");  // PIN muy corto
        
        System.out.println("\nIntentando cambiar PIN correctamente:");
        cuenta1.setPin("1234", "4321");  // Correcto
        
        // ═══════════════════════════════════════════════════════════════════
        // DEMO 4: Validación en operaciones de negocio
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("\n=== DEMO 4: Validación en operaciones ===");
        cuenta1.mostrarInfo();
        
        System.out.println("Intentando depositar monto negativo:");
        cuenta1.depositar(-100);  // Debería fallar
        
        System.out.println("\nIntentando retirar más del saldo:");
        cuenta1.retirar(5000);  // Debería fallar
        
        System.out.println("\nOperaciones válidas:");
        cuenta1.depositar(500);
        cuenta1.retirar(200);
        
        // ═══════════════════════════════════════════════════════════════════
        // DEMO 5: Transferencia entre cuentas
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("\n=== DEMO 5: Transferencia entre cuentas ===");
        cuenta1.mostrarInfo();
        cuenta2.mostrarInfo();
        
        cuenta1.transferir(cuenta2, 300);
        
        cuenta1.mostrarInfo();
        cuenta2.mostrarInfo();
        
        // ═══════════════════════════════════════════════════════════════════
        // DEMO 6: Getter con lógica (ocultar información sensible)
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("=== DEMO 6: Seguridad en getters ===");
        System.out.println("Número completo de cuenta1: " + cuenta1.getNumeroCuenta());
        System.out.println("✅ El getter oculta los primeros dígitos por seguridad\n");
        
        System.out.println("╔══════════════════════════════════════════════════════════════╗");
        System.out.println("║                     FIN DE LA DEMOSTRACIÓN                   ║");
        System.out.println("╚══════════════════════════════════════════════════════════════╝");
        
        System.out.println("\n📚 RESUMEN DE MODIFICADORES:");
        System.out.println("   private   → Solo dentro de la clase (más seguro)");
        System.out.println("   protected → Clase, paquete y herencia");
        System.out.println("   default   → Clase y paquete (sin modificador)");
        System.out.println("   public    → Desde cualquier parte (menos seguro)");
    }
}

/**
 * RESUMEN AL ESTILO FEYNMAN:
 * 
 * 🔑 CONCEPTOS CLAVE:
 * 
 * 1. ENCAPSULAMIENTO = Ocultar datos + Exponer comportamientos
 *    - Los atributos son privados (protegidos)
 *    - Los métodos son públicos (interfaz de control)
 * 
 * 2. MODIFICADORES DE ACCESO = Niveles de seguridad
 *    - private: Máxima protección, mínima visibilidad
 *    - public: Mínima protección, máxima visibilidad
 *    - protected: Para herencia
 *    - default: Para paquetes
 * 
 * 3. GETTERS = Leer datos de forma controlada
 *    - Permiten leer atributos privados
 *    - Pueden modificar/formato la información
 *    - Pueden validar antes de devolver
 * 
 * 4. SETTERS = Modificar datos de forma controlada
 *    - Permiten escribir atributos privados
 *    - Validan datos antes de aceptar
 *    - Rechazan valores inválidos
 * 
 * 5. MÉTODOS DE NEGOCIO = Operaciones complejas
 *    - Encapsulan lógica de negocio
 *    - Validan reglas complejas
 *    - Mantienen consistencia de datos
 * 
 * 💡 ANÁLOGÍA FINAL:
 * 
 * La CAJA FUERTE perfecta:
 * - Contenido (atributos private): NADIE puede tocar directamente
 * - Cerradura (modificadores): Solo ciertas personas pueden abrir
 * - Panel de botones (métodos public): Interfaz segura de control
 * - Validación: Si introduces código incorrecto, no abre
 * 
 * Si alguien intenta romper la caja (acceso directo a atributos),
 * el sistema (compilador) lo impide completamente.
 * 
 * Esta protección garantiza que los datos siempre estén válidos
 * y que solo operaciones autorizadas puedan modificarlos.
 */