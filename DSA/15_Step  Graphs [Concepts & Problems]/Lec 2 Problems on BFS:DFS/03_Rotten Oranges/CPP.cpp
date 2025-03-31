#include<bits/stdc++.h>
using namespace std;

const vector<pair<int,int>>gridMoves={{-1,0},{0,-1},{0,1},{1,0}};

int BFS(vector<vector<int>>&grid){
    int n=grid.size(),m=grid[0].size(),cnt=0;
    vector<vector<int>>visited(n,vector<int>(m));
    queue<pair<int,int>>q;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(grid[i][j]==2){
                q.push({i,j});
                visited[i][j]=2;
            }
    while(!q.empty()){
        int q_size=q.size(),pushHappend=0;
        for(int k=0;k<q_size;k++){
            auto [i,j]=q.front();
            q.pop();
            for(int l=0;l<4;l++){
                int newi=i+gridMoves[l].first;
                int newj=j+gridMoves[l].second;
                if(newi>=0 && newi<n && newj>=0 && newj<m && !visited[newi][newj] && grid[newi][newj]==1){
                    q.push({newi,newj});
                    visited[newi][newj]=2;
                    ++pushHappend;
                }
            }
        }
        cnt+=(pushHappend>0);
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(grid[i][j]==1 && visited[i][j]!=2)
                cnt=-1;
    return cnt;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<vector<int>>grid={{2,1,1},{1,1,0},{0,1,1}};
    cout<<"After "<<BFS(grid)<<" minute all the oranges are rotten."<<endl;
    return 0;
}