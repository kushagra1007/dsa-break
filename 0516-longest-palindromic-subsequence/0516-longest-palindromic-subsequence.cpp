class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string text1 = s;
        string text2 = s;
        reverse(text2.begin(), text2.end());

        int n = text1.size(), m = text2.size();
        vector<int> prev(m+1, 0), curr(m+1, 0);
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(text1[i-1]==text2[j-1]){
                    curr[j] = max(curr[j], 1+prev[j-1]);
                } else {
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }
            swap(prev, curr);
        }

        return prev[m];
    }
};