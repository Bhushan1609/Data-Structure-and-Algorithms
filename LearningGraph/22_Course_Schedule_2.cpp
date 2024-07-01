// #include <bits/stdc++.h>
// using namespace std;
// void inputForList(vector<vector<int>>& prerequisites, int edges){
//     for (int i = 0 ; i < edges ; i++){
//         int u , v;
//         cout << "Enter Node which have Edge Between : ";cin >> u >> v;
//         adjacencyList[u].push_back(v); 
//     }
//     return ;
// }
// void printGraphList(vector <pair<int ,int>> prerequisites;, int edges){
//     cout << "Edge in Between : " << endl; 
//     for (int i = 0 ; i < prerequisites ; i++){
//         cout << prerequisites[i][1]
//         cout << endl;
//     }
//     cout << endl;
//     return ;
// }
// vector<int> findOrder(int n, int m, vector <pair<int ,int>> prerequisites;){
//     vector <int> adj[n];
//     for (auto i : prerequisites){
//         adj[i[1]].push_back(i[0]);
//     }
//     vector <int> indegree(n , 0);
//     vector<int>st;
//     for (int i = 0 ; i < n ; i++){
//         for (auto j : adj[i]){
//             indegree[j]++;
//         }
//     }
//     queue<int>q;
//     for (int i =0 ; i < n ; i++){
//         if(indegree[i] == 0) q.push(i);
//     }
//     while(!q.empty()){
//         int front = q.front();
//         q.pop();
//         st.push_back(front);
//         for (auto i : adj[front]){
//             indegree[i]--;
//             if(indegree[i] == 0) q.push(i);
//         }
//     }
//     if(st.size() == n) return st;
//     else return {};
// }
// int main(){
//     int nodes , edges ;
//     cout << "Enter Numbers of Nodes : "; cin >> nodes;
//     cout << "Enter Numbers of Edges : "; cin >> edges;
//     vector <pair<int ,int>> prerequisites;
//     inputForList(prerequisites , edges);
//     printGraphList(prerequisites,edges);
//     if(isPossible(nodes ,edges , adjacencyList)) cout << "Yes" << endl;
//     else{
//         cout << "No" << endl;
//     }
//     return 0;
// }