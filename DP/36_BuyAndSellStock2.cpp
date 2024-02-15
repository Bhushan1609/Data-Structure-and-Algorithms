#include<bits/stdc++.h>
using namespace std;
long recursion(int index,int buy,long *v,vector<vector<long>>&dp,int n){
    if(index==n)return 0;
    if(dp[index][buy]!=-1)return dp[index][buy];
    long profit=0;
    if(buy){
        profit=max(-v[index]+recursion(index+1,0,v,dp,n),recursion(index+1,1,v,dp,n));
    }
    else{
        profit=max(v[index]+recursion(index+1,1,v,dp,n),recursion(index+1,0,v,dp,n));
    }
    return dp[index][buy]=profit;
}
long tabulation(long *v,int n){
    vector<vector<long>>dp(n+1,vector<long>(3,0));
    dp[n][0]=dp[n][1]=0;
    for(int index=n-1;index>=0;index--){
        for(int buy=0;buy<2;buy++){
            long profit=0;
            if(buy){
                profit=max(-v[index]+dp[index+1][0],dp[index+1][1]);
            }
            else{
                profit=max(v[index]+dp[index+1][1],dp[index+1][0]);
            }
            dp[index][buy]=profit;
        }
    }
    return dp[0][1];
}
long optimal(long *v,int n){
    vector<long>ahead(2,0),curr(2,0);
    ahead[0]=ahead[1]=0;
    for(int index=n-1;index>=0;index--){
        for(int buy=0;buy<2;buy++){
            long profit=0;
            if(buy){
                profit=max(-v[index]+ahead[0],ahead[1]);
            }
            else{
                profit=max(v[index]+ahead[1],ahead[0]);
            }
            curr[buy]=profit;
        }
        ahead=curr;
    }
    return ahead[1];
}
long optimal2(long *v,int n){
    long a1=0,a2=0,b1=0,b2=0;
    for(int index=n-1;index>=0;index--){
        b2=max(-v[index]+a1,a2);
        b1=max(v[index]+a2,a1);
        a2=b2;
        a1=b1;
    }
    return a2;
}
int main(){
    long values[4]={1,2,3,4};
    vector<vector<long>>dp(4+1,vector<long>(3,-1));
    long answer=recursion(0,1,values,dp,4);
    cout<<answer<<endl;
    long answer1=tabulation(values,4);
    cout<<answer1<<endl;
    long answer3=optimal2(values,4);
    cout<<answer3<<endl;
    return 0;
}