#include<bits/stdc++.h>
#include <chrono>
#define SPEEDUP cin.tie(NULL)->sync_with_stdio(false)

using namespace std;
using namespace std::chrono;
using ll=long long;
using u32=unsigned int;
using u64=unsigned long long;

template <class T,class P>
using pi=pair<T,P>;

#define INT(...)int __VA_ARGS__; IN(__VA_ARGS__)
#define LL(...)ll __VA_ARGS__; IN(__VA_ARGS__)
#define STR(...)string __VA_ARGS__; IN(__VA_ARGS__)
#define CHR(...)char __VA_ARGS__; IN(__VA_ARGS__)
#define DBL(...)long double __VA_ARGS__; IN(__VA_ARGS__)

void read(int &a){cin>>a;}
void read(long long &a){cin>>a;}
void read(char &a){cin>>a;}
void read(double &a){cin>>a;}
void read(long double &a){cin>>a;}
void read(string &a){cin>>a;}

template<class T,class S>void read(pair<T,S>&p){read(p.first),read(p.second);}
template<class T>void read(vector<T>&a){for(auto &i:a)read(i);}
template <class T>void read(T &a){cin >> a;}
void IN(){}
template<class Head,class... Tail>void IN(Head &head, Tail &...tail) {read(head);IN(tail...);}
template<typename T,typename U>
ostream& operator<<(ostream& os, const pair<T, U>& A){os<<A.fi<<" "<<A.se;return os;}
template <typename T>
ostream& operator<<(ostream& os,const vector<T>&A) {
    for(size_t i=0;i<A.size();i++){
        if(i) os<<" ";
        os << A[i];
    }
    return os;
}
void print(){cout << '\n';cout.flush();}
template <class Head,class... Tail>
void print(Head&& head, Tail&&... tail) {
    cout<<head;
    if(sizeof...(Tail)) cout<<" ";
    print(forward<Tail>(tail)...);
}

#define dbg(x...){cout<< "("<< #x<<")"<< " = (";Print(x);} 
template<typename T1>void Print(T1 t1) {cout<< t1 << " )" <<endl;} 
template<typename T1,typename... T2>
void Print(T1 t1, T2... t2) {cout<<t1<<" , ";Print(t2...);}

void YES(bool t=1) {print(t?"YES":"NO");}
void NO(bool t=1) {YES(!t);}
void Yes(bool t=1) {print(t?"Yes":"No");}
void No(bool t=1) {Yes(!t);}
void yes(bool t=1) {print(t?"yes":"no");}
void no(bool t=1) {yes(!t);}

class Node{

public:
    int data;
    Node* next=NULL;
    Node* back=NULL;

    Node(int data){
        this->data=data;
        this->next=NULL;
        this->back=NULL;
    }

    Node(int data,Node* next,Node* back){
        this->data=data;
        this->next=next;
        this->back=back;
    }

};

Node* arrayToDLL(vector<int>&vec){
    Node* head=new Node(vec[0]);
    Node* prev=head;
    for(size_t i=1;i<vec.size();i++){
        Node* temp=new Node(vec[i]);
        prev->next=temp;
        temp->back=prev;
        prev=temp;
    }
    return head;
}

void printDLL(Node* head){
    while(head){
        cout<<(head->data)<<" ";
        head=head->next;
    }
    return print("");
}

Node* insertBeforeHead(Node* head,int val){
    Node* newHead=new Node(val,head,NULL);
    head->back=newHead;
    return newHead;
}

Node* insertBeforeTail(Node* head,int val){
    if(!head->next){
        return insertBeforeHead(head,val);
    }
    Node* temp=head;

    while(temp->next) temp=temp->next;

    Node* prev=temp->back;

    Node* newNode=new Node(val,temp,prev);
    prev->next=newNode;
    temp->back=newNode;

    return head;
}

Node* insertBeforeK(Node* head,int k,int val){
    if(k==1) return insertBeforeHead(head,val);
    Node* temp=head;
    int cnt=0;

    while(temp){
        cnt+=1;
        if(cnt==k)break;
        temp=temp->next;
    }

    Node* prev=temp->back;
    Node* newNode=new Node(val,temp,prev);
    prev->next=newNode;
    temp->back=newNode;
    return head;
}

void insertBeforeNode(Node* node,int val){
    Node* prev=node->back;
    Node* newNode=new Node(val,node,prev);
    prev->next=newNode;
    node->back=newNode;
    return ;
}

void solve(){
    vector<int>vec={1,2,3,4,5,6,7,8,9,10};
    Node* head=arrayToDLL(vec);
    printDLL(head);

    // head=insertBeforeHead(head,-1);
    // printDLL(head);

    // head=insertBeforeTail(head,-1);
    // printDLL(head);

    // head=insertBeforeK(head,5,-1);
    // printDLL(head);

    // insertBeforeNode(head->next,-1);
    // printDLL(head);

}

int main(){
    SPEEDUP;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ll tc=1;
    // LL(tc);
    auto start1 = chrono::high_resolution_clock::now();
    while(tc--) solve();
    auto stop1 = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop1 - start1);
    cerr<<"Time: "<<duration.count()/1000<<" ms"<<endl;
    return 0;
}