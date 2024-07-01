#include<bits/stdc++.h>
using namespace std;
int dijkstras(vector<vector<int>>&maze,int x1,int y1,int x2,int y2){
    if(x1==x2 and y1==y2) return 0;
    int n=maze.size() ,m=maze[0].size();
    vector<vector<int>>dist(n,vector<int>(m,1e9));
    queue<pair<int,pair<int,int>>>q;
    q.push({0,{x1,y1}});
    dist[x1][y1]=0;
    vector<int> arr1={-1,0,0,+1},arr2={0,-1,+1,0};
    while(!q.empty()){
        int dis=q.front().first;
        int x=q.front().second.first;
        int y=q.front().second.second;
        q.pop();
        for(int i=0;i<4;i++){
            int newx=x+arr1[i],newy=y+arr2[i];
            if(newx>=0 and newx<n and newy>=0 and newy<m and maze[newx][newy]==1){
                if(dis+1<dist[newx][newy]){
                    dist[newx][newy]=dis+1;
                    q.push({dis+1,{newx,newy}});
                }
            }
        }
    }
    if(dist[x2][y2]==1e9) return -1;
    return dist[x2][y2];
}
int main(){
    int n=3,m=4;
    vector<vector<int>> maze{
        {1 ,1 ,1 ,1},
        {0 ,1 ,1 ,0},
        {0 ,0 ,1 ,1}
    };
    int srcx=0,srcy=0;
    int destx=n-1,desty=m-1;
    int ans=dijkstras(maze,0,0,n-1,m-1);
    cout<<"Minimum Dist from source to destination is : "<<ans<<endl;
    return 0;
}