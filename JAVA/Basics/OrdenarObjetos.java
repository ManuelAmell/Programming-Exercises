import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

class Estudiante {
    private String nombre;
    private double nota;

    public Estudiante(String nombre, double nota) {
        this.nombre = nombre;
        this.nota = nota;
    }

    public String getNombre() { return nombre; }
    public double getNota()   { return nota;   }

    @Override
    public String toString() {
        return nombre + " (" + nota + ")";
    }
}

public class OrdenarObjetos {
    public static void main(String[] args) {

        ArrayList<Estudiante> lista = new ArrayList<>();
        lista.add(new Estudiante("Marta", 8.5));
        lista.add(new Estudiante("Luis",  6.0));
        lista.add(new Estudiante("Ana",   9.5));
        lista.add(new Estudiante("Pedro", 7.0));

        // ------------------------------------------------
        // ORDENAR POR NOTA — de menor a mayor
        // Comparator.comparingDouble le dice por qué campo ordenar.
        // ------------------------------------------------
        lista.sort(Comparator.comparingDouble(Estudiante::getNota));
        System.out.println("Por nota asc: " + lista);

        // ------------------------------------------------
        // ORDENAR POR NOTA — de mayor a menor
        // .reversed() invierte el orden.
        // ------------------------------------------------
        lista.sort(Comparator.comparingDouble(Estudiante::getNota).reversed());
        System.out.println("Por nota desc: " + lista);

        // ------------------------------------------------
        // ORDENAR POR NOMBRE — alfabético
        // ------------------------------------------------
        lista.sort(Comparator.comparing(Estudiante::getNombre));
        System.out.println("Por nombre: " + lista);

        // ------------------------------------------------
        // BUSCAR el de mayor nota manualmente
        // ------------------------------------------------
        Estudiante mejor = lista.get(0);
        for (Estudiante e : lista) {
            if (e.getNota() > mejor.getNota()) {
                mejor = e;
            }
        }
        System.out.println("Mejor nota: " + mejor);
    }
}