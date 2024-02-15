#include<bits/stdc++.h>
using namespace std;
int memoization(int index,vector<vector<int>>&points,int check , int n,vector<vector<int>>&dp){
    if(index<0) return 0; 
    int ans=INT_MIN;
    for(int i=0;i<3;i++){
        if(i!=check){
            if(dp[index][i] != -1){
                ans=max(ans,dp[index][i]);
            }
            else{
                int nextDay=points[index][i]+memoization(index-1,points,i,n,dp);
                ans=max(ans,nextDay);
                dp[index][i]=nextDay;
            }
        }
    }
    return ans;
}
int tabulation(int index,vector<vector<int>>& points ){
    
}
int main(){
    vector<vector<int>>points{
        {1,2,5},
        {3,1,1},
        {3,3,3}
    };
    int n=points.size();
    vector<vector<int>>dp(n+1,vector<int>(3,-1));
    int check=-1;
    int ans=memoization(n-1,points,check,n,dp);
    cout<<"Maximum training Points : " << ans << endl;
    return 0;
}