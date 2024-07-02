import java.util.*;
public class J{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int start=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++)System.out.print((start++)+" ");
           System.out.println();
        }
    }
}