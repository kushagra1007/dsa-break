class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n,0);
        int minPrice = prices[0];
        for(int i = 1; i<n;i++){
            dp[i] = max(dp[i-1],prices[i]-minPrice);
            minPrice = min(minPrice,prices[i]);
        }
        return dp[n-1];
    }
};