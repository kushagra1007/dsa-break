class Solution {
public:
    vector<int> parent;

    int find(int x){
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    bool Union(int x,int y){
        int px = find(x);
        int py = find(y);

        if(px == py)
            return false;

        parent[py] = px;
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        parent.resize(n);

        for(int i = 0; i<n ; i++){
            parent[i] = i;
        }

        for(int u = 0; u<n ; u++){
            if(graph[u].empty())
                continue;

            int first = graph[u][0];

            for(int v : graph[u]){
                if(find(u) == find(v))
                    return false;

                Union(first,v);
            }
        }

        return true;
    }
};