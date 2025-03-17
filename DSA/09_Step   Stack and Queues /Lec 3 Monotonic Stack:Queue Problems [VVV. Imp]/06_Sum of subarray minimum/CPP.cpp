#include<bits/stdc++.h>
using namespace std;

const int mod=1E9+7;

//TC-O(N^3)
//SC-O(1)
int callBrute(vector<int>& arr) {
    int n=arr.size();
    int sum=0;
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++){
            int mini=INT_MAX;
            for(int k=i;k<=j;k++)
                mini=min(mini,arr[k]);
            sum=(sum+mini)%mod;
        }
    return sum;
}

//TC-O(N^2)
//SC-O(1)
int callBetter(vector<int>& arr) {
    int n=arr.size();
    int sum=0;
    for(int i=0;i<n;i++){
        int mini=INT_MAX;
        for(int j=i;j<n;j++){
            mini=min(mini,arr[j]);
            sum=(sum+mini)%mod;
        }
    }
    return sum;
}

vector<int> prevSmallerElement(vector<int>&arr){
    int n=arr.size();
    stack<int>st;
    vector<int>pse(n);
    for(int i=0;i<n;i++){
        if(st.empty())
            pse[i]=-1;
        else{
            while(!st.empty() && arr[st.top()]>=arr[i])
                st.pop();
            if(st.empty())
                pse[i]=-1;
            else
                pse[i]=st.top();
        }
        st.push(i);
    }
    return pse;
}

vector<int> nextSmallerElement(vector<int>&arr){
    int n=arr.size();
    stack<int>st;
    vector<int>nse(n);
    for(int i=n-1;i>=0;i--){
        if(st.empty())
            nse[i]=n;
        else{
            while(!st.empty() && arr[st.top()]>arr[i])
                st.pop();
            if(st.empty())
                nse[i]=n;
            else
                nse[i]=st.top();
        }
        st.push(i);
    }
    return nse;
}

//TC-O(5N)
//SC-O(5N)
int callOptimal(vector<int>& arr) {
    int n=arr.size();
    int ans=0;
    vector<int>pse=prevSmallerElement(arr),nse=nextSmallerElement(arr);    
    for(int i=0;i<n;i++){
        pse[i]=i-pse[i];
        nse[i]=nse[i]-i;
        ans=(ans+1LL*pse[i]*nse[i]*arr[i])%mod;
    }
    return ans;
}

int main(){
    #ifndef ONLING_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    vector<int>arr={1,4,6,7,3,7,8,1};
    cout<<callBrute(arr)<<endl;
    cout<<callBetter(arr)<<endl;
    cout<<callOptimal(arr)<<endl;
    return 0;
}   