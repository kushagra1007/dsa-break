class Solution {
public:
    int dp[205][10005];

    bool solve(vector<int>& nums, int i, int target) {
        if (target == 0) return true;
        if (i >= nums.size() || target < 0) return false;

        if (dp[i][target] != -1) return dp[i][target];

        bool take = solve(nums, i + 1, target - nums[i]);
        bool skip = solve(nums, i + 1, target);

        return dp[i][target] = (take || skip);
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;

        for (int x : nums) sum += x;

        if (sum % 2 != 0) return false;

        memset(dp, -1, sizeof(dp));

        return solve(nums, 0, sum / 2);
    }
};