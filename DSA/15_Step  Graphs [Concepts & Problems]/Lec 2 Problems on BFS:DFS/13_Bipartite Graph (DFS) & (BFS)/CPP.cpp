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

bool BFS(int &node,vector<int>&visited,Graph<int>&g){
    queue<int>q;
    q.push(node);
    visited[node]=0;//Used 0 Color
    while(!q.empty()){
        int q_size=q.size();
        for(int q_it=0;q_it<q_size;q_it++){
            auto parent=q.front();
            q.pop();
            for(auto [child,weight]:g.adjList[parent]){
                if(visited[child]==-1){
                    q.push(child);
                    visited[child]=(visited[parent]==0?1:0);//mark according to parent
                }else{
                    if(visited[child] == visited[parent])
                        return false;
                }
            }
        }
    }
    return true;
}

bool DFS(int parent,int color,vector<int>&visited,Graph<int>&g){
    visited[parent]=color;
    for(auto [child,weight]:g.adjList[parent])
        if(visited[child]==-1){
            if(DFS(child,!color,visited,g)==false)
                return false;
        }else if(visited[parent]==visited[child])
            return false;
    return true;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<vector<int>>graph={{1,2,3},{0,2},{0,1,3},{0,2}};
    int nodes=graph.size(),edges=0;
    Graph<int>g(nodes,edges);
    for(int i=0;i<graph.size();i++)
        for(int j=0;j<graph[i].size();j++)
            g.addEdge(i,graph[i][j],0,1);

    vector<int>visited(g.nodes-1,-1);//0 Based Indexing
    bool ans=true,ans1=true;
    for(int node=0;node<g.nodes-1;node++)//what if there are multiple graph components
        if(visited[node]==-1)
            ans&=BFS(node,visited,g);

    fill(begin(visited),end(visited),-1);
    for(int node=0;node<g.nodes-1;node++)
        if(visited[node]==-1)
            ans1&=DFS(node,0,visited,g);

    if(ans)
        cout<<"Indeed graph is Bipartite Graph"<<endl;
    else
        cout<<"Not Bipartite Graph"<<endl;

    if(ans1)
        cout<<"Indeed graph is Bipartite Graph"<<endl;
    else
        cout<<"Not Bipartite Graph"<<endl;
    return 0;
}