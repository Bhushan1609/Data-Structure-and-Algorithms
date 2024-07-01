import java.util.*;
public class J{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        for(int i=1;i<=(n<<1)-1;i++){
            if(i<=n)for(int j=0;j<i;j++)System.out.print("*");
            else for(int j=0;j<(n-(i-n));j++)System.out.print("*");
            System.out.println();         
        }
    }
}