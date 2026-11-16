class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for(int i = 0; i < n; i++) {
            if(dp[i] == false)
                continue;

            for(int j = i; j < n; j++) {
                string word = s.substr(i, j - i + 1);
                if(find(wordDict.begin(), wordDict.end(), word) != wordDict.end()) {
                    dp[j + 1] = true;
                }
            }
        }
        return dp[n];
    }
};