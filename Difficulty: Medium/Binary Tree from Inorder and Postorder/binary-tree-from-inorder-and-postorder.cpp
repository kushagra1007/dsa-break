/* Structure of binary tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
}; */
class Solution {
public:
    int search(vector<int>& inorder, int left, int right, int val) {
        for (int i = left; i <= right; i++) {
            if (inorder[i] == val)
                return i;
        }
        return -1;
    }

    Node* helper(vector<int>& inorder, vector<int>& postorder,int& postIdx, int left, int right) {
        if (left > right)
            return NULL;

        int val = postorder[postIdx--];
        Node* root = new Node(val);

        int inIdx = search(inorder, left, right, val);

        root->right = helper(inorder, postorder, postIdx, inIdx + 1, right);
        root->left = helper(inorder, postorder, postIdx, left, inIdx - 1);

        return root;
    }

    Node* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIdx = postorder.size() - 1;

        return helper(inorder, postorder, postIdx, 0, inorder.size() - 1);
    }
};