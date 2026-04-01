package figGeomApp;
import figGeom.*;
import java.util.Scanner;
import java.awt.Color;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
/**
 * autores:
 * Andres Ramos-028
 * Manuel Amell-001
 * Brayan Ochoa-003
 */
public class App {
	private ArrayList<Triangulo> triangulos = new ArrayList<>();
    private ArrayList<Cuadrado> cuadrados = new ArrayList<>();
    private ArrayList<Rectangulo> rectangulos = new ArrayList<>();
    private ArrayList<Pentagono> pentagonos = new ArrayList<>();
    private ArrayList<Circulo> circulos = new ArrayList<>();
    
    public void cargarDatosDesdeCSV(String archivo) {
        try (BufferedReader br = new BufferedReader(new FileReader(archivo))) {
            String linea;
            int lineaNum = 0;
            
            while ((linea = br.readLine()) != null) {
                lineaNum++;
                try {
                    String[] partes = linea.split(";");
                    
                    if (partes.length < 3) continue;
                    
                    String tipo = partes[0].trim().toLowerCase();
                    String dimensiones = partes[1].trim();
                    String colorStr = partes[2].trim();
                    
                    Color color = parsearColor(colorStr);
                    
                    switch (tipo) {
                        case "circulo":
                            double diametro = Double.parseDouble(dimensiones);
                            circulos.add(new Circulo(diametro, color));
                            break;
                            
                        case "triangulo":
                            String[] ladosT = dimensiones.split("-");
                            triangulos.add(new Triangulo(
                                Double.parseDouble(ladosT[0]),
                                Double.parseDouble(ladosT[1]),
                                Double.parseDouble(ladosT[2]),
                                color
                            ));
                            break;
                            
                        case "cuadrado":
                            double lado = Double.parseDouble(dimensiones);
                            cuadrados.add(new Cuadrado(lado, color));
                            break;
                            
                        case "rectangulo":
                            String[] ladosR = dimensiones.split("-");
                            rectangulos.add(new Rectangulo(
                                Double.parseDouble(ladosR[0]),
                                Double.parseDouble(ladosR[1]),
                                color
                            ));
                            break;
                            
                        case "pentagono":
                            String[] ladosP = dimensiones.split("-");
                            pentagonos.add(new Pentagono(
                                Double.parseDouble(ladosP[0]),
                                Double.parseDouble(ladosP[1]),
                                Double.parseDouble(ladosP[2]),
                                Double.parseDouble(ladosP[3]),
                                Double.parseDouble(ladosP[4]),
                                color
                            ));
                            break;
                    }
                } catch (Exception e) {
                    System.err.println("Error en linea " + lineaNum + ": " + e.getMessage());
                }
            }
            
            System.out.println("Datos cargados desde " + archivo);
            
        } catch (IOException e) {
            System.err.println("Error al leer el archivo: " + e.getMessage());
        }
    }
    
    private Color parsearColor(String colorStr) {
        colorStr = colorStr.trim();
        
        if (colorStr.startsWith("new Color(") && colorStr.endsWith(")")) {
            String valores = colorStr.substring(10, colorStr.length() - 1);
            String[] rgb = valores.split(",");
            return new Color(
                Integer.parseInt(rgb[0].trim()),
                Integer.parseInt(rgb[1].trim()),
                Integer.parseInt(rgb[2].trim())
            );
        }
        
        String[] rgb = colorStr.split("-");
        return new Color(
            Integer.parseInt(rgb[0].trim()),
            Integer.parseInt(rgb[1].trim()),
            Integer.parseInt(rgb[2].trim())
        );
    } public void mostrarTodasLasFiguras() {
        System.out.println("\n=== FIGURAS GEOMETRICAS ===\n");
        for (Circulo c : circulos) System.out.println(c);
        for (Triangulo t : triangulos) System.out.println(t);
        for (Cuadrado cu : cuadrados) System.out.println(cu);
        for (Rectangulo r : rectangulos) System.out.println(r);
        for (Pentagono p : pentagonos) System.out.println(p);
    }
    public void ejecutarMenu() {
        Scanner sc = new Scanner(System.in);
        int opcion = -1;

        while (opcion != 0) {
            System.out.println("\n--- GESTION DE FIGURAS GEOMETRICAS ---");
            System.out.println("\nFiguras geometricas detectadas");
            System.out.println("Total circulos: " + circulos.size());
            System.out.println("Total triangulos: " + triangulos.size());
            System.out.println("Total cuadrados: " + cuadrados.size());
            System.out.println("Total rectangulos: " + rectangulos.size());
            System.out.println("Total pentagonos: " + pentagonos.size());
            System.out.println("1. Ver Circulos");
            System.out.println("2. Ver Triangulos");
            System.out.println("3. Ver Cuadrados");
            System.out.println("4. Ver Rectangulos");
            System.out.println("5. Ver Pentagonos");
            System.out.println("6. Ver Todas las Figuras");
            System.out.println("0. Salir");
            System.out.print("Seleccione una opción: ");
            
            try {

                opcion = Integer.parseInt(sc.nextLine());
                System.out.println();

                switch (opcion) {
                    case 1: for (Circulo c : circulos) System.out.println(c); break;
                    case 2: for (Triangulo t : triangulos) System.out.println(t); break;
                    case 3: for (Cuadrado cu : cuadrados) System.out.println(cu); break;
                    case 4: for (Rectangulo r : rectangulos) System.out.println(r); break;
                    case 5: for (Pentagono p : pentagonos) System.out.println(p); break;
                    case 6: mostrarTodasLasFiguras(); break;
                    case 0: System.out.println("Saliendo del sistema..."); break;
                    default: System.out.println("Opción no válida.");
                }
            } catch (NumberFormatException e) {
                System.out.println("Error: Por favor ingrese un número.");
            }
        }
        sc.close();
    }
  
	public static void main(String[] args) {
		
		App app = new App();
        System.out.println("Directorio: " + System.getProperty("user.dir"));
        app.cargarDatosDesdeCSV("data.csv");
        app.ejecutarMenu();

	}

}
