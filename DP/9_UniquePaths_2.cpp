#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int memoization(int n , int m ,vector<vector<int>>&mat,vector<vector<int>>&dp){
    if(n<0 or m<0) return 0;
    if(n==0 and m==0) return 1;
    if(mat[n][m]==-1) return 0;
    if(dp[n][m]!=-1) return dp[n][m];
    int left=0,up=0;
    left = memoization(n,m-1,mat,dp);
    up = memoization(n-1,m,mat,dp);
    return dp[n][m]=(left+up)%mod;
}
int tabulation(int n , int m ,vector<vector<int>>&mat){
    vector<vector<int>>dp(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==-1) dp[i][j]=0;
            else if(i==0 and j==0) dp[i][j]=1;
            else{
                int left=0,up=0;
                if(i>0) up=dp[i-1][j];
                if(j>0) left=dp[i][j-1];
                dp[i][j]=(left+up)%mod;
            }
        }
    }
    return dp[n-1][m-1]%mod;
}
int optimal(int n ,int m,vector<vector<int>>& mat){
    vector<int>prev(m,0);
    for(int i=0;i<n;i++){
        vector<int>curr(m,0);
        for(int j=0;j<m;j++){
            if(i==0 and j==0) curr[j]=1;
            else if(mat[i][j]==-1) curr[j]=0;
            else{
                int up = 0 , left = 0;
                if(i>0) up=prev[j];
                if(j>0) left=curr[j-1];
                curr[j]=(up+left)%mod;
            }
        }
        prev=curr;
    }
    return prev[m-1]%mod;
}
int main(){
    int m=3,n=3;
    vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
    vector<vector<int>>vec{
        {0 ,0 ,0 },
        {0 ,-1, 0}, 
        {0, 0, 0}
    };
    cout<<"Number of Unique Paths is : "<< memoization(m-1,n-1,vec,dp) <<endl;
    cout<<"Number of Unique Paths is : "<< tabulation(m,n,vec) <<endl;
    cout<<"Number of Unique Paths is : "<< optimal(m,n,vec) <<endl;

    return 0;
}