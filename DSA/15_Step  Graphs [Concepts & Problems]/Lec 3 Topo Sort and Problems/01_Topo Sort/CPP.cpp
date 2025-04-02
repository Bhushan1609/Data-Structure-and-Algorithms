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

void dfs(int parent,vector<int>&toposort,vector<int>&visited,Graph<int>&g){
    ++visited[parent];
    for(auto [child,weight]:g.adjList[parent])
        if(!visited[child])
            dfs(child,toposort,visited,g);
    toposort.emplace_back(parent);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int nodes=4,edges=3;
    Graph<int>g(nodes,edges);
    vector<vector<int>>edgesDirected={{3,0},{1,0},{2,0}};
    vector<int>visited(g.nodes-1,0);
    vector<int>toposort;//treated as stack 
    

    for(auto edge:edgesDirected)
        g.addEdge(edge[0],edge[1],0,1);

    for(int node=0;node<g.nodes-1;node++)
        if(!visited[node])
            dfs(node,toposort,visited,g);

    reverse(begin(toposort),end(toposort));//rather using stack use vector then reverse saves some space complexity        
    for(auto node:toposort)
        cout<<node<<" ";
    return 0;
}