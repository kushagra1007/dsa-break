class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int i=0;
        long ans=0;

        for(int j=0;j<n;j++){

            long target=nums[j];
            ans+=target;
            
            if((j-i+1)*target-ans>k){
                ans-=nums[i];
                i++;
            }
        }
        return n-i;
    }
};