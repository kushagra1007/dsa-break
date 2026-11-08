class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp( m, vector<vector<int>>(n, vector<int>(n, 0)));

        for (int j1 = 0; j1 < n; j1++) {
            for (int j2 = 0; j2 < n; j2++) {

                if (j1 == j2)
                    dp[m-1][j1][j2] = grid[m-1][j1];

                else
                    dp[m-1][j1][j2] = grid[m-1][j1] + grid[m-1][j2];
            }
        }
        for (int i = m-2; i >= 0; i--) {
            for (int j1 = 0; j1 < n; j1++) {
                for (int j2 = 0; j2 < n; j2++) {

                    int cherries = grid[i][j1];

                    if (j1 != j2)
                        cherries += grid[i][j2];

                    int maxi = -1e8;

                    for (int dj1 = -1; dj1 <= 1; dj1++) {
                        for (int dj2 = -1; dj2 <= 1; dj2++) {

                            int nj1 = j1 + dj1;
                            int nj2 = j2 + dj2;

                            if (nj1 >= 0 && nj2 >= 0 && nj1 < n && nj2 < n) {
                                maxi = max(maxi, dp[i+1][nj1][nj2]);
                            }
                        }
                    }

                    dp[i][j1][j2] = cherries + maxi;
                }
            }
        }

        return dp[0][0][n-1];
    }
};