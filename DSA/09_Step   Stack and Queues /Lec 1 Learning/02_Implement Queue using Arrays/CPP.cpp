#include<bits/stdc++.h>
using namespace std;

class MyQueue{
private:
    int front;
    int rear;
    int arr[1000];
public:
    MyQueue(){
        front=rear=-1;
    }
    void push(int x){
        if(rear-front+1==1000){
            cout<<"Array Size Exceeded"<<endl;
            return ;
        }
        if(front==-1 && rear==-1)
            front=rear=0;
        else
            rear=(rear+1)%1000;
        arr[rear]=x;
    }
    void pop(){
        if(front==-1 && rear==-1)
            return ;
        if(rear==front){
            rear=front=-1;
            return;
        }
        front=(front+1)%1000;
        return ;
    }
    int top(){
        if(front==-1 && rear==-1)
            return -1;
        return arr[front];
    }
    
    int size(){
        if(front==-1 && rear==-1)
            return -1;
        return rear-front+1;
    }
};

int main(){
    #ifndef ONLING_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    MyQueue myQueue=MyQueue();

    cout<<myQueue.top()<<endl;
    myQueue.push(2);
    myQueue.push(3);

    myQueue.pop();

    cout<<myQueue.top()<<endl;

    myQueue.pop();

    cout<<myQueue.top()<<endl;

    return 0;
}