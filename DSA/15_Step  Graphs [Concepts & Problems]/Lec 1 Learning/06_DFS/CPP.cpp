#include<bits/stdc++.h>
using namespace std;

template<class T>
class Graph{
public:
    T nodes;
    T edges;
    vector<pair<T,T>>*adjList;
    Graph(T n,T e){
        this->nodes=n+1;
        this->edges=e;
        adjList=new vector<pair<T,T>>[nodes+1];
    }
    void addEdge(T u,T v,T wt=0,T dir=0){
        adjList[u].push_back({v,wt});
        if(!dir)
            adjList[v].push_back({u,wt});
    }
    void printGraph(){
        for(T i=0;i<this->nodes;i++){
            cout<<i<<":";
            for(auto &j:adjList[i])
                cout<<"{"<<j.first<<","<<j.second<<"},";
            cout<<endl;
        }
    }
};

void dfsRecursion(int node,vector<int>&visited,Graph<int>&g){
    ++visited[node];
    cout<<node<<" ";
    for(auto &j:g.adjList[node])
        if(!visited[j.first])
            dfsRecursion(j.first,visited,g);
    return ;
}

void DFS(Graph<int>&g,int src){
    int n=g.nodes;
    vector<int>visited(n,0);
    dfsRecursion(src,visited,g);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int nodes;
    int edges;
    int src=1;
    cout<<"Enter Nodes & Edges respectively : "<<endl;
    cin>>nodes>>edges;
    cout<<"Enter Source Node to start : "<<endl;
    cin>>src;
    Graph<int>g(nodes,edges);
    for(int i=0;i<edges;i++){
        int u,v;
        cout<<"Enter Edge in Between : "<<endl;
        cin>>u>>v;
        g.addEdge(u,v);
    }
    DFS(g,src);
    return 0;
}