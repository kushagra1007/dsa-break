class Solution {
public:
    vector<vector<string>> ans;
    vector<string> path;
    vector<vector<int>> dp;

    bool isPalindrome(string &s, int i, int j) {
        if (i >= j)
            return true;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] != s[j])
            return dp[i][j] = 0;

        return dp[i][j] = isPalindrome(s, i + 1, j - 1);
    }

    void solve(string &s, int index) {
        if (index == s.size()) {
            ans.push_back(path);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));

                solve(s, i + 1);

                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        dp.assign(n, vector<int>(n, -1));

        solve(s, 0);

        return ans;
    }
};