package ClinicaApp;

public class Tratamiento {

    private String descripcion;
    private String fecha;
    private String nombreVeterinario;

    public Tratamiento(String descripcion, String fecha, String nombreVeterinario) {
        this.descripcion = descripcion;
        this.fecha = fecha;
        this.nombreVeterinario = nombreVeterinario;
    }

    public String getDescripcion() {
        return descripcion;
    }

    public void setDescripcion(String descripcion) {
        this.descripcion = descripcion;
    }

    public String getFecha() {
        return fecha;
    }

    public void setFecha(String fecha) {
        this.fecha = fecha;
    }

    public String getNombreVeterinario() {
        return nombreVeterinario;
    }

    public void setNombreVeterinario(String nombreVeterinario) {
        this.nombreVeterinario = nombreVeterinario;
    }

    @Override
    public String toString() {
        return "Tratamiento: " + descripcion +
               " | Fecha: " + fecha +
               " | Veterinario: " + nombreVeterinario;
    }
}