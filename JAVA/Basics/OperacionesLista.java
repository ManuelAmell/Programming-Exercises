import java.util.ArrayList;
import java.util.Collections;

public class OperacionesLista {
    public static void main(String[] args) {

        ArrayList<String> lista = new ArrayList<>();

        // ------------------------------------------------
        // AGREGAR ELEMENTOS
        // ------------------------------------------------
        lista.add("Marta");       // agrega al final
        lista.add("Ana");
        lista.add("Luis");
        lista.add("Pedro");
        lista.add(1, "Zara");    // inserta en el índice 1, mueve los demás

        // ------------------------------------------------
        // ACCEDER Y RECORRER
        // ------------------------------------------------
        System.out.println(lista.get(0));  // primer elemento
        System.out.println(lista.size());  // cuántos hay

        for (String nombre : lista) {
            System.out.println(nombre);
        }

        // ------------------------------------------------
        // BUSCAR
        // ------------------------------------------------
        System.out.println(lista.contains("Ana"));    // true
        System.out.println(lista.indexOf("Luis"));    // posición (o -1 si no existe)

        // ------------------------------------------------
        // ELIMINAR ELEMENTOS
        // Dos versiones de remove() — cuidado cuál usas.
        // ------------------------------------------------
        lista.remove("Ana");          // elimina por valor (el objeto)
        lista.remove(0);              // elimina por índice

        // EXCEPCION: IndexOutOfBoundsException
        // Si el índice no existe, el programa se cae.
        try {
            lista.remove(999);
        } catch (IndexOutOfBoundsException e) {
            System.out.println("Error: ese índice no existe en la lista.");
        }

        // ------------------------------------------------
        // ELIMINAR CON CONDICIÓN — forma segura
        // removeIf evita el error de modificar la lista
        // mientras la recorres (ConcurrentModificationException).
        // ------------------------------------------------
        lista.add("Carlos");
        lista.add("Carmen");
        lista.add("Carla");

        // Elimina todos los que empiecen con "Car"
        lista.removeIf(nombre -> nombre.startsWith("Car"));

        // ------------------------------------------------
        // EXCEPCION: ConcurrentModificationException
        // Si eliminas elementos dentro de un for-each normal,
        // Java lanza esta excepción porque la lista cambia
        // mientras la estás recorriendo.
        // ------------------------------------------------
        ArrayList<String> temporal = new ArrayList<>();
        temporal.add("uno");
        temporal.add("dos");
        temporal.add("tres");

        try {
            for (String s : temporal) {
                temporal.remove(s); // MAL — modifica mientras recorre
            }
        } catch (java.util.ConcurrentModificationException e) {
            System.out.println("Error: no modifiques la lista mientras la recorres.");
        }

        // Forma correcta: usa removeIf o un Iterator
        temporal.removeIf(s -> s.equals("dos")); // correcto

        // ------------------------------------------------
        // ORDENAR
        // Collections.sort() ordena alfabéticamente (o números de menor a mayor).
        // ------------------------------------------------
        ArrayList<String> nombres = new ArrayList<>();
        nombres.add("Zara");
        nombres.add("Ana");
        nombres.add("Luis");
        nombres.add("Marta");

        Collections.sort(nombres);              // A → Z
        System.out.println(nombres);            // [Ana, Luis, Marta, Zara]

        Collections.reverse(nombres);           // Z → A
        System.out.println(nombres);

        // Ordenar números
        ArrayList<Integer> numeros = new ArrayList<>();
        numeros.add(5); numeros.add(1); numeros.add(8); numeros.add(3);
        Collections.sort(numeros);
        System.out.println(numeros); // [1, 3, 5, 8]

        // ------------------------------------------------
        // ORDENAR OBJETOS PROPIOS — con Comparator
        // ------------------------------------------------
        ArrayList<int[]> pares = new ArrayList<>();
        pares.add(new int[]{3, 100});
        pares.add(new int[]{1, 200});
        pares.add(new int[]{2, 150});

        // Ordena por el primer elemento de cada par
        pares.sort((a, b) -> a[0] - b[0]);

        // ------------------------------------------------
        // LIMPIAR Y VERIFICAR
        // ------------------------------------------------
        ArrayList<String> temp = new ArrayList<>();
        temp.add("algo");
        System.out.println(temp.isEmpty()); // false
        temp.clear();                        // vacía la lista
        System.out.println(temp.isEmpty()); // true
    }
}