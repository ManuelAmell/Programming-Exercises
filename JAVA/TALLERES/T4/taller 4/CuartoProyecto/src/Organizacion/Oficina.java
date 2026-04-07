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
	}
	

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

	public void añadirEmpleado(Empleado emp) {
		this.empleados.add(emp);
		emp.agregarOficina(this);
	}
	
	public Tarea crearTarea(int id, String desc) {
		Tarea tarea = new Tarea(id, desc);
		this.tareas.add(tarea);
		return tarea; 
	}

	public String toString() {
		return "Oficina: " + nombre + 
			   "\nEmpleados: " + empleados +
			   "\nTareas: " + tareas;
	    }
	}
