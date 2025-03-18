#include<bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k) {
    if(k==num.size())
        return "0";
    string st="";
    for(int i=0;i<num.size();i++){
        if(st.empty())
            st.push_back(num[i]);
        else{
            while(!st.empty() && k && st.back()-'0'>num[i]-'0'){
                st.pop_back();
                k--;
            }   
            st.push_back(num[i]);
        }
    }
    while(!st.empty() && k--)
        st.pop_back();   
    string res="";
    while(!st.empty()){
        res+=st.back();
        st.pop_back();
    }
    while(!res.empty() && res.back()=='0')
        res.pop_back();
    reverse(res.begin(),res.end());
    if(res.empty()) 
        return "0";
    return res;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    cout<<removeKdigits("1432219",3)<<endl;
    return 0;
}
