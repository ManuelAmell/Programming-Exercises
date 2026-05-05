    package FigurasGeometricas;
import java.awt.Color;

public class Circulo extends Figura {
    protected double diametro; // Atributo protegido

    public Circulo(int id, Color color, double diametro) {
        super(id, color);
        this.diametro = diametro;
    }

    public void setDiametro(double diametro) { this.diametro = diametro; }

    @Override
    public double calcularArea() {
        double radio = diametro / 2.0;
        return Math.PI * Math.pow(radio, 2);
    }

    @Override
    public double calcularPerimetro() {
        return Math.PI * diametro;
    }
}