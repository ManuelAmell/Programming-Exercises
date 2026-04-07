public class Conversiones {
    public static void main(String[] args) {

        // ------------------------------------------------
        // CONVERSIÓN IMPLÍCITA (widening)
        // Java la hace solo cuando no hay riesgo de perder datos.
        // Va de menor a mayor capacidad.
        // byte → short → int → long → float → double
        // ------------------------------------------------
        int entero = 100;
        double doble = entero;     // Java lo convierte solo
        System.out.println(doble); // 100.0

        // ------------------------------------------------
        // CONVERSIÓN EXPLÍCITA (casting / narrowing)
        // Tú le dices a Java que fuerce el cambio.
        // Puede perder información — es tu responsabilidad.
        // ------------------------------------------------
        double precio = 9.99;
        int precioCortado = (int) precio; // corta los decimales, no redondea
        System.out.println(precioCortado); // 9

        // ------------------------------------------------
        // STRING → número
        // parseInt, parseDouble, etc.
        // EXCEPCION: NumberFormatException
        // Si el String no es un número válido, el programa se cae.
        // ------------------------------------------------
        String textoEntero = "42";
        String textoDecimal = "3.14";
        String textoInvalido = "hola";

        int    n1 = Integer.parseInt(textoEntero);
        double n2 = Double.parseDouble(textoDecimal);
        System.out.println(n1 + n2); // 45.14

        try {
            int n3 = Integer.parseInt(textoInvalido); // explota aquí
        } catch (NumberFormatException e) {
            System.out.println("Error: '" + textoInvalido + "' no es un número.");
        }

        // ------------------------------------------------
        // número → STRING
        // Tres formas, todas válidas.
        // ------------------------------------------------
        int num = 50;
        String s1 = String.valueOf(num);    // forma recomendada
        String s2 = Integer.toString(num);  // igual de común
        String s3 = "" + num;               // funciona pero es menos clara
        System.out.println(s1 + " | " + s2 + " | " + s3);

        // ------------------------------------------------
        // char → int y viceversa
        // Un char internamente es un número (código ASCII/Unicode).
        // ------------------------------------------------
        char letra = 'A';
        int codigo = (int) letra;          // 65
        char deVuelta = (char) (codigo + 1); // 'B'
        System.out.println(codigo + " → " + deVuelta);

        // ------------------------------------------------
        // AUTOBOXING y UNBOXING
        // Java convierte automáticamente entre primitivos y
        // sus clases envolventes (wrapper classes).
        // int ↔ Integer, double ↔ Double, etc.
        // EXCEPCION: NullPointerException en unboxing
        // ------------------------------------------------
        Integer a = 10;   // autoboxing: int → Integer
        int b = a;        // unboxing: Integer → int

        Integer c = null;
        try {
            int d = c;    // NullPointerException — no puede desempaquetar null
        } catch (NullPointerException e) {
            System.out.println("Error: no puedes convertir null a int.");
        }
    }
}