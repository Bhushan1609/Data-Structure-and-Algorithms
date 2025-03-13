#include<bits/stdc++.h>
using namespace std;

class MyQueue{
private:
    int Size=100;
    int arr[100];
    int curr_size;
    int start;
    int end;
public:
    MyQueue(){
        curr_size=0;
        start=-1;
        end=-1;
    }
    void push(int x){
        if(curr_size==Size){
            cout<<"Queue Size Exceeded"<<endl;
            return ;
        }else if(curr_size==0){
            start=end=0;
        }else{
            end=(end+1)%Size;
        }
        ++curr_size;
        arr[end]=x;
        return;
    }
    void pop(){
        if(!curr_size){
            return ;
        }else if(curr_size==1){
            start=end=-1;
        }else{
            start=(start+1)%Size;
        }
        --curr_size;
        return;
    }
    int top(){
        if(!curr_size)
            return -1;
        return arr[start]; 
    }
    int size(){
        return curr_size;
    }
};

int main(){
    #ifndef ONLING_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    MyQueue q=MyQueue();
    q.push(10);
    q.push(10);
    cout<<q.size()<<endl;
    q.pop();
    cout<<q.size()<<endl;
    cout<<q.top()<<endl;
    return 0;
}   