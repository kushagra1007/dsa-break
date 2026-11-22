    class Solution {
    public:
        int gcd(int a, int b) {
        int ans = 1;

        for (int i = 1; i <= min(a, b); i++) {
            if (a % i == 0 && b % i == 0) {
                ans = i;
            }
        }

        return ans;
    }
        int findGCD(vector<int>& nums) {
            int mini = INT_MAX;
            int maxi = INT_MIN;
            for(int i = 0; i < nums.size(); i++){
                mini = min(nums[i], mini);
                maxi = max(nums[i], maxi);
            }
            return gcd(mini, maxi);
        }
    };