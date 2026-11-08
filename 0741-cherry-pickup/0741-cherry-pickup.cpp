class Solution {
public:
    int solve(int r1, int c1, int r2, vector<vector<int>>& grid, int n, vector<vector<vector<int>>>& dp){
        int c2 = r1 + c1 - r2;
        if(r1 >= n || c1 >= n || r2 >= n || c2 >= n)
            return -1e8;

        if(grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return -1e8;

        if(r1 == n-1 && c1 == n-1)
            return grid[r1][c1];

        if (dp[r1][c1][r2] != -1)
            return dp[r1][c1][r2];

        int cherries = grid[r1][c1];

        if(r1 != r2 || c1 != c2)
            cherries += grid[r2][c2];

        int a = solve(r1+1, c1, r2+1, grid, n, dp);
        int b = solve(r1+1, c1, r2, grid, n, dp);
        int c = solve(r1, c1+1, r2+1, grid, n, dp);
        int d = solve(r1, c1+1, r2, grid, n, dp);

        return dp[r1][c1][r2] = cherries + max({a, b, c, d});
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<vector<int>>> dp(n,vector<vector<int>> (n, vector<int>(n, -1)));

        int ans = solve(0, 0, 0, grid, n, dp);
        return max(0, ans);
    }
};