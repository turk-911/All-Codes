#include<iostream>
#include<queue>
#include<list>
#include<unordered_map>
using namespace std;
unordered_map<int, list<int>> adjacentList(vector<vector<int>>& edges){
    unordered_map<int, list<int>> adjList;
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
    }
    return adjList;
}
vector<int> kahnsAlgorithm(vector<vector<int>>& edges, int v, int e){
    unordered_map<int, list<int>> adj = adjacentList(edges);
    vector<int> indegree(v);
    vector<int> ans;
    queue<int> q;
    for(auto i : adj){
        for(auto j : i.second){
            indegree[j]++;
        }
    }
    for(int i = 0; i < v; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for(auto neighbour : adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }
    return ans;
}   