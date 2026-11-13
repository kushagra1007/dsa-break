class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        for(int i = 0; i < n; i++){
            pq.push({matrix[i][0], i, 0});
        }
        while(k > 1){
            auto top = pq.top();
            pq.pop();

            int row = top[1];
            int col = top[2];

            if(col + 1 < n){
                pq.push({matrix[row][col+1], row, col + 1});
            }
            k--;
        }
        return pq.top()[0];
    }
};