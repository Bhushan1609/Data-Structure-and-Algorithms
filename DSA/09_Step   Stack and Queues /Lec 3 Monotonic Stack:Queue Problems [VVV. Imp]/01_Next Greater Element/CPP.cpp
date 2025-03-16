#include<bits/stdc++.h>
using namespace std;

vector<int> callBrute(vector<int>&nums){
    int n=nums.size();
    vector<int>ans(n);
    for(int i=0;i<n;i++){
        bool flag=false;
        for(int j=i+1;j<n;j++){
            if(nums[j]>nums[i]){
                flag=true;
                ans[i]=nums[j];
                break;
            }
        }
        if(!flag)
            ans[i]=-1;
    }
    return ans;
}

vector<int> callOptimal(vector<int>&nums){
    int n=nums.size();
    vector<int>ans(n);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        if(st.empty())
            ans[i]=-1;
        else{
            while(!st.empty() && nums[i]>st.top())
                st.pop();
            if(st.empty())
                ans[i]=-1;
            else
                ans[i]=st.top();
        }
        st.push(nums[i]);
    }
    return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    vector<int>nums={6,0,8,1,3};
    for(auto &i:callBrute(nums))
        cout<<i<<" ";
    cout<<endl;

    for(auto &i:callOptimal(nums))
        cout<<i<<" ";
    cout<<endl;
    return 0;
}