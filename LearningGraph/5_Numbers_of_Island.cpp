#include <bits/stdc++.h>
using namespace std;
void dfs(vector <vector <char>>& grid , vector <vector <bool>>& visited , int i , int j , int n , int m){
        visited[i][j] = true;
        if((i-1) >= 0 and (j-1) >= 0 and !visited[i-1][j-1] and grid[i-1][j-1] == '1'){
            dfs(grid , visited , i-1 , j-1 , n, m);
        }
        if((i-1) >= 0 and !visited[i-1][j] and grid[i-1][j] == '1'){
            dfs(grid , visited , i-1 , j , n, m);
        }
        if((i-1) >= 0 and (j+1) < m and !visited[i-1][j+1] and grid[i-1][j+1] == '1'){
            dfs(grid , visited , i-1 , j+1 , n, m);
        }
        if((j-1) >= 0 and !visited[i][j-1] and grid[i][j-1] == '1'){
            dfs(grid , visited , i , j-1 , n, m);
        }
        if((j+1) < m and !visited[i][j+1] and grid[i][j+1] == '1'){
            dfs(grid , visited , i , j+1 , n, m);
        }
        if((i+1) < n and (j-1) >= 0 and !visited[i+1][j-1] and grid[i+1][j-1] == '1'){
            dfs(grid , visited , i+1 , j-1 , n, m);
        }
        if((i+1) < n and !visited[i+1][j] and grid[i+1][j] == '1'){
            dfs(grid , visited , i+1 , j , n, m);
        }
        if((i+1) < n and (j+1) < m and !visited[i+1][j+1] and grid[i+1][j+1] == '1'){
            dfs(grid , visited , i+1 , j+1 , n, m);
        }
        return ;
    }
    int calculateIsland(vector<vector<char>>& grid){
        int n = grid.size() , m = grid[0].size() , cnt = 0;
        vector <vector <bool>> visited (n , vector <bool> (m , false));
        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < m ; j++){
                if(!visited[i][j] and grid[i][j] == '1'){
                    cnt++;
                    dfs(grid , visited , i , j , n , m);
                }
            }
        }
        return cnt;
    }
int main(){
    vector <vector <char>> grid {
        {'0', '1', '1', '1'},
        {'0', '0', '1', '0'},
        {'0', '1', '0', '1'},
        {'1', '0', '0', '1'},
        {'1', '0', '0', '0'},
        {'1', '1', '0', '1'},
        {'0', '1', '0', '1'},
        {'1', '1', '0', '0'}
    };
    int ans = calculateIsland(grid);
    cout << "Number of Island : " << ans << endl;
    return 0;
}