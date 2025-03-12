#include<bits/stdc++.h>
using namespace std;

class stImple{
public:
    int stack[10],interator=-1;
    stImple(){
        for(int i=0;i<10;i++)
            stack[i]=0;
    }
    void push(int val){
        if(interator+1>=10){
            cout<<"Stack Size Exceeded !!!"<<endl;
            return ;
        }
        interator+=1;
        stack[interator]=val;
    }
    int top(){
        if(interator!=-1)
            return stack[interator];
        cout<<"Stack is Empty : "<<endl;
        return -1;
    }
    void pop(){
        if(interator!=-1)
            interator-=1;
    }
    int size(){
        if(interator==-1)
            return 0;
        return interator+1;
    }
};

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    stImple myStack=stImple();
    cout<<myStack.top()<<endl;
    myStack.push(12);
    cout<<myStack.size()<<endl;
    myStack.push(13);
    myStack.push(14);
    myStack.push(15);
    myStack.push(15);
    myStack.push(15);
    myStack.push(15);
    myStack.push(15);
    myStack.push(15);
    myStack.push(15);
    myStack.push(15);
    myStack.push(15);
    myStack.push(15);
    myStack.push(15);
    cout<<myStack.top()<<endl;
    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop();
    cout<<myStack.top()<<endl;
    myStack.pop();
    cout<<myStack.top()<<endl;
    return 0;
}