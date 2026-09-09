/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> inMap;
    int preIdx = 0;

    TreeNode* helper(vector<int>& preorder, int left, int right) {
        if (left > right) {
            return NULL;
        }
        int rootVal = preorder[preIdx++];
        TreeNode* root = new TreeNode(rootVal);
        int inIdx = inMap[rootVal];

        root->left = helper(preorder, left, inIdx - 1);
        root->right = helper(preorder, inIdx + 1, right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        return helper(preorder, 0, inorder.size() - 1);
    }
};