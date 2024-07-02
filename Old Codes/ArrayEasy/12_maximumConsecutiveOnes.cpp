#include <bits/stdc++.h>
using namespace std;
int main(){
    vector <int> v = {1,1,0,1,1,1,0,1,1};
    int cnt = 0 ;
    int ans = INT_MIN;
    for (int i =0 ; i < v.size() ; i++){
        if(v[i]) {
            cnt++;
            ans = max(ans , cnt);
        }
        else cnt = 0;
    }
    cout << ans << endl;
    return 0;
}