class Solution {
public:
    int m,n;
    void dfs(vector<vector<int>>& grid,int i,int j,vector<vector<bool>>& vis){
        if(i < 0 || j < 0 || j >= n || i >= m || grid[i][j] == 0 || vis[i][j]){
            return;
        }
        vis[i][j] = true;
        dfs(grid,i + 1,j,vis);
        dfs(grid,i - 1, j, vis);
        dfs(grid, i, j+1,vis);
        dfs(grid, i, j-1,vis);
    }

    int numberOfIslands(vector<vector<int>> &grid){
        int islands = 0;
        vector<vector<bool>> vis(m,vector<bool>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    islands++;
                    dfs(grid, i, j, vis);
                }
            }
        }
        return islands;
    }
    int minDays(vector<vector<int>>& grid) {
        m =  grid.size();
        n = grid[0].size();
        int islands = numberOfIslands(grid);
        if(islands > 1 || islands == 0){
            return  0;
        } 
        else{
            for(int i=0; i<m;i++){
                for(int j = 0;j<n;j++){
                    if(grid[i][j] == 1){
                        grid[i][j] = 0;
                        islands = numberOfIslands(grid);
                        if(islands > 1 || islands == 0){
                            return 1;
                        }
                        grid[i][j] = 1;
                    }
                }
            }
        }
        return 2;
    }
};