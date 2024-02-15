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
void BFS(int node, vector <int> adjacecncyList[] , vector <int>& visited){
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for (auto i : adjacecncyList[front]){
            if(!visited[i]){
                visited[i] = 1;
                q.push(i);
            }
        }
    }
    return  ;
}
int numberOfProvinces(vector <int> adjacencyList[] , int nodes){
    int cnt = 0;
    vector <int>visited(nodes , 0);
    for (int i = 1 ; i < nodes ; i++){
        if(!visited[i]){
            cnt++;
            BFS(i, adjacencyList , visited);
        }
    }
    cout << endl;
    return cnt;
}
int main(){
    int nodes , edges ;
    cout << "Enter Numbers of Nodes : "; cin >> nodes;
    cout << "Enter Numbers of Edges : "; cin >> edges;
    vector <int> adjacencyList[nodes+1];
    inputForList(adjacencyList , edges);
    printGraphList(adjacencyList , nodes);
    int cnt = numberOfProvinces(adjacencyList , nodes);
    cout << "Number of Provincess : " << cnt << endl;
    return 0;
}