#include<bits/stdc++.h>
using namespace std;

class MyQueue{
    stack<int>st1,st2;
public:
    void push(int x){
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(x);
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        return ;
    }
    void pop(){
        st1.pop();
    }
    int top(){
        return st1.top();
    }
    int size(){
        return st1.size();
    }
};
// What if there is lots of push calls that lead to higher time complexity also high amortized cost
// to reduce time complexity following code will helpful
// also both code have 2*N dynamic space Complexity
class MyQueue{
    stack<int>st1,st2;
public:
    void push(int x){
        st1.push(x);
    }
    void pop(){
        if(!st2.empty())
            st2.pop();
        else{
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            st2.pop();
        }
    }
    int top(){
        if(!st2.empty())
            return st2.top();
        else{
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        return st2.top();
    }
    int size(){
        return st1.size()+st2.size();
    }
};
int main(){
    #ifndef ONLING_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    MyQueue q=MyQueue();
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout<<q.size()<<endl;
    q.pop();
    cout<<q.size()<<endl;
    q.pop();
    cout<<q.size()<<endl;
    cout<<q.top()<<endl;
    return 0;
}   