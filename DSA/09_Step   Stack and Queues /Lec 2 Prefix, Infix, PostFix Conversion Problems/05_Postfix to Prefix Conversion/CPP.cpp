#include<bits/stdc++.h>
using namespace std;

string postToPre(string s) {
    int i=0;
    stack<string>st;
    while(i<s.size()){
        string add;
        if((s[i]>='A' && s[i]<='Z') or (s[i]>='a' && s[i]<='z') or (s[i]>='0' && s[i]<='9')){
            add+=s[i];
        }else{
            string first=st.top();
            st.pop();
            string second=st.top();
            st.pop();
            add+=s[i];
            add+=second;
            add+=first;
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
    cout<<postToPre("AB-DE+F*/")<<endl;
    return 0;
}