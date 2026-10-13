class Solution {
public:
    int S;

    int solve(vector<int>& nums, int target, int i, int currSum, vector<vector<int>>& dp) {
        if (i == nums.size()) {
            return currSum == target;
        }

        if (dp[i][currSum + S] != -1) {
            return dp[i][currSum + S];
        }

        int plus = solve(nums, target, i + 1, currSum + nums[i], dp);
        int minus = solve(nums, target, i + 1, currSum - nums[i], dp);

        return dp[i][currSum + S] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        S = accumulate(nums.begin(), nums.end(), 0);

        if (abs(target) > S) return 0;

        vector<vector<int>> dp(nums.size(), vector<int>(2 * S + 1, -1));

        return solve(nums, target, 0, 0, dp);
    }
};