#include <bits/stdc++.h>
bool dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& visited) {
    visited[node] = 1;
    for (auto nbr: adj[node]) {
        if (!visited[nbr]) {
            if (dfs(nbr, node, adj, visited)) {
                return true;
            }
        } else if (nbr != parent) {
            return true;
        }
    }
    return false;

}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    string ans = "Yes";
    vector<int> visited(n + 1, 0);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited)) {
                return ans;
            }
        }
    }
    ans = "No";
    return ans;

    
}

