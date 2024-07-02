import java.util.*;
public class J{
    static void rec(int n){
        if(n==0)return ;
        System.out.println(n);
        rec(n-1);
    }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        rec(n);
    }
}