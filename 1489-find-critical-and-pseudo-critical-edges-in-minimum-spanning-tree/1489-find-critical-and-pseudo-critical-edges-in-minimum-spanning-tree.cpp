class Solution {
public:

    vector<int> parent;

    int find(int x){
        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    bool Union(int a,int b){
        a = find(a);
        b = find(b);

        if(a == b)
            return false;

        parent[b] = a;
        return true;
    }

    int kruskal(vector<vector<int>>& edges,int n,int skip,int add){

        parent.resize(n);

        for(int i = 0;i<n;i++)
            parent[i] = i;

        int sum = 0;
        int count = 0;

        if(add != -1){

            Union(edges[add][0],edges[add][1]);

            sum += edges[add][2];
            count++;
        }

        for(int i = 0;i<edges.size();i++){

            if(i == skip)
                continue;

            if(Union(edges[i][0],edges[i][1])){

                sum += edges[i][2];
                count++;

                if(count == n-1)
                    break;
            }
        }

        if(count != n-1)
            return INT_MAX;

        return sum;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(
        int n, vector<vector<int>>& edges) {

        for(int i = 0;i<edges.size();i++)
            edges[i].push_back(i);

        sort(edges.begin(),edges.end(),
            [](vector<int>& a,vector<int>& b){
                return a[2] < b[2];
            });

        int mst = kruskal(edges,n,-1,-1);

        vector<int> critical;
        vector<int> pseudo;

        for(int i = 0;i<edges.size();i++){

            if(kruskal(edges,n,i,-1) > mst){

                critical.push_back(edges[i][3]);

            }
            else if(kruskal(edges,n,-1,i) == mst){

                pseudo.push_back(edges[i][3]);
            }
        }

        return {critical,pseudo};
    }
};
