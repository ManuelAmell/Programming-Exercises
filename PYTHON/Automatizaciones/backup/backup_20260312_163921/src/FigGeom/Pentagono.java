package FigGeom;

import java.awt.Color;

public class Pentagono {
    private double lado1;
    private double lado2;
    private double lado3;
    private double lado4;
    private double lado5;
    private Color color;
    
    public Pentagono(double lado1, double lado2, double lado3, double lado4, double lado5, Color color) {
        this.lado1 = lado1;
        this.lado2 = lado2;
        this.lado3 = lado3;
        this.lado4 = lado4;
        this.lado5 = lado5;
        this.color = color;
    }
    
    public double calcularPerimetro() {
        return lado1 + lado2 + lado3 + lado4 + lado5;
    }
    
    public double calcularArea() {
        if (esRegular()) {
            double apotema = lado1 / (2 * Math.tan(Math.PI / 5));
            return (calcularPerimetro() * apotema) / 2;
        }
        return 0;
    }
    
    private boolean esRegular() {
        return lado1 == lado2 && lado2 == lado3 && lado3 == lado4 && lado4 == lado5;
    }
    
    public Color getColor() {
        return color;
    }
    
    @Override
    public String toString() {
        return String.format("Pentagono[lados=(%.2f, %.2f, %.2f, %.2f, %.2f), color=RGB(%d,%d,%d), perimetro=%.2f, area=%.2f]",
                lado1, lado2, lado3, lado4, lado5, color.getRed(), color.getGreen(), color.getBlue(),
                calcularPerimetro(), calcularArea());
    }
}
