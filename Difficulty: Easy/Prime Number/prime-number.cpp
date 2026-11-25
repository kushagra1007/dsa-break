class Solution {
  public:
    bool solve(int n, int i){
        if(n <= 1)
            return false;
            
        if(i > n/i){
            return true;
        }
        if(n % i == 0){
            return false;
        }
        solve(n, i + 1);
    }
    bool isPrime(int n) {
        // code here
        return solve(n, 2);
    }
};
