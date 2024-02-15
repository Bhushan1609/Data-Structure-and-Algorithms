#include <bits/stdc++.h>
using namespace std;
void inputForList(vector <pair <int , int >> adjacencyList[] , int edges){
    for (int i = 0 ; i < edges ; i++){
        int u , v , wt;
        cout << "Enter Node which have Edge Between : ";cin >> u >> v;
        cout << "Enter Weight For it : "; cin >> wt;
        adjacencyList[u].push_back({v , wt});
    }
    return ;
}
void printGraphList(vector<pair <int , int >> adjacencyList[] , int nodes){
    for (int i = 0 ; i < nodes ; i++){
        cout << "{" << i << "} : " ;
        for (auto j : adjacencyList[i]){
            cout << "{" << j.first << " " << j.second << "} ";
        }
        cout << endl;
    }
    cout << endl;
    return ;
}
void dfs(int node , vector <int>& visited , vector <pair <int,int>> adjacencyList[] , stack<int>& st){
    visited[node] = 1;
    for (auto i : adjacencyList[node]){
        if(!visited[i.first]) dfs(i.first , visited , adjacencyList , st);
    }
    st.push(node);
    return ;
}
void topoSort(vector <pair <int , int>> adjacencyList[] ,int nodes , stack<int>& st){
    vector <int> visited(nodes , 0);
    for (int i = 0 ; i < nodes ; i++){
        if(!visited[i]){
            dfs(i , visited , adjacencyList , st);
        }
    }
    return ;
}
vector <int> shortestPath(vector <pair <int , int>> adjacencyList[] ,int nodes ){
    stack <int> st;
    topoSort(adjacencyList , nodes , st);
    int src = 0;// Mentioned in Q....
    vector <int> dist(nodes , 1e9);
    dist[src] = 0;
    while(!st.empty()){
        int top = st.top();
        st.pop();
        for (auto i : adjacencyList[top]){
            int node = i.first;
            int wt = i.second;
            if(dist[top] + wt < dist[node]){
                dist[node] = dist[top] + wt;
            }
        }
    }
    for (int i = 0 ; i < nodes ; i++){
        if(dist[i] == 1e9){
            dist[i] = -1;
        }
    }
    return dist;
}
int main(){
    int nodes , edges ;
    cout << "Enter Numbers of Nodes : "; cin >> nodes;
    cout << "Enter Numbers of Edges : "; cin >> edges;
    vector <pair <int , int>> adjacencyList[nodes+1];
    inputForList(adjacencyList , edges);
    // printGraphList(adjacencyList , nodes);
    vector <int> answer = shortestPath(adjacencyList , nodes);
    for (auto i : answer){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}