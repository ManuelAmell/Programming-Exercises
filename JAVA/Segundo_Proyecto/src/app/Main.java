package app;
import pets.Dog;

public class Main {

	public static void main(String[] args) {
		//crea instancias
		Dog dog1 =new Dog("Mastiff", "Large" , 1 ,"Black");
		Dog dog2 =new Dog("Buldog", "Big" , 8 ,"Brown");
		Dog dog3 =new Dog("chiuahua", "small" , 12 ,"white");
		Dog dog4 =new Dog("pitbull", "Large" , 5 ,"red");
		//manipular objetos
		dog1.setName("LALO");
		System.out.println(dog1.getString());
		System.out.println(dog2.getString());
		System.out.println(dog3.getString());
		System.out.println(dog4.getString());
		
	}

}
