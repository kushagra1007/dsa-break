class Solution {
public:
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();

        vector<array<int, 3>> jobs;
        for(int i = 0; i < n; i++){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());

        for(int i = 0; i < n; i++){
            startTime[i] = jobs[i][0];
            endTime[i] = jobs[i][1];
            profit[i] = jobs[i][2];
        }
        vector<int> dp(n + 1, 0);

        for(int i = n -1; i >= 0; i--){
            

            int j = lower_bound(startTime.begin() + i + 1, startTime.end(), endTime[i]) - startTime.begin();

            int take = profit[i] + dp[j];

            int skip = dp[i + 1];

            dp[i] = max(take, skip);
        }
        return dp[0];
    }
};