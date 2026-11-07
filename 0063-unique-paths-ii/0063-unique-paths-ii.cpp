class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(i >= m || j >= n)
            return 0;
        if(obstacleGrid[i][j] == 1)
            return 0;
        if(i == m-1 && j == n-1)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        int down = solve(i + 1, j, obstacleGrid, dp);
        int right = solve(i, j+1, obstacleGrid, dp);

        return dp[i][j] = down + right;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, obstacleGrid, dp);
    }
};