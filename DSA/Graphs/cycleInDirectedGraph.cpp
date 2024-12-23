#include <iostream>
#include<list>
using namespace std;

bool cycleDfs(int node, unordered_map<int, bool>& visited, unordered_map<int, bool>& dfsVisited, unordered_map<int, list<int>>& adjList) {
        visited[node] = 1;
        dfsVisited[node] = 1;
        for(auto neighbour: adjList[node]) {
                if(!visited[neighbour]) {
                        bool cycle = cycleDfs(neighbour, visited, dfsVisited, adjList);
                        if (cycle) return 1;
                }
                else if(dfsVisited[neighbour]) return 1;
        }
        dfsVisited[node] = 0;
        return 0;
}
bool detectCycle(int n, vector<pair<int, int>>& edges) {
        unordered_map<int, list<int>> adjList;
        for(int i = 0; i < edges.size(); i++) {
                int u = edges[i].first;
                int v = edges[i].second;
                adjList[u].push_back(v);
        }
        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsVisited;
        for(int i = 1; i <= n; i++) {
                if(!visited[i]) {
                        bool cycleFound = cycleDfs(i, visited, dfsVisited, adjList);
                        if(cycleFound) return 1;
                }
        }
        return 0;
}