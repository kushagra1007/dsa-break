class KthLargest {
public:
    int K;
    multiset<int> st;

    KthLargest(int k, vector<int>& nums) {
        K = k;

        for (int num : nums) {
            st.insert(num);

            if (st.size() > K) {
                st.erase(st.begin());  // remove smallest
            }
        }
    }

    int add(int val) {
        st.insert(val);

        if (st.size() > K) {
            st.erase(st.begin());
        }

        return *st.begin();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */