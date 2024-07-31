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
int dp[51][2501];
int topDown(int index,int sum , vector<int>&arr){
	if(index == 0){
        if(sum == 0 and arr[0] == 0) return 2;
        if(sum ==0 or sum == arr[0]) return 1;
        return 0;
    }
    if(index==0)return arr[0]==sum;
    if(dp[index][sum] != -1)return dp[index][sum];
    int pick=0;
    int npick=topDown(index-1,sum,arr) % mod;
    if(arr[index] <= sum) pick=topDown(index-1,sum-arr[index],arr) % mod;
    return dp[index][sum]=(pick+npick) % mod;
}
int bottomUp(vd<int>&arr,int sum){
    int n=len(arr);
    vdd<int>dp(n,vd<int>(sum+1,0));
    if(!arr[0]) dp[0][0]+=2;
    else dp[0][0]+=1;
    if(arr[0] and arr[0] <= sum)dp[0][arr[0]]+=1;
    if(arr[0] <= sum)dp[0][arr[0]]=1;
    FOR(i,1,n){
        FOR(j,sum+1){
          dp[i][j]=dp[i-1][j] + ((arr[i] <= j) ? dp[i-1][j-arr[i]] : 0);
        }
    }
    return dp[n-1][sum];
}
int spaceOptimize(vd<int>&arr,int sum){
    int n=len(arr);
    vd<int>prev(sum+1,0);
    if(!arr[0]) prev[0]+=2;
    else prev[0]+=1;
    if(arr[0] and arr[0] <= sum)prev[arr[0]]+=1;
    if(arr[0] <= sum)prev[arr[0]]=1;
    FOR(i,1,n){
        vd<int>curr(sum+1,0);
        FOR(j,sum+1){
          curr[j]=prev[j] + ((arr[i] <= j) ? prev[j-arr[i]] : 0);
        }
        swap(prev,curr);
    }
    return prev[sum];
}
void itachi_1609(){
    vd<int>arr={5, 2 ,6 ,4};
    int d=3;
    int totSum=0;
    for(auto i:arr)totSum+=i;
    if((totSum-d)<0 or (totSum-d)%2) return print("0");
    for(int i=0;i<51;i++){
		for(int j=0;j<2501;j++){
			dp[i][j]=-1;
		}
	}
    print(topDown(len(arr) - 1, (totSum-d)/2, arr));printn();
    print(bottomUp(arr,(totSum-d)/2));printn();
    print(spaceOptimize(arr,(totSum-d)/2));printn();
    return;
}
int main(){
    nfs;
    ll tc=1;
    // LL(tc);
    while(tc--)itachi_1609();
   return 0;
}
