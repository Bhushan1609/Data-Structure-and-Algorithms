#include <bits/stdc++.h>
#define nfs cin.tie(NULL)->sync_with_stdio(false)
using namespace std;
using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
template <class T>
using vd = vector<T>;
template <class T>
using vdd = vector<vd<T>>;
template <class T>
using vddd = vector<vdd<T>>;
template <class T>
using vdddd = vector<vddd<T>>;
template <class T>
using vddddd = vector<vdddd<T>>;
template <class T>
using q = queue<T>;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
#define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...) vector<vector<vector<vector<type>>>> name( a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))
#define FOR1(a) for (ll _ = 0; _ < ll(a); ++_)
#define FOR2(i, a) for (ll i = 0; i < ll(a); ++i)
#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)
#define FOR4(i, a, b, c) for (ll i = a; i < ll(b); i += (c))
#define FOR1_R(a) for (ll i = (a)-1; i >= ll(0); --i)
#define FOR2_R(i, a) for (ll i = (a)-1; i >= ll(0); --i)
#define FOR3_R(i, a, b) for (ll i = (b)-1; i >= ll(a); --i)
#define overload4(a, b, c, d, e, ...) e
#define overload3(a, b, c, d, ...) d
#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)
#define all(x) x.begin(), x.end()
#define len(x) ll(x.size())
#define pb emplace_back
#define mp make_pair
#define fi first
#define se second
const int mod = 1e9 + 7;
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define INT(...) int __VA_ARGS__; IN(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__; IN(__VA_ARGS__)
#define STR(...) string __VA_ARGS__; IN(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__; IN(__VA_ARGS__)
#define DBL(...) long double __VA_ARGS__; IN(__VA_ARGS__)
#define VEC(type, name, size) vector<type> name(size); read(name)
#define VV(type, name, h, w) vector<vector<type>> name(h, vector<type>(w)); read(name)
void read(int &a) { cin >> a; }
void read(long long &a) { cin >> a; }
void read(char &a) { cin >> a; }
void read(double &a) { cin >> a; }
void read(long double &a) { cin >> a; }
void read(string &a) { cin >> a; }
template <class T, class S> void read(pair<T, S> &p) { read(p.first), read(p.second); }
template <class T> void read(vector<T> &a) {for(auto &i : a) read(i);}
template <class T> void read(T &a) { cin >> a; }
void IN() {}
template <class Head, class... Tail> void IN(Head &head, Tail &...tail) {read(head);IN(tail...);}
template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& A) {os << A.fi << " " << A.se;return os;}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& A) {
  for (size_t i = 0; i < A.size(); i++) {
    if(i) os << " ";
    os << A[i];
  }
  return os;
}
void printn() {cout << "\n";cout.flush();}
void print() {cout << ' ';cout.flush();}
template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
  cout << head;
  if (sizeof...(Tail)) cout << " ";
  print(forward<Tail>(tail)...);
}

void YES(bool t = 1) { print(t ? "YES" : "NO"); }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { print(t ? "Yes" : "No"); }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { print(t ? "yes" : "no"); }
void no(bool t = 1) { yes(!t); }
int dp[10001][10001] = {0};
int topDown(int index,int w,vd<int>&profit,vd<int>&weight){
    if(index==0) return (w>=weight[0]) ? ( w/weight[0] ) * profit[0] : 0;
    if(dp[index][w] != 0)return dp[index][w];
    int ntake=topDown(index-1,w,profit,weight);
    int take=0;
    if (w >= weight[index]) {
        take=profit[index] + topDown(index, w - weight[index], profit, weight);
    }
    return dp[index][w]=max(take,ntake);
}
int bottomUp(int w,vd<int>&profit,vd<int>&weight){
    vdd<int>dp(len(profit) , vd<int>(w+1 , 0));
    FOR(j,w+1){
        dp[0][j]=( j/weight[0] ) * profit[0] ;
    }
    FOR(i,1,len(profit)){
        FOR(j,w+1){
            int ntake=dp[i-1][j];
            int take=0;
            if(j>=weight[i]){
                take=profit[i] + dp[i][j-weight[i]];
            }
            dp[i][j]=max(take ,ntake);
        }
    }
    return dp[len(profit) - 1][w];
}
int spaceOptmize(int w,vd<int>&profit,vd<int>&weight){
    vd<int>prev(w+1 , 0), curr(w+1 , 0);
    FOR(j,w+1)prev[j]=( j/weight[0] ) * profit[0] ;
    FOR(i,1,len(profit)){
        FOR(j,w+1){
            int ntake=prev[j];
            int take=0;
            if(j>=weight[i]){
                take=profit[i]+curr[j-weight[i]];
            }
            curr[j]=max(take ,ntake);
        }
        swap(curr,prev);
    }
    return prev[w];
}
int spaceOptmize2(int w,vd<int>&profit,vd<int>&weight){
    vd<int>prev(w+1 , 0);
    FOR(j,w+1)prev[j]=( j/weight[0] ) * profit[0] ;
    FOR(i,1,len(profit)){
        FOR(j,w+1){
            int ntake=prev[j];
            int take=0;
            if(j>=weight[i]){
                take=profit[i]+prev[j-weight[i]];
            }
            prev[j]=max(take ,ntake);
        }
    }
    return prev[w];
}
void itachi_1609(){
    int w=10;
    vd<int>profit={5, 11, 13};
    vd<int>weight={2,4,6};
    int n=len(weight);
    print(topDown(n-1 , w , profit , weight));printn();
    print(bottomUp(w,profit,weight));printn();
    print(spaceOptmize(w,profit,weight));printn();
    print(spaceOptmize2(w,profit,weight));printn();
    return;
}
int main(){
    nfs;
    ll tc=1;
    // LL(tc);
    while(tc--)itachi_1609();
   return 0;
}