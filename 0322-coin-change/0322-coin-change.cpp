class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;

        if (i == coins.size() || amount < 0)
            return INT_MAX;

        if (dp[i][amount] != -1)
            return dp[i][amount];

        int take = solve(i, coins, amount - coins[i]);
        if (take != INT_MAX)
            take++;

        int skip = solve(i + 1, coins, amount);

        return dp[i][amount] = min(take, skip);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.assign(n, vector<int>(amount + 1, -1));

        int ans = solve(0, coins, amount);
        return ans == INT_MAX ? -1 : ans;
    }
};