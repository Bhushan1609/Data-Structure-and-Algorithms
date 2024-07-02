#include<bits/stdc++.h>
using namespace std;
// const int mod = 1e9+7;
// int dp[101][100001];
// int recursion(int i,int sum , vector<int>&arr){
// 	if(i==-1) return sum==0?1:0;
// 	if(sum==0)return 1;
// 	if(dp[i][sum]!=-1)return dp[i][sum];
// 	int ntake=recursion(i-1,sum,arr)%mod;
// 	int take=0;
// 	if(arr[i]<=sum) take=recursion(i-1,sum-arr[i],arr)%mod;
// 	return dp[i][sum]=(take+ntake)%mod;
// }
// int tabulation(int n,int sum,vector<int>&arr){
// 	vector<vector<int>>dp(n,vector<int>(sum+1,0));
// 	for(int i=0;i<n;i++)dp[i][0]=1;
// 	if(arr[0]<=sum)dp[0][arr[0]]=1;
// 	for(int i=1;i<n;i++){
// 		for(int j=0;j<=sum;j++){
// 			int ntake=dp[i-1][j];
// 			int take=0;
// 			if(arr[i]<=j) take=dp[i-1][j-arr[i]];
// 			dp[i][j]=(take+ntake);
// 		}
// 	}
// 	return dp[n-1][sum];
// }
int optimal(int n,int sum,vector<int>&arr){
	vector<int>prev(sum+1,0),curr(sum+1,0);
	for(int i=0;i<n;i++)prev[0]=1;
	if(arr[0]<=sum)prev[arr[0]]=1;
	for(int i=1;i<n;i++){
		for(int j=0;j<=sum;j++){
			int ntake=prev[j];
			int take=0;
			if(arr[i]<=j) take=prev[j-arr[i]];
			curr[j]=(take+ntake);
		}
        prev=curr;
	}
	return prev[sum];
}
int main(){
    int n=1,target=1;
    vector<int>arr={1};
    cout<<"Value fot : "<<n<<" is: "<<(int)optimal(n,target,arr)<<endl;
	for(int i=0;i<20;i++){
		arr.push_back(n+1);
		n+=1;
		target+=1;
    	cout<<"Value fot : "<<n<<" is: "<<(int)optimal(n,target,arr)<<endl;
	}

    // memset(dp,-1,sizeof(dp));
    // cout<<(int)recursion(n-1,target,arr)<<endl;
    // cout<<(int)tabulation(n,target,arr)<<endl;
    // return 0;
}