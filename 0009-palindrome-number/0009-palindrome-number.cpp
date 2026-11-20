class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0){
            return false;
        }
        long long Num = 0;
        int z = x;
        while (x> 0) {
            int a = x%10;
            x = x/10;
            Num = Num*10 + a;
        }
        if (Num == z) {
            return true;
        }
        else 
            return false;
    }
};