class Solution {
public:
    int solve(int i, vector<int>& startTime, vector<int>& endTime,
              vector<int>& profit, vector<int>& dp, int n) {

        if (i >= n) return 0;

        if (dp[i] != -1) return dp[i];
        int skip = solve(i + 1, startTime, endTime, profit, dp, n);

        int low = i + 1;
        int high = n;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (startTime[mid] >= endTime[i]) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        int j = low;
        int take = profit[i] + solve(j, startTime, endTime, profit, dp, n);

        return dp[i] = max(take, skip);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

        int n = startTime.size();

        vector<array<int, 3>> jobs;

        for (int i = 0; i < n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end());

        for (int i = 0; i < n; i++) {
            startTime[i] = jobs[i][0];
            endTime[i] = jobs[i][1];
            profit[i] = jobs[i][2];
        }
        vector<int> dp(n, -1);
        return solve(0, startTime, endTime, profit, dp, n);
    }
};