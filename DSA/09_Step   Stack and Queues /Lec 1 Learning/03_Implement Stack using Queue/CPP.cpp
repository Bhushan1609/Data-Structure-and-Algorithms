#include<bits/stdc++.h>
using namespace std;

class MyStack{
    queue<int>q;
public:
    void push(int x){
        int rev_size=q.size();
        q.push(x);
        for(int i=0;i<rev_size;i++){
            q.push(q.front());
            q.pop();
        }
        return ;
    }
    void pop(){
        q.pop();
    }
    int top(){
        return q.front();
    }
    int size(){
        return q.size();
    }
};

int main(){
    #ifndef ONLING_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    MyStack st=MyStack();
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.size()<<endl;
    st.pop();
    cout<<st.size()<<endl;
    cout<<st.top()<<endl;
    return 0;
}   