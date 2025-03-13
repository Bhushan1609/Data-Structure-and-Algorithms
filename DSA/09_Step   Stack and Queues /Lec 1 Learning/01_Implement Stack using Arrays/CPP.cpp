#include<bits/stdc++.h>
using namespace std;

class MyStack{
private:
    int arr[100];
    int top;
public:
    MyStack(){
        top=-1;
    }
    void push(int x){
        if(top+1>=100){
            cout<<"Stack Size Exceeded"<<endl;
            return;
        }
        ++top;
        arr[top]=x;
        return;
    }
    void pop(){
        if(top>-1)
            --top;
        return;
    }
    int Top(){
        if(top==-1)
            return -1;
        return arr[top];
    }
    int size(){
        return top+1;
    }
};

int main(){
    #ifndef ONLING_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    MyStack st=MyStack();
    st.push(10);
    cout<<st.size()<<endl;
    st.pop();
    cout<<st.size()<<endl;
    cout<<st.Top()<<endl;
    return 0;
}   