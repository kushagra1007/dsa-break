class Solution {
  public:
    void reverse(vector<int> &arr, int start, int end) {

            if (start >= end)
                return;
            swap(arr[start], arr[end]);
            reverse(arr, start + 1, end - 1);
        }
    void reverseArray(vector<int> &arr) {
        // code here
        reverse(arr, 0, arr.size() - 1);
    }
};