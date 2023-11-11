#include <bits/stdc++.h>
using namespace std;
//O(N*logN) + O(2*N)
//O(N)
void callbrute(vector<vector<int>> v) {
    int n = v.size();
    sort(v.begin(), v.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) { 
        int start = v[i][0];
        int end = v[i][1];
        if (!ans.empty() && end <= ans.back()[1]) {
            continue;
        }
        for (int j = i + 1; j < n; j++) {
            if (v[j][0] <= end) {
                end = max(end, v[j][1]);
            }
            else {
                break;
            }
        }
        ans.push_back({start, end});
    }
    for(auto i: ans){
        for (auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    return ;
}
// O(N*logN) + O(N)
// O(N)
void calloptimal(vector <vector <int>>v){
    int n = v.size(); 
    sort(v.begin(), v.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++){
        if (ans.empty() || v[i][0] > ans.back()[1]) {
            ans.push_back(v[i]);
        }
        else {
            ans.back()[1] = max(ans.back()[1], v[i][1]);
        }
    }
    for(auto i: ans){
        for (auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    return ;
}
int main()
{
    vector<vector<int>> v = {
        {1, 3},
        {8, 10},
        {2, 6},
        {15, 18}
    };
    callbrute(v);
    calloptimal(v);
    return 0;
}

