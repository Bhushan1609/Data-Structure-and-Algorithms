#include<bits/stdc++.h>
using namespace std;
int memoization(int n,int m,vector<vector<int>>& grid,vector<vector<int>>& dp){
    if(n==0 and m==0) return grid[n][m];
    if(n<0 or m<0) return INT_MAX;
    if(dp[n][m]!=-1) return dp[n][m];
    int left=memoization(n,m-1,grid,dp);
    int up=memoization(n-1,m,grid,dp);
    if(left<0) left=0;
    if(up<0) up=0;
    return dp[n][m]=grid[n][m]+min(left,up);
}
int tabulation(int n, int m , vector<vector<int>>&grid){
    vector<vector<int>>dp(n,vector<int>(m,0));
    dp[0][0]=grid[0][0];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 and j==0) dp[i][j]=grid[0][0];
            else{  
                int left=INT_MAX,up=INT_MAX; 
                if(j>0) left=dp[i][j-1];
                if(i>0) up=dp[i-1][j];
                dp[i][j]=grid[i][j]+min(left,up);
            }
        }
    }
    return dp[n-1][m-1];
}
int optimal(int n, int m , vector<vector<int>>&grid){
    vector<int>prev(m, 0);
    for(int i=0; i<n; i++){
        vector<int>curr(m, 0);
        for(int j=0; j<m; j++){
            if(i == 0 && j == 0) curr[j] = grid[i][j];
            else{
                int up = 1e9;
                int left = 1e9;
                if(i>0){
                    up = prev[j];
                }
                if (j > 0) {
                  left = curr[j-1];
                }
                curr[j] = grid[i][j] + min(up, left);
            }
        }
        prev=curr;
    }
    return prev[m-1];
}
int main(){
    int n=2 , m = 3;
    vector <vector<int>> grid={
       {5, 9, 6},
        {11, 5, 2}
    };
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    cout<< memoization(n-1,m-1,grid,dp)<<endl;
    cout<< tabulation(n,m,grid)<<endl;
    cout<< optimal(n,m,grid)<<endl;
    return 0;
}