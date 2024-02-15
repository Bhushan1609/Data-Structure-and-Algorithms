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
// by using bfs
bool isitBipartiteBFS(int nodes , vector <int> adjacencyList[]){
    vector <int> visited(nodes , -1);
    queue <int> q;
    for (int i = 0 ;  i < nodes ; i++){
        if(visited[i] == -1){
            q.push(i);
            visited[i] = 0;
            while(!q.empty()){
                int front = q.front();
                q.pop();
                for (auto i : adjacencyList[front]){
                    if(visited[i] == visited[front] and visited[i] != -1) return false;
                    else if(visited[i] == -1){
                        visited[i] = !visited[front];
                        q.push(i);
                    }
                }
            }
        }
    }
    return true;
}
bool dfs(int node , vector <int>& visited , vector <int> adjacencyList[] ,int color){
    visited[node] = color;
    for(auto i : adjacencyList[node]){
        if(visited[i] == color) return false;
        else if(visited[i] == -1){
            if(dfs(i ,visited , adjacencyList , !color) == false) return false;
        }
    }
    return true;
}
//by using dfs
bool isitBipartiteDFS(int nodes , vector <int> adjacencyList[]){
    vector <int> visited(nodes , -1);
    for (int i = 0 ; i  < nodes ; i++){
        if(visited[i] == -1){
            if(dfs(i , visited , adjacencyList ,0) == false) return false;
        }
    }
    return true;
}
int main(){
    int nodes , edges ;
    cout << "Enter Numbers of Nodes : "; cin >> nodes;
    cout << "Enter Numbers of Edges : "; cin >> edges;
    vector <int> adjacencyList[nodes];
    inputForList(adjacencyList , edges);
    if(isitBipartiteBFS(nodes , adjacencyList)){
        cout << "Yes , it is!!" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}