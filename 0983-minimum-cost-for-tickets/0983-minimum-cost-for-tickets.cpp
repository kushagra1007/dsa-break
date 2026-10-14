class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> t(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int j = i;
            while (j < n && days[j] < days[i] + 7) j++;
            int cost7 = costs[1] + t[j];

            j = i;
            while (j < n && days[j] < days[i] + 30) j++;
            int cost30 = costs[2] + t[j];

            int cost1 = costs[0] + t[i + 1];

            t[i] = min({cost1, cost7, cost30});
        }

        return t[0];
    }
};