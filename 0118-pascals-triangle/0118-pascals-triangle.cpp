class Solution {
public:
    int solve(int r, int c, vector<vector<int>>& dp) {
        if (c == 0 || c == r)
            return 1;

        if (dp[r][c] != -1)
            return dp[r][c];

        return dp[r][c] = solve(r - 1, c - 1, dp) + solve(r - 1, c, dp);
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<vector<int>> dp(numRows, vector<int>(numRows, -1));

        for (int i = 0; i < numRows; i++) {
            vector<int> row;

            for (int j = 0; j <= i; j++) {
                row.push_back(solve(i, j, dp));
            }

            ans.push_back(row);
        }

        return ans;
    }
};