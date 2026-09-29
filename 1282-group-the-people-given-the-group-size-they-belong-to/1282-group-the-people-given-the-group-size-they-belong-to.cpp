class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        
        vector<pair<int, int>> people;
        vector<vector<int>> ans;
        
        for (int i = 0; i < groupSizes.size(); i++) {
            people.push_back({groupSizes[i], i});
        }
        sort(people.begin(), people.end());
        
        vector<int> group;
        
        for (auto p : people) {
            
            int size = p.first;
            int index = p.second;
            
            group.push_back(index);
            
            if (group.size() == size) {
                ans.push_back(group);
                group.clear();
            }
        }
        return ans;
    }
};