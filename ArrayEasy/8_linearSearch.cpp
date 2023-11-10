#include <bits/stdc++.h>
using namespace std;
int search(vector <int>& v ,int ele){
    for (int i = 0 ; i < v.size() ; i++){
        if(v[i] == ele) return i;
    }
    return -1;
}
int main(){
    vector <int>v = {1,2,3,4,5,6};
    int ele = 5;
    int ans = search(v , ele);
    cout << ans << endl;
    return 0;
}