public class ManejoDeCadenas {
    public static void main(String[] args) {

        String s = "  Hola Mundo Java  ";

        // ------------------------------------------------
        // OPERACIONES BÁSICAS
        // ------------------------------------------------
        System.out.println(s.length());          // largo total con espacios
        System.out.println(s.trim());            // quita espacios al inicio y final
        System.out.println(s.toUpperCase());     // todo mayúsculas
        System.out.println(s.toLowerCase());     // todo minúsculas
        System.out.println(s.contains("Mundo")); // true
        System.out.println(s.replace("Mundo", "Java")); // reemplaza

        // ------------------------------------------------
        // COMPARACIÓN
        // NUNCA uses == para comparar Strings.
        // == compara si son el mismo objeto en memoria.
        // .equals() compara el contenido letra por letra.
        // ------------------------------------------------
        String x = "hola";
        String y = "HOLA";

        System.out.println(x == y);                      // false (diferente objeto)
        System.out.println(x.equals(y));                 // false (diferente contenido)
        System.out.println(x.equalsIgnoreCase(y));       // true (ignora mayúsculas)

        // ------------------------------------------------
        // SUBSTRING — extraer partes del String
        // EXCEPCION: StringIndexOutOfBoundsException
        // Si el índice está fuera del rango, el programa se cae.
        // ------------------------------------------------
        String texto = "Guatemala";
        System.out.println(texto.substring(0, 4)); // "Guat" (del 0 al 3, el 4 no incluye)
        System.out.println(texto.substring(5));    // "mala" (del 5 al final)

        try {
            System.out.println(texto.substring(0, 50)); // índice fuera de rango
        } catch (StringIndexOutOfBoundsException e) {
            System.out.println("Error: índice fuera del rango del String.");
        }

        // ------------------------------------------------
        // SPLIT — dividir un String en partes
        // Devuelve un arreglo de Strings.
        // ------------------------------------------------
        String csv = "Ana,Luis,Marta,Pedro";
        String[] partes = csv.split(",");

        for (String parte : partes) {
            System.out.println(parte);
        }

        // ------------------------------------------------
        // VERIFICACIONES ÚTILES
        // ------------------------------------------------
        String vacio = "";
        System.out.println(vacio.isEmpty());        // true — longitud 0
        System.out.println("  ".isEmpty());         // false — tiene espacios
        System.out.println("  ".isBlank());         // true — solo espacios

        // ------------------------------------------------
        // EXCEPCION: NullPointerException en Strings
        // Si el String es null y llamas cualquier método, explota.
        // ------------------------------------------------
        String nulo = null;
        try {
            System.out.println(nulo.length()); // explota
        } catch (NullPointerException e) {
            System.out.println("Error: el String es null.");
        }

        // Forma segura de comparar cuando uno puede ser null:
        // pon el literal primero — un literal nunca es null.
        System.out.println("hola".equals(nulo)); // false, no explota
    }
}