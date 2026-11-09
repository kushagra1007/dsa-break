class Solution {
public:
    int minimumDifference(vector<int>& nums) {

        int n = nums.size() / 2;

        vector<vector<long long>> left(n + 1), right(n + 1);

        for(int mask = 0; mask < (1 << n); mask++) {

            long long sum1 = 0, sum2 = 0;
            int cnt = 0;

            for(int i = 0; i < n; i++) {

                if(mask & (1 << i)) {
                    sum1 += nums[i];
                    sum2 += nums[i + n];
                    cnt++;
                }
            }

            left[cnt].push_back(sum1);
            right[cnt].push_back(sum2);
        }

        for(int i = 0; i <= n; i++) {
            sort(right[i].begin(), right[i].end());
        }

        long long totalSum = 0;

        for(int x : nums) {
            totalSum += x;
        }

        long long ans = LLONG_MAX;

        for(int i = 0; i <= n; i++) {

            for(long long x : left[i]) {

                long long target = totalSum / 2 - x;

                auto it = lower_bound(
                    right[n - i].begin(),
                    right[n - i].end(),
                    target
                );

                if(it != right[n - i].end()) {

                    long long sum1 = x + *it;
                    long long sum2 = totalSum - sum1;

                    ans = min(ans, abs(sum1 - sum2));
                }

                if(it != right[n - i].begin()) {

                    it--;

                    long long sum1 = x + *it;
                    long long sum2 = totalSum - sum1;

                    ans = min(ans, abs(sum1 - sum2));
                }
            }
        }

        return ans;
    }
};