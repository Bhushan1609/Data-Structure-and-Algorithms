import java.util.*;
public class J{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        for(int i=0;i<n;i++){
            char ch='A';
            for(int j=0;j<n-i-1;j++)System.out.print(" ");
            for(int j=1;j<=2*i+1;j++){
                System.out.print(ch+" ");
                if(j <= (2*i+1)/2)ch++;
                else {
                    ch--;
                }
            }
            for(int j=0;j<n-i-1;j++)System.out.print(" ");
            System.out.println();
        }
    }
}