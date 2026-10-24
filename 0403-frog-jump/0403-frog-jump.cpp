class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(vector<int>& stones, int curr_stone_idx, int prevJump) {
        if (curr_stone_idx == n - 1) {
            return true;
        }

        if (dp[curr_stone_idx][prevJump] != -1) {
            return dp[curr_stone_idx][prevJump];
        }

        bool result = false;

        for (int nextJump = prevJump - 1; nextJump <= prevJump + 1; nextJump++) {
            if (nextJump > 0) {
                int next_stone = stones[curr_stone_idx] + nextJump;

                for (int i = curr_stone_idx + 1; i < n; i++) {
                    if (stones[i] == next_stone) {
                        result = result || solve(stones, i, nextJump);
                        break;
                    }
                }
            }
        }

        return dp[curr_stone_idx][prevJump] = result;
    }

    bool canCross(vector<int>& stones) {
        n = stones.size();

        if (n < 2 || stones[1] != 1) {
            return false;
        }

        dp.assign(n, vector<int>(n + 1, -1));

        return solve(stones, 0, 0);
    }
};