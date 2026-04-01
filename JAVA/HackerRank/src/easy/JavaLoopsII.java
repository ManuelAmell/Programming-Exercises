package easy;

import java.util.*;

public class JavaLoopsII {

    public static void main(String[] args) {
        
        Scanner scanner =new Scanner(System.in);
        int q = scanner.nextInt();

        
        for (int i = 0; i < q;i++){
        
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        long suma=a;
        for (int j=0; j < c; j++){
            
            suma = suma + (int)Math.pow(2,j) * b;
            
            System.out.print(suma + " ");
        }
        System.out.println();
        }
    scanner.close();
    }
}