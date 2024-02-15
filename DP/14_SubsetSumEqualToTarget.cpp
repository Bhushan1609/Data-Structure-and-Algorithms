#include <bits/stdc++.h> 
using namespace std;
bool recursion(int index,int sum,vector<int>&arr,vector<vector<int>>&dp){
    if(sum==0)return true;
    if(index==0) return arr[0]==sum;
    if(dp[index][sum]!=-1) return dp[index][sum];
    bool pick=false;
    if(arr[index]<=sum){
        pick=recursion(index-1,sum-arr[index],arr,dp);
    }
    bool npick=recursion(index-1,sum,arr,dp);
    return dp[index][sum]=(pick or npick);
}
bool tabulation(int n, int k ,vector<int>&arr){
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
    return dp[n-1][k];
}
bool optimal(int n, int k ,vector<int>&arr){
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
    return prev[k];
}
int main(){
    int n=3,k=2;
    vector<int>arr={1,2,3};
    vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
    if(recursion(n-1,k,arr,dp))cout<<"Present"<<endl;
    else cout<<"Absent"<<endl;
    return 0;
}