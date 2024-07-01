import java.util.*;
public class J{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        for(int i=1;i<=n;i++){
            if((i&1)==1) {
            for(int j=0;j<i;j++){
                    if((j&1)==0)System.out.print("1");
                    else System.out.print("0");
                }
            }
            else{
                for(int j=0;j<i;j++){
                    if((j&1)==1)System.out.print("1");
                    else System.out.print("0");
                }
            }
            System.out.println();
        }
    }
}