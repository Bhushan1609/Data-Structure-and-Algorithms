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

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int numCourses=2;
    vector<vector<int>>prerequisites={{1,0}};
    int nodes=numCourses,edges=0;
    Graph<int>g(nodes,edges);
    vector<int>indegree(g.nodes-1,0);
    vector<int>toposort;

    for(int i=0;i<prerequisites.size();i++)
        for(int j=0;j<prerequisites[i].size();j++)
            g.addEdge(prerequisites[i][0],prerequisites[i][1],0,1);

    for(int node=0;node<g.nodes-1;node++)
        for(auto [child,weight]:g.adjList[node])
            ++indegree[child];

    queue<int>q;
    for(int node=0;node<g.nodes-1;node++)
        if(indegree[node]==0)
            q.push(node);

    while(!q.empty()){
        int parent=q.front();
        q.pop();
        toposort.emplace_back(parent);
        for(auto [child,weight]:g.adjList[parent]){
            --indegree[child];
            if(indegree[child]==0)
                q.push(child);
        }
    }

    if(toposort.size() != g.nodes-1)
        cout<<"Graph has Cycle can't Finish the Courses"<<endl;
    else
        cout<<"Graph has not Cycle can Finish the Courses"<<endl;    
    return 0;
}