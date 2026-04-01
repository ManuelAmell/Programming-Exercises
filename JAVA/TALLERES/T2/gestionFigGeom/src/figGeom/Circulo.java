package figGeom;
import java.awt.Color;

public class Circulo {
    private double diametro;
    private Color color;
    
    public Circulo(double diametro, Color color) {
        this.diametro = diametro;
        this.color = color;
    }
    
    public double calcularPerimetro() {
        return Math.PI * diametro;
    }
    
    public double calcularArea() {
        double radio = diametro / 2;
        return Math.PI * radio * radio;
    }
    
    public Color getColor() {
        return color;
    }
    
    @Override
    public String toString() {
        return String.format("Circulo[diametro=%.2f, color=RGB(%d,%d,%d), perimetro=%.2f, area=%.2f]",
                diametro, color.getRed(), color.getGreen(), color.getBlue(), 
                calcularPerimetro(), calcularArea());
    }
}
