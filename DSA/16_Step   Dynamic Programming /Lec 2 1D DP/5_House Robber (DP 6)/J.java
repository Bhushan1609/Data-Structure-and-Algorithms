import java.util.*;
public class J{
    static int topDown(int index,int[] nums,int[] dp){
        if(index<=0)return (index == 0) ? nums[0] : 0;
        if(dp[index] != -1)return dp[index];
        int ntake=topDown(index-1,nums,dp);
        int take=nums[index] + topDown(index-2,nums,dp);
        return dp[index] = Math.max(ntake,take);
    }
    static int BottomUp(int[] nums){
        int[] dp=new int[nums.length+1];
        dp[0]=nums[0];
        for(int index=1;index<nums.length;index++){
            dp[index] = Math.max(dp[index-1],(index>=2) ? (nums[index]+dp[index-2]) : nums[index]);
        }
        return dp[nums.length-1];
    }
    static int spaceOptimize(int[] nums){
        if(nums.length == 1)return nums[0];
        int prev=nums[0];
        int prev2=nums[1];
        for(int index=1;index<nums.length;index++){
            int curr = Math.max(prev,(index>=2) ? (nums[index]+prev2) : prev2);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
    public static void main(String[] args){
        int[] nums={1,2,3,1};
        int[] dp=new int[101];
        for(int i=0;i<101;i++)dp[i]=-1;
        System.out.println(topDown(nums.length-1,nums,dp));
        System.out.println(BottomUp(nums));
        System.out.println(spaceOptimize(nums));
    }
}