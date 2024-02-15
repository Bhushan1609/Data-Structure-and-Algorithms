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
//Using BFS
bool isCycle(int V, vector<int> adj[]) {
    vector <int> visited(V, 0);
    queue <pair <int , int>> q;
    int prevNode = -1;
    for (int i = 0 ; i < V ; i++){
        if(!visited[i]){
            q.push({i , prevNode});
            visited[i] = 1;
            while (!q.empty()) {
                pair <int , int> front = q.front();
                prevNode = front.second;
                q.pop();
                for (auto i : adj[front.first]) {
                    if(i == prevNode) continue;
                    else if (visited[i] == 1){
                        return true;
                    }   
                    else{
                        q.push({i , front.first});
                        visited[i] = 1;
                    }
                }
            }
        }
    }
    return false;
}
//Using DFS
bool dfs(int node , vector <int>& visited , vector <int> adj[] , int& prevNode){
    visited[node] = 1;
    for (auto i : adj[node]){
        if(i == prevNode) continue;
        else if(visited[i] == 1) return true;
        else {
            if(dfs(i , visited , adj , node)) return true;
        }
    }
    return false;
}
bool isCycledfs(int V ,vector <int> adj[]){
    vector <int> visited(V , 0);
    int prevNode = -1;
    for (int i = 0 ; i < V ; i++){
        if(!visited[i]){
            if(dfs(i , visited , adj , prevNode)) return true;
        }
    }
    return false;
} 
int main(){
    int nodes , edges ;
    cout << "Enter Numbers of Nodes : "; cin >> nodes;
    cout << "Enter Numbers of Edges : "; cin >> edges;
    vector <int> adjacencyList[nodes+1];
    inputForList(adjacencyList , edges);
    printGraphList(adjacencyList , nodes);
    if(isCycle(nodes , adjacencyList)){
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}