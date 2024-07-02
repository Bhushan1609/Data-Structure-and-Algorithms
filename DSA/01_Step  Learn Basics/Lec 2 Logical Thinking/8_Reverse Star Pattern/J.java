import java.util.*;
public class J{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++)System.out.print(" ");
            for(int j=0;j<((n<<1) - ((i<<1)+1) );j++)System.out.print("*");
            for(int j=0;j<i;j++)System.out.print(" ");
            System.out.println();
        }
    }
}