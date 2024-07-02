import java.util.Scanner;

public class J {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        for (int i = 1; i <= n; i++) {
            char x = (char) ('A' + n - 1);
            for (int j = 0; j < i; j++) {
                System.out.print(x + " ");
                x--;
            }
            System.out.println();
        }
        
        sc.close();
    }
}
