class Solution {
public:

    void dfs(int u, vector<pair<int,int>> graph[],
             vector<int>& dist) {

        for(auto edge : graph[u]) {

            int v = edge.first;
            int wt = edge.second;
            if(dist[u] + wt < dist[v]) {

                dist[v] = dist[u] + wt;

                dfs(v, graph, dist);
            }
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<pair<int,int>> graph[n + 1];

        // Create graph
        for(auto edge : times) {

            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            graph[u].push_back({v, wt});
        }

        vector<int> dist(n + 1, INT_MAX);

        dist[k] = 0;

        dfs(k, graph, dist);

        int ans = 0;

        for(int i = 1; i <= n; i++) {

            if(dist[i] == INT_MAX)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};