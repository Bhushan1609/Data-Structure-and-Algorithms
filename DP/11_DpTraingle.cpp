#include <bits/stdc++.h>
using namespace std;
int memoization(int i, int j , vector<vector<int>>& triangle, int n,vector<vector<int>>&dp){
	if(i==n-1) return triangle[i][j];
	if(dp[i][j]!=-1) return dp[i][j];
	int right =INT_MAX,downRight=INT_MAX;
	right = memoization(i+1,j,triangle,n,dp);
	downRight = memoization(i+1,j+1,triangle,n,dp);
	return dp[i][j]=triangle[i][j]+min(right,downRight);
}
int tabulation(vector<vector<int>>& triangle,int n){
	vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++){
        dp[n - 1][i] = triangle[n - 1][i];
    }
	for (int i = n - 2; i >= 0; i--){
        for (int j = 0; j <= i; j++){
            dp[i][j]=min(dp[i+1][j],dp[i+1][j+1])+triangle[i][j];
        }
    }
    return dp[0][0];
}
int optimal(vector<vector<int>>& triangle,int n){
	vector<int>dp(n,0);
	for (int i = 0; i < n; i++){
        dp[i] = triangle[n-1][i];
    }
    for (int i = n - 2; i >= 0; i--){
        for (int j = 0; j <=i ; j++){
            dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
        }
    }
    return dp[0];
}
int main(){
    vector<vector<int>>triangle{
        {1},
        {2,3},
        {3,6,7},
        {8,9,6,10}
    };
    int n=triangle.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
	cout<<memoization(0,0,triangle,n,dp)<<endl;
	cout<<tabulation(triangle,n)<<endl;
	cout<<optimal(triangle,n)<<endl;
    return 0;
}