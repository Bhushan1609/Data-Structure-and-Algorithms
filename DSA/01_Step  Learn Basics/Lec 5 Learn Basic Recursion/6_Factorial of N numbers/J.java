import java.util.*;
public class J{
    static int rec(int n){
        if(n==0)return 1;
        return n*rec(n-1);
    }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        System.out.println(rec(n));
    }
}