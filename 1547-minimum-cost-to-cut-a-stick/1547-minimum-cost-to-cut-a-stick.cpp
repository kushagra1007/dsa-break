class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int l = cuts.size();

        cuts.push_back(0);
        cuts.push_back(n);

        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(l + 2, vector<int>(l + 2, 0));

        for (int i = l; i >= 1; i--) {
            for (int j = i; j <= l; j++) {
                int mini = INT_MAX;

                for (int k = i; k <= j; k++) {
                    int cost = cuts[j + 1] - cuts[i - 1]+ dp[i][k - 1]+ dp[k + 1][j];

                    mini = min(mini, cost);
                }

                dp[i][j] = mini;
            }
        }

        return dp[1][l];
    }
};