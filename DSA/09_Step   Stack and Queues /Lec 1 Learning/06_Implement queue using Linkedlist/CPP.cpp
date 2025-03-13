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

class MyQueue{
private:
    int Size;
    LLNode* start;
    LLNode* end;
public:
    MyQueue(){
        start=end=NULL;
        Size=0;
    }
    void push(int x){
        if(!start){
            start=end=new LLNode(x);
            return;
        }
        end->next=new LLNode(x);
        end=end->next;
        ++Size;
    }
    void pop(){
        if(!start)
            return;
        LLNode* node=start;
        start=start->next;
        if(!start)
            end=NULL;
        delete node;
        --Size;
        return;
    }
    int top(){
        if(!start)
            return -1;
        return start->data;
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
    return 0;
}   