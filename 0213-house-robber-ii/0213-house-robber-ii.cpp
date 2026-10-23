class Solution {
public:
    int solve(vector<int>& nums, int start, int end) {
        int n = nums.size();
        vector<int> dp(n, 0);

        dp[start] = nums[start];

        for (int i = start + 1; i <= end; i++) {
            int rob = nums[i];

            if (i - 2 >= start) {
                rob += dp[i - 2];
            }

            int skip = dp[i - 1];

            dp[i] = max(rob, skip);
        }

        return dp[end];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        return max(solve(nums, 0, n - 2), solve(nums, 1, n - 1));
    }
};