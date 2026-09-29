class Solution {
public:

    int dfs(int u, int dst, int flightsLeft,
            vector<pair<int,int>> graph[],
            vector<vector<int>>& dp) {

        if(u == dst)
            return 0;

        if(flightsLeft == 0)
            return 1e9;

        if(dp[u][flightsLeft] != -1)
            return dp[u][flightsLeft];

        int ans = 1e9;

        for(auto edge : graph[u]) {

            int v = edge.first;
            int wt = edge.second;

            int cost = dfs(v, dst, flightsLeft - 1, graph, dp);

            if(cost != 1e9)
                ans = min(ans, wt + cost);
        }

        return dp[u][flightsLeft] = ans;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<pair<int,int>> graph[n];

        for(auto flight : flights) {

            int u = flight[0];
            int v = flight[1];
            int wt = flight[2];

            graph[u].push_back({v, wt});
        }

        vector<vector<int>> dp(n, vector<int>(k + 2, -1));

        int ans = dfs(src, dst, k + 1, graph, dp);

        return ans == 1e9 ? -1 : ans;
    }
};