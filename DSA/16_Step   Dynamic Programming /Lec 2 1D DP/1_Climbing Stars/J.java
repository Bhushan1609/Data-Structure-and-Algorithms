import java.util.*;
public class J{
    static int topDown(int n,int[] dp){
        if(n<=0)return (n == 0) ? 1 : 0;
        if(dp[n] != 0)return dp[n];
        return dp[n]=topDown(n-1,dp) + topDown(n-2,dp);
    }
    static int BotttomUp(int n){
        int[] dp=new int[n+1];
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    static int spaceOptimize(int n){
        int p1=1,p2=1,curr;
        for(int i=2;i<=n;i++){
            curr=p1+p2;
            p1=p2;
            p2=curr;
        }
        return p2;
    }
    public static void main(String[] args){
        int n=10;
        int[] dp=new int[n+1];
        System.out.println(topDown(n,dp));
        System.out.println(BotttomUp(n));
        System.out.println(spaceOptimize(n));
    }
}