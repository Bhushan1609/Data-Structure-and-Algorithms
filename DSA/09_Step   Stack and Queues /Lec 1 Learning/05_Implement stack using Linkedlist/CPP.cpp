#include<bits/stdc++.h>
using namespace std;

class LLNode{
public:
    int data;
    LLNode* next;
    LLNode(int data){
        this->data=data;
        next=NULL;
    }
};

class MyStack{
private:
    int Size;
    LLNode* top;
public:
    MyStack(){
        top=NULL;
        Size=0;
    }
    void push(int x){
        LLNode* node=new LLNode(x);
        node->next=top;
        top=node;
        ++Size;
    }
    void pop(){
        if(!top)
            return;
        LLNode* node=top;
        top=top->next;
        delete node;
        --Size;
        return;
    }
    int Top(){
        if(!top)
            return -1;
        return top->data;
    }
    int size(){
        return Size;
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
    st.push(12);
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    return 0;
}   