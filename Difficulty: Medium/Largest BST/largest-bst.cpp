/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {

    class Info {
    public:
        int mn;
        int mx;
        int sz;

        Info(int mi, int ma, int size) {
            mn = mi;
            mx = ma;
            sz = size;
        }
    };

    Info helper(Node* root) {
        if (root == NULL) {
            return Info(INT_MAX, INT_MIN, 0);
        }
        Info left = helper(root->left);
        Info right = helper(root->right);
        if (root->data > left.mx && root->data < right.mn) {

            int currMin = min(root->data, left.mn);
            int currMax = max(root->data, right.mx);
            int currSize = left.sz + right.sz + 1;

            return Info(currMin, currMax, currSize);
        }
        return Info(INT_MIN, INT_MAX, max(left.sz, right.sz));
    }

public:
    int largestBst(Node *root) {

        Info info = helper(root);

        return info.sz;
    }
};