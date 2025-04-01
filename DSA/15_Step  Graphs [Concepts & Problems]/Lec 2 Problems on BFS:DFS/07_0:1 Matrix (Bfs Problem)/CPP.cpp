#include<bits/stdc++.h>
using namespace std;

const vector<pair<int,int>>gridMoves={{-1,0},{0,-1},{0,1},{1,0}};

void BFS(vector<vector<int>>&mat,vector<vector<int>>&ans){
    int n=mat.size(),m=mat[0].size();
    vector<vector<int>>visited(n,vector<int>(m));
    queue<pair<pair<int,int>,int>>q;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(mat[i][j]==0){
                ++visited[i][j];
                q.push({{i,j},0});
            }
    while(!q.empty()){
        int q_size=q.size();
        for(int it=0;it<q_size;it++){
            auto [ij,dist]=q.front();
            q.pop();
            auto [i,j]=ij;
            ans[i][j]=dist;
            for(int k=0;k<4;k++){
                int newi=i+gridMoves[k].first;
                int newj=j+gridMoves[k].second;
                if(newi>=0 && newi<n && newj>=0 && newj<m && !visited[newi][newj]){
                    q.push({{newi,newj},dist+1});
                    ++visited[newi][newj];
                }
            }
        }
    }
    return ;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<vector<int>>mat={{0,0,0},{0,1,0},{1,1,1}};
    vector<vector<int>>ans(mat.size(),vector<int>(mat[0].size()));// never ever altered/tampered given data
    BFS(mat,ans);
    cout<<"Distance of the nearest 0 : "<<endl;
    for(auto &i:ans){
        for(auto &j:i)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}