#include<bits/stdc++.h>
using namespace std;
int Memoization(int n,vector<int>&dp){
    if(n<=0)return n==0 ? 1 : 0;
    if(dp[n]!=-1)return dp[n];
    return dp[n]=Memoization(n-1,dp)+Memoization(n-2,dp);
}
int Tabulation(int n,vector<int>&dp){
    dp[0]=0;dp[1]=1;
    if(n<=1)return dp[n];
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int main(){
    int n;cout<<"Enter n : ";cin>>n;
    vector<int>dp(n+1,-1);
    cout<<"Number of Ways : "<< Memoization(n,dp) <<endl;
}