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
    ++visited[node];
    for(auto &[child,weight]:g.adjList[node])
        if(!visited[child])
            dfsRecursion(child,visited,g);
    return ;
}

int DFS(Graph<int>&g){
    int cnt=0;
    vector<int>visited(g.nodes);
    for(int node=0;node<g.nodes-1;node++)//g.nodes-1=>bcoz,zero based indexing
        if(!visited[node])
            dfsRecursion(node,visited,g),++cnt;
    return cnt;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<vector<int>>graphInput={{1,1,0},{1,1,0},{0,0,1}};
    int nodes=graphInput.size();
    Graph<int>g(nodes,0);
    for(int i=0;i<graphInput.size();i++)
        for(int j=0;j<graphInput[i].size();j++)
            if(i!=j && graphInput[i][j])
                g.addEdge(i,j,0,1);
    
    cout<<"Number of Provinces are : "<<DFS(g)<<endl;
    return 0;
}