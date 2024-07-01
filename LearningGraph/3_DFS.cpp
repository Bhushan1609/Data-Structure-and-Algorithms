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
void dfs(int node , vector <int>& visited , vector <int> adjacencyList[]){
    visited[node] = 1;
    cout << node << " ";
    for (auto i : adjacencyList[node]){
        if(!visited[i]){
            dfs(i , visited , adjacencyList);
        }
    }
}
void DFS(vector <int> adjacencyList[] , int nodes){
    int src;
    cout << "Enter Source to start Traversal : "; cin >> src; 
    vector <int> visited(nodes , 0);
    dfs(src,visited,adjacencyList);
    cout << endl;
    return ;
}
int main(){
    int nodes , edges ;
    cout << "Enter Numbers of Nodes : "; cin >> nodes;
    cout << "Enter Numbers of Edges : "; cin >> edges;
    vector <int> adjacencyList[nodes+1];
    inputForList(adjacencyList , edges);
    printGraphList(adjacencyList , nodes);
    DFS(adjacencyList , nodes);
    return 0;
}