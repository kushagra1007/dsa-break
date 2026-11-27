class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int cnt{};
        int maxCnt{};
        for(int i=0;i<n;i++){
            if(nums[i] == 1) cnt++;
            else cnt = 0;
            maxCnt = max(maxCnt, cnt);
        }
        return maxCnt;
    }
};