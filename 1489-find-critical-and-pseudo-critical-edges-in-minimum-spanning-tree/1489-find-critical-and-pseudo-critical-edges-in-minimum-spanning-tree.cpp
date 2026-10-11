
class Solution {
public:

    vector<int> parent;

    int find(int x){
        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int a,int b){
        a = find(a);
        b = find(b);

        if(a == b)
            return;

        parent[b] = a;
    }

    int kruskal(vector<vector<int>> &vec,int n,int skip_edge,int add_edge){

        parent.resize(n);

        for(int i = 0;i<n;i++){
            parent[i] = i;
        }

        int sum = 0;
        int count = 0;

        if(add_edge != -1){

            Union(vec[add_edge][0],vec[add_edge][1]);

            sum += vec[add_edge][2];
            count++;
        }

        for(int i = 0;i<vec.size();i++){

            if(i == skip_edge)
                continue;

            int u = vec[i][0];
            int v = vec[i][1];
            int wt = vec[i][2];

            int parent_u = find(u);
            int parent_v = find(v);

            if(parent_u != parent_v){

                Union(u,v);

                sum += wt;
                count++;
            }
        }

        if(count != n-1)
            return INT_MAX;

        return sum;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(
        int n, vector<vector<int>>& edges) {

        for(int i = 0;i<edges.size();i++){
            edges[i].push_back(i);
        }

        auto lambda = [](vector<int>& vec1,vector<int>& vec2){
            return vec1[2] < vec2[2];
        };

        sort(begin(edges),end(edges),lambda);

        int MST_WEIGHT = kruskal(edges,n,-1,-1);

        vector<int> critical;
        vector<int> pseudo_critical;

        for(int i = 0;i<edges.size();i++){

            if(kruskal(edges,n,i,-1) > MST_WEIGHT){

                critical.push_back(edges[i][3]);

            }
            else if(kruskal(edges,n,-1,i) == MST_WEIGHT){

                pseudo_critical.push_back(edges[i][3]);
            }
        }

        return {critical,pseudo_critical};
    }
};