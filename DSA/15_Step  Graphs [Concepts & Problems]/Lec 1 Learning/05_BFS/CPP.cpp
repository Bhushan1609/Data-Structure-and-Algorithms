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

void BFS(Graph<int>&g,int &sourceNode){
    vector<int>visited(g.nodes);
    queue<int>q;
    q.push(sourceNode);
    ++visited[sourceNode];
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            int topNode=q.front();
            q.pop();
            cout<<topNode<<" ";
            for(auto &[child,weight]:g.adjList[topNode])
                if(!visited[child])
                    q.push(child),++visited[child];
        }
    }
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
    BFS(g,sourceNode);
    return 0;
}