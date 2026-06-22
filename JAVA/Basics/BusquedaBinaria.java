import java.util.Arrays;
import java.util.Scanner;

public class BusquedaBinaria {

    private int[] v;
    private Scanner leer = new Scanner(System.in);

    public BusquedaBinaria(int[] vector) {
        this.v = vector;
    }

    public void ordenarVector() {
        Arrays.sort(v);
    }

    public boolean obtenerBusquedaBinaria(int n) {
        ordenarVector();
        int arriba = v.length - 1;
        int abajo = 0;
        int ci=0;
        while (abajo <= arriba) {
            int centro = (arriba + abajo) / 2;

            if (v[centro] == n) {
                return true;
            } else if (v[centro] < n) {
                abajo = centro + 1;
            } else {
                arriba = centro - 1;
            }
            ci++;
        }
        System.out.println("Numero de comparaciones: " + ci);
        return false;
    }

    public static void main(String[] args) {
        int[] datos = {5, 3, 8, 1, 9, 2, 7, 4, 6};
        BusquedaBinaria bb = new BusquedaBinaria(datos);

        Scanner leer = new Scanner(System.in);
        System.out.println("Ingrese el numero a buscar");
        int n = leer.nextInt();

        if (bb.obtenerBusquedaBinaria(n)) {
            System.out.println("El numero se encuentra en el vector");
        } else {
            System.out.println("El numero no se encuentra en el vector");
        }

        leer.close();
    }
}