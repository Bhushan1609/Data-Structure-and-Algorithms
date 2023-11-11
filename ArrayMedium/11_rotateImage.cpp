
#include<bits/stdc++.h>
using namespace std;
//O(n*n)
//O(n*n)
void callbrute(vector<vector<int>>v) {
    int n = v.size();
    vector<vector<int>>dummy(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dummy[j][n - i - 1] = v[i][j];
        }
    }
    for (auto i : dummy){
        for (auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    return ;
}
void calloptimal(vector <vector <int>>v){
    int n = v.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            swap(v[i][j], v[j][i]);
        }
    }
    for (int i = 0; i < n; i++) {
        reverse(v[i].begin(), v[i].end());
    }
    for (auto i : v){
        for (auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    return ;
}
int main() {
    vector < vector < int >> v=  {
        {1, 2, 3}, 
        {4, 5, 6}, 
        {7, 8, 9}
    };
    callbrute(v);
    calloptimal(v);
    return 0;
}
