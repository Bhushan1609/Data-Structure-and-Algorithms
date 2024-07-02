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
bool dfs(int node , vector <int>& visited , vector <int>& path , vector <int> adj[]){
    visited[node] = 1;
    path[node] = 1;
    for (auto i : adj[node]){
        if(path[i] == 1) return true;
        else if(!visited[i]){
            if(dfs(i , visited , path ,adj) == true) return true;
        }
    }
    path[node] = 0;
    return false;
}
bool isCyclic(int V, vector<int> adj[]) {
    vector <int> visited(V , 0);
    vector <int> path(V , 0);
    for (int i = 0 ; i < V ; i++){
        if(!visited[i]){
            if (dfs(i , visited , path , adj) == true ) return true;
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
    if(isCyclic(nodes , adjacencyList)) cout << "Yes" << endl;
    else{
        cout << "No" << endl;
    }
    return 0;
}