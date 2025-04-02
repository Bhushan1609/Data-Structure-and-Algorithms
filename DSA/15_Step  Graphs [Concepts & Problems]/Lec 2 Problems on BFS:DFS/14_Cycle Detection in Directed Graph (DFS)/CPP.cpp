#include<bits/stdc++.h>
using namespace std;

template<class T>
class Graph{
public:
    T nodes,edges;
    vector<pair<T,T>>*adjList;
    Graph(T n,T e){
        this->nodes=n+1;
        this->edges=e;
        adjList=new vector<pair<T,T>>[this->nodes];
    }
    void addEdge(T u,T v,T weight=0,T directed=0){
        adjList[u].push_back({v,weight});
        if(!directed)
            adjList[v].push_back({u,weight});
    }
    void printGraph(){
        for(T node=0;node<this->nodes;node++){
            cout<<"{"<<node<<"} : ";
            for(auto &[child,weight]:adjList[node])
                cout<<"{"<<child<<","<<weight<<"},";
            cout<<endl;
        }
    }
};

bool DFS(int parent,vector<int>&visited,vector<int>&pathVisited,Graph<int>&g){
    ++visited[parent];
    ++pathVisited[parent];
    for(auto [child,weight]:g.adjList[parent])
        if(!visited[child]){
            if(DFS(child,visited,pathVisited,g))
                return true;
        }else if(pathVisited[child])
            return true;
    --pathVisited[parent];
    return false;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<vector<int>>adj={{1},{2},{3},{3}};

    int nodes=adj.size(),edges=0;
    Graph<int>g(nodes,edges);
    vector<int>visited(g.nodes-1,0),pathVisited(g.nodes-1,0);

    for(int i=0;i<nodes;i++)
        for(int j=0;j<adj[i].size();j++)
            g.addEdge(i,adj[i][j],0,1);
    

    for(int node=0;node<g.nodes-1;node++)
        if(!visited[node])
            if(DFS(node,visited,pathVisited,g)){
                cout<<"Graph has Cycle"<<endl;
                return 0;
            }

    cout<<"Graph has not any cycle"<<endl;
    return 0;
}