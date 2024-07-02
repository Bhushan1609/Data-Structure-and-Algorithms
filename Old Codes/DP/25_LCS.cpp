#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int recursion(int i, int j,string a ,string b){
	if(i==0 or j==0) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	int ans=0;
	if(a[i-1]==b[j-1]){
		ans = 1 + recursion(i-1,j-1,a,b);
	}
	else if(a[i-1]!=b[j-1]){ 
		int ans1=recursion(i,j-1,a,b);
		int ans2=recursion(i-1,j,a,b);
		ans=max(ans1,ans2);
	}
	return dp[i][j]=ans;
}
int tabulation(string a, string b){
	int n=a.size(),m=b.size();
	vector<vector<int>>dp(n+1,vector<int>(m+1,0));
	for(int i=0;i<=n;i++)dp[i][0]=0;
	for(int j=0;j<=m;j++)dp[0][j]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i-1]==b[j-1])dp[i][j]=1+dp[i-1][j-1];
			else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
		}
	}
	return dp[n][m];
}
int optimal(string a , string b){
	int n=a.size(),m=b.size();
	vector<int>prev(m+1,0),curr(m+1,0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i-1]==b[j-1])curr[j]=1+prev[j-1];
			else curr[j]=max(curr[j-1],prev[j]);
		}
		prev=curr;
	}
	return prev[m];
}
int main(){
    string a="abcd",b="bcd";
    memset(dp,-1,sizeof(dp));
	cout<<(int)recursion(a.size(),b.size(),a,b)<<endl;
	cout<<(int)tabulation(a,b)<<endl;
	cout<<(int)optimal(a,b)<<endl;

    return 0;
}