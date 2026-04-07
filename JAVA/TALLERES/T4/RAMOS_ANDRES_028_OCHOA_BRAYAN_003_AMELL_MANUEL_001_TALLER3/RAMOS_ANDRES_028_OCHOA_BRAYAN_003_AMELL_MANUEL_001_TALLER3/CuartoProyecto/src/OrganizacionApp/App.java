package OrganizacionApp;
import java.util.Scanner;

import Organizacion.Rol;
import Organizacion.Empleado;
import Organizacion.Oficina;
import Organizacion.Tarea;
public class App {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		//Declaracion de Roles
		Rol gerente = new Rol(1, "Gerente", 1);
		Rol developer = new Rol(2, "Developer", 2);
		Rol analista = new Rol(3, "Analista", 3);
		
		//Empleados
		Empleado juan = new Empleado(1072255345, "Juan", gerente);
		Empleado ana = new Empleado(78546532, "Ana", developer);
		Empleado alexis = new Empleado(1072134251, "Alexis", analista);
		
		//Oficinas
		
		Oficina rh = new Oficina(12, "Recursos Humanos");
		Oficina fc = new Oficina(13, "Finanzas y Contabilidad");
		Oficina mp = new Oficina(14, "Marketing y Publicidad");
		Oficina ac = new Oficina(15, "Atencion al Cliente");
		
		//Tareas
		Tarea t1 = new Tarea(111, "Implementar nuevas medidas de ciberseguridad");
		Tarea t2 = new Tarea(112, "Preparar informe financiero trimestral");
		Tarea t3 = new Tarea(113, "Lanzar campaña publicitaria en redes sociales");
		Tarea t4 = new Tarea(114, "Capacitación de empleados en nuevas herramientas");
		
		//Asignaciones
		ti.añadirEmpleado(juan);
		ti.añadirEmpleado(alexis);
		ti.añadirTarea(t1);
		
		rh.añadirEmpleado(alexis);
		rh.añadirTarea(t2);
		
		//PRE TEST
		System.out.println("======PRE TEST======");
		System.out.println(ti);
		System.out.println();
		System.out.println(rh);
		
		
		System.out.println();
		t1.finalizar(); //CHANGE TEST
		System.out.println();
		
		
		//POST TEST
		System.out.println("======POST TEST======");
		System.out.println(ti);
		
	
	}

}
