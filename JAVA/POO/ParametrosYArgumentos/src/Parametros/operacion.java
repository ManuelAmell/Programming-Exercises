package Parametros;
public class operacion {

	int suma;
	int resta;
	int multiplicacion;
	double division;
	

	public void sumar(int n1 , int n2) {//parametros son el tipo de declaracion 
										//de argumentos esperados					
		suma = n1 + n2;
	}
	public void  restar(int n1 , int n2) {
		resta =  n1 - n2;
	}
	public void dividir(int n1 , int n2) {
		division = n1 / n2;
	}
	public void multiplicar(int n1 , int n2) {
		multiplicacion =  (n1 * n2);
	}
	public void mostrarResultados() {
		System.out.println("La suma es :"+suma);
		System.out.println("La resta es :"+resta);
		System.out.println("La multiplicacion es :"+multiplicacion);
		System.out.println("La division es :"+division);	
	}
}
