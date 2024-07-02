#include <bits/stdc++.h>
using namespace std;
int tabulation(vector<int>&arr,int n){
    int k=0,mini=INT_MAX;
	for(auto i:arr)k+=i;
	vector<vector<bool>>dp(n,vector<bool>(k+1,false));
    for(int i=0;i<n;i++) dp[i][0]=true;
    dp[0][arr[0]]=true;
    for(int index=1;index<n;index++){
        for(int target=1;target<=k;target++){
            bool npick=dp[index-1][target];
            bool pick=false;
            if(arr[index]<=target)pick=dp[index-1][target-arr[index]];
            dp[index][target]=(pick or npick);
        }
    }
    for (int sum = 0; sum <= k/2; sum++) {
        if(dp[n-1][sum]==true){
			mini=min(mini,abs(2*sum-k));
		}
    }
    return mini;
}
int optimal(vector<int>&arr , int n){
    int k=0,mini=INT_MAX;
	for(auto i:arr)k+=i;
	vector<bool>prev(k+1,0),curr(k+1,0);
    prev[0]=curr[0]=true;
    for(int i=0;i<n;i++) prev[0]=true;
    prev[arr[0]]=true;
    for(int index=1;index<n;index++){
        for(int target=1;target<=k;target++){
            bool npick=prev[target];
            bool pick=false;
            if(arr[index]<=target)pick=prev[target-arr[index]];
            curr[target]=(pick or npick);
        }
        prev=curr;
    }
    for (int sum = 0; sum <= k/2; sum++) {
        if(prev[sum]==true){
			mini=min(mini,abs(2*sum-k));
		}
    }
    return mini;
}
int main(){
    vector<int>arr={1,2,3,4};
    int n=arr.size();
    cout<<(int)tabulation(arr,n)<<endl;
    cout<<(int)optimal(arr,n)<<endl;
    return 0;
}