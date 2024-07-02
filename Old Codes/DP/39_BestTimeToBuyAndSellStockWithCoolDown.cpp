#include<bits/stdc++.h>
using namespace std;
int getAns(vector<int> Arr, int ind, int buy, int n, vector<vector<int>> &dp) {
    if (ind >= n) return 0;
    if (dp[ind][buy] != -1)
        return dp[ind][buy];
        
    int profit;
    if (buy == 0) { // We can buy the stock
        profit = max(0 + getAns(Arr, ind + 1, 0, n, dp), -Arr[ind] + getAns(Arr, ind + 1, 1, n, dp));
    }
    if (buy == 1) { // We can sell the stock
        profit = max(0 + getAns(Arr, ind + 1, 1, n, dp), Arr[ind] + getAns(Arr, ind + 2, 0, n, dp));
    }
    return dp[ind][buy] = profit;
}
int main(){
    vector<int>Arr={1,2,4,5};
    int n = Arr.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    int ans = getAns(Arr, 0, 0, n, dp);
    cout<<ans<<endl;
    // long answer1=tabulation(values,4);
    // cout<<answer1<<endl;
    // long answer3=optimal2(values,4);
    // cout<<answer3<<endl;
    return 0;
}