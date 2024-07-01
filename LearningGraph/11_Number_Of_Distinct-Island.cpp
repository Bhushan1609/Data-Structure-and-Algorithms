#include <bits/stdc++.h>
using namespace std;
void dfs(int i , int j , vector <vector <int>>& visited ,
    vector <vector <int>>&grid,vector <pair<int , int>>& ans , int addi ,int addj){
    ans.push_back({i-addi,j-addj});
    visited[i][j] = 1;
    vector <int> arr1 = {0 , 0 , +1 , -1};
    vector <int> arr2 = {+1 , -1 , 0 , 0};
    int n = grid.size();
    int m = grid[0].size();
    for (int it = 0 ; it < 4 ; it++){
        int newi = i + arr1[it];
        int newj = j + arr2[it];
        if(newi >= 0 and newi < n and newj >= 0 and newj < m and !visited[newi][newj] and
        grid[newi][newj]){
            dfs(newi , newj , visited , grid , ans, addi , addj); 
        }
    }
    return ;
}
int countDistinctIslands(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector <vector <int>> visited (n , vector <int> (m , 0));
    set<vector <pair <int , int>>>answer;
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j++){
            if(grid[i][j] and !visited[i][j] ){
                vector <pair<int , int>> ans;
                dfs(i , j , visited , grid , ans , i , j);
                answer.insert(ans);
            }
        }
    }
    return answer.size();
}
int main(){
    vector <vector <int>> grid{
        {1,1, 0, 0, 0}, 
        {1,1, 0, 0, 0},
        {0,0, 0, 1, 1},
        {0,0, 0, 1, 1}
    };
    cout << "Number of Distinct Island : " << (int) countDistinctIslands(grid) << endl;
    return 0;
}