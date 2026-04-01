package FigGeomApp;

import FigGeom.*;
import java.awt.Color;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

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
    }
    
    public void mostrarTodasLasFiguras() {
        System.out.println("\n=== FIGURAS GEOMETRICAS ===\n");
        
        System.out.println("Total circulos: " + circulos.size());
        System.out.println("Total triangulos: " + triangulos.size());
        System.out.println("Total cuadrados: " + cuadrados.size());
        System.out.println("Total rectangulos: " + rectangulos.size());
        System.out.println("Total pentagonos: " + pentagonos.size());
    }
    
    public static void main(String[] args) {
        App app = new App();
        System.out.println("Directorio: " + System.getProperty("user.dir"));
        app.cargarDatosDesdeCSV("data.csv");
        app.mostrarTodasLasFiguras();
    }
}
