#include<bits/stdc++.h>
using namespace std;

string postToInfix(string s) {
    stack<string>st;
    int i=0;
    while(i<s.size()){
        string add;
        if((s[i]>='A' && s[i]<='Z') or (s[i]>='a' && s[i]<='z') or (s[i]>='0' && s[i]<='9')){
            add+=s[i];
        }else{
            string second=st.top();
            st.pop();
            string first=st.top();
            st.pop();
            add+="("+first+s[i]+second+")";
        }
        st.push(add);
        i++;
    }
    return st.top();
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    cout<<postToInfix("AB-DE+F*/")<<endl;
    return 0;
}