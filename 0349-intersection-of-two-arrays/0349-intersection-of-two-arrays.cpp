class Solution {
public:
    vector<int> intersection(vector<int>& num1, vector<int>& num2) {
        sort(begin(num1),end(num1)); 
        sort(begin(num2),end(num2));
        
        int i = 0;
        int j = 0;
        int m = num1.size();
        int n = num2.size();
        vector<int> result;
        while(i<m && j<n){
            if(num1[i] == num2[j]){
                result.push_back(num1[i]);

                while(i<m-1 && num1[i] == num1[i+1]){
                    i++;
                }
                while(j<n-1 && num2[j] == num2[j+1]){
                    j++;
                }
                i++;
                j++;
            
            } else if(num1[i]<num2[j]){
                i++;
            }
            else {
                j++;
            }
        }
        return result;
    }
};