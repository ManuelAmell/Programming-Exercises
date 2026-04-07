import java.util.ArrayList;

public class Busqueda {
    public static void main(String[] args) {

        ArrayList<Integer> numeros = new ArrayList<>();
        for (int i = 0; i < 10; i++) numeros.add(i * 2); // [0,2,4,6,8,10,12,14,16,18]

        // ------------------------------------------------
        // BÚSQUEDA LINEAL
        // Recorre uno por uno hasta encontrarlo.
        // Funciona con listas desordenadas.
        // O(n) — en el peor caso revisa todos los elementos.
        // ------------------------------------------------
        int objetivo = 12;
        int posicion = -1; // -1 = no encontrado

        for (int i = 0; i < numeros.size(); i++) {
            if (numeros.get(i) == objetivo) {
                posicion = i;
                break;
            }
        }

        if (posicion != -1) {
            System.out.println("Encontrado en posición: " + posicion);
        } else {
            System.out.println("No encontrado.");
        }

        // ------------------------------------------------
        // BÚSQUEDA BINARIA
        // Solo funciona si la lista está ordenada.
        // Divide la lista a la mitad en cada paso.
        // O(log n) — mucho más rápida en listas grandes.
        // EXCEPCION: no lanza excepción, devuelve negativo si no encuentra.
        // ------------------------------------------------
        int resultado = Collections.binarySearch(numeros, objetivo);
        // Si resultado >= 0 → encontrado en ese índice
        // Si resultado < 0  → no existe

        if (resultado >= 0) {
            System.out.println("Binaria: encontrado en índice " + resultado);
        } else {
            System.out.println("Binaria: no encontrado.");
        }

        // ------------------------------------------------
        // BUSCAR CON CONDICIÓN — sobre objetos
        // ------------------------------------------------
        ArrayList<String> nombres = new ArrayList<>();
        nombres.add("Ana"); nombres.add("Luis"); nombres.add("Marta");

        // Encontrar el primero que cumple condición
        String encontrado = null;
        for (String n : nombres) {
            if (n.startsWith("M")) {
                encontrado = n;
                break;
            }
        }
        System.out.println("Encontrado: " + encontrado);

        // Encontrar todos los que cumplen condición
        ArrayList<String> resultados = new ArrayList<>();
        for (String n : nombres) {
            if (n.length() > 3) {
                resultados.add(n);
            }
        }
        System.out.println("Más de 3 letras: " + resultados);
    }
}