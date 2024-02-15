#include <bits/stdc++.h>
using namespace std;
void inputForList(vector <pair<int,int>> adjacencyList[] , int edges){
    for (int i = 0 ; i < edges ; i++){
        int u , v , wt;
        cout << "Enter Node which have Edge Between and along with Weight : ";cin >> u >> v >> wt;
        adjacencyList[u].push_back({v,wt});
        adjacencyList[v].push_back({u,wt});
    }
    return ;
}
void printGraphList(vector<pair<int,int>> adjacencyList[] , int nodes){
    for (int i = 0 ; i < nodes ; i++){
        cout << "{" << i << "} : " ;
        for (auto j : adjacencyList[i]){
            cout << j.first << " " << j.second << ", ";
        }
        cout << endl;
    }
    cout << endl;
    return ;
}
vector<int> Dijkstras(vector<pair<int,int>> adjacencyList[],int nodes){
    vector<int>dist(nodes,1e9);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    dist[0]=0;
    //      {Dist,Node}
    pq.push({0,0});
    while(!pq.empty()){
        int dist1=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(auto i : adjacencyList[node]){
            int nodeWeight=i.second;
            int adjacentnode=i.first;
            if(dist1+nodeWeight<dist[adjacentnode]) {
                dist[adjacentnode]=dist1+nodeWeight;
                pq.push({dist[adjacentnode],node});
            }
        }
    }
    return dist;
}
int main(){
    int nodes , edges ;
    cout << "Enter Numbers of Nodes : "; cin >> nodes;
    cout << "Enter Numbers of Edges : "; cin >> edges;
    vector <pair<int,int>> adjacencyList[nodes+1];
    inputForList(adjacencyList , edges);
    vector<int> answer=Dijkstras(adjacencyList,nodes);
    for(auto i:answer){cout<<i<<" ";cout<<endl;}
    // printGraphList(adjacencyList , nodes);
    return 0;
}