package ClasesYObjetos;

public class Persona {
    String nombre;
    int edad;
    String cedula;
    double km;

    public Persona(String nombre, int edad, String cedula) {//sobre carga de constructores
        this.nombre = nombre;
        this.edad = edad;
        this.cedula = cedula;
    }

    public Persona(String nombre, int edad) {
        this(nombre, edad, "No definida");
        //this.nombre = nombre;
        //this.edad =edad;
        //this.cedula = "No definida";
    }

    public Persona(String cedula) {
        this("Sin nombre", 0, cedula);
        //this.nombre = nombre;
        //this.edad =edad;
        //this.cedula = cedula;
    }
    public void setKm (int km) {//si se ingresa un numero cerrado de km entra por aqui y sobre escribe el valor km
    	this.km =km;
    	System.out.println("kilometros enteros");
    	System.out.println("he corrido :"+ km);
    }
    public void setKm(double km) {//si se ingresa un numero decimal para los km entra aqui 
    	this.km = km;
    	System.out.println("kilometros con decimal");
    	System.out.println("he corrido :"+ km);

    }

    public void mostrarDatos() {
        System.out.println("Nombre: " + nombre);
        System.out.println("Edad: " + edad);
        System.out.println("Cedula: " + cedula);
        System.out.println(" totales km: " + km);
    }
}