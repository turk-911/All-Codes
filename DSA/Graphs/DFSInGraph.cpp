#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
void solve(int node, unordered_map<int, bool>& visited, unordered_map<int, list<int>>& adj, vector<int>& component){
    component.push_back(node);
    visited[node] = true;
    for(auto i : adj[node]){
        if(visited[i] == false){
            solve(i, visited, adj, component);
        }
    }
}
vector<vector<int>> depthFirstSearch(int vertex, int e, vector<vector<int>>& edges){
    unordered_map<int, list<int>> adj;
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> ans;
    unordered_map<int, bool> visited;
    for(int i = 0; i < vertex; i++){
        if(visited[i] == false){
            vector<int> component;
            solve(i, visited, adj, component);
            ans.push_back(component);
        }
    }
    return ans;
}