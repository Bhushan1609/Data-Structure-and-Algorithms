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
    set<pair<int,int>>set;
    //         Dist Node
    set.insert({0,0});
    dist[0]=0;
    while(!set.empty()){
        pair<int,int>top=*(set.begin());
        int dist1=top.first;
        int node=top.second;
        set.erase(top); 
        for(auto i:adjacencyList[node]){
            int wt=i.second;
            int adjacentnode=i.first;
            if(dist1+wt<dist[adjacentnode]){
                if(dist[adjacentnode]!=1e9){
                    set.erase({dist[adjacentnode],adjacentnode});
                }
                dist[adjacentnode]=dist1+wt;
                set.insert({dist[adjacentnode],adjacentnode});
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