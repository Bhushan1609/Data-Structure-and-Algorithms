#include<bits/stdc++.h>
using namespace std;
int memoization(int i,int j,vector<vector<int>> &matrix,int n,int m,vector<vector<int>>&dp){
    if(i==n-1) return matrix[i][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int leftDown=INT_MIN,down=INT_MIN,rightDown=INT_MIN;
    if(i+1<n and j-1>=0)leftDown=memoization(i+1,j-1,matrix,n,m,dp);
    if(i+1<n)down=memoization(i+1,j,matrix,n,m,dp);
    if(i+1<n and j+1<m)rightDown=memoization(i+1,j+1,matrix,n,m,dp);
    return dp[i][j]=matrix[i][j]+max({leftDown,down,rightDown});
}
int tabulation(vector<vector<int>> &matrix,int n,int m){
    vector<vector<int>>dp(n,vector<int>(m,0));
    for(int j=0;j<m;j++){
        dp[0][j]=matrix[0][j];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int leftDown=INT_MIN,down=INT_MIN,rightDown=INT_MIN;
            if(i-1>=0 and j+1<m)leftDown=dp[i-1][j+1];
            if(i-1>=0)down=dp[i-1][j];
            if(i-1>=0 and j-1>=0)rightDown=dp[i-1][j-1];
            dp[i][j]=matrix[i][j]+max({leftDown,down,rightDown});
        }
    }
    int maxi=dp[n-1][0];
    for(int j=0;j<m;j++){
        maxi=max(maxi,dp[n-1][j]);
    }
    return maxi;
}
int optimal(vector<vector<int>> &matrix,int n,int m){
    vector<int>prev;
    for(int j=0;j<m;j++){
        prev.push_back(matrix[0][j]);
    }
    for(int i=1;i<n;i++){
        vector<int>curr(m,0);
        for(int j=0;j<m;j++){
            int leftDown=INT_MIN,down=INT_MIN,rightDown=INT_MIN;
            if(j+1<m)leftDown=prev[j+1];
            down=prev[j];
            if(j-1>=0)rightDown=prev[j-1];
            curr[j]=matrix[i][j]+max({leftDown,down,rightDown});
        }
        prev=curr;
    }
    int maxi=prev[0];
    for(int j=0;j<m;j++){
        maxi=max(maxi,prev[j]);
    }
    return maxi; 
}
int main(){
    int ans=INT_MIN;
    vector<vector<int>>matrix{
        {1,2,10,9},
        {100,3,2,1},
        {1,1,20,2},
        {1,2,2,1}
    };
    int n=matrix.size(),m=matrix[0].size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    for(int j=0;j<m;j++){
        int result=memoization(0,j,matrix,n,m,dp);
        ans=max(ans,result);
    }
    cout<<ans<<endl;
    cout<<tabulation(matrix,n,m)<<endl;
    cout<<optimal(matrix,n,m)<<endl;
    return  0;
}