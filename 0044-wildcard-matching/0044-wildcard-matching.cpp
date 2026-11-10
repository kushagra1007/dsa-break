class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0, star = -1, match = 0;
        int n = s.size(), m = p.size();
        while (i < n) {
            if (j < m && (p[j] == '?' || p[j] == s[i])) {
                i++; j++;
            } else if (j < m && p[j] == '*') {
                star = j;
                match = i;
                j++;
            } else if (star != -1) {
                j = star + 1;
                match++;
                i = match;
            } else {
                return false;
            }
        }
        while (j < m && p[j] == '*') j++;
        return j == m;
    }
};