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
        if(!flag){
            for(int j=0;j<i;j++){
                if(nums[j]>nums[i]){
                    flag=true;
                    ans[i]=nums[j];
                    break;
                }
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
    for(int i=2*n-1;i>=0;i--){
        while(!st.empty() && nums[i%n]>=st.top())
            st.pop();
        if(i<n)
            ans[i]=(st.empty()?-1:st.top());  
        st.push(nums[i%n]);
    }
    return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    vector<int>nums={2,10,12,1,11};
    for(auto &i:callBrute(nums))
        cout<<i<<" ";
    cout<<endl;

    for(auto &i:callOptimal(nums))
        cout<<i<<" ";
    cout<<endl;
    return 0;
}