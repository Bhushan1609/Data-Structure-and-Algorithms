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
int dp[501][501];
int topDown(int i,int j,string a,string b){
    if(i<0) return j+1;
    if(j<0) return i+1;
    if(dp[i][j] != -1)return dp[i][j];
    if(a[i] == b[j]) return dp[i][j]=topDown(i-1,j-1,a,b);
    return dp[i][j]=min({1+topDown(i-1,j-1,a,b) , 1+topDown(i-1,j,a,b), 1+topDown(i,j-1,a,b)});
}
int bottomUp(string a,string b){
    int n=len(a) + 1;
    int m=len(b) + 1;
    vdd<int>dp(n,vd<int>(m,0));
    FOR(i,n) dp[i][0]=i;
    FOR(j,m) dp[0][j]=j;
    FOR(i,1,n){
        FOR(j,1,m){
            if(a[i-1] == b[j-1]) dp[i][j]=dp[i-1][j-1];
            else{
                dp[i][j]=min({1+dp[i-1][j-1], 1+dp[i-1][j], 1+dp[i][j-1]});
            }
        }
    }
    return dp[n-1][m-1];
}
int spaceOptimize(string a,string b){
    int n=len(a) + 1;
    int m=len(b) + 1;
    vd<int>prev(m,0) , curr(m,0);
    FOR(j,m) prev[j]=j;
    FOR(i,1,n){
        curr[0]=i;
        FOR(j,1,m){
            if(a[i-1] == b[j-1]) curr[j]=prev[j-1];
            else{
                curr[j]=min({1+prev[j-1], 1+prev[j], 1+curr[j-1]});
            }
        }
        swap(prev,curr);
    }
    return prev[m-1];
}
void itachi_1609(){
    string a="horse",b="ros";
    FOR(i,501 * 501) dp[i/501][i%501] = -1;
    print(topDown(len(a)-1,len(b)-1,a,b));printn();
    print(bottomUp(a,b));printn();
    print(spaceOptimize(a,b));printn();
    return;
}
int main(){
    nfs;
    ll tc=1;
    // LL(tc);
    while(tc--)itachi_1609();
   return 0;
}