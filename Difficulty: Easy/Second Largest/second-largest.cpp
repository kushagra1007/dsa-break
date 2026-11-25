class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {

        int largest = -1;
        int second = -1;

        for(int i = 0; i < arr.size(); i++) {

            if(arr[i] > largest) {
                second = largest;
                largest = arr[i];
            }
            else if(arr[i] > second && arr[i] != largest) {
                second = arr[i];
            }
        }

        return second;
    }
};