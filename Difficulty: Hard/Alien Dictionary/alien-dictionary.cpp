class Solution {
public:
    string findOrder(vector<string> &words) {
        int n = words.size();

        vector<vector<int>> adj(26);
        vector<bool> present(26, false);

        for (string word : words) {
            for (char ch : word) {
                present[ch - 'a'] = true;
            }
        }

        for (int i = 0; i < n - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];

            int len = min(s1.size(), s2.size());
            int j = 0;

            while (j < len && s1[j] == s2[j]) {
                j++;
            }

            if (j == len) {
                if (s1.size() > s2.size()) {
                    return "";
                }
            }
            else {
                int u = s1[j] - 'a';
                int v = s2[j] - 'a';

                adj[u].push_back(v);
            }
        }

        vector<int> indegree(26, 0);

        for (int i = 0; i < 26; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < 26; i++) {
            if (present[i] && indegree[i] == 0) {
                q.push(i);
            }
        }

        string ans = "";

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans += char(node + 'a');

            for (auto it : adj[node]) {
                indegree[it]--;

                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        int count = 0;

        for (int i = 0; i < 26; i++) {
            if (present[i]) {
                count++;
            }
        }

        if (ans.size() != count) {
            return "";
        }

        return ans;
    }
};