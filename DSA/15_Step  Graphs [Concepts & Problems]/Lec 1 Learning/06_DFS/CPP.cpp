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

void dfsRecursion(int &node,vector<int>&visited,Graph<int>&g){
    cout<<node<<" ";
    ++visited[node];
    for(auto &[child,weight]:g.adjList[node])
        if(!visited[child])
            dfsRecursion(child,visited,g);
    return ;
}

void DFS(Graph<int>&g,int &sourceNode){
    vector<int>visited(g.nodes);
    dfsRecursion(sourceNode,visited,g);
    return ;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int nodes,edges,sourceNode=1;
    cout<<"Enter Nodes & Edges & Source Node Respectively : "<<endl;
    cin>>nodes>>edges>>sourceNode;

    Graph<int>g(nodes,edges);
    for(int i=0;i<edges;i++){
        int u,v;
        cout<<"Enter Edge In Between : "<<endl;
        cin>>u>>v;
        g.addEdge(u,v);
    }
    DFS(g,sourceNode);
    return 0;
}