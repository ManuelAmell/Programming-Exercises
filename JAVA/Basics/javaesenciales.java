import java.util.ArrayList;
import java.util.Scanner;

// ============================================================
// CLASES Y OBJETOS
// Una clase es el molde. Define qué datos tiene y qué hace.
// ============================================================

class Producto {

    // --------------------------------------------------------
    // ENCAPSULAMIENTO
    // Los atributos son private — nadie los toca directo.
    // Solo se acceden a través de métodos controlados.
    // --------------------------------------------------------
    private String nombre;
    private double precio;
    private int stock;

    // CONSTRUCTOR
    // Se ejecuta cuando haces "new Producto(...)".
    // "this.nombre" = atributo de la clase
    // "nombre"      = parámetro que llegó al constructor
    // Sin "this" Java no sabría cuál es cuál.
    public Producto(String nombre, double precio, int stock) {
        this.nombre = nombre;
        this.precio = precio;
        this.stock  = stock;
    }

    // --------------------------------------------------------
    // GETTERS — permiten leer los atributos desde afuera
    // Solo lectura, no modifican nada.
    // --------------------------------------------------------
    public String getNombre() { return nombre; }
    public double getPrecio() { return precio; }
    public int    getStock()  { return stock;  }

    // --------------------------------------------------------
    // SETTER con validación — escritura controlada
    // En vez de exponer el atributo, controlamos qué valores
    // son válidos antes de guardarlos.
    // --------------------------------------------------------
    public void setPrecio(double nuevoPrecio) {
        if (nuevoPrecio <= 0) {
            System.out.println("Error: el precio debe ser mayor a 0.");
            return; // sale del método sin cambiar nada
        }
        this.precio = nuevoPrecio;
    }

    // Método con lógica de negocio — no es un simple setter
    // porque valida y modifica el stock de forma controlada
    public boolean vender(int cantidad) {
        if (cantidad <= 0) {
            System.out.println("Error: la cantidad debe ser positiva.");
            return false;
        }
        if (cantidad > stock) {
            System.out.println("Error: stock insuficiente. Disponible: " + stock);
            return false;
        }
        stock -= cantidad;
        return true;
    }

    // --------------------------------------------------------
    // toString
    // Java llama este método automáticamente cuando haces
    // System.out.println(objeto).
    // Sin esto imprimiría algo como: Producto@1b6d3586
    // --------------------------------------------------------
    @Override
    public String toString() {
        return String.format("%-15s | Precio: $%6.2f | Stock: %3d",
                nombre, precio, stock);
    }
}


// ============================================================
// CLASE PRINCIPAL — aquí corre el programa
// ============================================================

public class Main {

    // --------------------------------------------------------
    // ARRAYLIST CON OBJETOS
    // Es una lista dinámica — crece sola cuando agregas cosas.
    // <Producto> le dice que solo guarda objetos de tipo Producto.
    // La declaramos aquí para que todos los métodos la usen.
    // --------------------------------------------------------
    static ArrayList<Producto> productos = new ArrayList<>();

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {

        // Cargamos algunos productos de prueba al inicio
        productos.add(new Producto("Café",    3.50, 20));
        productos.add(new Producto("Leche",   2.00, 15));
        productos.add(new Producto("Pan",     1.50, 30));
        productos.add(new Producto("Mantequilla", 4.00, 10));

        int opcion;

        do {
            System.out.println("\n========== TIENDA ==========");
            System.out.println("1. Ver todos los productos");
            System.out.println("2. Buscar producto");
            System.out.println("3. Vender producto");
            System.out.println("4. Agregar producto nuevo");
            System.out.println("5. Cambiar precio de un producto");
            System.out.println("0. Salir");
            System.out.print("Opción: ");

            // ------------------------------------------------
            // EXCEPCION: nextInt()
            // Si el usuario escribe una letra en vez de número,
            // nextInt() lanza InputMismatchException y el
            // programa se cae. Lo manejamos con try-catch.
            // ------------------------------------------------
            try {
                opcion = sc.nextInt();
            } catch (java.util.InputMismatchException e) {
                System.out.println("Error: debes escribir un número.");
                sc.nextLine(); // limpia lo que quedó en el buffer
                opcion = -1;  // valor inválido para repetir el menú
            }

            switch (opcion) {
                case 1  -> verTodos();
                case 2  -> buscar();
                case 3  -> vender();
                case 4  -> agregar();
                case 5  -> cambiarPrecio();
                case 0  -> System.out.println("Hasta luego.");
                default -> System.out.println("Opción inválida.");
            }

        } while (opcion != 0);
    }


    // --------------------------------------------------------
    // VER TODOS
    // Recorre el ArrayList con for-each y usa toString()
    // automáticamente al pasar el objeto a println.
    // --------------------------------------------------------
    static void verTodos() {
        if (productos.isEmpty()) {
            System.out.println("No hay productos registrados.");
            return;
        }
        System.out.println("\n--- Productos disponibles ---");
        for (Producto p : productos) {
            System.out.println(p); // llama p.toString() internamente
        }
        System.out.println("Total: " + productos.size() + " productos.");
    }


