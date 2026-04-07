package OrganizacionApp;
import Organizacion.Rol;
import Organizacion.Empleado;
import Organizacion.Oficina;
import Organizacion.Tarea;
/* Autores:
* Andres Ramos-028
* Manuel Amell-001
* Brayan Ochoa-003
*/
public class App {

	public static void main(String[] args) {

		Rol gerente   = new Rol(1, "Gerente de Proyecto",       1);
		Rol developer = new Rol(2, "Desarrollador de Software",  2);
		Rol analista  = new Rol(3, "Analista de Datos",          3);

		Empleado juan   = new Empleado(1072255345, "Juan",   gerente);
		Empleado ana    = new Empleado(78546532,   "Ana",    developer);
		Empleado alexis = new Empleado(1072134251, "Alexis", analista);

		Oficina ti = new Oficina(11, "Departamento de Tecnologia");
		Oficina rh = new Oficina(12, "Recursos Humanos");
		Oficina fc = new Oficina(13, "Finanzas y Contabilidad");
		Oficina mp = new Oficina(14, "Marketing y Publicidad");
		Oficina ac = new Oficina(15, "Atencion al Cliente");


		Tarea t1 = ti.crearTarea(111, "Implementar nuevas medidas de ciberseguridad");
		fc.crearTarea(112, "Preparar informe financiero trimestral");
		mp.crearTarea(113, "Lanzar campana publicitaria en redes sociales");
		rh.crearTarea(114, "Capacitacion de empleados en nuevas herramientas");
	
		ti.añadirEmpleado(juan);
		ti.añadirEmpleado(ana);
 
		rh.añadirEmpleado(juan);
		rh.añadirEmpleado(alexis);
 
		fc.añadirEmpleado(alexis);
 
		mp.añadirEmpleado(ana);
 
		ac.añadirEmpleado(alexis);


		System.out.println("======PRE TEST======");
		System.out.println(ti);
		System.out.println();
		System.out.println(rh);
		System.out.println();
		System.out.println(fc);
		System.out.println();
		System.out.println(mp);
		System.out.println();
		System.out.println(ac);


		System.out.println();
		t1.finalizar(); 
		System.out.println();


		System.out.println("======POST TEST======");
		System.out.println(ti);
	}
}
