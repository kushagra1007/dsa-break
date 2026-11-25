class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            rotate(nums.begin(), nums.begin() + 1, nums.end());
            if(is_sorted(nums.begin(), nums.end())){
                return true;
            }
        }
        return false;
    }
};