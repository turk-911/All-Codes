#include<iostream>
#include<queue>
#include<unordered_map>
#include<list>
using namespace std;
unordered_map<int, list<int>> adjacentList(vector<vector<int>>& edges){
    unordered_map<int, list<int>> adjList;
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    return adjList;
}
vector<int> shortestPath(vector<vector<int>>& edges, int n, int m, int s, int t){
    unordered_map<int, list<int>> adjList = adjacentList(edges);
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    vector<int> ans;
    queue<int> q;
    q.push(s); visited[s] = true; parent[s] = -1;
    int currentNode = t; ans.push_back(t);
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(auto i : adjList[front]){
            if(visited[i] == false){
                visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
        }
    }
    while(currentNode != s){
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}