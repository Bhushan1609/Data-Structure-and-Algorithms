#include <bits/stdc++.h>
using namespace std;
//O(n*n)
//O(1)
void callbrute(vector <int>v){
    int n = v.size();
    for(int i = 1 ; i <= n ; i++){
        int find =0;
        for (int j =0 ; j  < n ; j++){
            if(v[j] == i) find++;
        }
        if(find == 1){
            cout << "Element that appears only onces : "<< i << endl;
            return ;
        }
    }
    return ;
}
//O(3n)
//O(maximumElement)
void callbetter(vector <int>v){
    int n = v.size();
    int maxi = INT_MIN;
    for (int i =0 ; i < n ; i++) maxi = max(maxi , v[i]);
    int hash[maxi] = {0};
    for (int i = 0 ; i < n ; i++) hash[v[i]]++;
    for (int i = 0; i < n ; i++){
        if(hash[v[i]] == 1){
            cout << "Element that appears only onces : "<< v[i] << endl;
            return ;
        }
    }
    return;
}
// where m = (n/2 + 1) elements store in mapp
//time --> O(nlogm) + O (m)
//space --> O(m)
void callbetter2(vector <int>v){
    int n = v.size();
    map<long long ,int> mapp;
    for (auto i : v) mapp[i]++;
    for (auto i : mapp) if(i.second == 1) cout << "Element that appears only onces : "<< i.first << endl;return ;
    return;
}
void calloptimal(vector <int>v){
    int x = 0;
    for (int i = 0 ; i < v.size() ; i++) x ^= v[i];
    cout << "Element that appears only onces : "<< x << endl;
    return ;
}
int main(){
    vector <int> v = {1,1,2,3,3,4,4};
    callbrute(v);
    callbetter(v);
    callbetter2(v);
    calloptimal(v);
    return 0;
}