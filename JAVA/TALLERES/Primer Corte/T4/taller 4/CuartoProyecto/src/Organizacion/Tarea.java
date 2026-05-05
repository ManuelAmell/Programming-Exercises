package Organizacion;

public class Tarea {

	private int id;
	private String desc;
	private String estado;
	
	public Tarea(int id, String desc) {
		this.id = id;
		this.desc = desc;
		this.estado = "en desarrollo";
	}
	
	public int getId() {
		return id;
	}
	
	public String getDesc() {
		return desc;
	}
	
	public String getEstado() {
		return estado;
	}
	
	public void finalizar() {
		this.estado = "finalizada";
	}
	
	public String toString() {
		return  "["+ desc + " - Estado: " + estado + "]";
	}
}