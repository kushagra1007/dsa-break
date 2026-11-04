class Solution {
public:
int find(int x, vector<int>& parent) {
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent[x], parent);
}

void merge(int a, int b, vector<int>& parent) {
    a = find(a, parent);
    b = find(b, parent);

    if (a != b)
        parent[a] = b;
}

int mst(int n, vector<vector<int>>& edges, int skip, int force) {

    vector<int> parent(n);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    int sum = 0, count = 0;

    if (force != -1) {
        sum += edges[force][2];
        merge(edges[force][0], edges[force][1], parent);
        count++;
    }

    for (int i = 0; i < edges.size(); i++) {

        if (i == skip || i == force)
            continue;

        int u = edges[i][0];
        int v = edges[i][1];

        if (find(u, parent) != find(v, parent)) {
            merge(u, v, parent);
            sum += edges[i][2];
            count++;
        }
    }

    if (count != n - 1)
        return INT_MAX;

    return sum;
}

vector<vector<int>> findCriticalAndPseudoCriticalEdges(
    int n, vector<vector<int>>& edges) {

    for (int i = 0; i < edges.size(); i++)
        edges[i].push_back(i);

    sort(edges.begin(), edges.end(),
         [](vector<int>& a, vector<int>& b) {
             return a[2] < b[2];
         });

    int original = mst(n, edges, -1, -1);

    vector<int> critical, pseudo;

    for (int i = 0; i < edges.size(); i++) {

        if (mst(n, edges, i, -1) > original) {
            critical.push_back(edges[i][3]);
        }

        else if (mst(n, edges, -1, i) == original) {
            pseudo.push_back(edges[i][3]);
        }
    }

    return {critical, pseudo};
}
};