    // --------------------------------------------------------
    // BUSCAR
    // Recorre la lista comparando nombres con .equals()
    // Nunca uses == para comparar Strings — compara referencias,
    // no el contenido. .equals() compara letra por letra.
    // --------------------------------------------------------
    static void buscar() {
        System.out.print("Nombre del producto: ");
        sc.nextLine(); // limpia el buffer antes de leer texto
        String nombre = sc.nextLine();

        Producto encontrado = null; // asumimos que no existe

        for (Producto p : productos) {
            // equalsIgnoreCase ignora mayúsculas/minúsculas
            if (p.getNombre().equalsIgnoreCase(nombre)) {
                encontrado = p;
                break; // ya lo encontré, no necesito seguir
            }
        }

        // ------------------------------------------------
        // EXCEPCION: NullPointerException
        // Si buscarProducto() devuelve null y luego intentas
        // llamar un método sobre ese null, el programa se cae.
        // Siempre verifica si es null antes de usar el objeto.
        // ------------------------------------------------
        if (encontrado == null) {
            System.out.println("Producto no encontrado.");
        } else {
            System.out.println("Encontrado: " + encontrado);
        }
    }


    // --------------------------------------------------------
    // VENDER
    // Busca el producto y llama su método vender().
    // El método ya tiene las validaciones internas.
    // --------------------------------------------------------
    static void vender() {
        System.out.print("Nombre del producto: ");
        sc.nextLine();
        String nombre = sc.nextLine();

        Producto p = encontrarPorNombre(nombre);

        if (p == null) {
            System.out.println("Producto no encontrado.");
            return;
        }

        System.out.print("Cantidad a vender: ");

        try {
            int cantidad = sc.nextInt();

            if (p.vender(cantidad)) {
                double total = p.getPrecio() * cantidad;
                System.out.printf("Venta exitosa. Total: $%.2f%n", total);
                System.out.println("Stock restante: " + p.getStock());
            }

        } catch (java.util.InputMismatchException e) {
            System.out.println("Error: debes escribir un número entero.");
            sc.nextLine();
        }
    }


    // --------------------------------------------------------
    // AGREGAR
    // Crea un nuevo objeto Producto y lo mete al ArrayList.
    // --------------------------------------------------------
    static void agregar() {
        sc.nextLine(); // limpia buffer

        System.out.print("Nombre: ");
        String nombre = sc.nextLine();

        // Verificar que no exista ya uno con ese nombre
        if (encontrarPorNombre(nombre) != null) {
            System.out.println("Ya existe un producto con ese nombre.");
            return;
        }

        double precio = 0;
        int stock = 0;

        try {
            System.out.print("Precio: ");
            precio = sc.nextDouble();

            System.out.print("Stock inicial: ");
            stock = sc.nextInt();

        } catch (java.util.InputMismatchException e) {
            System.out.println("Error: valor inválido. Operación cancelada.");
            sc.nextLine();
            return;
        }

        // Validaciones antes de crear el objeto
        if (precio <= 0 || stock < 0) {
            System.out.println("Error: precio debe ser > 0 y stock >= 0.");
            return;
        }

        // Crea el objeto y lo agrega a la lista
        productos.add(new Producto(nombre, precio, stock));
        System.out.println("Producto agregado correctamente.");
    }


    // --------------------------------------------------------
    // CAMBIAR PRECIO
    // Usa el setter con validación que definimos en Producto.
    // El setter rechaza valores inválidos internamente.
    // --------------------------------------------------------
    static void cambiarPrecio() {
        System.out.print("Nombre del producto: ");
        sc.nextLine();
        String nombre = sc.nextLine();

        Producto p = encontrarPorNombre(nombre);

        if (p == null) {
            System.out.println("Producto no encontrado.");
            return;
        }

        try {
            System.out.print("Nuevo precio: ");
            double nuevoPrecio = sc.nextDouble();
            p.setPrecio(nuevoPrecio); // el setter valida internamente
            System.out.println("Precio actualizado: " + p);

        } catch (java.util.InputMismatchException e) {
            System.out.println("Error: debes escribir un número.");
            sc.nextLine();
        }
    }


    // --------------------------------------------------------
    // MÉTODO AUXILIAR — reutilizable
    // En vez de repetir el bucle de búsqueda en cada método,
    // lo centralizamos aquí. Devuelve null si no lo encuentra.
    // --------------------------------------------------------
    static Producto encontrarPorNombre(String nombre) {
        for (Producto p : productos) {
            if (p.getNombre().equalsIgnoreCase(nombre)) {
                return p;
            }
        }
        return null; // no lo encontró
    }
}