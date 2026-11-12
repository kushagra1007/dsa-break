class Solution {
public:

    int partition(vector<pair<int,int>>& arr, int low, int high) {

        int pivot = arr[high].second;

        int i = low;

        for(int j = low; j < high; j++) {

            if(arr[j].second >= pivot) {
                swap(arr[i], arr[j]);
                i++;
            }
        }

        swap(arr[i], arr[high]);

        return i;
    }

    void quickSelect(vector<pair<int,int>>& arr, int low, int high, int k) {

        if(low >= high)
            return;

        int p = partition(arr, low, high);

        if(p == k)
            return;

        if(p < k)
            quickSelect(arr, p + 1, high, k);

        else
            quickSelect(arr, low, p - 1, k);
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> mp;

        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        vector<pair<int,int>> arr;

        for(auto it : mp) {
            arr.push_back({it.first, it.second});
        }

        quickSelect(arr, 0, arr.size() - 1, k - 1);

        vector<int> ans;

        for(int i = 0; i < k; i++) {
            ans.push_back(arr[i].first);
        }

        return ans;
    }
};