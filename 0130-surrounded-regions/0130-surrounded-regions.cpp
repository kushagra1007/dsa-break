class Solution {
public:

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                board[i][0] = '#';
                q.push({i, 0});
            }

            if (board[i][n - 1] == 'O') {
                board[i][n - 1] = '#';
                q.push({i, n - 1});
            }
        }

        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') {
                board[0][j] = '#';
                q.push({0, j});
            }

            if (board[m - 1][j] == 'O') {
                board[m - 1][j] = '#';
                q.push({m - 1, j});
            }
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int ni = i + dr[k];
                int nj = j + dc[k];

                if (ni >= 0 && ni < m && nj >= 0 && nj < n &&
                    board[ni][nj] == 'O') {

                    board[ni][nj] = '#';
                    q.push({ni, nj});
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == 'O')
                    board[i][j] = 'X';

                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
}
;