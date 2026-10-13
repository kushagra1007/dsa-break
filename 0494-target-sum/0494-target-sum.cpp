class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int S = 0;

        for (int i = 0; i < nums.size(); i++) {
            S += nums[i];
        }

        if (abs(target) > S) return 0;

        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(2 * S + 1, 0));

        dp[0][S] = 1;

        for (int i = 0; i < n; i++) {
            for (int currSum = -S; currSum <= S; currSum++) {
                if (dp[i][currSum + S] != 0) {
                    dp[i + 1][currSum + nums[i] + S] += dp[i][currSum + S];
                    dp[i + 1][currSum - nums[i] + S] += dp[i][currSum + S];
                }
            }
        }

        return dp[n][target + S];
    }
};