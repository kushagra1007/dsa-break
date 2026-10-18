class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for (auto& c : cuboids)
            sort(c.begin(), c.end());

        sort(cuboids.begin(), cuboids.end());

        int n = cuboids.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int curr = n - 1; curr >= 0; curr--) {
            for (int prev = curr - 1; prev >= -1; prev--) {
                int include = 0;

                if (prev == -1 ||
                    (cuboids[curr][0] >= cuboids[prev][0] &&
                     cuboids[curr][1] >= cuboids[prev][1] &&
                     cuboids[curr][2] >= cuboids[prev][2])) {
                    include = cuboids[curr][2] + dp[curr + 1][curr + 1];
                }

                int exclude = dp[curr + 1][prev + 1];

                dp[curr][prev + 1] = max(include, exclude);
            }
        }

        return dp[0][0];
    }
};