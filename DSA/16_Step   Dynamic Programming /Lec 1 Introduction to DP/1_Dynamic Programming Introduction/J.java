import java.util.*;
public class J{
    static long recursion(int n,long[] dpr){
        if(n<=1)return n;
        if(dpr[n] != 0)return dpr[n];
        return dpr[n]=(recursion(n-1,dpr) + recursion(n-2,dpr)) % 1000000007;
    }
    static long topDown(int n) {
        long[] dpr=new long[n+1];
        return recursion(n,dpr);
    }

    static long bottomUp(int n) {
        int[] dp=new int[n+1];
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=(dp[i-1] + dp[i-2])%1000000007;
        }
        return dp[n];
    }
    static long spaceOptimize(int n) {
        long p1=0,p2=1,ans;
        for(int i=2;i<=n;i++){
            ans=(p1+p2)%1000000007;
            p1=p2;
            p2=ans;
        }
        return p2;
    }
    public static void main(String[] args){
        System.out.println(topDown(5));
        System.out.println(bottomUp(5));
        System.out.println(spaceOptimize(5));
    }
}