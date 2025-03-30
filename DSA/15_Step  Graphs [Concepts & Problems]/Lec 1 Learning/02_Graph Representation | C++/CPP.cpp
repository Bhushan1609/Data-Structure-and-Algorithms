#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> createGraphMat(){
    int n,m;
    cout<<"Enter numbers of nodes & edges respectively : "<<endl;cin>>n>>m;
    vector<vector<int>>graph(n+1,vector<int>(n+1,0));
    for(int i=0;i<m;i++){
        int u,v;
        cout<<"Enter Edge in between : "<<endl;
        cin>>u>>v;
        ++graph[u][v];
        ++graph[v][u];
    }
    return graph;
}

void printGraphMat(vector<vector<int>>&graph){
    for(auto i:graph){
        for(auto j:i)
            cout<<j<<" ";
        cout<<endl;
    }
    return;
}

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
        for(T i=0;i<this->edges;i++){
            T u,v;
            cout<<"Enter Edge in Between : "<<endl;
            cin>>u>>v;
            addEdge(u,v);
        }
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

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<vector<int>>graphMat=createGraphMat();
    printGraphMat(graphMat);

    Graph<int> g(5,6);
    g.printGraph();
    return 0;
}