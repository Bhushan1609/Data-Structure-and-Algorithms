#include<bits/stdc++.h>
using namespace std;

const vector<pair<int,int>>gridMoves={{-1,0},{0,-1},{0,1},{1,0},{-1,-1},{-1,1},{1,-1},{1,1}};

void dfsRecursion(int i,int j,vector<vector<int>>&visited,vector<vector<int>>&mat){
    ++visited[i][j];
    for(int k=0;k<8;k++){
        int newi=i+gridMoves[k].first;
        int newj=j+gridMoves[k].second;
        if(newi>=0 && newi<mat.size() && newj>=0 && newj<mat[0].size() && !visited[newi][newj] && mat[newi][newj])
            dfsRecursion(newi,newj,visited,mat);
    }
    return ;
}

int DFS(vector<vector<int>>&mat){
    int n=mat.size();
    int m=mat[0].size();
    vector<vector<int>>visited(n,vector<int>(m, 0));
    int cnt=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(!visited[i][j] && mat[i][j])
                dfsRecursion(i,j,visited,mat),++cnt;
    return cnt;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    vector<vector<int>>mat={{0,1},{1,0},{1,1},{1,0}};
    cout<<"Number of Islands are : "<<DFS(mat)<<endl;
    return 0;
}