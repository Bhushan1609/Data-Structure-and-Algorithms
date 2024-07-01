#include<bits/stdc++.h>
using namespace std;
int dp[51][51][51];
int recursion(int i,int j1, int j2,vector<vector<int>> &grid, int n, int m){
    if(j1<0 or  j2<0 or j1>=m or j2>=m) return -1e9;
    if(i==n-1){
        return (j1==j2)?(grid[i][j1]):(grid[i][j1]+grid[i][j2]);
    }
    if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
    int ans=0;
    vector<pair<int,int>>aliceMoves={{+1,-1},{+1,0},{+1,+1}},bobMoves={{+1,-1},{+1,0},{+1,+1}};
    for(int it=0;it<3;it++){
        for(int jt=0;jt<3;jt++){
            int newi=i+1;
            int newj1=j1+aliceMoves[it].second;
            int newj2=j2+bobMoves[jt].second;
            int sum= (j1==j2)?(grid[i][j1]):(grid[i][j1]+grid[i][j2]);
            sum = sum+recursion(newi,newj1,newj2,grid,n,m);
            ans=max(ans,sum);
        }
    }
    return dp[i][j1][j2]=ans;
}
int  tabulation(vector<vector<int>> &grid, int n, int m){
    int dp2[n][m][m];
    //Base cases
    for(int j1=0;j1<m;j1++){
        for(int j2=0;j2<m;j2++){
            dp2[n-1][j1][j2]= (j1==j2)?(grid[n-1][j1]):(grid[n-1][j1]+grid[n-1][j2]);
        }
    }
    for(int i=n-2;i>=0;i--){
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                int ans=-1e9;
                vector<pair<int,int>>aliceMoves={{+1,-1},{+1,0},{+1,+1}},bobMoves={{+1,-1},{+1,0},{+1,+1}};
                for(int it=0;it<3;it++){
                    for(int jt=0;jt<3;jt++){
                        int newi=i+1;
                        int newj1=j1+aliceMoves[it].second;
                        int newj2=j2+bobMoves[jt].second;
                        int sum= (j1==j2)?(grid[i][j1]):(grid[i][j1]+grid[i][j2]);
                        if(newj1>=0 and  newj2>=0 and newj1<m and newj2<m)sum = sum+dp2[newi][newj1][newj2];
                        else sum += -1e9;
                        ans=max(ans,sum);
                    }
                }
                dp2[i][j1][j2]=ans;
            }
         }
    }
    return dp2[0][0][m-1];
}
int  optimal(vector<vector<int>> &grid, int n, int m){
    vector<vector<int>>front(m,vector<int>(m,0)),curr(m,vector<int>(m,0));
    //Base cases
    for(int j1=0;j1<m;j1++){
        for(int j2=0;j2<m;j2++){
            front[j1][j2]= (j1==j2)?(grid[n-1][j1]):(grid[n-1][j1]+grid[n-1][j2]);
        }
    }
    for(int i=n-2;i>=0;i--){
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                int ans=-1e9;
                vector<pair<int,int>>aliceMoves={{+1,-1},{+1,0},{+1,+1}},bobMoves={{+1,-1},{+1,0},{+1,+1}};
                for(int it=0;it<3;it++){
                    for(int jt=0;jt<3;jt++){
                        int newi=i+1;
                        int newj1=j1+aliceMoves[it].second;
                        int newj2=j2+bobMoves[jt].second;
                        int sum= (j1==j2)?(grid[i][j1]):(grid[i][j1]+grid[i][j2]);
                        if(newj1>=0 and  newj2>=0 and newj1<m and newj2<m)sum = sum+front[newj1][newj2];
                        else sum += -1e9;
                        ans=max(ans,sum);
                    }
                }
                curr[j1][j2]=ans;
            }
        }
        front=curr;
    }
    return front[0][m-1];
}
int main(){
    memset(dp,-1,sizeof(dp));
    vector<vector<int>>grid{
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5}
    };
    int n=grid.size(),m=grid[0].size();
    int ans=recursion(0,0,n-1,grid,n,m);
    cout<<"Answer : "<<ans<<endl;
    int ans1=tabulation(grid,n,m);
    cout<<"Answer : "<<ans1<<endl;
    int ans2=optimal(grid,n,m);
    cout<<"Answer : "<<ans2<<endl;
    return 0;
}