package ClinicaApp;

import java.util.ArrayList;

public class HistoriaClinica {

    private ArrayList<Tratamiento> tratamientos;

    // Constructor
    public HistoriaClinica() {
        tratamientos = new ArrayList<>();
    }

    // Agregar tratamiento
    public void agregarTratamiento(Tratamiento tratamiento) {
        tratamientos.add(tratamiento);
    }

    // Mostrar historial completo
    public void mostrarHistorial() {
        if (tratamientos.isEmpty()) {
            System.out.println("No hay tratamientos registrados.");
        } else {
            System.out.println("Historial clínico:");
            for (Tratamiento t : tratamientos) {
                System.out.println(t);
            }
        }
    }

    // por si aja 
    public ArrayList<Tratamiento> getTratamientos() {
        return tratamientos;
    }
}
