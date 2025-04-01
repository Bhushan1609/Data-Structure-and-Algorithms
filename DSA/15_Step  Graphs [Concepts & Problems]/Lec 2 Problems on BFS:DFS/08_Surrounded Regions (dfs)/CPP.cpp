#include<bits/stdc++.h>
using namespace std;

const vector<pair<int,int>>gridMoves={{-1,0},{0,-1},{0,1},{1,0}};

void dfs(int i,int j,vector<vector<int>>&visited,vector<vector<char>>&board){
    ++visited[i][j];
    for(int k=0;k<4;k++){
        int newi=i+gridMoves[k].first;
        int newj=j+gridMoves[k].second;
        if(newi>=0 && newi<board.size() && newj>=0 && newj<board[0].size() && !visited[newi][newj] && board[newi][newj]=='O')
            dfs(newi,newj,visited,board);
    }
    return ;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<vector<char>>board={{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    int n=board.size(),m=board[0].size();
    vector<vector<int>>visited(n,vector<int>(m));
    for(int j=0;j<m;j++)
        if(board[0][j]=='O' && !visited[0][j])
            dfs(0,j,visited,board);
    for(int i=0;i<n;i++)
        if(board[i][0]=='O' && !visited[i][0])
            dfs(i,0,visited,board);
    for(int j=0;j<m;j++)
        if(board[n-1][j]=='O' && !visited[n-1][j])
            dfs(n-1,j,visited,board);
    for(int i=0;i<n;i++)
        if(board[i][m-1]=='O' && !visited[i][m-1])
            dfs(i,m-1,visited,board);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(board[i][j]=='O' && !visited[i][j])
                board[i][j]='X';
    for(auto &i:board){
        for(auto &j:i)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}