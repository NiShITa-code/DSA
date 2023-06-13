bool dfs(int node, vector<vector<int>>& adj, vector<int>&visited) {
  visited[node] = 2;
  for(int nbr: adj[node]) {
    if (!visited[nbr]) {
      if (dfs(nbr, adj, visited)) {
        return true;
      }
    } else if (visited[nbr] == 2) {
      return true;
    }
  }
  visited[node] = 1;
  return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  vector<int> visited(n + 1, 0);
  vector<vector<int>> adj(n + 1);
  for(int i = 0; i < edges.size(); i++) {
    adj[edges[i].first].push_back(edges[i].second);
  }
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      if (dfs(i, adj, visited) == true) {
        return true;
      }
    }
  }
  return false;
}
