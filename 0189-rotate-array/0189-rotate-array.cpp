class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int a = k % nums.size();
        ::rotate(nums.begin(),nums.end()-a,nums.end());
    }
};