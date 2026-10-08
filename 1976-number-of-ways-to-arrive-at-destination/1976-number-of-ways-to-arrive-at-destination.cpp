class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const long long MOD = 1e9 + 7;

        vector<vector<pair<int,int>>> adj(n);

        for (auto &r : roads) {
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);

        set<pair<long long,int>> st;

        dist[0] = 0;
        ways[0] = 1;

        st.insert({0, 0});

        while (!st.empty()) {
            auto [d, u] = *st.begin();
            st.erase(st.begin());

            for (auto [v, wt] : adj[u]) {
                long long nd = d + wt;

                if (nd < dist[v]) {
                    if (dist[v] != LLONG_MAX)
                        st.erase({dist[v], v});

                    dist[v] = nd;
                    ways[v] = ways[u];

                    st.insert({dist[v], v});
                }
                else if (nd == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};