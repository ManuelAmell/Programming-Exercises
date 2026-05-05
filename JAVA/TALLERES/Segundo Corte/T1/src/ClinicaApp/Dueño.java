package ClinicaApp;

import java.util.ArrayList;

public class Dueño extends Persona {

    private ArrayList<Animal> animales;

   
    public Dueño(String nombre, String direccion, String telefono) {
        super(nombre, direccion, telefono);
        this.animales = new ArrayList<>();
    }

 
    public void agregarAnimal(Animal animal) {
        animales.add(animal);
    }

    
    public void mostrarAnimales() {
        System.out.println("Animales de " + getNombre() + ":");

        for (Animal a : animales) {
            System.out.println("- " + a.getNombre() + " (" + a.getEspecie() + ")");
        }
    }

    // Getter
    public ArrayList<Animal> getAnimales() {
        return animales;
    }
}