class Solution {
public:
    int m, n;

    vector<vector<int>> directions = {{1, 0},{-1, 0},{0, -1},{0, 1}};

    bool cycleDetectBFS(int r, int c,vector<vector<char>>& grid,vector<vector<bool>>& visited) {

        queue<pair<pair<int, int>, pair<int, int>>> q;
        q.push({{r, c}, {-1, -1}});
        visited[r][c] = true;

        while (!q.empty()) {

            auto front = q.front();
            q.pop();

            int curr_r = front.first.first;
            int curr_c = front.first.second;

            int prev_r = front.second.first;
            int prev_c = front.second.second;

            for (auto &dir : directions) {

                int new_r = curr_r + dir[0];
                int new_c = curr_c + dir[1];

                if (new_r >= 0 && new_r < m &&
                    new_c >= 0 && new_c < n &&
                    grid[new_r][new_c] == grid[curr_r][curr_c]) {
                    if (new_r == prev_r && new_c == prev_c) {
                        continue;
                    }
                    if (visited[new_r][new_c]) {
                        return true;
                    }

                    visited[new_r][new_c] = true;

                    q.push({{new_r, new_c},{curr_r, curr_c}});
                }
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {

        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    if (cycleDetectBFS(i, j, grid, visited)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};