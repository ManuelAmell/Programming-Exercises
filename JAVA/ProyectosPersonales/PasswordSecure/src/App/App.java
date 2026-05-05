package App;

import java.util.Scanner;
import java.util.ArrayList;

import java.io.File;
import java.io.FileWriter;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.Console;
import password.Cuenta;

public class App {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		ArrayList<Cuenta> cuentas = new ArrayList<>();
		
		int opc = -1;
		
		File file = new File("Credenciales.txt");

		try {
		    if (file.createNewFile()) {
		        System.out.println("Archivo Credenciales.txt creado");
		        System.out.println(new File("Credenciales.txt").getAbsolutePath());
		    } else {
		        System.out.println("El archivo Credenciales.txt ya existe");
		        System.out.println(new File("Credenciales.txt").getAbsolutePath());
		    }
		} catch (IOException e) {
		    e.printStackTrace();
		}
		
		do {
		System.out.println("1) Ingresar Una Cuenta");
		System.out.println("2) Ver Credenciales");
		
		 try {
             opc = Integer.parseInt(sc.nextLine());
         } catch (NumberFormatException e) {
             System.out.println("Entrada invalida. Por favor, ingrese un numero del 0 al 2.");
             continue; 
         }
		 
		 switch (opc) {
		 
		 case 1:{
			 if (!file.exists()) {
				    System.out.println("No hay Archivos creados ni credenciales guardadas aún.");
			 }
			 else {
				 Console console = System.console();
				 System.out.print("Usuario:");
				 String usuario = sc.nextLine();
				 String contraseña;
				 
				 if (console != null) {
					    char[] passwordArray = console.readPassword("Contraseña: ");
					     contraseña = new String(passwordArray);
					     java.util.Arrays.fill(passwordArray, ' ');
					}
				 else{
					    System.out.print("Contraseña (visible): ");
					    contraseña = sc.nextLine();
					}
				 
				 System.out.print("Sitio Web:");
				 String url = sc.nextLine();
				 
				 try {
					    FileWriter writer = new FileWriter("Credenciales.txt", true);
					    
					    writer.write(usuario + "," + contraseña + "," + url + "\n");
					    writer.close();
					    
					} catch (IOException e) {
					    e.printStackTrace();
					}
			 }
			 break;
		 }
		 case 2:{
		        try {
		            Scanner reader = new Scanner(file);

		            while (reader.hasNextLine()) {
		                String linea = reader.nextLine();
		                System.out.println(linea);
		            }

		            reader.close();
		            System.out.println("-----FIN del archivo -----");

		        } catch (FileNotFoundException e) {
		            e.printStackTrace();
		        }
			 break;	
		 }
		 default :{
		 System.out.print("Opcion invalida");
		 for (int i = 0; i < 3; i++) {
			    System.out.print(".");
			    	try {
			        Thread.sleep(500);
			    	} 
			    	catch (InterruptedException e) {
			        e.printStackTrace();
			    	}
			}
		 System.out.println();
		 	}
		 }
		}while(opc != 0);
		sc.close();
	}

}
