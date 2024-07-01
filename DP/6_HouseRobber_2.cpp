#include <bits/stdc++.h>
using namespace std;
long long int memoization(int index,vector<int>&nums,vector<long long int>&dp){
    if(index<0) return 0;
    if(dp[index]!=-1)return dp[index];
    long long int take=nums[index]+memoization(index-2,nums,dp);
    long long int nottake=memoization(index-1,nums,dp);
    return dp[index]=max(take,nottake);
}
long long int Tabulation(vector<int>&nums){
    int n=nums.size();
    vector<long long int>dp(n,0);
    dp[0]=(long long int)nums[0];
    for(int i=1;i<n;i++){
        long long int take=0,nottake=0;
        if(i-2>=0) take = nums[i]+dp[i-2];
        if(i-1>=0) nottake=dp[i-1];
        dp[i]=max(take,nottake);
    }
    return dp[n-1];
}
long long int Optimal(vector<int>&nums){
    long long int prev2=0,prev=nums[0],n=nums.size();
    for(int i=1;i<n;i++){
        long long int take=nums[i],nottake=0;
        if(i-2>=0) take = nums[i]+prev2;
        if(i-1>=0) nottake=prev;
        prev2=prev;
        prev=max(take,nottake);
    }
    return prev;
}
int main(){
    vector<int>valueInHouse={1,2,3,1};
    int n=valueInHouse.size();
    if(n==1)return valueInHouse[0];
    vector<int>temp1,temp2;
    for(int i=0;i<n;i++){
        if( i != 0)temp2.push_back(valueInHouse[i]);
        if(i != n-1)temp1.push_back(valueInHouse[i]);
    }
    // vector<long long int>dp1(n,-1);
    // long long int ans1=memoization(n-2,temp1,dp1);
    // vector<long long int>dp2(n,-1);
    // long long int ans2=memoization(n-2,temp2,dp2);
    // return max(ans1,ans2);

    // long long int ans1=Tabulation(temp1);
    // long long int ans2=Tabulation(temp2);
    // return max(ans1,ans2);


    // long long int ans1=Optimal(temp1);
    // long long int ans2=Optimal(temp2);
    // return max(ans1,ans2);
    return 0;
}