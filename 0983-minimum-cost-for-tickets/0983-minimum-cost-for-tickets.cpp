class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> st(begin(days), end(days));

        int last_day = days.back();

        vector<int> t(last_day+1,0);
        t[0] = 0;

        for(int i = 1; i <= last_day; i++){
            if(st.find(i) == st.end()){
                t[i] = t[i-1];
                continue;
            }
            t[i] = INT_MAX;

            int day_1_pass = costs[0] + t[max(i-1,0)];

            int day_7_pass = costs[1] + t[max(i-7,0)];

            int day_30_pass = costs[2] + t[max(i-30,0)];

            t[i] = min({day_1_pass,day_7_pass,day_30_pass});
        }
        return t[last_day];
    }
};