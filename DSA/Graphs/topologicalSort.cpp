#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
using namespace std;
void solve(int node, unordered_map<int, list<int>>& adjList, stack<int>& s, unordered_map<int, bool>& visited){
    visited[node] = true;
    for(auto neighbour : adjList[node]){
        if(visited[neighbour] == false){
            solve(neighbour, adjList, s, visited);
        }
    }
    s.push(node);
}
vector<int> topologicalSort(vector<pair<int, int>>& edges, int vertex, int e){
    unordered_map<int, list<int>> adjList;
    unordered_map<int, bool> visited;
    stack<int> s;
    vector<int> ans;
    for(int i = 0; i < edges.size(); i++){                         
        int u = edges[i].first;  
        int v = edges[i].second;
        adjList[u].push_back(v);
    }
    for(int i = 0; i < vertex; i++){
        if(visited[i] == false){
            solve(i, adjList, s, visited);
        }
    }
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}