class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;

        for (int x : nums) sum += x;

        if (sum % 2 != 0) return false;

        int target = sum / 2;
        int n = nums.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= target; j++) {
                bool skip = dp[i + 1][j];
                bool take = false;

                if (j >= nums[i]) {
                    take = dp[i + 1][j - nums[i]];
                }

                dp[i][j] = take || skip;
            }
        }

        return dp[0][target];
    }
};