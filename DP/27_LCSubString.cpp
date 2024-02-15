#include <bits/stdc++.h>
using namespace std;
int recursion(int i, int j,string a,string b,vector<vector<int>>&dp){
    if(i<0 or j<0)return 0;
    if(a[i]!=b[j]) return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    return dp[i][j]=1+recursion(i-1,j-1,a,b,dp);
}
int tabultaion(string a, string b){
    int n=a.size();
    int m=b.size();
    int ans=0;
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++)dp[i][0]=0;
    for(int j=0;j<=m;j++)dp[0][j]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=0;
            ans=max(ans,dp[i][j]);
        }
    }
    return ans;
}
int optimal(string a, string b){
    int n=a.size();
    int m=b.size();
    int ans=0;
    vector<int>prev(m+1,0),curr(m+1,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]) curr[j]=1+prev[j-1];
            else curr[j]=0;
            ans=max(ans,curr[j]);
        }
        prev=curr;
    }
    return ans;
}
int main(){
    string str1="abcdBhushan",str2="Bhushan";
    int ans=0;
    int n=str1.size(),m=str2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            ans=max(ans,recursion(i,j,str1,str2,dp));
        }
    }
    cout<<ans<<endl;
    cout<<tabultaion(str1,str2)<<endl;
    cout<<optimal(str1,str2)<<endl;
    return 0;
}