package pets;

public class Dog {
	private String breed;
	private String size; 
	private int age;
	private String color;
	private String name;
		//Constructor
	public Dog(String breed,String size,int age,String color ){
		this.breed=breed;
		this.size=size;	
		this.age=age;
		this.color=color;
		this.name ="NO DEFINIDO";
	}
	public String getString() {
		return "Breed:" + this.breed + "\n"+
			   " Size:" + this.size  +"\n" +
			   " Age:" + this.age +"\n" +
			   "Color:" + this.color +"\n"+
			   "Nombre:" + this.name +"\n";
	}
public void setName(String name) {
	this.name =name;
}
	
}
