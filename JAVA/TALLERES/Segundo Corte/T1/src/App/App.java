package App;

import ClinicaApp.*;
import java.util.ArrayList;
import java.util.Scanner;

public class App {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        ArrayList<Dueño> dueños = new ArrayList<>();
        ArrayList<Animal> animales = new ArrayList<>();
        ArrayList<Veterinario> veterinarios = new ArrayList<>();

        int opcion;

        do {
            System.out.println("\n===== CLINICA VETERINARIA  =====");
            System.out.println("1. Registrar dueño");
            System.out.println("2. Registrar veterinario");
            System.out.println("3. Registrar animal");
            System.out.println("4. Asociar animal a dueño");
            System.out.println("5. Aplicar tratamiento");
            System.out.println("6. Ver historial de un animal");
            System.out.println("0. Salir");
            System.out.print("Opción: ");
            
            try {
                opcion = sc.nextInt();
                sc.nextLine();
                
            } 
            catch (Exception e) {
            	
                System.out.println("Entrada invalida, debe ingresar un numero entre 0-6...");
                sc.nextLine(); 
                opcion = -1;   
            }
           

            switch (opcion) {

                case 1:
                    System.out.print("Nombre: ");
                    String nombreD = sc.nextLine();
                    System.out.print("Dirección: ");
                    String dirD = sc.nextLine();
                    System.out.print("Teléfono: ");
                    String telD = sc.nextLine();

                    dueños.add(new Dueño(nombreD, dirD, telD));
                    System.out.println("Dueño registrado");
                    break;

                case 2:
                    System.out.print("Nombre: ");
                    String nombreV = sc.nextLine();
                    System.out.print("Dirección: ");
                    String dirV = sc.nextLine();
                    System.out.print("Teléfono: ");
                    String telV = sc.nextLine();

                    veterinarios.add(new Veterinario(nombreV, dirV, telV));
                    System.out.println(" Veterinario registrado");
                    break;

                case 3:
                    System.out.print("Nombre del animal: ");
                    String nombreA = sc.nextLine();
                    System.out.print("Especie: ");
                    String especie = sc.nextLine();
                    System.out.print("Edad: ");
                    int edad = sc.nextInt();
                    sc.nextLine();

                    animales.add(new Animal(nombreA, especie, edad));
                    System.out.println("Animal registrado");
                    break;

                case 4:
                    if (dueños.isEmpty() || animales.isEmpty()) {
                        System.out.println(" Debe registrar dueños y animales primero");
                        break;
                    }

                    System.out.println("Dueños:");
                    for (int i = 0; i < dueños.size(); i++) {
                        System.out.println(i + ". " + dueños.get(i).getNombre());
                    }

                    System.out.print("Seleccione dueño: ");
                    int idxD = sc.nextInt();

                    System.out.println("Animales:");
                    for (int i = 0; i < animales.size(); i++) {
                        System.out.println(i + ". " + animales.get(i).getNombre());
                    }

                    System.out.print("Seleccione animal: ");
                    int idxA = sc.nextInt();
                    sc.nextLine();

                    dueños.get(idxD).agregarAnimal(animales.get(idxA));
                    System.out.println(" Animal asociado al dueño");
                    break;

                case 5:
                    if (veterinarios.isEmpty() || animales.isEmpty()) {
                        System.out.println(" Deberegistrar veterinarios y animales");
                        break;
                    }

                    System.out.println("Veterinarios:");
                    for (int i = 0; i < veterinarios.size(); i++) {
                        System.out.println(i + ". " + veterinarios.get(i).getNombre());
                    }

                    System.out.print("Seleccione veterinario: ");
                    int idxVet = sc.nextInt();

                    System.out.println("Animales:");
                    for (int i = 0; i < animales.size(); i++) {
                        System.out.println(i + ". " + animales.get(i).getNombre());
                    }

                    System.out.print("Seleccione animal: ");
                    int idxAni = sc.nextInt();
                    sc.nextLine();

                    System.out.print("Descripción del tratamiento: ");
                    String desc = sc.nextLine();

                    System.out.print("Fecha: ");
                    String fecha = sc.nextLine();

                    Tratamiento t = new Tratamiento(
                            desc,
                            fecha,
                            veterinarios.get(idxVet).getNombre()
                    );

                    veterinarios.get(idxVet).aplicarTratamiento(animales.get(idxAni), t);

                    System.out.println(" Tratamiento aplicado");
                    break;

                case 6:
                    if (animales.isEmpty()) {
                        System.out.println("No hay animales registrados");
                        break;
                    }

                    System.out.println("Animales:");
                    for (int i = 0; i < animales.size(); i++) {
                        System.out.println(i + ". " + animales.get(i).getNombre());
                    }

                    System.out.print("Seleccione animal: ");
                    int idxHist = sc.nextInt();

                    animales.get(idxHist).mostrarInfo();
                    animales.get(idxHist).getHistoria().mostrarHistorial();
                    break;

                case 0:
                    System.out.println("Saliendo del sistema...");
                    break;

                default:
                    System.out.println("Opción inválida");
            }

        } while (opcion != 0);

        sc.close();
    }
}