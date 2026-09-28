class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for(int i = 0; i < prerequisites.size(); i++) {

            int course = prerequisites[i][0];
            int prerequisite = prerequisites[i][1];
            adj[prerequisite].push_back(course);

            indegree[course]++;
        }
        queue<int> q;

        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()) {

            int src = q.front();
            q.pop();

            ans.push_back(src);

            for(int v : adj[src]) {

                indegree[v]--;
                if(indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        if(ans.size() == n) {
            return ans;
        }
        return {};
    }
};