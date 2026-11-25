class Solution {
  public:
    int solve(vector<int> &arr, int n, int i){
        if(i == n - 1){
            return arr[i];
        }
        return arr[i] + solve(arr, n, i + 1);
        
    }
    int arraySum(vector<int>& arr) {
        // code here
        int n = arr.size();
        return solve(arr,n,0);
    }
};