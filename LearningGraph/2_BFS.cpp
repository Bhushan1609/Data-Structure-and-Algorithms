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
void BFS(vector <int> adjacencyList[] , int nodes){
    int src;
    cout << "Enter Source to start Traversal : "; cin >> src; 
    queue <int> q;
    q.push(src);
    vector <int> visited(nodes , 0);
    visited[src] = 1;
    cout << "BFS Traversal : " ;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        cout << front << " ";
        for (auto i : adjacencyList[front]){
            if(!visited[i]) {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
    for (int i = 1 ; i < nodes ; i++){
        if(!visited[i]){
            visited[i] = 1;
            q.push(i);
        }
        while(!q.empty()){
            int front = q.front();
            q.pop();
            cout << front << " ";
            for (auto i : adjacencyList[front]){
                if(!visited[i]) {
                    visited[i] = 1;
                    q.push(i);
                }
            }
        }
    }
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
    BFS(adjacencyList , nodes);
    return 0;
}