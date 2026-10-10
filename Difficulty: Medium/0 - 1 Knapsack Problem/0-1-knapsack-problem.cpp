class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));

        return solve(W, val, wt, n, dp);
    }

    int solve(int W, vector<int> &val, vector<int> &wt, int n,
              vector<vector<int>> &dp) {

        if (n == 0 || W == 0)
            return 0;

        if (dp[n][W] != -1)
            return dp[n][W];

        if (wt[n - 1] <= W) {
            int include = val[n - 1] + solve(W - wt[n - 1], val, wt, n - 1, dp);
            int exclude = solve(W, val, wt, n - 1, dp);

            return dp[n][W] = max(include, exclude);
        }
        else {
            return dp[n][W] = solve(W, val, wt, n - 1, dp);
        }
    }
};