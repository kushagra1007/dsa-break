class Solution {
public:

    int find(int x, vector<int>& parent) {
        if (parent[x] == x){
            return x;
        }
        return parent[x] = find(parent[x], parent);
    }

    void Union(int a, int b, vector<int>& parent) {
        a = find(a, parent);
        b = find(b, parent);

        if (a != b){
            parent[b] = a;
        }
    }

    int removeStones(vector<vector<int>>& stones) {

        int n = stones.size();
        vector<int> parent(n);

        for (int i = 0; i < n; i++){
            parent[i] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                if (stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1]) {
                    Union(i, j, parent);
                }
            }
        }
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (find(i, parent) == i){
                components++;
            }
        }
        return n - components;
    }
};