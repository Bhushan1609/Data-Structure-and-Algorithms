#include<bits/stdc++.h>
using namespace std;

template<class T>
class Graph{
public:
    T nodes;
    T edges;
    vector<pair<T,T>>*adjList;
    Graph(T n,T e){
        this->nodes=n;
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

void dfsRecursion(int node,Graph<int>&g,vector<int>&visited){
    ++visited[node];
    for(auto i:g.adjList[node])
        if(!visited[i.first])
            dfsRecursion(i.first,g,visited);
}

int DFS(Graph<int>&g){
    int nodes=g.nodes,cnt=0;
    vector<int>visited(nodes);
    for(int i=0;i<nodes;i++)
        if(!visited[i]){
            dfsRecursion(i,g,visited);
            ++cnt;
        }
    return cnt;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    vector<vector<int>>adj={
        {1,1,0},{1,1,0},{0,0,1}
    };
    int nodes=adj.size();
    int edges=0;
    for(int i=0;i<adj.size();i++)
        for(int j=0;j<adj[i].size();j++)
            edges+=(i!=j && adj[i][j]);
    Graph g(nodes,edges);
    for(int i=0;i<adj.size();i++)
        for(int j=0;j<adj[i].size();j++)
            if(i!=j && adj[i][j])
                g.addEdge(i,j,0,1);
    cout<<"Number Of Provinces are : "<<DFS(g)<<endl;
    return 0;
}