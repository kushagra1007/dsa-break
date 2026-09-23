class Solution {
public:

    bool dfs(int src, int par, vector<vector<int>>& graph, vector<int>& vis) {
        vis[src] = true;

        for (int v : graph[src]) {

            if (vis[v]) {
                if (v != par)
                    return true;
            }
            else {
                if (dfs(v, src, graph, vis))
                    return true;
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
            if (dfs(u, -1, graph, vis))
                return edge;
        }

        return {};
    }
};