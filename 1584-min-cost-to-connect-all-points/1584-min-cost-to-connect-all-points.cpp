class Solution {
public:

    vector<int> parent;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b){
            return false;
        }
        parent[b] = a;
        return true;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        parent.resize(n);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        vector<vector<int>> edges;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int cost = abs(points[i][0] - points[j][0])+ abs(points[i][1] - points[j][1]);
                edges.push_back({cost, i, j});
            }
        }

        sort(edges.begin(), edges.end());

        int ans = 0;
        int count = 0;

        for (auto edge : edges) {

            int cost = edge[0];
            int u = edge[1];
            int v = edge[2];

            if (unite(u, v)) {
                ans += cost;
                count++;
            }
            if (count == n - 1){
                break;
            }
        }
        return ans;
    }
};