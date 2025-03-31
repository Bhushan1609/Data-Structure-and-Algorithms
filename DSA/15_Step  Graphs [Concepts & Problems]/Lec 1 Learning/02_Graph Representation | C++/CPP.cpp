#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>createGraphMatrix(int &nodes,int &edges){
    vector<vector<int>>graph(nodes+1,vector<int>(nodes+1));
    for(int i=0;i<edges;i++){
        int u,v;
        cout<<"Enter Edge In Between : "<<endl;
        cin>>u>>v;
        ++graph[u][v];
        ++graph[v][u];
    }
    return graph;
}

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


int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int nodes,edges;
    cout<<"Enter Nodes & Edges Respectively : "<<endl;
    cin>>nodes>>edges;

    vector<vector<int>>graphMatrix=createGraphMatrix(nodes,edges);
    for(auto &i:graphMatrix){
        for(auto &j:i)
            cout<<j<<" ";
        cout<<endl;
    }

    Graph<int>g(nodes,edges);
    for(int i=0;i<edges;i++){
        int u,v;
        cout<<"Enter Edge In Between : "<<endl;
        cin>>u>>v;
        g.addEdge(u,v);
    }
    g.printGraph();
    return 0;
}