#include <bits/stdc++.h>
using namespace std;
// O(n*n)
// O(1)
void callbrute(vector <int>v){
    int n = v.size(); 
    vector<int> ans; 
    for (int i = 0; i < n; i++) {
        if (ans.size() == 0 || ans[0] != v[i]) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (v[j] == v[i]) {
                    cnt++;
                }
            }
            if (cnt > (n / 3)) ans.push_back(v[i]);
        }
        if (ans.size() == 2) break;
    }
    for (auto i : ans){
        cout << i << " ";
    }
    cout << endl;
    return ;
}
//O(nlogn)
//O(n)
void callbetter(vector <int>v){
    int n = v.size(); 
    vector<int> ans;
    map<int, int> mpp;
    int mini = int(n / 3) + 1;
    for (int i = 0; i < n; i++) {
        mpp[v[i]]++;
        if (mpp[v[i]] == mini) {
            ans.push_back(v[i]);
        }
        if (ans.size() == 2) break;
    }
    for (auto i : ans){
        cout << i << " ";
    }
    cout << endl;
    return ;
}
//O(2n)
//constant
void calloptimal(vector<int>v){
    int n = v.size(); 
    int cnt1 = 0, cnt2 = 0; 
    int el1 = INT_MIN; 
    int el2 = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (cnt1 == 0 && el2 != v[i]) {
            cnt1 = 1;
            el1 = v[i];
        }
        else if (cnt2 == 0 && el1 != v[i]) {
            cnt2 = 1;
            el2 = v[i];
        }
        else if (v[i] == el1) cnt1++;
        else if (v[i] == el2) cnt2++;
        else {
            cnt1--, cnt2--;
        }
    }
    vector<int> ans;
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el1) cnt1++;
        if (v[i] == el2) cnt2++;
    }

    int mini = int(n / 3) + 1;
    if (cnt1 >= mini) ans.push_back(el1);
    if (cnt2 >= mini) ans.push_back(el2);
    for (auto i : ans){
        cout << i << ' ';
    }
    cout << endl;
    return ;
}

int main(){
    //( > n/3)
    vector <int> v = {11, 33, 33, 11, 33, 11};
    callbrute(v);
    callbetter(v);
    calloptimal(v);
    return 0;
}