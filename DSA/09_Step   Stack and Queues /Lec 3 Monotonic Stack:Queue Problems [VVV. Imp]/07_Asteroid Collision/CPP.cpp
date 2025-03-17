#include<bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids){
    int n=asteroids.size();
    vector<int>ans;
    vector<int>st;
    for(int i=0;i<n;i++){
        if(asteroids[i]>0)
            st.push_back(i);
        else{
            while(!st.empty() && asteroids[st.back()] < abs(asteroids[i]))
                st.pop_back();
            if(st.empty())
                ans.push_back(asteroids[i]);
            else
                if(asteroids[st.back()] == abs(asteroids[i]))
                    st.pop_back();
        }
    }
    for(auto &i:st)
        ans.push_back(asteroids[i]);
    return ans;
}

int main(){
    #ifndef ONLING_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    vector<int>arr={4,7,1,1,2,-3,-7,17,15,-16};
    for(auto &i:asteroidCollision(arr)){
        cout<<i<<" ";
    }cout<<endl;
    return 0;
}   