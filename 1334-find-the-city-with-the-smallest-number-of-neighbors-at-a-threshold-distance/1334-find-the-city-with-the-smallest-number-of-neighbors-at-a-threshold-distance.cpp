class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<pair<int, int>>> adj(n);

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        int ans = -1;
        int minCount = INT_MAX;

        for (int src = 0; src < n; src++) {

            vector<int> dist(n, INT_MAX);

            priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq;

            dist[src] = 0;
            pq.push({0, src});

            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();
                if (d > dist[u]) {
                    continue;
                }
                for (auto [v, w] : adj[u]) {
                    if (d + w < dist[v]) {
                        dist[v] = d + w;
                        pq.push({dist[v], v});
                    }
                }
            }
            int count = 0;
            for (int i = 0; i < n; i++) {
                if (i != src &&
                    dist[i] <= distanceThreshold) {
                    count++;
                }
            }
            if (count <= minCount) {
                minCount = count;
                ans = src;
            }
        }
        return ans;
    }
};