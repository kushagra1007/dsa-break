class Solution {
public:
    vector<string> solve(int n, int open, int close, vector<vector<vector<string>>>& dp){
        if(open == n && close == n){
            return {""};
        }
        if(!dp[open][close].empty()){
            return dp[open][close];
        }
        vector<string> ans;
        if(open < n){
            vector<string> temp = solve(n, open + 1, close, dp);

            for(string s : temp){
                ans.push_back("("+s);
            }
        }
        if(close < open){
            vector<string> temp = solve(n, open, close+1, dp);

            for(string s : temp){
                ans.push_back(")"+s);
            }
        }   
        return dp[open][close] = ans;
    }

    vector<string> generateParenthesis(int n) {
        vector<vector<vector<string>>> dp(n + 1, vector<vector<string>>(n + 1));
        return solve(n, 0, 0, dp);
    }
};