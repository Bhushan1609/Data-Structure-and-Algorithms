#include<bits/stdc++.h>
using namespace std;

const vector<pair<int,int>>gridMoves={{-1,0},{0,-1},{0,1},{1,0}};

void dfs(int i,int j,int &color,int &original_color,vector<vector<int>>&visited,vector<vector<int>>&image){
    ++visited[i][j];
    image[i][j]=color;
    for(int k=0;k<4;k++){
        int newi=i+gridMoves[k].first;
        int newj=j+gridMoves[k].second;
        if(newi>=0 && newi<image.size() && newj>=0 && newj<image[0].size() && !visited[newi][newj] && image[newi][newj]==original_color)
            dfs(newi,newj,color,original_color,visited,image);
    }
    return ;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<vector<int>>image={{1,1,1},{1,1,0},{1,0,1}};
    int sr=1,sc=1,color=2,original_color=image[sr][sc];
    int n=image.size(),m=image[0].size();
    vector<vector<int>>visited(n,vector<int>(m));
    dfs(sr,sc,color,original_color,visited,image);
    cout<<"After Applying Flood-Fill : "<<endl;
    for(auto &i:image){
        for(auto &j:i)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}