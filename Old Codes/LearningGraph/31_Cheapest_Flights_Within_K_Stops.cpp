#include <bits/stdc++.h>
using namespace std;
void inputForList(vector <pair<int,int>> adjacencyList[] , int edges){
    for (int i = 0 ; i < edges ; i++){
        int u , v,wt;
        cout << "Enter Node which have Edge Between : ";cin >> u >> v >> wt;
        adjacencyList[u].push_back({v,wt});
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
int calculateMinCost(vector<pair<int , int>>adjacencyList[],int src,int dest ,int k,int nodes){
    vector<int>dist(nodes,1e9);
    queue<pair<int ,pair<int,int>>>q;
    int start=0;
    //     stops,nodes,dist
    q.push({start,{src,0}});
    dist[src]=0;
    while(!q.empty()){
        int stops=q.front().first;
        int node=q.front().second.first;
        int dis=q.front().second.second;
        q.pop();
        if(stops>k) continue;
        for(auto i: adjacencyList[node]){
            if(dist[i.first]>dis+i.second and stops <= k){
                dist[i.first]=dis+i.second;
                q.push({stops+1,{i.first,dis+i.second}});
            }
        }
    }
    if(dist[dest]==1e9) return -1;
    return dist[dest];
}
int main(){
    int nodes , edges ;
    cout << "Enter Numbers of Nodes : "; cin >> nodes;
    cout << "Enter Numbers of Edges : "; cin >> edges;
    vector <pair<int,int>> adjacencyList[nodes+1];
    inputForList(adjacencyList , edges);
    // printGraphList(adjacencyList , nodes);
    int src=0,dest=2,k=2;
    //For this graph 
    //Nodes : 5
    //Edges : 5
    // 0 1 5
    // 0 3 2
    // 1 2 5
    // 1 4 1
    //3 1 2 
    int ans=calculateMinCost(adjacencyList,src,dest,k,nodes);
    cout<< "Minimum Cost to Travel From "<< src << " to " << dest << " is : "<< ans <<endl;
    return 0;
}