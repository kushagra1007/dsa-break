class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        vector<int> ans(n, 0);
        int j = 0;
        for(int i = n-k; i<n; i++){
            ans[j] = nums[i];
            j++;
        }
        for(int i = 0; i < n-k; i++){
            ans[j] = nums[i];
            j++;
        }
        for(int i = 0; i < n; i++){
            nums[i] = ans[i];
        }
    }
};