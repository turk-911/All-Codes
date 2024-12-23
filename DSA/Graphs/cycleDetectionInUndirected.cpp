#include<iostream>
#include<unordered_map>
#include<queue>
#include<list>
#include<vector>
using namespace std;
bool isCyclicBFS(int node, unordered_map<int, bool>& visited, unordered_map<int, list<int> >& adj){
    unordered_map<int, int> parent;
    parent[node] = -1;
    visited[node] = true;
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        for(auto neighbour : adj[frontNode]){
            if(visited[neighbour] == true && neighbour != parent[frontNode]){
                return true;
            }
            else if(visited[neighbour] == false){
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = frontNode;
            }
        }
    }
    return false;
}
string cycleDetectionBFS(vector<vector<int>>& edges, int n, int m){
    unordered_map<int, list<int>> adj;
    for(int i = 0; i < m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int, bool> visited;
    for(int i = 0; i < n; i++){
        if(visited[i] == false){
            bool ans = isCyclicBFS(i, visited, adj);
            if(ans == true){
                return "Yes";
            }
        }
    }
    return "No";
}
bool isCyclicDFS(int node, int parent, unordered_map<int, bool>& visited, unordered_map<int, list<int>>& adj){
    visited[node] = true;
    for(auto neighbour : adj[node]){
        if(visited[neighbour]){
            bool cycle = isCyclicDFS(neighbour, node, visited, adj);
            if(cycle == true){
                return true;
            }
        }
        else if(neighbour != parent){
            return true;
        }
    }
    return false;
}
string cycleDetectionDFS(vector<vector<int>>& edges, int n, int m){
    unordered_map<int, list<int>> adj;
    for(int i = 0; i < m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int, bool> visited;
    for(int i = 0; i < n; i++){
        if(visited[i] == false){
            bool ans = isCyclicDFS(i, -1, visited, adj);
            if(ans == true){
                return "Yes";
            }
        }
    }
    return "No";
}