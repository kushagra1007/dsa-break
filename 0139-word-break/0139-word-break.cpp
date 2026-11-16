class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.length();
        vector<bool> dp(len+1, false);
        dp[0] = true;

        for(int i = 0; i < len; i++){
            for(string word:wordDict){
                string comp = s.substr(i, word.length());
                if(comp == word){
                    dp[i + word.length()] = (dp[i + word.length()]) || (true && dp[i]);
                }
            }
        }

        return dp[len];
    }
};