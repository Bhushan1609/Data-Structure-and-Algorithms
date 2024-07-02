#include <bits/stdc++.h>
using namespace std;
void inputForList(vector <int> adjacencyList[] , int edges){
    for (int i = 0 ; i < edges ; i++){
        int u , v;
        cout << "Enter Node which have Edge Between : ";cin >> u >> v;
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }
    return ;
}
void printGraphList(vector<int> adjacencyList[] , int nodes){
    for (int i = 0 ; i < nodes ; i++){
        cout << "{" << i << "} : " ;
        for (auto j : adjacencyList[i]){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    return ;
}
void bfs(vector <int> adjacencyList[] , int nodes , vector <int>& visited , int src){
    queue<pair <int , int>> q;
    q.push({src , 0});
    visited[src] = 0;
    while(!q.empty()){
        int node = q.front().first;
        int dist = q.front().second;
        q.pop();
        for (auto i : adjacencyList[node]){
            if(visited[i] == INT_MAX){
                visited[i] = dist+1;
                q.push({i , dist + 1});
            }
            else if(visited[i] != INT_MAX){
                visited[i] = min(visited[i] , dist + 1);
            }
        }
    }
    for (int i = 0 ; i < nodes ; i++){
        if(visited[i] == INT_MAX) { // Unreachable Nodes
            visited[i] = -1;
        }
    }
    return ;
}
// void dfs(vector <int> adjacency[] , int node , vector <int>& visited , int dist){
//     visited[node] = dist;
//     for (auto i : adjacency[node]){
//         if(visited[i] == INT_MAX){
//             dfs(adjacency , i , visited , dist+1);
//         }
//         else if(visited[i] != INT_MAX){
//             visited[i] = min(visited[i] , dist+1);
//         }
//     }
//     return ;
// }
vector<int> shortestPath(vector <int> adjacencyList[], int nodes){
    vector <int> visited(nodes, INT_MAX);
    int src = 0; // Depends Where To Start // 
    bfs(adjacencyList , nodes , visited ,src);
    return visited;
}
int main(){
    int nodes , edges ;
    cout << "Enter Numbers of Nodes : "; cin >> nodes;
    cout << "Enter Numbers of Edges : "; cin >> edges;
    vector <int> adjacencyList[nodes+1];
    inputForList(adjacencyList , edges);
    printGraphList(adjacencyList , nodes);
    vector <int> answer = shortestPath(adjacencyList , nodes);
    for (auto i : answer){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}