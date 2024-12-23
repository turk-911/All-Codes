#include<iostream>
#include<list>
#include<unordered_map>
#include<queue>
#include<vector>
using namespace std;
class graph{
    public:
        unordered_map<int, list<int> > adj;
        void addEdge(int u, int v, bool direction){
          adj[u].push_back(v);
          if(direction == false){
              adj[v].push_back(u);
          }
        }
        void printAdjList(){
            for(auto i : adj){
                cout << i.first << " -> ";
                for(auto j : i.second){
                    cout << j << " ";
                }
                cout << endl;
            }
        }
};
void prepareAdjList(unordered_map<int, list<int> >& adjList, vector<pair<int, int>>& edges){
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}
void solve(unordered_map<int, list<int> > adjList, unordered_map<int, bool> visited, vector<int>& ans, int node){
    queue<int> q;
    q.push(node);
    visited[node] = true;
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);
        for(auto i : adjList[frontNode]){
            if(visited[i] == false){
                q.push(i);
                visited[i] = true;
            }   
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>>& edges){
    unordered_map<int, list<int> > adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;
    prepareAdjList(adjList, edges);
    for(int i = 0; i < vertex; i++){
        if(visited[i] == false){
            solve(adjList, visited, ans, i);
        }
    }
    return ans;
}