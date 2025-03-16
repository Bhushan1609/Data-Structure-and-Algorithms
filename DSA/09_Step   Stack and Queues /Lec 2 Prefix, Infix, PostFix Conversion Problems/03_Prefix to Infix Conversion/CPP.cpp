#include<bits/stdc++.h>
using namespace std;

string preToInfix(string s) {
    int i=s.size()-1;
    stack<string>st;
    while(i>=0){
        string add;
        if((s[i]>='A' && s[i]<='Z') or (s[i]>='a' && s[i]<='z') or (s[i]>='0' && s[i]<='9')){
            add+=s[i];
        }else{
            string first=st.top();
            st.pop();
            string second=st.top();
            st.pop();
            add="("+first+s[i]+second+")";
        }
        st.push(add);
        i--;
    }
    return st.top();
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    cout<<preToInfix("*+PQ-MN")<<endl;
    return 0;
}