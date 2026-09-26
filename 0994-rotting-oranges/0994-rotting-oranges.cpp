class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;

        int fresh = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int time = 0;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!q.empty() && fresh > 0) {

            int size = q.size();

            for(int i = 0; i < size; i++) {

                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for(int j = 0; j < 4; j++) {

                    int nr = r + drow[j];
                    int nc = c + dcol[j];

                    if(nr >= 0 && nr < n &&
                       nc >= 0 && nc < m &&
                       grid[nr][nc] == 1) {

                        grid[nr][nc] = 2;
                        fresh--;

                        q.push({nr, nc});
                    }
                }
            }

            time++;
        }

        if(fresh > 0)
            return -1;

        return time;
    }
};