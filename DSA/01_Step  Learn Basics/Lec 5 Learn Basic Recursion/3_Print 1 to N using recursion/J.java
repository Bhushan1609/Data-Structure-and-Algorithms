import java.util.*;
public class J{
    static void rec(int a,int n){
        if(a>n)return ;
        System.out.println(a);
        rec(a+1,n);
    }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        rec(1,n);
    }
}