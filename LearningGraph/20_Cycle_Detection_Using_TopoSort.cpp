#include <bits/stdc++.h>
using namespace std;
void inputForList(vector <int> adjacencyList[] , int edges){
    for (int i = 0 ; i < edges ; i++){
        int u , v;
        cout << "Enter Node which have Edge Between : ";cin >> u >> v;
        adjacencyList[u].push_back(v);
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
bool isCyclic(int V, vector<int> adj[]) {
    vector <int> ans;
    vector <int> indegree(V , 0);
    for (int i = 0 ; i < V ; i++){
        for (auto j : adj[i]){
            indegree[j]++;
        }
    }
    queue<int>q;
    for (int i = 0 ; i < V ; i++){
        if(indegree[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for(auto i : adj[front]){
            indegree[i]--;
            if(indegree[i] == 0){
                q.push(i);
            }
        }
    }
    return V != ans.size();
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