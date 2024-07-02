#include <bits/stdc++.h>
using namespace std;
void dfs(int intialColor ,vector <vector <int>>& answer , vector <vector <int>>& image , int i , int j , int color ){
    answer[i][j] = color;
    int n = answer.size() , m = answer[0].size();
    if((i-1) >= 0 and answer[i-1][j] != color and image[i-1][j] == intialColor){
        dfs(intialColor,answer , image , i-1 , j , color);
    }
    if((j-1) >= 0 and answer[i][j-1] != color and image[i][j-1] == intialColor){
        dfs(intialColor,answer , image , i , j-1 , color);
    }
    if((j+1) < m and  answer[i][j+1] != color and image[i][j+1] == intialColor){
        dfs(intialColor,answer , image , i , j+1 , color);
    }
    if((i+1) < n and  answer[i+1][j] != color and image[i+1][j] == intialColor){
        dfs(intialColor,answer , image , i+1 , j , color);
    }
    return ;
}
int main(){
    vector <vector <int>> image {
        {1,1,1},
	    {1,1,0},
	    {1,0,1}
    };
    int sr = 0 , sc = 0 , color = 2;
    int intailColor = image[sr][sc];
    vector <vector <int>> answer = image;
    dfs(intailColor , answer , image , sr , sc , color);
    cout << "output : " << endl;
    for(auto i : answer){
        for (auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}