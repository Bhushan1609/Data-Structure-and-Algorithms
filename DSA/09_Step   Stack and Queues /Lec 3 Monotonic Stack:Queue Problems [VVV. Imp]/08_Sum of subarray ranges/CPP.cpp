#include<bits/stdc++.h>
using namespace std;

//TC-O(N^3)
//SC-O(1)
int callBrute(vector<int>& arr) {
    int n=arr.size();
    int sum=0;
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++){
            int mini=INT_MAX;
            int maxi=INT_MIN;
            for(int k=i;k<=j;k++){
                mini=min(mini,arr[k]);
                maxi=max(maxi,arr[k]);
            }
            sum=(sum+maxi-mini);
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
        int maxi=INT_MIN;
        for(int j=i;j<n;j++){
            mini=min(mini,arr[j]);
            maxi=max(maxi,arr[j]);
            sum=(sum+maxi-mini);
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

vector<int> prevGreaterElement(vector<int>&arr){
    int n=arr.size();
    stack<int>st;
    vector<int>pge(n);
    for(int i=0;i<n;i++){
        if(st.empty())
            pge[i]=-1;
        else{
            while(!st.empty() && arr[st.top()]<=arr[i])
                st.pop();
            if(st.empty())
                pge[i]=-1;
            else
                pge[i]=st.top();
        }
        st.push(i);
    }
    return pge;
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

vector<int> nextGreaterElement(vector<int>&arr){
    int n=arr.size();
    stack<int>st;
    vector<int>nge(n);
    for(int i=n-1;i>=0;i--){
        if(st.empty())
            nge[i]=n;
        else{
            while(!st.empty() && arr[st.top()]<arr[i])
                st.pop();
            if(st.empty())
                nge[i]=n;
            else
                nge[i]=st.top();
        }
        st.push(i);
    }
    return nge;
}

//TC-O(10N)
//SC-O(10N)
long long callOptimal(vector<int>& arr) {
    int n=arr.size();
    long long ans=0;
    vector<int>pse=prevSmallerElement(arr),nse=nextSmallerElement(arr); 
    vector<int>pge=prevGreaterElement(arr),nge=nextGreaterElement(arr);   
    for(int i=0;i<n;i++){
        pse[i]=i-pse[i];
        nse[i]=nse[i]-i;
        pge[i]=i-pge[i];
        nge[i]=nge[i]-i;
        ans=(ans-1LL*pse[i]*nse[i]*arr[i]);
        ans=(ans+1LL*pge[i]*nge[i]*arr[i]);
    }
    return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    vector<int>arr={1,4,3,2};
    cout<<callBrute(arr)<<endl;
    cout<<callBetter(arr)<<endl;
    cout<<callOptimal(arr)<<endl;
    return 0;
}
