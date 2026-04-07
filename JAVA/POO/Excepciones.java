/**
 * ╔══════════════════════════════════════════════════════════════════════════════╗
 * ║                    POO EN JAVA - EXCEPCIONES                               ║
 * ╚══════════════════════════════════════════════════════════════════════════════╝
 * 
 * EXPLICACIÓN AL ESTILO FEYNMAN:
 * 
 * Imagina que estás conduciendo un coche. De repente ves un BACHE en la carretera.
 * Tienes dos opciones:
 * 
 * 1. NO hacer nada → El coche cae en el bache, se daña, accidente grave ❌
 * 2. Frenar o esquivar → Evitas el problema, sigues tu camino ✅
 * 
 * En programación, las EXCEPCIONES son como esos baches:
 * - Son problemas que ocurren durante la ejecución
 * - Si no los manejas, el programa se "estrella" (termina abruptamente)
 * - Si los manejas, el programa puede recuperarse y continuar
 * 
 * ================================================================================
 *                    ¿QUÉ ES UNA EXCEPCIÓN?
 * ================================================================================
 * 
 * EXCEPCIÓN = Evento que interrumpe el flujo normal del programa.
 * 
 * Cuando ocurre una excepción:
 * 1. Se crea un objeto con información del error
 * 2. El programa busca quién puede manejarlo
 * 3. Si nadie lo maneja, el programa termina con error
 * 
 * Ejemplos de excepciones:
 * - Dividir entre cero
 * - Intentar acceder a una posición inválida de un array
 * - Abrir un archivo que no existe
 * - Convertir texto a número cuando el texto no es numérico
 * 
 * ================================================================================
 *                    JERARQUÍA DE EXCEPCIONES
 * ================================================================================
 * 
 * Throwable (clase base)
 * ├── Error (errores graves del sistema)
 * │   ├── OutOfMemoryError (sin memoria)
 * │   ├── StackOverflowError (desbordamiento de pila)
 * │   └── ... (otros errores fatales)
 * │
 * └── Exception (excepciones que podemos manejar)
 *     ├── RuntimeException (excepciones NO chequeadas)
 *     │   ├── NullPointerException (objeto nulo)
 *     │   ├── ArrayIndexOutOfBoundsException (índice inválido)
 *     │   ├── ArithmeticException (error matemático)
 *     │   ├── IllegalArgumentException (argumento ilegal)
 *     │   ├── NumberFormatException (formato de número inválido)
 *     │   ├── ClassCastException (casting inválido)
 *     │   └── ... (otras excepciones de tiempo de ejecución)
 *     │
 *     └── Excepciones CHEQUEADAS (deben declararse o capturarse)
 *         ├── IOException (error de entrada/salida)
 *         │   ├── FileNotFoundException (archivo no encontrado)
 *         │   ├── EOFException (fin de archivo inesperado)
 *         │   └── ... (otras IOExceptions)
 *         │
 *         ├── SQLException (error de base de datos)
 *         ├── ClassNotFoundException (clase no encontrada)
 *         ├── InterruptedException (interrupción de hilo)
 *         ├── ParseException (error de parseo)
 *         └── ... (otras excepciones chequeadas)
 * 
 * ================================================================================
 *                    EXCEPCIONES CHEQUEADAS vs NO CHEQUEADAS
 * ================================================================================
 * 
 * CHEQUEADAS (Checked):
 *   - El compilador OBLIGA a manejarlas
 *   - Usan 'throws' en la declaración del método
 *   - O capturas con try-catch, o propagas con throws
 *   - Ejemplo: IOException, SQLException
 * 
 * NO CHEQUEADAS (Unchecked):
 *   - El compilador NO obliga a manejarlas
 *   - Son RuntimeException y sus subclases
 *   - Puedes manejarlas si quieres, pero no es obligatorio
 *   - Ejemplo: NullPointerException, ArrayIndexOutOfBoundsException
 * 
 * ================================================================================
 *                    MANEJO DE EXCEPCIONES
 * ================================================================================
 * 
 * BLOQUE TRY-CATCH:
 * 
 *   try {
 *       // Código que puede lanzar excepción
 *   } catch (TipoExcepcion e) {
 *       // Código que maneja la excepción
 *   }
 * 
 * BLOQUE FINALLY:
 * 
 *   try {
 *       // Código
 *   } catch (Excepcion e) {
 *       // Manejo
 *   } finally {
 *       // Siempre se ejecuta, ocurra o no excepción
 *       // Útil para liberar recursos
 *   }
 * 
 * MULTI-CATCH:
 * 
 *   try {
 *       // Código
 *   } catch (ExcepcionA | ExcepcionB e) {
 *       // Manejo de ambas
 *   }
 * 
 * THROWS:
 *   - Declara que un método PUEDE lanzar excepciones
 *   - Delega el manejo al llamador
 * 
 * THROW:
 *   - Lanza una excepción manualmente
 *   - throw new MiExcepcion("mensaje");
 */

