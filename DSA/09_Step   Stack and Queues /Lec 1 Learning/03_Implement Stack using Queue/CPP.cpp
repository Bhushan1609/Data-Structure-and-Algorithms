#include<bits/stdc++.h>
using namespace std;

class MyStack {
    queue<int>q;
public:
    void push(int x) {
        int size=q.size();
        q.push(x);
        for(int i=1;i<=size;i++){
            q.push(q.front());
            q.pop();
        }
    }
    int pop() {
        int val=q.front();
        q.pop();
        return val;
    }
    int top() {
        return q.front();
    }
    bool empty() {
        return q.empty();
    }
};

int main(){
    #ifndef ONLING_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    return 0;
}