#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int dp[1001][1001];
int recursion(int i, int j,string a,string b){
    if(j==0)return 1;
    if(i==0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(a[i-1]==b[j-1]) return dp[i][j]=(recursion(i-1,j-1,a,b)%mod+recursion(i-1,j,a,b)%mod);
    return dp[i][j]=recursion(i-1,j,a,b)%mod;
}
int tabulation(string a,string b){
    int n=a.size(),m=b.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++)dp[i][0]=1;
    for(int j=1;j<=m;j++)dp[0][j]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]) dp[i][j]=(dp[i-1][j-1]%mod+dp[i-1][j]%mod);
            else dp[i][j]=dp[i-1][j]%mod;
        }
    }
    return dp[n][m];
}
int optimal(string a,string b){
    int n=a.size(),m=b.size();
    vector<int>prev(m+1,0),curr(m+1,0);
    prev[0]=curr[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]) curr[j]=(prev[j-1]%mod+prev[j]%mod);
            else curr[j]=prev[j]%mod;
        }
        prev=curr;
    }
    return prev[m];
}
int optimal2(string a,string b){
    int n=a.size(),m=b.size();
    vector<int>prev(m+1,0);
    prev[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            if(a[i-1]==b[j-1]) prev[j]=(prev[j-1]%mod+prev[j]%mod);
        }
    }
    return prev[m];
}
int main(){
    string s="babgbag",t="bag";
    memset(dp,-1,sizeof(dp));
    int ans=recursion(s.size(),t.size(),s,t);
    cout<<ans<<endl;
    int ans1=tabulation(s,t);
    cout<<ans1<<endl;
    int ans2=optimal(s,t);
    cout<<ans2<<endl;
    int ans3=optimal2(s,t);
    cout<<ans3<<endl;
    return 0;
}