class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        int ans = -1;
        int minCount = INT_MAX;

        for (int src = 0; src < n; src++) {

            vector<int> dist(n, INT_MAX);
            dist[src] = 0;

            for (int i = 1; i <= n - 1; i++) {

                bool changed = false;

                for (auto edge : edges) {

                    int u = edge[0];
                    int v = edge[1];
                    int w = edge[2];
                    if (dist[u] != INT_MAX &&
                        dist[u] + w < dist[v]) {

                        dist[v] = dist[u] + w;
                        changed = true;
                    }
                    if (dist[v] != INT_MAX &&
                        dist[v] + w < dist[u]) {

                        dist[u] = dist[v] + w;
                        changed = true;
                    }
                }
                if (!changed) {
                    break;
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