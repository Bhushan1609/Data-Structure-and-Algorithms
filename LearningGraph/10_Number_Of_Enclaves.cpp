#include <bits/stdc++.h>
using namespace std;
void dfs(int i , int j , vector <vector <int>>& visited , vector <vector <int>>& grid){
    visited[i][j] = 1;
    int n = grid.size();
    int m = grid[0].size();
    vector <int> arr1 = {-1,0,0,+1};
    vector <int> arr2 = {0,-1,+1,0};
    for (int it = 0 ; it < 4 ; it++){
        int newi = i + arr1[it];
        int newj = j + arr2[it];
        if(newi >= 0 and newi < n and newj >= 0 and newj < m 
        and !visited[newi][newj] and grid[newi][newj] == 1){
            dfs(newi , newj , visited , grid);
        }
    }
    return ;
}
int countEnclaves(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    vector <vector <int>> visited(n , vector <int> (m , 0));
    for (int j = 0 ; j < m ; j++){
        if(grid[0][j] and !visited[0][j]){
            dfs(0 , j, visited , grid);
        }
        if(grid[n-1][j] and !visited[n-1][j]){
            dfs(n-1 , j , visited , grid);
        }
    }
    for (int i = 0 ; i < n ; i++){
        if(grid[i][0] and !visited[i][0]){
            dfs(i , 0, visited , grid);
        }
        if(grid[i][m-1] and !visited[i][m-1]){
            dfs(i , m-1 , visited , grid);
        }
    }
    int count = 0;
    for (int i = 0 ; i < n ; i++){
        for (int j =0 ; j < m ; j++){
            if(grid[i][j] and !visited[i][j]) count++;
        }
    }
    return count;
}
int main(){
    vector <vector <int>> grid {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };
    int count = countEnclaves(grid);
    cout << "Count is : " << count << endl;
    return 0;
}