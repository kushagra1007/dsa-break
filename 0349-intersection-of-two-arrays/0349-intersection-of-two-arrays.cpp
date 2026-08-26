class Solution {
public:
    vector<int> intersection(vector<int>& num1, vector<int>& num2) {
        unordered_set<int> st1(begin(num1),end(num1));
        unordered_set<int>st2;

        for(int &num : num2){
            if(st1.find(num) != st1.end()){
                st2.insert(num);
            }
        }
        vector<int> result(begin(st2),end(st2));
        return result;
    }
};