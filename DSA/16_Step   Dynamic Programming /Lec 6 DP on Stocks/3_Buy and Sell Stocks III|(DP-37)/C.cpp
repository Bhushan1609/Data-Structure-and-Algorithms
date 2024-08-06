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
int dp[100001][2][3];
int topDown(int index,int buy,int cap,vd<int>&prices){
    if(index==len(prices)) return 0;
    if(cap==0)return 0;
    if(dp[index][buy][cap] != -1)return dp[index][buy][cap];
    int profit=0;
    if(buy){
        profit=max({-prices[index]+topDown(index+1,0,cap,prices) , topDown(index+1,1,cap,prices)});
    }
    else{
        profit=max({+prices[index]+topDown(index+1,1,cap-1,prices) , topDown(index+1,0,cap,prices) });
    }
    return dp[index][buy][cap]=profit;
}
int bottomUp(vd<int>&prices){
    int n=len(prices);
    vddd<int>dp(n+1, vdd<int>(2,vd<int>(3,0)));
    dp[n][0][0]=dp[n][1][0]=0;
    FOR_R(index,0,n){
        FOR(buy,0,2){
            FOR(cap,1,3){
                int profit=0;
                if(buy){
                    profit=max({-prices[index]+dp[index+1][0][cap] ,dp[index+1][1][cap] });
                }
                else{
                    profit=max({+prices[index]+dp[index+1][1][cap-1] ,dp[index+1][0][cap] });
                }
                dp[index][buy][cap]=profit;
            }
        }
    }
    return dp[0][1][2];
}
int spaceOptimize(vd<int>&prices){
    int n=len(prices);
    vdd<int>prev(2,vd<int>(3,0)),curr(2,vd<int>(3,0));
    prev[0][0]=prev[1][0]=0;
    FOR_R(index,0,n){
        FOR(buy,0,2){
            FOR(cap,1,3){
                int profit=0;
                if(buy){
                    profit=max({-prices[index]+prev[0][cap] ,prev[1][cap] });
                }
                else{
                    profit=max({+prices[index]+prev[1][cap-1] ,prev[0][cap] });
                }
                curr[buy][cap]=profit;
            }
        }
        swap(prev,curr);
    }
    return prev[1][2];
}

int dp1[100001][4];
int topDown1(int index,int check,vd<int>&prices){
    if(index==len(prices) or check==4) return 0;
    if(dp1[index][check] != -1)return dp1[index][check];
    int profit=0;
    if(check % 2 == 0){
        profit=max({-prices[index]+topDown1(index+1,check+1,prices) , topDown1(index+1,check,prices)});
    }
    else{
        profit=max({+prices[index]+topDown1(index+1,check+1,prices) , topDown1(index+1,check,prices) });
    }
    return dp1[index][check]=profit;
}
int bottomUp1(vd<int>&prices){
    int n=len(prices);
    vdd<int>dp(n+1,vd<int>(5,0));
    FOR(j,4)dp[n][j]=0;
    FOR(i,n+1)dp[i][4]=0;
    FOR_R(index,0,n){
        FOR_R(check,0,4){
            int profit=0;
            if(check % 2 == 0){
                profit=max(-prices[index]+dp[index+1][check+1] , dp[index+1][check] );
            }
            else{
                profit=max(+prices[index]+dp[index+1][check+1] , dp[index+1][check] );
            }
            dp[index][check]=profit;
        }
    }
    return dp[0][0];
}
int spaceOptimize1(vd<int>&prices){
    int n=len(prices);
    vd<int>prev(5,0),curr(5,0);
    FOR(j,4)prev[j]=0;
    FOR(i,n+1)prev[4]=0;
    FOR_R(index,0,n){
        FOR_R(check,0,4){
            int profit=0;
            if(check % 2 == 0){
                profit=max(-prices[index]+prev[check+1] , prev[check] );
            }
            else{
                profit=max(+prices[index]+prev[check+1] , prev[check] );
            }
            curr[check]=profit;
        }
        swap(prev,curr);
    }
    return prev[0];
}
void itachi_1609(){
    vd<int>prices={1,2,3,4,5};
    FOR(i,100001){
        FOR(j,2){
            FOR(k,3){
                dp[i][j][k]=-1;
            }
        }
    }
    print(topDown(0,1,2,prices));printn();
    print(bottomUp(prices));printn();
    print(spaceOptimize(prices));printn();

    FOR(i,100001 * 4)dp1[i/4][i%4]=-1;
    print(topDown1(0,0,prices));printn();
    print(bottomUp1(prices));printn();
    print(spaceOptimize1(prices));printn();
    return;
}
int main(){
    nfs;
    ll tc=1;
    // LL(tc);
    while(tc--)itachi_1609();
   return 0;
}