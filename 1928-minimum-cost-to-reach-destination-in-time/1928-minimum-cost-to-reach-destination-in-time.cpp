class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<vector<pair<int,int>>>graph(n);
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int time = e[2];

            graph[u].push_back({v,time});
            graph[v].push_back({u,time});
        }
        vector<vector<int>> dist(n,vector<int> (maxTime + 1,INT_MAX));

        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        dist[0][0] = passingFees[0];
        pq.push({passingFees[0],0,0});

        while(!pq.empty()){
            auto[cost,time,node] = pq.top();
            pq.pop();
            if(cost > dist[node][time]){
                continue;
            }
            if(node == n-1){
                return cost;
            }

            for(auto &[next,travelTime] : graph[node]){
                int newTime = time + travelTime;

                if(newTime >maxTime){
                    continue;
                }
                int newCost = cost + passingFees[next];
                if(newCost < dist[next][newTime]){
                    dist[next][newTime] = newCost;

                    pq.push({newCost,newTime,next});
                }
            }
        }
        return -1;
    }
};