#include<bits/stdc++.h>
using namespace std;

class MyStack{
private:
    int arr[1000];
    int top;
public:
    MyStack(){
        top=-1;
    }
    int pop(){
        if(top!=-1){
            return arr[top--];
        }
        return top;
    }
    void push(int x){
        if(top<1000){
           top+=1;
           arr[top]=x;
        }
    }
    int size(){
        return top+1;
    }
    int Top(){
        if(top!=-1){
            return arr[top];
        }
        return -1;
    }
};

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    MyStack myStack=MyStack();
    cout<<myStack.Top()<<endl;
    myStack.push(12);
    cout<<myStack.size()<<endl;
    myStack.push(13);
    myStack.push(14);
    myStack.push(15);
    cout<<myStack.Top()<<endl;
    myStack.pop();
    myStack.pop();
    cout<<myStack.Top()<<endl;
    myStack.pop();
    cout<<myStack.Top()<<endl;
    return 0;
}