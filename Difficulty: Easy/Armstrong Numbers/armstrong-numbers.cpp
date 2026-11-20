class Solution {
  public:
    bool armstrongNumber(int n) {
        int temp = n;
        int sum = 0;
        int digits = 0;

        int t = n;
        while (t > 0) {
            digits++;
            t /= 10;
        }

        while (n > 0) {
            int digit = n % 10;
            sum += pow(digit, digits);
            n /= 10;
        }

        return sum == temp;
    }
};