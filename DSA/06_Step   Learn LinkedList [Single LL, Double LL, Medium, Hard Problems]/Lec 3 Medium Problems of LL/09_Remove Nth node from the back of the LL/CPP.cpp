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

#define overload4(a, b, c, d, e, ...) e
#define overload3(a, b, c, d, ...) d
#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)
#define all(x) x.begin(), x.end()
#define len(x) ll(x.size())
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define SUM(v) accumulate(all(v),(int)0)

template <class T>
using vd=vector<T>;
template <class T>
using vdd=vector<vd<T>>;
template <class T>
using vddd=vector<vdd<T>>;
template <class T>
using vdddd=vector<vddd<T>>;
template <class T>
using vddddd=vector<vdddd<T>>;
template <class T>
using q=queue<T>;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-const-variable"
const int mod = 1e9 + 7; 
vd<pi<int, int>> gridMoves = { {-1, 0}, {0, -1}, {0, 1}, {1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };
#pragma GCC diagnostic pop

/*MaxHeap*/
template <class T>
using pq=priority_queue<T>;
/*MinHeap*/
template <class T>
using pqg=priority_queue<T,vector<T>, greater<T>>;

/*FOR*/
#define FOR1(a) for(ll _=0;_<ll(a);++_)
#define FOR2(i,a) for(ll i=0;i<ll(a);++i)
#define FOR3(i,a,b) for(ll i=a;i<ll(b);++i)
#define FOR4(i,a,b,c) for (ll i =a;i<ll(b);i+=(c))
/*FOR_R*/
#define FOR1_R(a) for (ll i =(a)-1;i>=ll(0);--i)
#define FOR2_R(i,a) for (ll i=(a)-1;i>=ll(0);--i)
#define FOR3_R(i,a,b) for(ll i=(b)-1;i>=ll(a);--i)

/*Declare 2d/3d(type,name,size,size1,size2,....)*/
#define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__))))
#define vvvv(type, name, a, b, c, ...) vector<vector<vector<vector<type>>>> name( a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))

/*Read 1d/2d(type,name,size,size1)*/
#define VEC(type, name, size) vector<type> name(size); read(name)
#define VV(type, name, h, w) vector<vector<type>> name(h, vector<type>(w)); read(name)

class Node{

public:
    int data;
    Node* next=NULL;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }

    Node(int data,Node* next){
        this->data=data;
        this->next=next;
    }

};

Node* arrayToLL(vd<int>&vec){
    Node* head=new Node(vec[0]);
    Node* mover=head;
    FOR(i,1,len(vec)){
        Node* newNode=new Node(vec[i]);
        mover->next=newNode;
        mover=newNode;
    }
    return head;
}

void printLL(Node* head){
    while(head){
        cout<<(head->data)<<" ";
        head=head->next;
    }
    return print("");
}

Node* callBrute(Node* head,int n){
    int cnt=0;
    Node* temp=head;
    while(temp){
        cnt+=1;
        temp=temp->next;
    }
    if(cnt==n){
        Node* newHead=head->next;
        delete(head);
        return newHead;
    }
    int result=cnt-n;
    temp=head;
    while(temp){
        result--;
        if(result==0){
            Node* delNode=temp->next;
            temp->next=temp->next->next;
            delete(delNode);
            break;
        }
        temp=temp->next;
    }
    return head;
}

Node* callOptimal(Node* head,int n){
    Node* fast=head;
    FOR(i,n) if(fast)fast=fast->next;
    if(!fast) return head->next;
    Node* slow=head;
    while(fast->next){
        fast=fast->next;
        slow=slow->next;
    }
    Node* delNode=slow->next;
    slow->next=slow->next->next;
    delete(delNode);
    return head;
}

void solve(){
    vd<int>vec={1,2,3,4,5};
    Node* head=arrayToLL(vec);
    printLL(head);

    // head=callBrute(head,5);    
    // printLL(head);

    // head=callOptimal(head,5);
    // printLL(head);
}

int main(){
    SPEEDUP;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ll tc=1;
    // LL(tc);
    auto start1 = high_resolution_clock::now();
    while(tc--) solve();
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    cerr<<"Time: "<<duration.count()/1000<<" ms"<<endl;
    return 0;
}
    