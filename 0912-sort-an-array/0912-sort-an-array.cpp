class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        int minEle = *min_element(nums.begin(), nums.end());
        int maxEle = *max_element(nums.begin(), nums.end());

        int len = maxEle - minEle + 1;

        vector<int> count(len, 0);
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            count[nums[i] - minEle]++;
        }

        for (int i = 0; i < len; i++) {
            while (count[i] > 0) {
                ans.push_back(i + minEle);
                count[i]--;
            }
        }

        return ans;
    }
};