#include<bits/stdc++.h>
using namespace std;

int priority(char ch){
    if(ch=='^')
        return 3;
    if(ch=='*' or ch=='/')
        return 2;
    if(ch=='+' or ch=='-')
        return 1;
    return -1;
}        

string infixToPrefix(string s) {
    reverse(s.begin(),s.end());
    string ans;
    int i=0;
    stack<char>st;
    while(i<s.size()){
        if(s[i]=='(')
            s[i]=')';
        else if(s[i]==')')
            s[i]='(';
        if((s[i]>='A' && s[i]<='Z') or (s[i]>='a' && s[i]<='z') or (s[i]>='0' && s[i]<='9')){
            ans+=s[i];
        }else if(s[i]=='('){
            st.push(s[i]);
        }else if(s[i]==')'){
            while(!st.empty() && st.top() != '('){
                ans+=st.top();
                st.pop();
            }
            st.pop(); 
        }else{
            if(s[i]=='^'){
                while(!st.empty() && priority(s[i])<=priority(st.top())){
                    ans+=st.top();
                    st.pop();
                }
            }else{
                while(!st.empty() && priority(s[i])<priority(st.top())){
                    ans+=st.top();
                    st.pop();
                }
            }   
            st.push(s[i]);
        }
        i++;
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    cout<<infixToPrefix("A^B^C")<<endl;
    return 0;
}