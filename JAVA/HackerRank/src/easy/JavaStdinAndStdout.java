package easy;

import java.util.Scanner;

/**
 * HackerRank Problem: Java Stdin and Stdout    
 * Difficulty: Easy
 * URL: https://www.hackerrank.com/challenges/java-stdin-and-stdout-1
 */
public class JavaStdinAndStdout {

    public static void main(String[] args) {    
        Scanner scanner = new Scanner(System.in);
        
        int c = scanner.nextInt();
        double b = scanner.nextDouble();
        scanner.nextLine(); // Consume newline
        String a = scanner.nextLine();
        
        scanner.close();
        
        System.out.println("String: " + a);
        System.out.println("Double: " + b);
        System.out.println("Int: " + c);
    }
}
