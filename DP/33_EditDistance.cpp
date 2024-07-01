#include<bits/stdc++.h>
using namespace std;
int dp[501][501];
int recursion(int i, int j,string a , string b){
    if(j==0)return i;
    if(i==0)return j;
    if(dp[i][j]!=-1)return dp[i][j];
    if(a[i-1]==b[j-1]) return dp[i][j]=recursion(i-1,j-1,a,b);
    else return dp[i][j]=min({1+recursion(i,j-1,a,b),1+recursion(i-1,j,a,b),1+recursion(i-1,j-1,a,b)});
}
int tabulation(string a,string b){
    int n=a.size();
    int m=b.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++)dp[i][0]=i;
    for(int j=0;j<=m;j++)dp[0][j]=j;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=min({1+dp[i][j-1],1+dp[i-1][j],1+dp[i-1][j-1]});
        }
    }
    return dp[n][m];
}
int optimal(string a,string b){
    int n=a.size();
    int m=b.size();
    vector<int>prev(m+1,0),curr(m+1,0);
    for(int j=0;j<=m;j++)prev[j]=j;
    for(int i=1;i<=n;i++){
        curr[0]=i;
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]) curr[j]=prev[j-1];
            else curr[j]=min({1+curr[j-1],1+prev[j],1+prev[j-1]});
        }
        prev=curr;
    }
    return prev[m];
}
int main(){
    string s="horse",t="ros";
    memset(dp,-1,sizeof(dp));
    int ans=recursion(s.size(),t.size(),s,t);
    cout<<ans<<endl;
    int ans1=tabulation(s,t);
    cout<<ans1<<endl;
    int ans2=optimal(s,t);
    cout<<ans2<<endl;
    return 0;
}