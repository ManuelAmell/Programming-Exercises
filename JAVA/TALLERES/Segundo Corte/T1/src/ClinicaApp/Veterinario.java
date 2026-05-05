package ClinicaApp;


public class Veterinario extends Persona {

    // Constructor
    public Veterinario(String nombre, String direccion, String telefono) {
        super(nombre, direccion, telefono);
    }

    // Método clave (DEPENDENCIA)
    public void aplicarTratamiento(Animal animal, Tratamiento tratamiento) {
        animal.getHistoria().agregarTratamiento(tratamiento);
    }

    // Método opcional para mostrar info (puedes reutilizar el de Persona)
    @Override
    public void mostrarInfo() {
        System.out.println("=== VETERINARIO ===");
        super.mostrarInfo();
    }
}