#include <bits/stdc++.h>
using namespace std;
void markRow(vector<vector<int>> &matrix, int n, int m, int i) {
    for (int j = 0; j < m; j++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}
void markCol(vector<vector<int>> &matrix, int n, int m, int j) {
    for (int i = 0; i < n; i++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}
// O((n*m)*(n + m)) + O(n*m)
void callbrute(vector <vector <int>> v ){
    int n = v.size();
    int m = v[0].size();
    for (int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(!v[i][j]){
                markRow(v, n, m, i);
                markCol(v, n, m, j);
            }
        }
    }
    for(auto i : v){
        for (auto j : i){
            if(j == -1) j = 0;// set -1 to 0
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    return ;
}
// O(n*n)
void callbetter(vector <vector <int>> v){
    int n = v.size();
    int m = v[0].size();
    int row[n] = {0}; 
    int col[m] = {0}; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (row[i] || col[j]) {
                v[i][j] = 0;
            }
        }
    }
    for (auto i : v){
        for (auto j : i){
            cout << j << ' ';
        }
        cout << endl;
    }
    cout << endl;
    return ;
}
// O(2(n*m))
// constant
void calloptimal(vector <vector<int>>v){
    int n = v.size();
    int m = v[0].size();
    int col0 = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 0) {
                v[i][0] = 0;
                if (j != 0)
                    v[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (v[i][j] != 0) {
                if (v[i][0] == 0 || v[0][j] == 0) {
                    v[i][j] = 0;
                }
            }
        }
    }
    if (v[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            v[0][j] = 0;
        }
    }
    if (col0 == 0) {
        for (int i = 0; i < n; i++) {
            v[i][0] = 0;
        }
    }
    for (auto i : v){
        for (auto j : i){
            cout << j << ' ';
        }
        cout << endl;
    }
    cout << endl;
    return ;
}
int main(){
    vector <vector <int>> v = {
        {1,1,1,1,},
        {1,0,0,1},
        {1,1,0,1}
    };
    callbrute(v);
    vector <vector <int>> v1 = {
        {1,1,1,1,},
        {1,0,0,1},
        {1,1,0,1}
    };
    callbetter(v1);
    vector <vector <int>> v2 = {
        {1,1,1,1,},
        {1,0,0,1},
        {1,1,0,1}
    };
    calloptimal(v2);
    return 0;
}