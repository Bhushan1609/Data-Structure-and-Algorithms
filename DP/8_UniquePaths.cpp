#include <bits/stdc++.h>
using namespace std;
int memoization(int x,int y,vector<vector<int>>&dp){
	if(x==0 and y==0)return 1;
	if(x<0 or y<0)return 0;
	if(dp[x][y]!=-1)return dp[x][y];
    int left=memoization(x-1,y,dp);
    int right=memoization(x,y-1,dp);
    return dp[x][y]=left+right;
}
int tabulation(int m,int n){
    vector<vector<int>>dp(m,vector<int>(n,0));
    dp[0][0]=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 and j==0) dp[i][j]=1;
            else{
                int left=0,right=0;
                if(i>0) left=dp[i-1][j];
                if(j>0) right=dp[i][j-1];
                dp[i][j]=left+right;
            }
        }
    }
    return dp[m-1][n-1];
}
int optimal(int m ,int n){
    vector<int>prev(n,0);
    for(int i=0;i<m;i++){
        vector<int>curr(n,0);
        for(int j=0;j<n;j++){
            if(i==0 and j==0) curr[j]=1;
            else{
                int up = 0 , left = 0;
                if(i>0) up=prev[j];
                if(j>0) left=curr[j-1];
                curr[j]=up+left;
            }
        }
        prev=curr;
    }
    return prev[n-1];
}
int main(){
    int m=5,n=5;
    vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
    int ans=memoization(m-1,n-1,dp);
    cout<<"Number of Unique Paths is : "<< ans <<endl;
    cout<<"Number of Unique Paths is : "<< tabulation(m,n) <<endl;
    return 0;
}