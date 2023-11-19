#include <bits/stdc++.h>
using namespace std;
void callbrute(int n , int m){
    int ans = -1;
    for (int i = 1 ; i <= m ; i++){
        int limit = n;
        long long flag = 1;
        while(limit--) flag *= i;
        if(flag == m) {
            ans = i;
            break;
        }
        else if(flag > m){
            break;  // exceeded value flag >>>> m
        }
    }
    cout << ans << endl;
    return ;
}
//return 1, if == m:
//return 0, if < m:
//return 2, if > m:
int func(int mid, int n, int m) {
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = ans * mid;
        if (ans > m) return 2;
    }
    if (ans == m) return 1;
    return 0;
}

int calloptimal(int n, int m) {
    //Use Binary search on the answer space:
    int low = 1, high = m;
    while (low <= high) {
        int mid = (low + high) / 2;
        int midN = func(mid, n, m);
        if (midN == 1) {
            return mid;
        }
        else if (midN == 0) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
int main(){
    int n = 9 , m = 1953125;
    callbrute(n , m);//O(n*m) if used pow() function instead of while (time --> O(mlogn))
    cout << calloptimal(n,m) << endl; // O(log(n*m))
    return 0;
}