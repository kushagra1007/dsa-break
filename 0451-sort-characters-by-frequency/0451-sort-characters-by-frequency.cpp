class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();

        unordered_map<char, int> mp;

        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
        }
        vector<vector<char>> bucket(n + 1);
        for (auto it : mp) {
            bucket[it.second].push_back(it.first);
        }

        string result = "";
        for (int i = n; i >= 1; i--) {
            for (char ch : bucket[i]) {
                result += string(i, ch);
            }
        }

        return result;
    }
};