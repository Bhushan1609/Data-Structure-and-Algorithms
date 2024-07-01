#include <bits/stdc++.h>
using namespace std;
void inputForList(vector <pair<int,int>> adjacencyList[] , int edges){
    for (int i = 0 ; i < edges ; i++){
        int u , v,wt;
        cout << "Enter Node which have Edge Between : ";cin >> u >> v>>wt;
        adjacencyList[u].push_back({v,wt});
        adjacencyList[v].push_back({u,wt});
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
int calculateWays(vector<pair<int,int>>adjacencyList[],int nodes){
    vector<int>dist(nodes,1e9),ways(nodes,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    //      Dist Node
    pq.push({0,0});
    dist[0]=0;
    int mod=(int)1e9+7;
    while(!pq.empty()){
        int dis=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(auto i : adjacencyList[node]){
            int adjnode=i.first;
            int adjweight=i.second;
            if(dis+adjweight<dist[adjnode]){
                dist[adjnode]=dis+adjweight;
                pq.push({dist[adjnode],adjnode});
                ways[adjnode]=ways[node];
            }
            else if(dis+adjweight==dist[adjnode]){
                dist[adjnode]=(dist[adjnode]+ways[node])%mod;
            }                               
        }
    }
    return dist[nodes-1]%mod;
}
int main(){
    int nodes , edges ;
    cout << "Enter Numbers of Nodes : "; cin >> nodes;
    cout << "Enter Numbers of Edges : "; cin >> edges;
    vector <pair<int,int>> adjacencyList[nodes+1];
    inputForList(adjacencyList , edges);
    // printGraphList(adjacencyList , nodes);
    int ans=calculateWays(adjacencyList,nodes);
    cout<<"Number of Ways to Arrrive at Destination : "<<(int)ans <<endl;
    return 0;
}