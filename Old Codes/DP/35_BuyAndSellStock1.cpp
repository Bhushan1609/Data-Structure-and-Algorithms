#include<bits/stdc++.h>
using namespace std;
int maximumProfit(vector<int> &prices){
    int n=prices.size();
    int maxi=0;
    int mini=prices[0];
    for(int i=1;i<n;i++){
        maxi=max(maxi,prices[i]-mini);
        mini=min(mini,prices[i]);
    }
    return maxi;
}
int main(){
    vector<int>a={1,2,3,4};
    int answer=maximumProfit(a);
    cout<<answer<<endl;
    return 0;
}