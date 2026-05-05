package password;
import java.security.SecureRandom;

public class PasswordGenerator {
	
	public String doPasswordSecure(int tamaño){
	StringBuilder password = new StringBuilder();
    String mayus = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    String minus = "abcdefghijklmnopqrstuvwxyz";
    String numeros = "0123456789";
    String simbolos = "!@#$%^&*";
    
    SecureRandom rand = new SecureRandom();
    
    for (int i =0 ; i < tamaño; i++) {
    		int aleatorio = rand.nextInt(4)+1;
    		
    		if (aleatorio == 1) {
    			password.append(mayus.charAt(rand.nextInt(mayus.length())));
    		}
    		else if (aleatorio == 2) {
    			password.append(minus.charAt(rand.nextInt(minus.length())));
    		}
    		else if (aleatorio == 3) {
    			password.append(numeros.charAt(rand.nextInt(numeros.length())));
    		}
    		else if (aleatorio == 4) {
    			password.append(simbolos.charAt(rand.nextInt(simbolos.length())));
    		}
    	}
    	return password.toString();
	}
}
