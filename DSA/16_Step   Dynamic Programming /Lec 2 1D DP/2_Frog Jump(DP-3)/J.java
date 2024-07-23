import java.util.*;
public class J{
    static int topDown(int index,int[] h,int[] dp){
        if(index<=0) return (index == 0) ? 0 : Integer.MAX_VALUE;
        if(dp[index] != 0)return dp[index];
        int oneStep=Integer.MAX_VALUE,twoStep=Integer.MAX_VALUE;
        if(index-1 >= 0) oneStep=Math.abs(h[index] - h[index-1]) + topDown(index-1,h,dp);
        if(index-2 >= 0) twoStep=Math.abs(h[index] - h[index-2]) + topDown(index-2,h,dp);
        return dp[index]=Math.min(oneStep,twoStep);
    }
    static int BottomUp(int N,int[] h){
        int[] dp=new int[N];
        for(int i=1;i<N;i++){
            int oneStep=Integer.MAX_VALUE,twoStep=Integer.MAX_VALUE;
            if(i-1 >= 0) oneStep=Math.abs(h[i] - h[i-1])+dp[i-1];
            if(i-2 >= 0) twoStep=Math.abs(h[i] - h[i-2])+dp[i-2];
            dp[i]=Math.min(oneStep,twoStep);
        }
        return dp[N-1];
    }
    static int spaceOptimize(int N,int[] h){
        int p1=0,p2=0,curr;
        for(int i=1;i<N;i++){
            int oneStep=Integer.MAX_VALUE,twoStep=Integer.MAX_VALUE;
            if(i-1 >= 0) oneStep=Math.abs(h[i] - h[i-1])+p1;
            if(i-2 >= 0) twoStep=Math.abs(h[i] - h[i-2])+p2;
            curr=Math.min(oneStep,twoStep);
            p2=p1;
            p1=curr;
        }
        return p1;
    }
    public static void main(String[] args){
        int[] dp=new int[1000001];
        int[] h={1,2,3,4};
        System.out.println(topDown(h.length - 1,h,dp));
        System.out.println(BottomUp(h.length,h));
        System.out.println(spaceOptimize(h.length,h));
    }
}