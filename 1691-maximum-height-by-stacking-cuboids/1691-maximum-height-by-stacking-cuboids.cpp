class Solution {
public: 
    int solve(vector<vector<int>>& cuboids, int curr, int prev, vector<vector<int>>& dp){
        if(curr == cuboids.size())
            return 0;

        if (dp[curr][prev + 1] != -1)
            return dp[curr][prev + 1];
        
        int include = 0;

        if(prev == -1 || (cuboids[curr][0] >= cuboids[prev][0] && cuboids[curr][1] >= cuboids[prev][1] && cuboids[curr][2] >= cuboids[prev][2])){
            include = cuboids[curr][2] + solve(cuboids, curr + 1, curr,dp);
        }

        int exclude = solve(cuboids, curr + 1, prev,dp);

        return dp[curr][prev+1] = max(include, exclude);
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto& c: cuboids)
            sort(c.begin(), c.end());
        
        sort(cuboids.begin(), cuboids.end());

        int n = cuboids.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));

        return solve(cuboids, 0, -1,dp);
    }
};