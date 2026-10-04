class Solution {
  public:
    void dfs(int u,int par,vector<vector<int>>& adj,vector<int>& vis,vector<int>& dt,vector<int>& low,vector<int>& isAP,int& timer){
        vis[u] = 1;
        dt[u] = low[u] = ++timer;
        int children = 0;
        for(int v : adj[u]){
            if(!vis[v]){
                children ++;
                dfs(v,u,adj, vis, dt, low, isAP, timer);
                low[u] = min(low[u],low[v]);
                if(par != -1 && low[v] >= dt[u]){
                    isAP[u] = 1;
                }
            }
            else{
                low[u] = min(low[u],dt[v]);
            }
        }
        if(par == -1 && children > 1){
            isAP[u] = 1;
        }}
    vector<int> articulationPoints(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n,0);
        vector<int> dt(n);
        vector<int> low(n);
        vector<int> isAp(n,0);
        int timer = 0;
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                dfs(i,-1,adj,vis,dt,low,isAp,timer);
            }
        }
        vector<int> ans;
        for(int i = 0; i< n;i++){
            if(isAp[i]){
                ans.push_back(i);
            }
        }
        if(ans.empty()){
            return {-1};    
        }
        return ans;
    }
};