#include <bits/stdc++.h>
using namespace std;
void call(vector<vector<int>> v) {
    vector<int> ans;
    int n = v.size(); 
    int m = v[0].size(); 
    int top = 0, left = 0, bottom = n - 1, right = m - 1;
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) ans.push_back(v[top][i]);
        top++;
        for (int i = top; i <= bottom; i++) ans.push_back(v[i][right]);
        right--;
        if (top <= bottom) {
        for (int i = right; i >= left; i--) ans.push_back(v[bottom][i]);
        bottom--;
        }
        if(left <= right) {
        for (int i = bottom; i >= top; i--){
            ans.push_back(v[i][left]);
        }
        left++;
        }
    }
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return ;
}

int main() {
    vector<vector<int>> v ={
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
        };                  
    call(v);
    return 0;
}