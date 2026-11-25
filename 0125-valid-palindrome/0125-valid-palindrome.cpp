class Solution {
public:
    bool solve(string &s, int i, int j) {
        
        if (i >= j)
            return true;

        if (!isalnum(s[i]))
            return solve(s, i + 1, j);

        if (!isalnum(s[j]))
            return solve(s, i, j - 1);

        if (tolower(s[i]) != tolower(s[j]))
            return false;

        return solve(s, i + 1, j - 1);
    }

    bool isPalindrome(string s) {
        return solve(s, 0, s.size() - 1);
    }
};