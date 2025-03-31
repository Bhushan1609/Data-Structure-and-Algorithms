#include<bits/stdc++.h>
using namespace std;

const vector<pair<int,int>>gridMoves={{-1,0},{0,-1},{0,1},{1,0},{-1,-1},{-1,1},{1,-1},{1,1}};

void dfs(int i,int j,vector<vector<int>>&visited,vector<vector<int>>&matrix){
    ++visited[i][j];
    for(int k=0;k<8;k++){
        int newi=i+gridMoves[k].first;
        int newj=j+gridMoves[k].second;
        if(newi>=0 && newi<matrix.size() && newj>=0 && newj<matrix[0].size() && !visited[newi][newj] && matrix[newi][newj])
            dfs(newi,newj,visited,matrix);
    }
    return ;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<vector<int>>matrix={{0,1},{1,0},{1,1},{1,0}};
    int n=matrix.size(),m=matrix[0].size(),cnt=0;
    vector<vector<int>>visited(n,vector<int>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(!visited[i][j] && matrix[i][j])
                dfs(i,j,visited,matrix),++cnt;
    cout<<"Numbers of Islands are : "<<cnt<<endl;
    return 0;
}