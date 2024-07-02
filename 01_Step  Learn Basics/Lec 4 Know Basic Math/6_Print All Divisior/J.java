import java.util.*;
public class J{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        for(int i=1;i<=(Math.sqrt(n));i++){
            if(n%i == 0){
                System.out.print(i+" ");
                if(!(n/i == i))System.out.print(n/i+" ");
            }
        }
    }
    
}