#include<bits/stdc++.h>
using namespace std;

// TC-O(N)
// SC-O(2N)
class MinStack{
    stack<pair<int,int>>st;
public:
    void push(int val){
        if(st.empty())
            st.push({val,val});
        else
            st.push({val,min(val,st.top().second)});
    }
    void pop(){
        st.pop();
    }
    int top(){
        return st.top().first;   
    }
    int getMin(){
        return st.top().second;
    }
};

// TC-O(N)
// SC-O(N)
class MinStack{
    stack<long long>st;
    long long mini=INT_MAX;
public:
    void push(int val){
        if(st.empty()){
            st.push(val);
            mini=val;
        }else{
            if(mini>val){
                st.push(1LL*2*val-mini);
                mini=val;
            }else{
                st.push(val);
            }
        }
    }
    void pop(){
        if(st.top()<mini){
            mini=2*mini-st.top();
            st.pop();
        }else{
            st.pop();
        }
    }
    int top(){
        if(st.top()<mini){
            return mini;
        }else{
            return st.top();
        }
    }
    int getMin(){
        return mini;
    }
};

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    return 0;
}