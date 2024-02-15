#include <bits/stdc++.h>
using namespace std;
int memoization(int index,vector<int>&nums,vector<int>&dp){
    if(index<0) return 0;
    if(dp[index]!=-1)return dp[index];
    int take=nums[index]+memoization(index-2,nums,dp);
    int nottake=memoization(index-1,nums,dp);
    return dp[index]=max(take,nottake);
}
int Tabulation(vector<int>&nums){
    int n=nums.size();
    vector<int>dp(n,0);
    dp[0]=nums[0];
    for(int i=1;i<n;i++){
        int take=0,nottake=0;
        if(i-2>=0) take = nums[i]+dp[i-2];
        if(i-1>=0) nottake=dp[i-1];
        dp[i]=max(take,nottake);
    }
    return dp[n-1];
}
int Optimal(vector<int>&nums){
    int prev2=0,prev=nums[0],n=nums.size();
    for(int i=1;i<n;i++){
        int take=nums[i],nottake=0;
        if(i-2>=0) take = nums[i]+prev2;
        if(i-1>=0) nottake=prev;
        prev2=prev;
        prev=max(take,nottake);
    }
    return prev;
}
int main(){
    vector<int>nums={1,2,3,1};
    vector<int>dp(5,-1);
    // cout<<memoization(3,nums,dp)<<endl;
    // cout<<Tabulation(nums)<<endl;
    cout<<Optimal(nums)<<endl;
    return 0;
}