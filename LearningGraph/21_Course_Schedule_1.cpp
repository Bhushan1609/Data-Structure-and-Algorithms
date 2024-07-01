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
bool isPossible(int N,int P, vector<int> adj[]) {
    vector <int> indegree(N , 0);
    stack<int>st;
    for (int i = 0 ; i < N ; i++){
        for (auto j : adj[i]){
            indegree[j]++;
        }
    }
    queue<int>q;
    for (int i =0 ; i < N ; i++){
        if(indegree[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int front = q.front();
        q.pop();
        st.push(front);
        for (auto i : adj[front]){
            indegree[i]--;
            if(indegree[i] == 0) q.push(i);
        }
    }
    return st.size() == N;
}
int main(){
    int nodes , edges ;
    cout << "Enter Numbers of Nodes : "; cin >> nodes;
    cout << "Enter Numbers of Edges : "; cin >> edges;
    vector <int> adjacencyList[nodes];
    inputForList(adjacencyList , edges);
    printGraphList(adjacencyList,nodes);
    if(isPossible(nodes ,edges , adjacencyList)) cout << "Yes" << endl;
    else{
        cout << "No" << endl;
    }
    return 0;
}
