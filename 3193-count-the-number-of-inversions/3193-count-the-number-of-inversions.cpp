class Solution {
public:
        const int MOD= 1e9+7;
        int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        vector<int>req(n,-1);
        int maxInv=0;
        for(auto r: requirements){
            req[r[0]]=r[1];
            maxInv=max(maxInv,r[1]);
        }
        vector<int>prev(maxInv+1,0);
        prev[0]=1;
        if(req[0]!=-1){
            for(int inv=0;inv<=maxInv;inv++){
                if(inv!=req[0])
                prev[inv]=0;
            }
        }
        for(int i=1;i<n;i++){
            vector<int>curr(maxInv+1,0);
            long long sum=0;
            for(int inv=0;inv<=maxInv;inv++){
                sum=sum+prev[inv];
                if(inv-i-1>=0){
                    sum=sum-prev[inv-i-1];
                }
                sum=(sum+MOD)%MOD;
                curr[inv]=sum;
            }
            if(req[i] != -1) {
                for(int inv = 0; inv <= maxInv; inv++) {
                    if(inv != req[i]){
                        curr[inv] = 0;
                    }
                }
            }
            prev=curr;
        }
  
        return prev[req[n-1]];
    }
};