class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {

        int mod = 1e9 + 7;

        vector<int> req(n, -1);

        for(auto it : requirements) {
            req[it[0]] = it[1];
        }
        int maxInv = n * (n - 1) / 2;

        vector<int> dp(maxInv + 1, 0);

        dp[0] = 1;

        for(int len = 0; len < n; len++) {

            vector<int> temp(maxInv + 1, 0);

            int sum = 0;

            for(int j = 0; j <= maxInv; j++) {

                sum = (sum + dp[j]) % mod;

                if(j - len - 1 >= 0) {
                    sum = (sum - dp[j - len - 1] + mod) % mod;
                }

                temp[j] = sum;
            }

            if(req[len] != -1) {
                for(int j = 0; j <= maxInv; j++) {
                    if(j != req[len]) {
                        temp[j] = 0;
                    }
                }
            }

            dp = temp;
        }

        int ans = 0;

        for(int i = 0; i <= maxInv; i++) {
            ans = (ans + dp[i]) % mod;
        }

        return ans;
    }
};