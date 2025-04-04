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

void dfs(int parent,set<int>&safeNodes,vector<int>&visited,vector<int>&pathVisited,Graph<int>&g){
    ++visited[parent];
    ++pathVisited[parent];
    int pathVisitedChilds=0;//this variable telling that any child is pahtVisited mark
    for(auto [child,weight]:g.adjList[parent])
        if(!visited[child]){
            dfs(child,safeNodes,visited,pathVisited,g);
            if(pathVisited[child])
                ++pathVisitedChilds;
            else
                safeNodes.insert(child);
        }else if(visited[child]){
            if(pathVisited[child])
                ++pathVisitedChilds;
            else
                safeNodes.insert(child);
        }
    if(!pathVisitedChilds) //checking that if any child is pathVisited means that child from cycle if not then it is {terminal node}
        safeNodes.insert(parent),--pathVisited[parent];
    return;
}

void DFS1(Graph<int>&g){//It take space complexity O(4N) => visited,pathVisited,safeNodes,answer
    vector<int>visited(g.nodes-1),pathVisited(g.nodes-1),answer;
    set<int>safeNodes;

    for(int node=0;node<g.nodes-1;node++)
        if(!visited[node])
            dfs(node,safeNodes,visited,pathVisited,g);

    for(auto &node:safeNodes)
        answer.emplace_back(node);

    for(auto &node:answer)
        cout<<node<<" ";
    cout<<endl;
    return ;
}

bool dfs(int parent,vector<int>&isFormedCycle,vector<int>&visited,vector<int>&pathVisited,Graph<int>&g){
    ++visited[parent];
    ++pathVisited[parent];
    for(auto [child,weight]:g.adjList[parent])
        if(!visited[child]){
            if(dfs(child,isFormedCycle,visited,pathVisited,g)==true)
                return true;
        }else if(visited[child]){
            if(pathVisited[child])
                return true;
        }
    isFormedCycle[parent]=0;
    --pathVisited[parent];
    return false;
}

void DFS2(Graph<int>&g){
    vector<int>visited(g.nodes-1),pathVisited(g.nodes-1),isFormedCycle(g.nodes-1,1);
    vector<int>answer;
    for(int node=0;node<g.nodes-1;node++)
        if(!visited[node])
            dfs(node,isFormedCycle,visited,pathVisited,g);

    for(int node=0;node<g.nodes-1;node++)
        if(isFormedCycle[node]==0)//says no it does not form any cycle
            answer.emplace_back(node);

    for(auto &node:answer)
        cout<<node<<" ";
    cout<<endl;
    return ;
}

void BFS(Graph<int>&g){// applying toposort
    Graph<int>new_g(g.nodes-1,0);
    //reverese all the directed edges
    for(int parent=0;parent<g.nodes-1;parent++)
        for(auto [child,weight]:g.adjList[parent])
            new_g.addEdge(child,parent,0,1);

    vector<int>indegree(new_g.nodes-1,0);
    vector<int>toposort;

    for(int node=0;node<g.nodes-1;node++)
        for(auto [child,weight]:new_g.adjList[node])
            ++indegree[child];

    queue<int>q;
    for(int node=0;node<new_g.nodes-1;node++)
        if(indegree[node]==0)
            q.push(node);

    while(!q.empty()){
        int parent=q.front();
        q.pop();
        toposort.emplace_back(parent);
        for(auto [child,weight]:new_g.adjList[parent]){
            --indegree[child];
            if(indegree[child]==0)
                q.push(child);
        }
    }
    sort(begin(toposort),end(toposort));//N*ln(N)
    for(auto &node:toposort)
        cout<<node<<" ";
    cout<<endl;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int V=7;
    vector<int>adj[V];
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[0].push_back(2);
    adj[2].push_back(5);
    adj[1].push_back(3);
    adj[3].push_back(0);
    adj[4].push_back(5);

    int nodes=V,edges=0;
    Graph<int>g(nodes,edges);
    for(int parent=0;parent<g.nodes-1;parent++)
        for(auto child:adj[parent])
            g.addEdge(parent,child,0,1);
    
    DFS1(g);//Approach1 Dont look for the this solution both are same with some tweaks 
    DFS2(g);//Approach2 describe how cycle nodes are eliminate
            // try with one vector for {visited,pathVisited}={1,2}
    BFS(g);
    return 0;
}