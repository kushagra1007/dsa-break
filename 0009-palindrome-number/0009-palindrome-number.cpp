class Solution {
public:
    bool isPalindrome(int x) {
        int y = x;
        if(x < 0){
            return false;
        }

        int ans = 0;
        while(x != 0){
            int digit = x % 10;
            x /= 10;

            if(ans > INT_MAX/10 || ans < INT_MIN/10)
                return 0;
                
            ans = ans * 10 + digit;
        }
        if(y == ans) return true;

        return false;
    }
};