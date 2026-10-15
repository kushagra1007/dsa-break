class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(int i, vector<int>& coins, int amount) {
        if (amount == 0)
            return 1;

        if (i == n)
            return 0;

        if (dp[i][amount] != -1)
            return dp[i][amount];

        int skip = solve(i + 1, coins, amount);

        int take = 0;
        if (coins[i] <= amount)
            take = solve(i, coins, amount - coins[i]);

        return dp[i][amount] = take + skip;
    }

    int change(int amount, vector<int>& coins) {
        n = coins.size();
        dp.assign(n, vector<int>(amount + 1, -1));
        return solve(0, coins, amount);
    }
};