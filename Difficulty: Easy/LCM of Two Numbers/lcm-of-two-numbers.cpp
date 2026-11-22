class Solution {
  public:
    int lcm(int a, int b) {
        // code here
        int maxi = max(a, b);
        while(true){
            if(maxi % a == 0 && maxi % b == 0){
                return maxi;
            }
            maxi++;
        }
    }
};