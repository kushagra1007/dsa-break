class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();

        int low = matrix[0][0];
        int high = matrix[n-1][m-1];
        int ans = 0;

        while(low <= high){
            int mid = low + (high - low)/2;
            int count = 0;
            int r = n - 1;
            for(int c = 0; c < m; c++){
                while(r >= 0 && matrix[r][c] > mid){
                    r --;
                }
                count += r + 1;
            }
            if(count >= k){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};