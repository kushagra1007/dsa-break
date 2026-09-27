class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for(auto edge : prerequisites) {
            int course = edge[0];
            int prerequisite = edge[1];

            adj[prerequisite].push_back(course);
            indegree[course]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;
        while(!q.empty()) {
            int u = q.front();
            q.pop();

            count++;

            for(int v : adj[u]) {
                indegree[v]--;

                if(indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        return count == n;
    }
};