class Solution {
public:
    int m, n;

    void bfs(vector<vector<int>>& grid, int i, int j,vector<vector<bool>>& vis) {

        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = true;

        while (!q.empty()) {

            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            if (r + 1 < m &&
                grid[r + 1][c] == 1 &&
                !vis[r + 1][c]) {
                vis[r + 1][c] = true;
                q.push({r + 1, c});
            }

            if (r - 1 >= 0 &&
                grid[r - 1][c] == 1 &&
                !vis[r - 1][c]) {
                vis[r - 1][c] = true;
                q.push({r - 1, c});
            }

            if (c + 1 < n &&
                grid[r][c + 1] == 1 &&
                !vis[r][c + 1]) {
                vis[r][c + 1] = true;
                q.push({r, c + 1});
            }

            if (c - 1 >= 0 &&
                grid[r][c - 1] == 1 &&
                !vis[r][c - 1]) {
                vis[r][c - 1] = true;
                q.push({r, c - 1});
            }
        }
    }

    int numberOfIslands(vector<vector<int>>& grid) {

        int islands = 0;

        vector<vector<bool>> vis(m, vector<bool>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1 && !vis[i][j]) {

                    islands++;
                    bfs(grid, i, j, vis);
                }
            }
        }

        return islands;
    }

    int minDays(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        int islands = numberOfIslands(grid);

        if (islands > 1 || islands == 0) {
            return 0;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {

                    grid[i][j] = 0;

                    islands = numberOfIslands(grid);

                    if (islands > 1 || islands == 0) {
                        return 1;
                    }

                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};