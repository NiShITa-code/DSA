#include <bits/stdc++.h>
void dfsSort(int node, vector<int>& visited, vector<int> adj[], stack<int>& st) {
    visited[node] = 1;
    for (auto nbr: adj[node]) {
        if (!visited[nbr]) {
            dfsSort(nbr, visited, adj, st);
        } 
    }
    st.push(node);
}
void dfs(int node, vector<int>& visited, vector<int> adjT[], vector<int>& scc) {
    visited[node] = 1;
    scc.push_back(node);
    for (auto nbr: adjT[node]) {
        if (!visited[nbr]) {
            dfs(nbr, visited, adjT, scc);
        } 
    }
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    // 1. sort the scc node in order of finishing time
    //2. Reverse the edges
    //3. call dfs from sorted order and increment scc for every dfs
    vector<vector<int>> ans;
    vector<int> adj[n];
    vector<int> adjT[n];
    for (int i = 0; i < edges.size(); i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
        adjT[edges[i][1]].push_back(edges[i][0]);
    
    }
    vector<int> visited(n, 0);
    stack<int> st;
    int scc = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfsSort(i, visited, adj, st);
        }
    }
    
       
    fill(visited.begin(), visited.end(), 0);
    while(!st.empty()) {
        int node = st.top();
        st.pop();
        if (!visited[node]) {
            vector<int> scc;
            dfs(node, visited, adjT, scc);
            ans.push_back(scc);
        }
    }
    return ans;

}
