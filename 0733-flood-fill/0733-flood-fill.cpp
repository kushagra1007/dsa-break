class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int orgColor = image[sr][sc];
        
        if (orgColor == color)
            return image;
        
        int m = image.size();
        int n = image[0].size();
        
        queue<pair<int, int>> q;
        q.push({sr, sc});
        
        image[sr][sc] = color;
        
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        
        while (!q.empty()) {
            
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            for (int k = 0; k < 4; k++) {
                
                int ni = i + dx[k];
                int nj = j + dy[k];
                
                if (ni >= 0 && nj >= 0 && ni < m && nj < n &&
                    image[ni][nj] == orgColor) {
                    
                    image[ni][nj] = color;
                    q.push({ni, nj});
                }
            }
        }
        
        return image;
    }
};