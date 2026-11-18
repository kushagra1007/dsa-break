class Solution {
public:
    void merge(vector<int>& arr, int l, int mid, int r) {
        vector<int> temp;
        int i = l, j = mid + 1;

        while (i <= mid && j <= r) {
            if (arr[i] <= arr[j])
                temp.push_back(arr[i++]);
            else
                temp.push_back(arr[j++]);
        }

        while (i <= mid)
            temp.push_back(arr[i++]);

        while (j <= r)
            temp.push_back(arr[j++]);

        for (int k = l; k <= r; k++)
            arr[k] = temp[k - l];
    }

    void mergeSort(vector<int>& arr, int l, int r) {
        if (l < r) {
            int mid = l + (r - l) / 2;

            mergeSort(arr, l, mid);
            mergeSort(arr, mid + 1, r);

            merge(arr, l, mid, r);
        }
    }

    int findContentChildren(vector<int>& g, vector<int>& s) {
        mergeSort(g, 0, g.size() - 1);
        mergeSort(s, 0, s.size() - 1);

        int i = 0, j = 0, count = 0;

        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                count++;
                i++;
                j++;
            }
            else {
                j++;
            }
        }

        return count;
    }
};