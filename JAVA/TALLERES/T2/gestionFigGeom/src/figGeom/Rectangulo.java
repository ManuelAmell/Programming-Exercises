package figGeom;
import java.awt.Color;

public class Rectangulo {
	private double largo;
    private double ancho;
    private Color color;
    
    public Rectangulo(double largo, double ancho, Color color) {
        this.largo = largo;
        this.ancho = ancho;
        this.color = color;
    }
    
    public double calcularPerimetro() {
        return 2 * (largo + ancho);
    }
    
    public double calcularArea() {
        return largo * ancho;
    }
    
    public Color getColor() {
        return color;
    }
    
    @Override
    public String toString() {
        return String.format("Rectangulo[largo=%.2f, ancho=%.2f, color=RGB(%d,%d,%d), perimetro=%.2f, area=%.2f]",
                largo, ancho, color.getRed(), color.getGreen(), color.getBlue(),
                calcularPerimetro(), calcularArea());
    }
}
