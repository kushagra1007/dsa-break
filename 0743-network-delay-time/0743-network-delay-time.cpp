class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<pair<int,int>> graph[n + 1];
        for(auto edge : times) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            graph[u].push_back({v, wt});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        pq.push({0, k});

        while(!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            int d = curr.first;
            int u = curr.second;

            if(d > dist[u]){
                continue;
            }
            for(auto edge : graph[u]) {

                int v = edge.first;
                int wt = edge.second;
                if(d + wt < dist[v]) {
                    dist[v] = d + wt;
                    pq.push({dist[v], v});
                }
            }
        }
        int ans = 0;

        for(int i = 1; i <= n; i++) {

            if(dist[i] == INT_MAX){
                return -1;
            }
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};