#include <bits/stdc++.h>
using namespace std;
//Recursive or Memoization
int Memoization(int n,vector<int>&dp){
    if(n<=1)return n;
    if(dp[n]!=-1)return dp[n];
    return dp[n]=Memoization(n-1,dp)+Memoization(n-2,dp);
}
//Tabulation
int Tabulation(int n,vector<int>&dp){
    dp[0]=0;dp[1]=1;
    if(n<=1)return dp[n];
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
//optimal
int Optimal(int n){
    int prev2=0,prev=1;
    for(int i=2;i<=n;i++){
        int curri=prev2+prev;
        prev2=prev;
        prev=curri;
    }
    return prev;
}
int main(){
    int n;cout<<"Enter n : ";cin>>n;
    vector<int>dp(n+1,-1);
    cout<<"Fibonacci Number is : ";
    // cout<<Tabulation(n,dp)<<endl;
    cout<<Optimal(n)<<endl;
    return 0;
}