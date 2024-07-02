#include<bits/stdc++.h>
using namespace std;
int recursion(int index,int buy,int cap,vector<int>&prices,vector<vector<vector<int>>>&dp){
    if(cap==0)return 0;
    if(index>=prices.size())return 0;
    if(dp[index][buy][cap]!=-1)return dp[index][buy][cap];
    int profit=0;
    if(buy){
        profit=max(-prices[index]+recursion(index+1,0,cap,prices,dp),recursion(index+1,buy,cap,prices,dp));
    }
    else{
        profit=max(prices[index]+recursion(index+1,1,cap-1,prices,dp),recursion(index+1,buy,cap,prices,dp));
    }
    return dp[index][buy][cap]=profit;
}
int tabulation(vector<int>prices){
    int n=prices.size();
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    for(int index=0;index<=n;index++){
        for(int buy=0;buy<=1;buy++){
            dp[index][buy][0]=0;
        }
    }
    for(int buy=0;buy<=1;buy++){
        for(int cap=0;cap<=2;cap++){
            dp[n][buy][cap]=0;
        }
    }
    for(int index=n-1;index>=0;index--){
        for(int buy=0;buy<=1;buy++){
            for(int cap=1;cap<=2;cap++){
                if(buy){
                    dp[index][buy][cap]=max(-prices[index]+dp[index+1][0][cap],dp[index+1][1][cap]);
                }
                else{
                    dp[index][buy][cap]=max(prices[index]+dp[index+1][1][cap-1],dp[index+1][0][cap]);
                }
            }
        }
    }
    return dp[0][1][2];
}
int optimal(vector<int>prices){
    int n=prices.size();
    vector<vector<int>>after(2,vector<int>(3,0));
    vector<vector<int>>curr(2,vector<int>(3,0));
    for(int index=0;index<=n;index++){
        for(int buy=0;buy<=1;buy++){
            curr[buy][0]=0;
        }
    }
    for(int buy=0;buy<=1;buy++){
        for(int cap=0;cap<=2;cap++){
            curr[buy][cap]=0;
        }
    }
    for(int index=n-1;index>=0;index--){
        for(int buy=0;buy<=1;buy++){
            for(int cap=1;cap<=2;cap++){
                if(buy){
                    curr[buy][cap]=max(-prices[index]+after[0][cap],after[1][cap]);
                }
                else{
                    curr[buy][cap]=max(prices[index]+after[1][cap-1],after[0][cap]);
                }
            }
        }
        after=curr;
    }
    return after[1][2];
}
int main(){
    vector<int>prices={3, 3, 5, 0, 3, 1, 4};
    vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,-1)));
    int answer=recursion(0,1,2,prices,dp);
    cout<<answer<<endl;
    int answer1=tabulation(prices);
    cout<<answer1<<endl;
    int answer2=optimal(prices);
    cout<<answer2<<endl;
    return 0;
}