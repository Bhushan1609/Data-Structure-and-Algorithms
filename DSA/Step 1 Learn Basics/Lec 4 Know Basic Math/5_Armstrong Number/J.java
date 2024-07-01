import java.util.*;
public class J{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int dup=n;
        int add=0;
        while(n!=0){
            int cube=n%10;
            add+=(cube*cube*cube);
            n/=10;
        }
        if(add==dup)System.out.println("YES");
        else System.out.println("NO");
        System.out.println();
    }
}