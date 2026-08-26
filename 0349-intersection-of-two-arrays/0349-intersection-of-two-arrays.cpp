class Solution {
public:
    vector<int> intersection(vector<int>& num1, vector<int>& num2) {
        unordered_set<int> st1(begin(num1),end(num1));
        vector<int> result;

        for(int &num : num2){
            if(st1.find(num) != st1.end()){
                result.push_back(num);
                st1.erase(num);
            }

        }
        
        return result;
    }
};