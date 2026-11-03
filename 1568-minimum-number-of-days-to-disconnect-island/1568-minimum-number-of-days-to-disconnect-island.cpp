class Solution {
public:
    int n, m;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        vis[i][j] = true;

        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];

            if (x >= 0 && x < n && y >= 0 && y < m &&
                grid[x][y] == 1 && !vis[x][y]) {
                dfs(x, y, grid, vis);
            }
        }
    }

    int countIslands(vector<vector<int>>& grid) {
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    dfs(i, j, grid, vis);
                    count++;
                }
            }
        }
        return count;
    }

    int minDays(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        if (countIslands(grid) != 1)
            return 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if (countIslands(grid) != 1)
                        return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};