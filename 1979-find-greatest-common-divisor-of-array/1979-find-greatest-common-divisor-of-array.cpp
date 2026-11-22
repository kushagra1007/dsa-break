    class Solution {
    public:
        int gcd(int a, int b) {
            while(b != 0){
                int temp = b;
                b = a % b;
                a = temp;
            }
            return a;
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