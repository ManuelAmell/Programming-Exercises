package ClasesYObjetos;

public class Persona {
	String nombre;
	int edad;
	/*
	public Persona(String xnombre, int xedad) {
		nombre = xnombre;
		edad = xedad;
	}*/
	
	public Persona(String nombre , int edad) {
		this.nombre = nombre;
		this.edad = edad;
	}
	//el this es para decirle q nombre es de los atributos 
	//y el otro es el parametro
	public void mostrarDatos() {
		System.out.println("Nombre :"+ nombre);
		System.out.println("Edad :"+ edad);
	}

}
