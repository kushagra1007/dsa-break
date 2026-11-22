class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini=nums[0];
        int maxi=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]>maxi){ 
                maxi=nums[i];
            }
            if(nums[i]<mini) {
                mini=nums[i];
            }
        }
        if(mini==maxi){
            return mini;
        }
        int ans=1;
        for(int i=2;i<=min(maxi,mini);i++)
            if(maxi%i==0 && mini%i ==0){
                ans=i;
            }
        return ans; 
    }
};