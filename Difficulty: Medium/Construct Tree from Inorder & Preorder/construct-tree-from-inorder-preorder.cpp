/* Structure of a Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
public:
    unordered_map<int, int> mp;
    int preIdx;

    Node* helper(vector<int>& inorder, vector<int>& preorder,
                 int left, int right) {
        if (left > right)
            return NULL;

        int val = preorder[preIdx++];
        Node* root = new Node(val);

        int inIdx = mp[val];

        root->left = helper(inorder, preorder, left, inIdx - 1);
        root->right = helper(inorder, preorder, inIdx + 1, right);

        return root;
    }

    Node* buildTree(vector<int>& inorder, vector<int>& preorder) {
        mp.clear();

        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        preIdx = 0;

        return helper(inorder, preorder, 0, inorder.size() - 1);
    }
};