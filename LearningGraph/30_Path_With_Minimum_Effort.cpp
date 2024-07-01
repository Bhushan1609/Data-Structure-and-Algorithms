#include <bits/stdc++.h>
using namespace std;
int calculateMinEffort(vector<vector<int>>& matrix,int n,int m){
    vector<vector<int>>dist(n,vector<int>(m,1e9));
    priority_queue<pair<int,pair<int,int>>,
    vector<pair<int,pair<int,int>>>,
    greater<pair<int,pair<int,int>>>>pq;
    dist[0][0]=0;
    pq.push({0,{0,0}});
    vector<int>arr1={0,-1,+1,0},arr2={-1,0,0,+1};
    while(!pq.empty()){
        int dis=pq.top().first;
        int x=pq.top().second.first;
        int y=pq.top().second.second;
        if(x==n-1 and y==m-1) return dis;
        pq.pop();
        for(int i=0;i<4;i++){
            int newx=x+arr1[i],newy=y+arr2[i];
            if(newx>=0 and newx<n and newy>=0 and newy<m){
                int newEffort=max(abs(matrix[newx][newy]-matrix[x][y]),dis);
                if(newEffort<dist[newx][newy]){
                    dist[newx][newy]=newEffort;
                    pq.push({dist[newx][newy],{newx,newy}});
                }
            }
        }
    }
    return 0;//notReachable
}
int main(){
    vector<vector<int>> matrix{
        {1,2,2},
        {3,8,2},
        {5,3,5}
    };
    int ans=calculateMinEffort(matrix,matrix.size(),matrix[0].size());
    cout<<"Minimum Effort from 0,0 to n,n is : "<<ans<<endl;
    return 0;
}