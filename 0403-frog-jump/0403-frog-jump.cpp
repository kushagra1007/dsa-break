class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();

        if (n < 2 || stones[1] != 1)
            return false;

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[stones[i]] = i;
        }

        vector<vector<bool>> dp(n, vector<bool>(n + 1, false));

        dp[0][0] = true;

        for (int i = 0; i < n; i++) {
            for (int prevJump = 0; prevJump <= n; prevJump++) {
                if (dp[i][prevJump]) {
                    for (int nextJump = max(1, prevJump - 1); nextJump <= prevJump + 1; nextJump++) {
                        int nextStone = stones[i] + nextJump;

                        if (mp.find(nextStone) != mp.end()) {
                            int nextIdx = mp[nextStone];
                            dp[nextIdx][nextJump] = true;
                        }
                    }
                }
            }
        }

        for (int jump = 0; jump <= n; jump++) {
            if (dp[n - 1][jump])
                return true;
        }

        return false;
    }
};