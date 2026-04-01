package figGeom;
import java.awt.Color;

public class Cuadrado {
	private double lado;
    private Color color;
    
    public Cuadrado(double lado, Color color) {
        this.lado = lado;
        this.color = color;
    }
    
    public double calcularPerimetro() {
        return 4 * lado;
    }
    
    public double calcularArea() {
        return lado * lado;
    }
    
    public Color getColor() {
        return color;
    }
    
    @Override
    public String toString() {
        return String.format("Cuadrado[lado=%.2f, color=RGB(%d,%d,%d), perimetro=%.2f, area=%.2f]",
                lado, color.getRed(), color.getGreen(), color.getBlue(),
                calcularPerimetro(), calcularArea());
    }
}
