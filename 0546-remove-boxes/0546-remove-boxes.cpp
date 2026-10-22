class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n + 1, 0)));
        for (int l = n - 1; l >= 0; l--) {
            for (int r = l; r < n; r++) {
                for (int k = 0; k < n; k++) {
                    int ans = (k + 1) * (k + 1);
                    if (l < r)
                        ans += dp[l][r - 1][0];

                    for (int i = l; i < r; i++) {
                        if (boxes[i] == boxes[r]) {
                            int left = dp[l][i][k + 1];
                            int mid = (i + 1 <= r - 1)? dp[i + 1][r - 1][0] : 0;
                            ans = max(ans, left + mid);
                        }
                    }
                    dp[l][r][k] = ans;
                }
            }
        }

        return dp[0][n - 1][0];
    }
};