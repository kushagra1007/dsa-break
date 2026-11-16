class Solution {
public:

    bool solve(int idx, string &s, vector<string>& wordDict, vector<int>& dp) {

        if(idx == s.size())
            return true;

        if(dp[idx] != -1)
            return dp[idx];

        for(int i = idx; i < s.size(); i++) {
            string word = s.substr(idx, i - idx + 1);
            if(find(wordDict.begin(), wordDict.end(), word) != wordDict.end()) {
                if(solve(i + 1, s, wordDict, dp))
                    return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        int n = s.size();
        vector<int> dp(n, -1);
        return solve(0, s, wordDict, dp);
    }
};