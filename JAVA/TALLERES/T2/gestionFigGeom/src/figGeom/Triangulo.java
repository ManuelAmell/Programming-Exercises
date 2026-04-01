package figGeom;
import java.awt.Color;

public class Triangulo {
	private double ladoA;
    private double ladoB;
    private double ladoC;
    private Color color;
    
    public Triangulo(double ladoA, double ladoB, double ladoC, Color color) {
        this.ladoA = ladoA;
        this.ladoB = ladoB;
        this.ladoC = ladoC;
        this.color = color;
    }
    
    public double calcularPerimetro() {
        return ladoA + ladoB + ladoC;
    }
    
    public double calcularArea() {
        double s = calcularPerimetro() / 2;
        return Math.sqrt(s * (s - ladoA) * (s - ladoB) * (s - ladoC));
    }
    
    public Color getColor() {
        return color;
    }
    
    @Override
    public String toString() {
        return String.format("Triangulo[lados=(%.2f, %.2f, %.2f), color=RGB(%d,%d,%d), perimetro=%.2f, area=%.2f]",
                ladoA, ladoB, ladoC, color.getRed(), color.getGreen(), color.getBlue(),
                calcularPerimetro(), calcularArea());
    }
}
