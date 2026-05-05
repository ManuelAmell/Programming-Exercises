package Organizacion;
import java.util.ArrayList;

public class Empleado {
	private int id;
	private String nombre;
	private Rol rol;
	private ArrayList<Oficina> oficinas;
	
	public Empleado(int id, String nombre, Rol rol) {
		this.id = id;
		this.nombre = nombre;
		this.rol = rol;
		this.oficinas = new ArrayList<>(); 
	}
	public int getId() {
		return id;
	}
	
	public String getNombre() {
		return nombre;
	}
	
	public Rol getRol() {
		return rol;
	}
	
	public ArrayList<Oficina> getOficinas() {
		return oficinas;
	}
	
	public void agregarOficina(Oficina oficina)
	{
		this.oficinas.add(oficina);
	}
	
	
	public String toString() {
		return "Empleado: " + nombre + " - Rol: " + rol;
	}
}