import java.io.*;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Excepciones {
    
    // ═══════════════════════════════════════════════════════════════════════
    // MÉTODO MAIN - Demostración completa
    // ═══════════════════════════════════════════════════════════════════════
    public static void main(String[] args) {
        System.out.println("╔══════════════════════════════════════════════════════════════╗");
        System.out.println("║           DEMOSTRACIÓN: EXCEPCIONES                        ║");
        System.out.println("╚══════════════════════════════════════════════════════════════╝\n");
        
        Scanner scanner = new Scanner(System.in);
        
        // ═══════════════════════════════════════════════════════════════════
        // SECCIÓN 1: EXCEPCIONES NO CHEQUEADAS (Unchecked)
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("╔════════════════════════════════════════════════════════════╗");
        System.out.println("║  SECCIÓN 1: EXCEPCIONES NO CHEQUEADAS (Unchecked)         ║");
        System.out.println("╚════════════════════════════════════════════════════════════╝\n");
        
        // 1.1 ArithmeticException
        System.out.println("1️⃣  ArithmeticException - División por cero");
        System.out.println("─────────────────────────────────────────────────");
        try {
            int resultado = 10 / 0;  // ¡División por cero!
            System.out.println("Resultado: " + resultado);  // Nunca se ejecuta
        } catch (ArithmeticException e) {
            System.out.println("❌ EXCEPCIÓN CAPTURADA: " + e.getClass().getSimpleName());
            System.out.println("   Mensaje: " + e.getMessage());
            System.out.println("   Causa: No se puede dividir entre cero\n");
        }
        
        // 1.2 NullPointerException
        System.out.println("2️⃣  NullPointerException - Acceso a objeto nulo");
        System.out.println("─────────────────────────────────────────────────");
        try {
            String texto = null;
            int longitud = texto.length();  // ¡texto es null!
            System.out.println("Longitud: " + longitud);  // Nunca se ejecuta
        } catch (NullPointerException e) {
            System.out.println("❌ EXCEPCIÓN CAPTURADA: " + e.getClass().getSimpleName());
            System.out.println("   Mensaje: " + e.getMessage());
            System.out.println("   Causa: Intentando usar un objeto que es null\n");
        }
        
        // 1.3 ArrayIndexOutOfBoundsException
        System.out.println("3️⃣  ArrayIndexOutOfBoundsException - Índice inválido");
        System.out.println("─────────────────────────────────────────────────");
        try {
            int[] numeros = {1, 2, 3};
            int valor = numeros[10];  // ¡Índice 10 no existe!
            System.out.println("Valor: " + valor);  // Nunca se ejecuta
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("❌ EXCEPCIÓN CAPTURADA: " + e.getClass().getSimpleName());
            System.out.println("   Mensaje: " + e.getMessage());
            System.out.println("   Causa: El array tiene 3 elementos (índices 0-2), pedimos el 10\n");
        }
        
        // 1.4 StringIndexOutOfBoundsException
        System.out.println("4️⃣  StringIndexOutOfBoundsException - Índice de string inválido");
        System.out.println("─────────────────────────────────────────────────");
        try {
            String nombre = "Juan";
            char letra = nombre.charAt(10);  // "Juan" solo tiene índices 0-3
            System.out.println("Letra: " + letra);
        } catch (StringIndexOutOfBoundsException e) {
            System.out.println("❌ EXCEPCIÓN CAPTURADA: " + e.getClass().getSimpleName());
            System.out.println("   Mensaje: " + e.getMessage());
            System.out.println("   Causa: String 'Juan' tiene 4 caracteres, pedimos el índice 10\n");
        }
        
        // 1.5 NumberFormatException
        System.out.println("5️⃣  NumberFormatException - Formato de número inválido");
        System.out.println("─────────────────────────────────────────────────");
        try {
            String entrada = "abc123";
            int numero = Integer.parseInt(entrada);  // ¡"abc123" no es número!
            System.out.println("Número: " + numero);
        } catch (NumberFormatException e) {
            System.out.println("❌ EXCEPCIÓN CAPTURADA: " + e.getClass().getSimpleName());
            System.out.println("   Mensaje: " + e.getMessage());
            System.out.println("   Causa: Intentando convertir 'abc123' a número entero\n");
        }
        
        // 1.6 IllegalArgumentException
        System.out.println("6️⃣  IllegalArgumentException - Argumento ilegal");
        System.out.println("─────────────────────────────────────────────────");
        try {
            crearPersona("", -5);  // Nombre vacío y edad negativa
        } catch (IllegalArgumentException e) {
            System.out.println("❌ EXCEPCIÓN CAPTURADA: " + e.getClass().getSimpleName());
            System.out.println("   Mensaje: " + e.getMessage());
            System.out.println("   Causa: Argumentos no válidos para crear persona\n");
        }
        
        // 1.7 ClassCastException
        System.out.println("7️⃣  ClassCastException - Casting inválido");
        System.out.println("─────────────────────────────────────────────────");
        try {
            Object objeto = "Soy un String";
            Integer numero = (Integer) objeto;  // ¡No se puede convertir String a Integer!
            System.out.println("Número: " + numero);
        } catch (ClassCastException e) {
            System.out.println("❌ EXCEPCIÓN CAPTURADA: " + e.getClass().getSimpleName());
            System.out.println("   Mensaje: " + e.getMessage());
            System.out.println("   Causa: Intentando convertir String a Integer\n");
        }
        
        // 1.8 IllegalStateException
        System.out.println("8️⃣  IllegalStateException - Estado inválido del objeto");
        System.out.println("─────────────────────────────────────────────────");
        try {
            Contador contador = new Contador();
            contador.decrementar();  // Intenta decrementar sin haber incrementado
        } catch (IllegalStateException e) {
            System.out.println("❌ EXCEPCIÓN CAPTURADA: " + e.getClass().getSimpleName());
            System.out.println("   Mensaje: " + e.getMessage());
            System.out.println("   Causa: El objeto no está en estado válido para esta operación\n");
        }
        
        // ═══════════════════════════════════════════════════════════════════
        // SECCIÓN 2: EXCEPCIONES CHEQUEADAS (Checked)
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("\n╔════════════════════════════════════════════════════════════╗");
        System.out.println("║  SECCIÓN 2: EXCEPCIONES CHEQUEADAS (Checked)              ║");
        System.out.println("╚════════════════════════════════════════════════════════════╝\n");
        
        // 2.1 FileNotFoundException
        System.out.println("1️⃣  FileNotFoundException - Archivo no encontrado");
        System.out.println("─────────────────────────────────────────────────");
        try {
            FileReader archivo = new FileReader("archivo_inexistente.txt");
            System.out.println("Archivo abierto");
        } catch (FileNotFoundException e) {
            System.out.println("❌ EXCEPCIÓN CAPTURADA: " + e.getClass().getSimpleName());
            System.out.println("   Mensaje: " + e.getMessage());
            System.out.println("   Causa: El archivo no existe en la ruta especificada\n");
        }
        
        // 2.2 IOException
        System.out.println("2️⃣  IOException - Error de entrada/salida");
        System.out.println("─────────────────────────────────────────────────");
        try {
            FileWriter escritor = new FileWriter("/directorio_protegido/archivo.txt");
            System.out.println("Archivo creado");
            escritor.close();
        } catch (IOException e) {
            System.out.println("❌ EXCEPCIÓN CAPTURADA: " + e.getClass().getSimpleName());
            System.out.println("   Mensaje: " + e.getMessage());
            System.out.println("   Causa: No se puede escribir en esa ubicación\n");
        }
        
        // 2.3 ClassNotFoundException
        System.out.println("3️⃣  ClassNotFoundException - Clase no encontrada");
        System.out.println("─────────────────────────────────────────────────");
        try {
            Class.forName("com.ejemplo.ClaseInexistente");
            System.out.println("Clase cargada");
        } catch (ClassNotFoundException e) {
            System.out.println("❌ EXCEPCIÓN CAPTURADA: " + e.getClass().getSimpleName());
            System.out.println("   Mensaje: " + e.getMessage());
            System.out.println("   Causa: La clase no está en el classpath\n");
        }
        
        // 2.4 InterruptedException
        System.out.println("4️⃣  InterruptedException - Hilo interrumpido");
        System.out.println("─────────────────────────────────────────────────");
        try {
            System.out.println("   ⏰ Esperando 3 segundos...");
            Thread.sleep(3000);
            System.out.println("   ⏰ Tiempo completado");
        } catch (InterruptedException e) {
            System.out.println("❌ EXCEPCIÓN CAPTURADA: " + e.getClass().getSimpleName());
            System.out.println("   Mensaje: " + e.getMessage());
            System.out.println("   Causa: El hilo fue interrumpido durante el sleep\n");
        }
        
        // ═══════════════════════════════════════════════════════════════════
        // SECCIÓN 3: MANEJO CON FINALLY
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("\n╔════════════════════════════════════════════════════════════╗");
        System.out.println("║  SECCIÓN 3: BLOQUE FINALLY                                ║");
        System.out.println("╚════════════════════════════════════════════════════════════╝\n");
        
        System.out.println("Bloque finally SIEMPRE se ejecuta, ocurra o no excepción:\n");
        
        System.out.println("Ejemplo 1: Con excepción");
        try {
            int x = 5 / 0;
        } catch (ArithmeticException e) {
            System.out.println("   ✓ Catch: Excepción manejada");
        } finally {
            System.out.println("   ✓ Finally: Siempre se ejecuta (liberando recursos)\n");
        }
        
        System.out.println("Ejemplo 2: Sin excepción");
        try {
            int x = 5 / 1;
            System.out.println("   ✓ Try: Código ejecutado sin problemas");
        } catch (ArithmeticException e) {
            System.out.println("   ✓ Catch: No se ejecuta (no hay excepción)");
        } finally {
            System.out.println("   ✓ Finally: Aún así se ejecuta\n");
        }
        
        System.out.println("Ejemplo 3: Cerrando archivo (uso real)");
        BufferedReader lector = null;
        try {
            lector = new BufferedReader(new FileReader("archivo.txt"));
            String linea = lector.readLine();
            System.out.println("   ✓ Archivo leído: " + linea);
        } catch (IOException e) {
            System.out.println("   ✗ No se pudo leer el archivo (no existe)");
        } finally {
            try {
                if (lector != null) {
                    lector.close();
                    System.out.println("   ✓ Finally: Archivo cerrado correctamente\n");
                }
            } catch (IOException e) {
                System.out.println("   ✗ Error al cerrar archivo\n");
            }
        }
        
        // ═══════════════════════════════════════════════════════════════════
        // SECCIÓN 4: MULTI-CATCH
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("\n╔════════════════════════════════════════════════════════════╗");
        System.out.println("║  SECCIÓN 4: MULTI-CATCH                                   ║");
        System.out.println("╚════════════════════════════════════════════════════════════╝\n");
        
        System.out.println("Capturando múltiples excepciones en un solo catch:\n");
        
        try {
            String entrada = null;
            if (entrada == null) {
                throw new NullPointerException("Entrada es nula");
            }
            int num = Integer.parseInt(entrada) / 0;
        } catch (ArithmeticException | NullPointerException | NumberFormatException e) {
            System.out.println("✓ Excepción capturada: " + e.getClass().getSimpleName());
            System.out.println("  Mensaje: " + e.getMessage() + "\n");
        }
        
        // ═══════════════════════════════════════════════════════════════════
        // SECCIÓN 5: LANZAR EXCEPCIONES (THROW)
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("\n╔════════════════════════════════════════════════════════════╗");
        System.out.println("║  SECCIÓN 5: LANZAR EXCEPCIONES MANUALMENTE (THROW)        ║");
        System.out.println("╚════════════════════════════════════════════════════════════╝\n");
        
        System.out.println("Usando 'throw' para lanzar excepciones manualmente:\n");
        
        try {
            validarEdad(15);
        } catch (IllegalArgumentException e) {
            System.out.println("   ✓ Excepción lanzada manualmente: " + e.getMessage() + "\n");
        }
        
        // ═══════════════════════════════════════════════════════════════════
        // SECCIÓN 6: PROPAGACIÓN (THROWS)
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("\n╔════════════════════════════════════════════════════════════╗");
        System.out.println("║  SECCIÓN 6: PROPAGACIÓN DE EXCEPCIONES (THROWS)           ║");
        System.out.println("╚════════════════════════════════════════════════════════════╝\n");
        
        System.out.println("Usando 'throws' para delegar el manejo al llamador:\n");
        
        try {
            metodoQuePropaga();
        } catch (IOException e) {
            System.out.println("   ✓ Excepción propagada y capturada en main: " + e.getMessage() + "\n");
        }
        
        // ═══════════════════════════════════════════════════════════════════
        // SECCIÓN 7: EXCEPCIONES PERSONALIZADAS
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("\n╔════════════════════════════════════════════════════════════╗");
        System.out.println("║  SECCIÓN 7: EXCEPCIONES PERSONALIZADAS                    ║");
        System.out.println("╚════════════════════════════════════════════════════════════╝\n");
        
        System.out.println("Creando nuestras propias excepciones:\n");
        
        try {
            retirarDinero(1000, 1500);
        } catch (SaldoInsuficienteException e) {
            System.out.println("❌ EXCEPCIÓN PERSONALIZADA: " + e.getClass().getSimpleName());
            System.out.println("   Mensaje: " + e.getMessage());
            System.out.println("   Saldo disponible: $" + e.getSaldoDisponible());
            System.out.println("   Monto solicitado: $" + e.getMontoSolicitado());
            System.out.println("   Déficit: $" + e.getDeficit() + "\n");
        }
        
        try {
            validarContrasena("123");
        } catch (ContrasenaInvalidaException e) {
            System.out.println("❌ EXCEPCIÓN PERSONALIZADA: " + e.getClass().getSimpleName());
            System.out.println("   Mensaje: " + e.getMessage());
            System.out.println("   Longitud actual: " + e.getLongitudActual());
            System.out.println("   Longitud mínima requerida: " + e.getLongitudMinima() + "\n");
        }
        
        // ═══════════════════════════════════════════════════════════════════
        // SECCIÓN 8: TRY-WITH-RESOURCES (Java 7+)
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("\n╔════════════════════════════════════════════════════════════╗");
        System.out.println("║  SECCIÓN 8: TRY-WITH-RESOURCES (Java 7+)                  ║");
        System.out.println("╚════════════════════════════════════════════════════════════╝\n");
        
        System.out.println("Cerrando recursos automáticamente:\n");
        
        System.out.println("Forma antigua (con finally explícito):");
        BufferedReader br = null;
        try {
            br = new BufferedReader(new FileReader("test.txt"));
            System.out.println("   ✓ Archivo procesado");
        } catch (IOException e) {
            System.out.println("   ✗ Error: " + e.getMessage());
        } finally {
            if (br != null) {
                try {
                    br.close();
                    System.out.println("   ✓ Recurso cerrado en finally\n");
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
        
        System.out.println("Forma moderna (try-with-resources):");
        try (BufferedReader br2 = new BufferedReader(new FileReader("test.txt"))) {
            System.out.println("   ✓ Archivo procesado");
            System.out.println("   ✓ Recurso se cierra automáticamente al salir del try\n");
        } catch (IOException e) {
            System.out.println("   ✗ Error: " + e.getMessage() + "\n");
        }
        
        // ═══════════════════════════════════════════════════════════════════
        // SECCIÓN 9: ERRORES (NO EXCEPCIONES)
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("\n╔════════════════════════════════════════════════════════════╗");
        System.out.println("║  SECCIÓN 9: ERRORES (NO DEBEN CAPTURARSE)                 ║");
        System.out.println("╚════════════════════════════════════════════════════════════╝\n");
        
        System.out.println("Errores graves que generalmente no se capturan:\n");
        
        System.out.println("• OutOfMemoryError: Se acabó la memoria de la JVM");
        System.out.println("• StackOverflowError: Llamadas recursivas infinitas");
        System.out.println("• VirtualMachineError: Error interno de la JVM");
        System.out.println("• LinkageError: Problemas de vinculación de clases");
        System.out.println("• AssertionError: Falló una aserción\n");
        
        System.out.println("⚠️  Estos errores indican problemas graves que");
        System.out.println("    generalmente NO pueden recuperarse.");
        System.out.println("    No se capturan con try-catch normal.\n");
        
        // ═══════════════════════════════════════════════════════════════════
        // RESUMEN FINAL
        // ═══════════════════════════════════════════════════════════════════
        System.out.println("╔════════════════════════════════════════════════════════════╗");
        System.out.println("║                     FIN DE LA DEMOSTRACIÓN                ║");
        System.out.println("╚════════════════════════════════════════════════════════════╝");
        
        System.out.println("\n📚 RESUMEN DE EXCEPCIONES:\n");
        
        System.out.println("✅ EXCEPCIONES NO CHEQUEADAS (Unchecked):");
        System.out.println("   • RuntimeException y subclases");
        System.out.println("   • No obliga a manejarlas");
        System.out.println("   • Ejemplos: NullPointerException, ArrayIndexOutOfBoundsException,");
        System.out.println("               ArithmeticException, NumberFormatException");
        System.out.println();
        
        System.out.println("✅ EXCEPCIONES CHEQUEADAS (Checked):");
        System.out.println("   • Exception (excepto RuntimeException)");
        System.out.println("   • Obliga a usar try-catch o throws");
        System.out.println("   • Ejemplos: IOException, SQLException, ClassNotFoundException");
        System.out.println();
        
        System.out.println("✅ BLOQUES:");
        System.out.println("   • try: Código que puede lanzar excepción");
        System.out.println("   • catch: Maneja la excepción");
        System.out.println("   • finally: Siempre se ejecuta");
        System.out.println("   • try-with-resources: Cierra recursos automáticamente");
        System.out.println();
        
        System.out.println("✅ PALABRAS CLAVE:");
        System.out.println("   • throw: Lanza excepción manualmente");
        System.out.println("   • throws: Declara que método propaga excepción");
        System.out.println();
        
        System.out.println("✅ MEJORES PRÁCTICAS:");
        System.out.println("   • Capturar excepciones específicas, no solo Exception");
        System.out.println("   • Usar finally o try-with-resources para recursos");
        System.out.println("   • Crear excepciones personalizadas para tu dominio");
        System.out.println("   • Documentar con @throws en javadoc");
        System.out.println("   • No capturar Throwable o Error sin necesidad");
        
        scanner.close();
    }
    
    // ═══════════════════════════════════════════════════════════════════════
    // MÉTODOS AUXILIARES
    // ═══════════════════════════════════════════════════════════════════════
    
    static void crearPersona(String nombre, int edad) {
        if (nombre == null || nombre.trim().isEmpty()) {
            throw new IllegalArgumentException("El nombre no puede estar vacío");
        }
        if (edad < 0) {
            throw new IllegalArgumentException("La edad no puede ser negativa");
        }
        System.out.println("✓ Persona creada: " + nombre + ", " + edad + " años");
    }
    
    static void validarEdad(int edad) {
        if (edad < 18) {
            throw new IllegalArgumentException("Debes ser mayor de edad (tienes " + edad + ")");
        }
    }
    
    static void metodoQuePropaga() throws IOException {
        throw new IOException("Error de E/S simulado");
    }
    
    static void retirarDinero(double saldo, double monto) throws SaldoInsuficienteException {
        if (monto > saldo) {
            throw new SaldoInsuficienteException(saldo, monto);
        }
        System.out.println("✓ Retiro exitoso: $" + monto);
    }
    
    static void validarContrasena(String contrasena) throws ContrasenaInvalidaException {
        if (contrasena.length() < 8) {
            throw new ContrasenaInvalidaException(contrasena.length(), 8);
        }
        System.out.println("✓ Contraseña válida");
    }
}

// ════════════════════════════════════════════════════════════════════════════
// CLASE CONTADOR (Para ejemplo de IllegalStateException)
// ════════════════════════════════════════════════════════════════════════════

class Contador {
    private int valor;
    private boolean incrementado;
    
    public void incrementar() {
        valor++;
        incrementado = true;
        System.out.println("   Contador: " + valor);
    }
    
    public void decrementar() {
        if (!incrementado) {
            throw new IllegalStateException("No puedes decrementar sin haber incrementado primero");
        }
        valor--;
        System.out.println("   Contador: " + valor);
    }
}

// ════════════════════════════════════════════════════════════════════════════
// EXCEPCIÓN PERSONALIZADA 1 - Checked
// ════════════════════════════════════════════════════════════════════════════

class SaldoInsuficienteException extends Exception {
    private double saldoDisponible;
    private double montoSolicitado;
    
    public SaldoInsuficienteException(double saldo, double monto) {
        super("Saldo insuficiente para realizar la operación");
        this.saldoDisponible = saldo;
        this.montoSolicitado = monto;
    }
    
    public double getSaldoDisponible() {
        return saldoDisponible;
    }
    
    public double getMontoSolicitado() {
        return montoSolicitado;
    }
    
    public double getDeficit() {
        return montoSolicitado - saldoDisponible;
    }
}

// ════════════════════════════════════════════════════════════════════════════
// EXCEPCIÓN PERSONALIZADA 2 - Unchecked
// ════════════════════════════════════════════════════════════════════════════

class ContrasenaInvalidaException extends RuntimeException {
    private int longitudActual;
    private int longitudMinima;
    
    public ContrasenaInvalidaException(int actual, int minima) {
        super("La contraseña no cumple con los requisitos de longitud");
        this.longitudActual = actual;
        this.longitudMinima = minima;
    }
    
    public int getLongitudActual() {
        return longitudActual;
    }
    
    public int getLongitudMinima() {
        return longitudMinima;
    }
}

/**
 * RESUMEN AL ESTILO FEYNMAN:
 * 
 * 🔑 CONCEPTOS CLAVE:
 * 
 * 1. EXCEPCIÓN = Problema en tiempo de ejecución
 *    - Interrumpe el flujo normal del programa
 *    - Si no se maneja, el programa termina
 *    - Permite recuperación y continuidad
 * 
 * 2. TIPOS DE EXCEPCIONES:
 *    • Checked: Obliga a manejarlas (IOException, SQLException)
 *    • Unchecked: No obliga (RuntimeException y subclases)
 *    • Errors: Problemas graves del sistema
 * 
 * 3. MANEJO BÁSICO:
 *    • try-catch: Captura y maneja
 *    • throws: Propaga la responsabilidad
 *    • throw: Lanza manualmente
 *    • finally: Siempre se ejecuta
 * 
 * 4. JERARQUÍA:
 *    • Throwable (raíz)
 *      ├── Error (problemas graves)
 *      └── Exception (problemas manejables)
 *          ├── RuntimeException (unchecked)
 *          └── Otras (checked)
 * 
 * 5. MEJORES PRÁCTICAS:
 *    • Capturar lo más específico posible
 *    • Usar finally para liberar recursos
 *    • Crear excepciones personalizadas
 *    • Documentar con @throws
 *    • No ignorar excepciones (catch vacío)
 * 
 * 💡 ANÁLOGÍA FINAL:
 * 
 * Un RESTAURANTE:
 * 
 * • El CHEF (try) prepara la comida
 *   - Si algo sale mal (carne quemada), lanza EXCEPCIÓN
 * 
 * • El CHEF JEFE (catch) maneja el problema:
 *   - "Esta carne está quemada, prepara otra"
 *   - El cliente nunca se entera del problema
 * 
 * • El LIMPIEZA (finally) siempre:
 *   - Limpia la mesa, ocurra o no error
 *   - Nunca se olvida de limpiar
 * 
 * • El GERENTE (throws) delega:
 *   - "Si no hay ingredientes, avísame a mí"
 *   - No resuelve él, pasa al de arriba
 * 
 * • El MOZZARELLA (throw) personaliza:
 *   - "¡No hay queso mozzarella!" (excepción específica)
 *   - Mejor que "¡Error de ingrediente!" (genérico)
 * 
 * Las excepciones permiten que tu programa sea ROBUSTO
 * ante situaciones inesperadas, sin "colapsar" por
 * cada pequeño problema.
 */