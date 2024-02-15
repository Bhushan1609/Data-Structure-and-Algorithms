#include <bits/stdc++.h>
using namespace std;
vector <vector <int>> nearest(vector <vector <int>> & mat){
    int n = mat.size() , m = mat[0].size();
    vector <vector <int>> answer (n , vector <int> (m , 0));
    vector <vector <int>> visited (n , vector <int> (m , 0));
    queue <pair <pair <int , int > , int>> q;
    for (int i = 0 ; i < n ; i++){
        for (int j = 0; j < m ; j++){
            if(mat[i][j] == 1){
                q.push({{i , j} , 0});
                visited[i][j] = 1;
            }
        }
    }
    vector <int> arr1 = {-1 , 0 , 0 , +1};
    vector <int> arr2 = {0 , -1 , +1 , 0};
    while(!q.empty()){
        int i = q.front().first.first;
        int j = q.front().first.second;
        int dist = q.front().second;
        q.pop();
        answer[i][j] = dist;
        for (int it = 0 ; it < 4 ; it++){
            int newi = i + arr1[it];
            int newj = j + arr2[it];
            if(newi >= 0 and newi < n and newj >= 0 and newj < m and visited[newi][newj] == 0){
                q.push({{newi , newj} , dist + 1});
                visited[newi][newj] = 1 ;
            }
        }
    }
    return answer;
}
int main(){
    vector <vector <int>> mat {
        {1 , 0 , 1}, 
        {1 , 1 , 0},
        {1 , 0 , 0}
    };
    vector <vector <int>> answer = nearest(mat);
    for (auto i : answer){
        for (auto j : i){
            cout  << j << " ";
        }
        cout << endl;
    }
    return 0;
}