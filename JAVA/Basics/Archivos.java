import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

public class Archivos {
    public static void main(String[] args) {

        String ruta = "datos.txt";

        // ------------------------------------------------
        // ESCRIBIR UN ARCHIVO
        // FileWriter crea el archivo si no existe.
        // Si ya existe, lo sobreescribe.
        // El segundo parámetro en true = modo append (agrega al final).
        // EXCEPCION: IOException — si no tiene permisos, disco lleno, etc.
        // ------------------------------------------------
        try {
            FileWriter escritor = new FileWriter(ruta);
            escritor.write("Ana,9.5\n");
            escritor.write("Luis,7.0\n");
            escritor.write("Marta,8.5\n");
            escritor.close(); // SIEMPRE cerrar — si no, puede perder datos
            System.out.println("Archivo escrito.");
        } catch (IOException e) {
            System.out.println("Error al escribir: " + e.getMessage());
        }

        // ------------------------------------------------
        // LEER UN ARCHIVO línea por línea
        // BufferedReader es más eficiente que leer caracter por caracter.
        // EXCEPCION: FileNotFoundException — si el archivo no existe.
        // EXCEPCION: IOException — si falla la lectura.
        // ------------------------------------------------
        try {
            BufferedReader lector = new BufferedReader(new FileReader(ruta));
            String linea;

            while ((linea = lector.readLine()) != null) {
                System.out.println("Leído: " + linea);
            }

            lector.close();
        } catch (FileNotFoundException e) {
            System.out.println("Error: el archivo no existe en esa ruta.");
        } catch (IOException e) {
            System.out.println("Error al leer el archivo: " + e.getMessage());
        }

        // ------------------------------------------------
        // LEER Y CONVERTIR A OBJETOS
        // Combina split() con parseInt/parseDouble
        // para convertir cada línea en un objeto útil.
        // ------------------------------------------------
        ArrayList<String[]> registros = new ArrayList<>();

        try {
            BufferedReader lector = new BufferedReader(new FileReader(ruta));
            String linea;

            while ((linea = lector.readLine()) != null) {
                if (!linea.isBlank()) {           // ignora líneas vacías
                    String[] partes = linea.split(",");
                    registros.add(partes);
                }
            }

            lector.close();
        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        }

        for (String[] r : registros) {
            System.out.println("Nombre: " + r[0] + " | Nota: " + r[1]);
        }

        // ------------------------------------------------
        // FORMA MODERNA — try-with-resources
        // Cierra el archivo automáticamente aunque haya error.
        // Es la forma recomendada en Java moderno.
        // ------------------------------------------------
        try (BufferedReader lector = new BufferedReader(new FileReader(ruta))) {
            String linea;
            while ((linea = lector.readLine()) != null) {
                System.out.println(linea);
            }
            // lector.close() se llama solo al terminar el bloque
        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        }

        // ------------------------------------------------
        // AGREGAR al final de un archivo existente (append)
        // ------------------------------------------------
        try (FileWriter fw = new FileWriter(ruta, true)) {
            fw.write("Pedro,6.5\n");
            System.out.println("Línea agregada.");
        } catch (IOException e) {
            System.out.println("Error al agregar: " + e.getMessage());
        }

        // ------------------------------------------------
        // VERIFICAR si un archivo existe antes de leerlo
        // ------------------------------------------------
        File archivo = new File(ruta);
        if (archivo.exists()) {
            System.out.println("El archivo existe. Tamaño: " + archivo.length() + " bytes.");
        } else {
            System.out.println("El archivo no existe.");
        }
    }
}