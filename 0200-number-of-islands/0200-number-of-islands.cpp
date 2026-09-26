class Solution {
public:

    void bfs(int i, int j, vector<vector<bool>>& vis,vector<vector<char>>& grid, int n, int m) {

        queue<pair<int, int>> q;

        q.push({i, j});
        vis[i][j] = true;

        while (!q.empty()) {

            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (x - 1 >= 0 && !vis[x-1][y] && grid[x-1][y] == '1') {
                vis[x-1][y] = true;
                q.push({x-1, y});
            }
            if (y + 1 < m && !vis[x][y+1] && grid[x][y+1] == '1') {
                vis[x][y+1] = true;
                q.push({x, y+1});
            }
            if (x + 1 < n && !vis[x+1][y] && grid[x+1][y] == '1') {
                vis[x+1][y] = true;
                q.push({x+1, y});
            }
            if (y - 1 >= 0 && !vis[x][y-1] && grid[x][y-1] == '1') {
                vis[x][y-1] = true;
                q.push({x, y-1});
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int island = 0;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    bfs(i, j, vis, grid, n, m);
                    island++;
                }
            }
        }
        return island;
    }
};