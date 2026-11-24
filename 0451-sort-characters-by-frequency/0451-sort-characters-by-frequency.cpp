class Solution {
public:
    string frequencySort(string s) {
        int n=s.length();

        multiset<pair<int,char>,greater<pair<int,char>>>ms;
        string result;

        unordered_map<char,int>mp;

        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }

        for(auto it:mp){
            ms.insert({it.second,it.first});
        }

        for(auto i:ms){
            result+=string(i.first,i.second);
        }
        return result;
    }
};