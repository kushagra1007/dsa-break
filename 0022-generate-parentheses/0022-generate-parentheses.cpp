class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<vector<string>>> dp(n + 1, vector<vector<string>>(n + 1));
        dp[n][n] = {""};

        for (int open = n; open >= 0; open--) {
            for (int close = open; close >= 0; close--) {
                if (open == n && close == n)
                    continue;   
                vector<string> ans;
                if (open < n) {
                    for (string s : dp[open + 1][close]) {
                        ans.push_back("(" + s);
                    }
                }
                if (close < open) {
                    for (string s : dp[open][close + 1]) {
                        ans.push_back(")" + s);
                    }
                }
                dp[open][close] = ans;
            }
        }
        return dp[0][0];
    }
};