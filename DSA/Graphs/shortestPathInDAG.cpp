#include<iostream>
#include<unordered_map>
#include<stack>
#include<list>
#include<vector>
using namespace std;
class Graph{
    public:
    unordered_map<int, list<pair<int, int> > > adjList;
    void addEdge(int u, int v, int weight){
        pair<int, int> p = make_pair(v, weight);
        adjList[u].push_back(p);
    }
    void printAdj(){
        for(auto i : adjList){
            cout << i.first << " -> ";
            for(auto j : i.second){
                cout << "(" << j.first << " ," << j.second << ")," ;
            }
            cout << endl;
        }
    }
    void dfs(int node, unordered_map<int, bool>& visited, stack<int>& s, unordered_map<int, list<pair<int, int> > > & adjList){
        visited[node] = true;
        for(auto neighbour : adjList[node]){
            if(!visited[neighbour.first]){
                dfs(neighbour.first, visited, s, adjList);
            }
        }
        s.push(node);
    }
    void shortestPath(int src, vector<int>& distance, stack<int>& s){
        distance[src] = 0;
        while(!s.empty()){
            int top = s.top();
            s.pop();
            if(distance[top] != INT_MAX){
                for(auto i : adjList[top]){
                    if(distance[top] + i.second < distance[i.first]){
                        distance[i.first] = distance[top] + i.second;
                    }
                }
            }
        }
    }
};
int main(){
    Graph g;
    int n = 6, src = 1;
    unordered_map<int, list<pair<int, int> > > adjList;
    stack<int> s;
    unordered_map<int, bool> visited;
    vector<int> distance(n);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
    g.printAdj();
    for(int i = 0; i < 6; i++){
        if(!visited[i]){
            g.dfs(i, visited, s, adjList);
        }
    }
    for(int i = 0; i < n; i++){
        distance[i] = INT_MAX;
    }
    g.shortestPath(src, distance, s);
    for(int i = 0; i < distance.size(); i++){
        cout << distance[i] << " " ;
    } 
    return 0;
}