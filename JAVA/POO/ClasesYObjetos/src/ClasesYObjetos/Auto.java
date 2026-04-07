package ClasesYObjetos;

public class Auto {
	String color;
	String marca;
	int km;

	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Auto carro1 = new Auto();
		carro1.color = "rojo";
		carro1.marca = "ferrari";
		
		System.out.println("Color de el carro es :"+ carro1.color);
		System.out.println("marca de el crro es "+ carro1.marca);
		
		Auto carro2 = new Auto();
		
		carro2.color = "azul";
		carro2.marca = "mazda";
		
		System.out.println("Color de el carro es :"+ carro2.color);
		System.out.println("marca de el crro es "+ carro2.marca);
		

	}

}
