#include<iostream>
#include<unordered_map>
#include<queue>
#include<list>
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
bool detectCycleInDirectedGraph(vector<vector<int>>& edges, int n){
    unordered_map<int, list<int>> adjList = adjacentList(edges);
    vector<int> indegree(n);
    queue<int> q;
    int count = 0;
    for(auto i : adjList){
        for(auto j : i.second){
            indegree[j]++;
        }
    }
    for(int i = 0; i < n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int front = q.front();
        q.pop();
        count++;
        for(auto neighbour : adjList[front]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }
    return count != n;
}