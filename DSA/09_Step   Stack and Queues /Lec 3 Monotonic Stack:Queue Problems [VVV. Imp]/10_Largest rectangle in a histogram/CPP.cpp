#include<bits/stdc++.h>
using namespace std;

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

int callBrute(vector<int>&heights){
    int n=heights.size();
    int ans=0;
    vector<int>pse=prevSmallerElement(heights),nse=nextSmallerElement(heights);
    for(int i=0;i<n;i++)
        ans=max(ans,(nse[i]-pse[i]-1)*heights[i]);
    return ans;
}

int callOptimal(vector<int>&heights){
    int n=heights.size();
    int ans=0;
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && heights[st.top()]>heights[i]){
            int element=heights[st.top()];
            st.pop();
            int nse=i;
            int pse=(st.empty()?-1:st.top());
            ans=max(ans,(nse-pse-1)*element);
        }
        st.push(i);
    }
    while(!st.empty()){
        int element=heights[st.top()];
        st.pop();
        int nse=n;
        int pse=(st.empty()?-1:st.top());
        ans=max(ans,(nse-pse-1)*element);
    }
    return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    vector<int>heights={2,1,5,6,2,3};
    cout<<callBrute(heights)<<endl;
    cout<<callOptimal(heights)<<endl;
    return 0;
}
