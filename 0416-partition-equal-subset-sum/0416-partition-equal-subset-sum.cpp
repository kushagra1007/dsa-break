class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int N = nums.size();
        int total = 0;

        for (int i = 0; i < N; i++) {
            total += nums[i];
        }

        if (total % 2 != 0) return false;

        int target = total / 2;

        vector<vector<int>> dp(N + 1, vector<int>(target + 1, 0));

        for (int i = 0; i <= N; i++) {
            dp[i][0] = 1;
        }

        for (int index = N - 1; index >= 0; index--) {
            for (int target = 0; target <= total / 2; target++) {
                bool incl = 0;

                if (target - nums[index] >= 0) {
                    incl = dp[index + 1][target - nums[index]];
                }

                bool excl = dp[index + 1][target];

                dp[index][target] = incl || excl;
            }
        }

        return dp[0][total / 2];
    }
};