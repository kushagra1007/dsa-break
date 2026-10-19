class Solution {
public:
    vector<vector<string>> ans;
    vector<string> path;
    vector<vector<bool>> dp;

    void solve(string &s, int index) {
        if (index == s.size()) {
            ans.push_back(path);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (dp[index][i]) {
                path.push_back(s.substr(index, i - index + 1));

                solve(s, i + 1);

                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        dp.assign(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 2)
                        dp[i][j] = true;
                    else
                        dp[i][j] = dp[i + 1][j - 1];
                }
            }
        }

        solve(s, 0);

        return ans;
    }
};