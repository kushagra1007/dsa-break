class Solution {
public:

    int solve(int i, int j, vector<vector<int>>& grid, int m, int n, vector<vector<int>>& dp) {

        if(i >= m || j >= n)
            return INT_MAX;

        if(i == m-1 && j == n-1)
            return max(1, 1 - grid[i][j]);

        if(dp[i][j] != -1)
            return dp[i][j];

        int down = solve(i + 1, j, grid, m, n, dp);
        int right = solve(i, j + 1, grid, m, n, dp);

        int mini = min(down, right);

        return dp[i][j] = max(1, mini - grid[i][j]);
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(0, 0, dungeon, m, n, dp);
    }
};