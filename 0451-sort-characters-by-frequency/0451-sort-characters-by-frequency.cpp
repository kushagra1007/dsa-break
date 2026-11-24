class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mpp;
        priority_queue<pair<int , char>>p;
        string ans;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        for(auto it : mpp){
            p.push({it.second , it.first});
        }
        while(!p.empty()){
            for(int i=0;i<p.top().first;i++){
                ans.push_back(p.top().second);
            }
            p.pop();
        }
        return ans;
    }
};