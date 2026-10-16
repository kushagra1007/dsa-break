class Solution {
public:
    int dp[1001][1001];
    int solve(vector<int> &nums1, vector<int> &nums2,int i, int j){
        if(i == 0 || j == 0)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(nums1[i-1] == nums2[j-1])
            dp[i][j] = 1 + solve(nums1, nums2, i-1, j-1);

        else
            dp[i][j] = 0;

        return dp[i][j];
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, -1, sizeof(dp));

        int ans = 0;
        for(int i = 1 ; i <= nums1.size(); i++){
            for(int j = 1 ; j <= nums2.size(); j++){
                ans = max(ans,solve(nums1, nums2, i, j));
            }
        }
        return ans;
    }
};