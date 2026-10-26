class Solution {
public:
    vector<string> solve(int n, int open, int close) {
        if (open == n && close == n) {
            return {""};
        }
        vector<string> ans;

        if (open < n) {
            vector<string> temp = solve(n, open + 1, close);
            for (string s : temp) {
                ans.push_back("(" + s);
            }
        }
        if (close < open) {
            vector<string> temp = solve(n, open, close + 1);
            for (string s : temp) {
                ans.push_back(")" + s);
            }
        }
        return ans;
    }
    vector<string> generateParenthesis(int n) {
        return solve(n, 0, 0);
    }
};