import java.util.*;
public class J{
    static int topDown(int index,int k,int[] h,int[] dp){
        if(index<=0) return (index == 0) ? 0 : Integer.MAX_VALUE;
        if(dp[index] != 0)return dp[index];
        int oneStep=Integer.MAX_VALUE;
        for(int i=1;i<=k;i++){
            if(index-i >= 0) oneStep=Math.min(oneStep,Math.abs(h[index] - h[index-i]) + topDown(index-i,k,h,dp));
        }
        return dp[index]=oneStep;
    }
    static int BottomUp(int N,int k,int[] h){
        int[] dp=new int[N+1];
        for(int index=1;index<N;index++){
            int oneStep=Integer.MAX_VALUE;
            for(int i=1;i<=k;i++){
                if(index-i >= 0) oneStep=Math.min(oneStep,Math.abs(h[index] - h[index-i]) + dp[index-i]);
            }
            dp[index]=oneStep;
        }
        return dp[N-1];
    }
    public static void main(String[] args){
        int[] dp=new int[1001];
        int[] h={1,2,3,4};
        int k=2;
        System.out.println(topDown(h.length-1,k,h,dp));
        System.out.println(BottomUp(h.length,k,h));
    }
}