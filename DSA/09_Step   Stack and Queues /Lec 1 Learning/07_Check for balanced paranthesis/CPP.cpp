#include<bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    stack<char>st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(' or s[i]=='{' or s[i]=='['){
            st.push(s[i]);
        }else{
            if(s[i]==')'){
                if(st.empty()){
                    return false;
                }else{
                    if(st.top() != '('){
                        return false;
                    }else{
                        st.pop();
                    }
                }
            }else if(s[i]=='}'){
                if(st.empty()){
                    return false;
                }else{
                    if(st.top() != '{'){
                       return false;
                    }else{
                        st.pop();
                    }
                }   
            }else if(s[i]==']'){
                if(st.empty()){
                    return false;
                }else{
                    if(st.top() != '['){
                        return false;
                    }else{
                        st.pop();
                    }
                }
            }
        }
    }
    return st.empty() ;
}

int main(){
    #ifndef ONLING_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    cout<<"Valid or Not : "<<isValid("()")<<endl;
    return 0;
}