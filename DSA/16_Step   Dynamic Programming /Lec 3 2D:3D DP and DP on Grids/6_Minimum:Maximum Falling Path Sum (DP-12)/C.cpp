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
int dp[101][101];
int topDown(int i ,int j ,int n ,int m,vdd<int>&matrix){
    if(i==0) return matrix[0][j];
    if(dp[i][j] != -1)return dp[i][j];
    int ans=1e9;
    int newi=i-1;
    int newj=j;
    if(newi >= 0 and newi < n and newj >=0 and newj < m)ans=min(ans,topDown(newi,newj,n,m,matrix));
    newi=i-1;
    newj=j-1;
    if(newi >= 0 and newi < n and newj >=0 and newj < m)ans=min(ans,topDown(newi,newj,n,m,matrix));
    newi=i-1;
    newj=j+1;
    if(newi >= 0 and newi < n and newj >=0 and newj < m)ans=min(ans,topDown(newi,newj,n,m,matrix));
    return dp[i][j] = matrix[i][j]+ans;
}
int bottomUp(int n,int m,vdd<int>&matrix){
    vdd<int>dp(n,vd<int>(m,0));
    FOR(i,n)dp[0][i]=matrix[0][i];
    FOR(i,1,n){
        FOR(j,m){
            dp[i][j]=matrix[i][j]+min({ ( (i>0) ? dp[i-1][j]  : 1e9)  , ( (i>0 && j>0) ? dp[i-1][j-1]  : 1e9) , ( (i>0 && j<(m-1)) ? dp[i-1][j+1]  : 1e9) });
        }
    }
    return MIN(dp[n-1]);
}
int spaceOptimize(int n,int m,vdd<int>&matrix){
    vd<int>prev(n,0);
    FOR(i,n)prev[i]=matrix[0][i];
    FOR(i,1,n){
        vd<int>temp(n,0);
        FOR(j,m){
            temp[j]=matrix[i][j]+min({ ( (i>0) ? prev[j]  : 1e9)  , ( (i>0 && j>0) ? prev[j-1]  : 1e9) , ( (i>0 && j<(m-1)) ? prev[j+1]  : 1e9) });
        }
        swap(prev,temp);
    }
    return MIN(prev);
}
void itachi_1609(){
    vdd<int>matrix{
        {2,1,3},
        {6,5,4},
        {7,8,9}
    };
    int n=len(matrix);
    int m=len(matrix[0]);
    FOR(i, 101 * 101) dp[i/101][i%101]=-1;
    int ans=1e9;
    FOR(j,m) ans=min(ans,topDown(n-1,j,n,m,matrix));
    print(ans);printn();
    print(bottomUp(n,m,matrix));printn();
    print(spaceOptimize(n,m,matrix));printn();
    return;
}
int main(){
    nfs;
    ll tc=1;
    // LL(tc);
    while(tc--)itachi_1609();
   return 0;
}