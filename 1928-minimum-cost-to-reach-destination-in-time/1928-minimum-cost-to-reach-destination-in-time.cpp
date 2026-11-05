class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        const int INF = 1e9;

        vector<vector<int>> dp(maxTime + 1, vector<int>(n, INF));

        dp[0][0] = passingFees[0];

        for (int t = 0; t <= maxTime; t++) {
            for (auto &e : edges) {
                int u = e[0];
                int v = e[1];
                int time = e[2];

                if (t + time <= maxTime) {
                    if (dp[t][u] != INF) {
                        dp[t + time][v] = min(dp[t + time][v],dp[t][u] + passingFees[v]);
                    }

                    if (dp[t][v] != INF) {
                        dp[t + time][u] = min(dp[t + time][u],dp[t][v] + passingFees[u]);
                    }
                }
            }
        }

        int ans = INF;

        for (int t = 0; t <= maxTime; t++) {
            ans = min(ans, dp[t][n - 1]);
        }

        return ans == INF ? -1 : ans;
    }
};