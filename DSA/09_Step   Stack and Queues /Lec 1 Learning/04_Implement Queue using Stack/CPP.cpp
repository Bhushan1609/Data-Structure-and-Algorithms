#include<bits/stdc++.h>
using namespace std;

class MyQueue {
    stack<int>s1,s2;
public:
    void push(int x) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    int pop() {
        int val=s1.top();
        s1.pop();
        return val;
    }
    int peek() {
        return s1.top();
    }
    bool empty() {
        return s1.empty();
    }
};

// What if there is lots of push calls that lead to higher time complexity also high amortized cost
// to reduce time complexity following code will helpful
// also both code have 2*N dynamic space Complexity
class MyQueue {
    stack<int>s1,s2;
public:
    void push(int x) {
       s1.push(x); 
    }
    int pop(){
        int val;
        if(!s2.empty()){
            val=s2.top();
            s2.pop();
        }else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            val=s2.top();
            s2.pop();
        }
        return val;
    }
    int peek(){
        if(!s2.empty()){
            return s2.top();
        }else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }
    bool empty(){
        return s2.empty() && s1.empty();
    }
};

int main(){
    #ifndef ONLING_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    return 0;
}