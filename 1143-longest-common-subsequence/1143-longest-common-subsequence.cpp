class Solution {
public:
    vector<vector<int>> dp;

    int solve(string& s1, string& s2, int i, int j) {
        if (i >= s1.length() || j >= s2.length())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j])
            return dp[i][j] = 1 + solve(s1, s2, i + 1, j + 1);

        return dp[i][j] = max(solve(s1, s2, i, j + 1),solve(s1, s2, i + 1, j));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();

        dp.assign(m, vector<int>(n, -1));

        return solve(text1, text2, 0, 0);
    }
};