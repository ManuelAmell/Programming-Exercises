package Parametros;
import javax.swing.JOptionPane;
public class Main {

	public static void main(String[] args) {
		int n1 = Integer.parseInt(JOptionPane.showInputDialog("Digite numero 1:"));
		int n2 = Integer.parseInt(JOptionPane.showInputDialog("Digite numero 2:"));
		
		operacion objeto = new operacion();
		
		objeto.sumar(n1,n2);//argumentos son las variables que les damos a los metodos
		objeto.restar(n1,n2);//(son un valor q enviamos)
		objeto.multiplicar(n1,n2);
		objeto.dividir(n1,n2);
		objeto.mostrarResultados();
	}

}
