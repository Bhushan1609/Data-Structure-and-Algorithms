#include<bits/stdc++.h>
using namespace std;

const vector<pair<int,int>>gridMoves={{-1,0},{0,-1},{0,1},{1,0}};

void dfs(int i,int j,vector<vector<int>>&visited,vector<vector<int>>&grid){
    ++visited[i][j];
    for(int k=0;k<4;k++){
        int newi=i+gridMoves[k].first;
        int newj=j+gridMoves[k].second;
        if(newi>=0 && newi<grid.size() && newj>=0 && newj<grid[0].size() && !visited[newi][newj] && grid[newi][newj])
            dfs(newi,newj,visited,grid);
    }
    return ;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<vector<int>>grid={{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
    int n=grid.size(),m=grid[0].size(),cnt=0;
    vector<vector<int>>visited(n,vector<int>(m));
    for(int j=0;j<m;j++)
        if(grid[0][j] && !visited[0][j])
            dfs(0,j,visited,grid);
    for(int i=0;i<n;i++)
        if(grid[i][0] && !visited[i][0])
            dfs(i,0,visited,grid);
    for(int j=0;j<m;j++)
        if(grid[n-1][j] && !visited[n-1][j])
            dfs(n-1,j,visited,grid);
    for(int i=0;i<n;i++)
        if(grid[i][m-1] && !visited[i][m-1])
            dfs(i,m-1,visited,grid);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cnt+=(grid[i][j] && !visited[i][j]);
    cout<<"Number of Enclaves are  : "<<cnt<<endl;
    return 0;
}