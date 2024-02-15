#include <bits/stdc++.h> 
using namespace std;
int dp[101][1001];
int recursion(int wt,int index,vector<int>&weight,vector<int>&value){
	if(wt==0) return 0;
	if(index==0){
		if(wt-weight[0]>=0) return value[0];
		return 0;
	}
	if(dp[index][wt]!=-1)return dp[index][wt];
	int take=0;
	if(wt-weight[index]>=0) take=value[index]+recursion(wt-weight[index],index-1,weight,value);
	int ntake=recursion(wt,index-1,weight,value);
	return dp[index][wt]=max(take,ntake);
}
int tabulation(int wt,int n,vector<int>&weight,vector<int>&value){
	vector<vector<int>>dp(n,vector<int>(wt+1,0));
	for(int i=weight[0];i<=wt;i++) dp[0][i]=value[0];
	for(int index=1;index<n;index++){
		for(int w=0;w<=wt;w++){
			int take=0;
			if(w-weight[index]>=0) take=value[index]+dp[index-1][w-weight[index]];
			int ntake=dp[index-1][w];
			dp[index][w]=max(take,ntake);
		}
	}
	return dp[n-1][wt];
}
int optimal(int wt,int n,vector<int>&weight,vector<int>&value){
	vector<int>prev(wt+1,0),curr(wt+1,0);
	for(int i=weight[0];i<=wt;i++) prev[i]=value[0];
	for(int index=1;index<n;index++){
		for(int w=0;w<=wt;w++){
			int take=0;
			if(w-weight[index]>=0) take=value[index]+prev[w-weight[index]];
			int ntake=prev[w];
			curr[w]=max(take,ntake);
		}
        prev=curr;
	}
	return prev[wt];
}
int optimal2(int wt,int n,vector<int>&weight,vector<int>&value){
	vector<int>prev(wt+1,0);
	for(int i=weight[0];i<=wt;i++) prev[i]=value[0];
	for(int index=1;index<n;index++){
		for(int w=wt;w>=0;w--){
			int take=0;
			if(w-weight[index]>=0) take=value[index]+prev[w-weight[index]];
			int ntake=prev[w];
			prev[w]=max(take,ntake);
		}
	}
	return prev[wt];
}
int main(){
    vector<int>weight={10,20,5,3},value={89,100,9,1};
    int n =4,wt=21;
    memset(dp,-1,sizeof(dp));
    cout<<(int)recursion(wt,n-1,weight,value)<<endl;
    cout<<(int)tabulation(wt,n,weight,value)<<endl;
    cout<<(int)optimal(wt,n,weight,value)<<endl;
    cout<<(int)optimal2(wt,n,weight,value)<<endl;
    return 0;
}