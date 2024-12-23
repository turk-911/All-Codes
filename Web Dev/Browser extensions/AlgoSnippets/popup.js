const algorithmSnippets = {
  binarySearch: ` 
  int binarySearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    while(left <= right) {
      int mid = left + (right - left) / 2;
      if(arr[mid] == target) return mid;
      if(arr[mid] < target) left = mid + 1;
      else right = mid - 1;
    }
    return -1;
  }
  `,
  dijkstra: `
  const int INF = INT_MAX;
  vector<int> dijkstra(int V, vector<vector<pair<int, int>>> &adj, int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, INF);
    dist[src] = 0;
    pq.push({0, src});
    while(!pq.empty()) {
      int u = pq.top().second;
      pq.pop();
      for(auto& edge: adj[u]) {
        int v = edge.first;
        int weight = edge.second;
        if(dist[u] + weight < dist[v]) {
          dist[v] = dist[u] + weight;
          pq.push({dist[v], v});
        }
      }
    }
    return dist;
  }
  `,
  kruskalAlgo: `
    struct Edge {
      int src, dest, weight;
    };
    bool compare(Edge a, Edge b) {
      return a.weight < b.weight;
    }
    int findParent(int v, vector<int> &parent) {
      if(v == parent[v]) return v;
      return parent[v] = findParent(parent[v], parent);
    }
    void unionSets(int u, int v, vector<int> &parent, vector<int> &rank) {
      u = findParent(u, parent);
      v = findParent(v, parent);
      if(rank[u] < rank[v]) parent[u] = v;
      else if(rank[v] < rank[u]) parent[v] = u;
      else {
        parent[v] = u;
        rank[u]++;
      }
    }
    void kruskal(vector<Edge>& edge, int V) {
      sort(edges.begin(), edges.end(), compare);
      vector<int> parent(V);
      vector<int> rank(V, 0);
      for(int i = 0; i < V; i++) parent[i] = i;
      int mstWeight = 0;
      vector<Edge> mstEdges;
      for(Edge& edge: edges) {
        int u = findParent(edge.src, parent);
        int v = findParent(edge.dest, parent);
        if(u != v) {
          mstEdges.push_back(edge);
          mstWeight += edge.weight;
          unionSets(u, v, parent, rank);
        }
      }
      cout << "Edges in mst: \n";
      for(Edge& edge: mstEdges) {
        cout << edge.src << " -- " << edge.dest << " == " << edge.weight << "\n";
      }
      cout << "Total weight of MST: " << mstWeight << endl;
    }
  `
};
const algoSelector = document.getElementById('algo-selector');
const snippetContainer = document.getElementById('code-snippet');
const getSnippetBtn = document.getElementById('get-snippet');
getSnippetBtn.addEventListener('click', () => {
  const selectedAlgo = algoSelector.value;
  const snippet = algorithmSnippets[selectedAlgo];
  snippetContainer.textContent = snippet || "No snippet available at this moment";
});