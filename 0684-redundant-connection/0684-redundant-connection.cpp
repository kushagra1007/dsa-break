class Solution {
public:

    bool bfs(int src, vector<vector<int>>& graph, vector<int>& vis) {

        queue<pair<int, int>> q;

        q.push({src, -1});
        vis[src] = true;

        while (!q.empty()) {

            auto [node, parent] = q.front();
            q.pop();

            for (int neighbour : graph[node]) {

                if (!vis[neighbour]) {
                    q.push({neighbour, node});
                    vis[neighbour] = true;
                }
                else if (neighbour != parent) {
                    return true;
                }
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        vector<vector<int>> graph(n + 1);

        for (auto edge : edges) {

            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);

            vector<int> vis(n + 1, false);
            if (bfs(u, graph, vis))
                return edge;
        }

        return {};
    }
};