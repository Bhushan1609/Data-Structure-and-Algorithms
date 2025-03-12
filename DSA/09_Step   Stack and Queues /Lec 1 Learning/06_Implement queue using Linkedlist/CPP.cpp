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

class MyQueue{
private:
    int size;
    LLNode* front;
    LLNode* rear;
public:
    MyQueue(){
        size=0;
        front=NULL;
        rear=NULL;
    }
    void push(int x){
        if(!front && !rear){
            front=rear=new LLNode(x);
            ++size;
            return;
        }
        rear->next=new LLNode(x);
        rear=rear->next;
        ++size;
    }
    void pop(){
        if(!front && !rear)
            return ;
        LLNode* node=front;
        if(front && front==rear)
            front=rear=NULL;
        else
            front=front->next;
        delete(node);
        --size;
        return ;
    }
    int Size(){
        return size;
    }
    int top(){
        if(!front)
            return -1;
        return front->data;
    }
};

int main(){
    #ifndef ONLING_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    MyQueue q=MyQueue();
    q.push(2);
    q.push(23);
    q.push(33);    
    cout<<q.Size()<<endl;
    cout<<q.top()<<endl;
    q.pop();
    cout<<q.top()<<endl;
    return 0;
}