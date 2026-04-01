package easy;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner scanner = new Scanner(System.in);
        
        String j = scanner.next();
            int jn = scanner.nextInt();
        String c = scanner.next();
            int cn = scanner.nextInt();
        String p = scanner.next();
            int pn =scanner.nextInt();
        scanner.close();
        
        System.out.println("================================");
        System.out.printf( "%-15s%03d%n" , j ,jn );
        System.out.printf( "%-15s%03d%n" , c ,cn );
        System.out.printf( "%-15s%03d%n" , p ,pn );
        System.out.println("================================");
    }
}