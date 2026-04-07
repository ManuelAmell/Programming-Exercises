package Organizacion;
import java.util.ArrayList;
public class Oficina {
	
	private int id;
	private String nombre;
	private ArrayList<Empleado> empleados;
	private ArrayList<Tarea> tareas;
	
	public Oficina(int id, String nombre) //CONSTRUCTOR
	{
		this.id = id;
		this.nombre = nombre;
		this.empleados = new ArrayList<>();
		this.tareas = new ArrayList<>();	
	} //FIN CONSTRUCTOR
	
	//Encapsulamiento de las variables
	public int getId() {
		return id;
	}
	
	public String getNombre() {
		return nombre;
	}
	
	public ArrayList<Empleado> getEmpleados() {
		return empleados;
	}
	
	public ArrayList<Tarea> getTareas() {
		return tareas;
	}
	//FIN EV
	
	//Relacion EMP & OFICINA
	public void añadirEmpleado(Empleado emp) {
		this.empleados.add(emp);
		emp.agregarOficina(this);
	}
	
	public void añadirTarea(Tarea tarea) {
		this.tareas.add(tarea);
	}

	public String toString() {
		return "Oficina: " + nombre + 
			   "\nEmpleados: " + empleados +
			   "\nTareas: " + tareas;
	    }
	}
