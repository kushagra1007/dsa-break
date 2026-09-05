class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int a = nums1.size();
        int b = nums2.size();
        int total = a + b;

        int i = 0, j = 0;
        int prev = 0, curr = 0;

        for(int count = 0; count <= total / 2; count++) {

            prev = curr;

            if(i < a && j < b) {
                if(nums1[i] <= nums2[j]) {
                    curr = nums1[i];
                    i++;
                }
                else {
                    curr = nums2[j];
                    j++;
                }
            }
            else if(i < a) {
                curr = nums1[i];
                i++;
            }
            else {
                curr = nums2[j];
                j++;
            }
        }

        if(total % 2 == 1)
            return curr;

        return (prev + curr) / 2.0;
    }
};