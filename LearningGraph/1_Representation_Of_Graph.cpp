#include <bits/stdc++.h>
using namespace std;
void printGraphMatrix(vector <vector <int>>& adjacencyMatrix){
    cout << "GraphMatrix is : " << endl;
    for (auto i : adjacencyMatrix){
        for (auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    return ;
}
void inputForMatrix(vector <vector <int>>& adjacencyMatrix , int m){
    for (int i = 0 ; i < m ; i++){
        int u , v , wt; 
        cout << "Enter Node which have Edge Between : ";cin >> u >> v;
        cout << "Enter weight : "; cin >> wt;
        adjacencyMatrix[u][v] = wt;// instead 1 store weight for the weighted Graph
        adjacencyMatrix[v][u] = wt;
    }
    cout << endl;
    return ;
}
void printGraphList(vector <pair <int , int >>  adjacencyList[] , int n){
    for (int i = 0 ; i < n ; i++){
        cout << "{" << i << "} : ";
        for (auto j : adjacencyList[i]){
            cout << "(" << j.first << " " << j.second << ")" << " ";
        } 
        cout << endl;
    }
    cout << endl;
    return ;
}
void inputForList(vector <pair <int , int >>  adjacencyList[] , int m){
    for (int i = 0 ; i < m ; i++){
        int u , v , wt;
        cout << "Enter Node which have Edge Between : ";cin >> u >> v;
        cout << "Enter weight : "; cin >> wt;
        adjacencyList[u].push_back({v , wt});
        adjacencyList[v].push_back({u , wt});
    }
    cout << endl;
    return ;
}
int main(){
    int n ;//numbers of nodes
    int m ;//numbers of edges
    cout << "Enter Numbers of Nodes : "; cin >> n;
    cout << "Enter Numbers of Edges : "; cin >> m;
    vector<vector <int>> adjacencyMatrix(n+1 , vector <int>(n+1 , 0));
    inputForMatrix(adjacencyMatrix , m);
    printGraphMatrix(adjacencyMatrix);
    vector <pair <int , int >> adjacencyList[n+1];
    inputForList(adjacencyList , m);
    printGraphList(adjacencyList , n);
    return 0;
}