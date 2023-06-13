class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> adj(numCourses);
        for (auto prerequisite : prerequisites) {
            indegree[prerequisite[0]]++;
            adj[prerequisite[1]].push_back(prerequisite[0]);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        int visNode = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            visNode++;
            for (auto nbr: adj[node]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
            
        }
        if (visNode != numCourses) {
            return false;
        }
        return true;
        
    }
};
