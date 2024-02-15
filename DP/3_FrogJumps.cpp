#include<bits/stdc++.h>
using namespace std;
//Memoization
int memoization(int n,vector<int> &heights,vector<int>&dp){
    if(n==0) return 0;
    if(dp[n]!=-1)return dp[n];
    int left=INT_MAX,right=INT_MAX;
    if(n-1>=0) left=abs(heights[n-1]-heights[n])+memoization(n-1,heights,dp);
    if(n-2>=0) right=abs(heights[n-2]-heights[n])+memoization(n-2,heights,dp);
    return dp[n]=min(left,right);
}
//Tabulation
int Tabulation(int n,vector<int> &heights,vector<int>&dp){
    dp[0]=0;
    for(int i=1;i<=n;i++){
        int left=INT_MAX,right=INT_MAX;
        if(i-1>=0) left=abs(heights[i-1]-heights[i])+dp[i-1];
        if(i-2>=0) right=abs(heights[i-2]-heights[i])+dp[i-2];
        dp[i]=min(left,right);
    }
    return dp[n];
}
int main(){
    int n;cout<<"Enter n : "; cin >> n;
    vector<int>heights= {10,20,30,10};
    // vector<int>dp(n,-1);
    //cout<<"Minimum Cost to reach N : "<< memoization(n-1,heights,dp)<<endl;
    vector<int>dp(n,0);
    cout<<"Minimum Cost to reach N : "<< Tabulation(n-1,heights,dp)<<endl;
    return 0;
}