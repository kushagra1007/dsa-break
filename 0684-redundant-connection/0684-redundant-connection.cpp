class Solution {
public:
    bool dfs(int node,int parent,vector<vector<int>> &graph,vector<int> &visited){
        visited[node] = 1;
        for(int neighbour : graph[node]){
            if(neighbour == parent)
                continue;
            if (visited[neighbour])
                return true;
            if (dfs(neighbour, node, graph, visited))
                return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> graph(n+1);
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
            vector<int> visted(n+1,0);

            if(dfs(u,-1,graph,visted))
                return edge;
        }
        return{};
    }
};