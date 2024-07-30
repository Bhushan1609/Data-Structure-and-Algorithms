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

int topDown(int i,int j,vdd<int>&arr,vdd<int>&dp){
    if(i<0)return 0;
    if(dp[i][j] != -1)return dp[i][j];
    int ans=-1e9;
    FOR(3)if(_ != j) ans=max(ans,arr[i][j]+topDown(i-1,_,arr,dp));
    return dp[i][j]=ans;
}
int bottomUp(vdd<int>&arr){
    int n=len(arr);
    vdd<int>dp(n+1,vd<int>(3,0));
    dp[0][0]=arr[0][0];
    dp[0][1]=arr[0][1];
    dp[0][2]=arr[0][2];
    
    FOR(i,len(arr)){
        if(i){
            dp[i][0] = arr[i][0] + max(dp[i-1][1] , dp[i-1][2]);
            dp[i][1] = arr[i][1] + max(dp[i-1][0] , dp[i-1][2]);
            dp[i][2] = arr[i][2] + max(dp[i-1][1] , dp[i-1][0]);
        }
    }
    return max({dp[n-1][0] , dp[n-1][1] , dp[n-1][2]});
}
int spaceOptimize(vdd<int>&arr){
    int first=arr[0][0];
    int second=arr[0][1];
    int third=arr[0][2];
    FOR(i,len(arr)){
        if(i){
            int newfirst=arr[i][0] + max(second , third);
            int newsecond=arr[i][1] + max(first , third);
            int newthird=arr[i][2] + max(second , first);
            first=newfirst;
            second=newsecond;
            third=newthird;
        }
    }
    return max({first,second,third});
}
void itachi_1609(){
    vdd<int>arr={
        {1,2,5},
        {3,1,1},
        {3,3,3}
    };
    int n=len(arr);
    int ans=-1e9;
    vdd<int>dp(n+1,vd<int>(3,-1));
    FOR(3)ans=max(ans,topDown(n-1,_,arr,dp));
    print(ans);printn();
    print(bottomUp(arr));printn();
    print(spaceOptimize(arr));printn();
    return;
}
int main(){
    nfs;
    ll tc=1;
    // LL(tc);
    while(tc--)itachi_1609();
   return 0;
}