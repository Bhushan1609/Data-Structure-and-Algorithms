#include <bits/stdc++.h>
using namespace std;
void dfs(int i , int j , vector <vector<int>>& visited , vector <vector <char>>& mat){
        visited[i][j] = 1;
        int n = mat.size() ;
        int m = mat[0].size();
        vector <int> arr1 = {-1 , 0 , 0 , +1};
        vector <int> arr2 = {0 , -1 , +1 , 0};
        for (int it = 0 ; it < 4 ; it++){
            int newi = i + arr1[it];
            int newj = j + arr2[it];
            if(newi >= 0 and newi < n and newj >= 0 and newj < m 
            and visited[newi][newj] == 0 and mat[newi][newj] == 'O'){
                dfs(newi , newj , visited , mat);
            }
        }
        return ;
    }
vector<vector<char>> fill(int n, int m, vector<vector<char>> mat){
    vector <vector <int>> visited(n , vector <int> (m , 0));
    for (int j = 0 ; j < m ; j++){
        if(mat[0][j] == 'O' and !visited[0][j]){
            dfs(0 , j , visited , mat);
        }
        if(mat[n-1][j] == 'O' and !visited[n-1][j]){
            dfs(n-1 , j , visited , mat);
        }
    }
    for (int i = 0 ; i < n ; i++){
        if(mat[i][0] == 'O' and !visited[i][0]){
            dfs(i , 0 , visited , mat);
        }
        if(mat[i][m-1] == 'O' and !visited[i][m-1]){
            dfs(i , m-1 , visited , mat);
        }
    }
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j++){
            if(visited[i][j] == 0 and mat[i][j] == 'O'){
                mat[i][j] = 'X';
            }
        }
    }
    return mat;
}
int main(){
    vector <vector <char>> mat {
        {'X' , 'X' , 'X' , 'X'},
        {'X' , 'O' , 'X' , 'X'},
        {'X' , 'O' , 'O' , 'X'},
        {'X' , 'O' , 'X' , 'X'},
        {'X' , 'X' , 'O' , 'O'}
    };
    int n = mat.size() , m = mat[0].size() ;
    vector <vector <char>> answer = fill(n , m , mat);
    for (auto i : answer){
        for (auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}