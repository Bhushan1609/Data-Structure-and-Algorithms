import java.util.*;
public class J{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int dup=n;
        int palindrome=0;
        while(n != 0){
            palindrome=palindrome*10+n%10;
            n/=10;
        }
        if(palindrome==dup)System.out.println("YES");
        else System.out.println("NO");
        System.out.println();
    }
}