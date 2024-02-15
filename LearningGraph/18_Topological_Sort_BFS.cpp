#include <bits/stdc++.h>
using namespace std;
void dfs(int node , vector <int>& visited , vector <int> adj[] , stack<int>& st){
    visited[node] = 1;
    for (auto i : adj[node]){
        if(!visited[i]) dfs(i , visited , adj , st);
    }
    st.push(node);
    return ;
}
void printTopologicalSort(int V, vector<int> adj[]) {
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
    for (auto i : ans){
        cout << i <<  " ";
    }
    cout << endl;
    return ;
}
//6 6 5 2 5 0 2 3 3 1 4 0 4 1 input
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
int main(){
    int nodes , edges ;
    cout << "Enter Numbers of Nodes : "; cin >> nodes;
    cout << "Enter Numbers of Edges : "; cin >> edges;
    vector <int> adjacencyList[nodes+1];
    inputForList(adjacencyList , edges);
    cout << "Topological Sort is : " << endl;
    printTopologicalSort(nodes ,adjacencyList);
    return 0;
}