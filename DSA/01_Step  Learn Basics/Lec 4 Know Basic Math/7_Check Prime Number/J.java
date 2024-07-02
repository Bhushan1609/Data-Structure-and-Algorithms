import java.util.*;
public class J{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int cnt=0;
        for(int i=1;i<=(Math.sqrt(n));i++){
            if(n%i == 0){
                cnt++;
                if(!(n/i == i))cnt++;
            }
        }
        if(cnt==2 || n==1)System.out.println("YES");
        else System.out.println("NO");
    }
    
}