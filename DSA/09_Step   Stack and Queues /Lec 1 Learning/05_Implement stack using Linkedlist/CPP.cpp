#include<bits/stdc++.h>
using namespace std;

class LLNode{
public:
    int data;
    LLNode *next;
    LLNode(int data){
        this->data=data;
        next=NULL;
    }
};

class MyStack{
private:
    int size;
    LLNode* top;
public:
    MyStack(){
        size=0;
        top=NULL;
    }
    void push(int x){
        LLNode* temp=new LLNode(x);
        temp->next=top;
        top=temp;
        ++size;
    }
    void pop(){
        if(!top)
            return ;
        top=top->next;
        --size;
        return;
    }
    int Size(){
        return size;
    }
    int Top(){
        if(!top)
            return -1;
        return top->data;
    }
};

int main(){
    #ifndef ONLING_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    MyStack myStack=MyStack();
    myStack.push(1);
    myStack.push(2);
    cout<<myStack.Top()<<endl;
    myStack.pop();
    cout<<myStack.Size()<<endl;
    return 0;
}