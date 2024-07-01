#include<bits/stdc++.h>
using namespace std;
//Memoization
int memoization(int n,int k,vector<int> &heights,vector<int>&dp){
    if(n==0) return 0;
    if(dp[n]!=-1)return dp[n];
    int minSteps=INT_MAX;
    for(int i=1;i<=k;i++){
        if(n-i>=0){
            int ans = abs(heights[n]-heights[n-i]) + memoization(n-i,k,heights,dp);
            minSteps=min(minSteps,ans);
        }
    }
    return dp[n]=minSteps;
}
//Tabulation
int Tabulation(int n,int k,vector<int> &heights,vector<int>&dp){
    dp[0]=0;
    for(int i=1;i<=n;i++){
        int minSteps=INT_MAX;
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                int ans = abs(heights[i]-heights[i-j]) + Tabulation(i-j,k,heights,dp);
                minSteps=min(minSteps,ans);
            }
        }
        dp[i]=minSteps;
    }
    return dp[n];
}
int main(){
    int n,k;cout<<"Enter n and k: "; cin >> n >> k;
    vector<int>heights= {10,20,30,10};
    // vector<int>dp(n,-1);
    //cout<<"Minimum Cost to reach N : "<< memoization(n,heights,dp)<<endl;
    vector<int>dp(n,0);
    cout<<"Minimum Cost to reach N : "<< Tabulation(n-1,k,heights,dp)<<endl;
    return 0;
}