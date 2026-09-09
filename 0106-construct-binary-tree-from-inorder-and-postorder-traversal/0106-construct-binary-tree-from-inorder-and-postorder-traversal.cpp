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
    unordered_map<int, int> mp;

    TreeNode* helper(vector<int>& postorder, int& postIdx, int left, int right) {
        if (left > right) {
            return NULL;
        }

        int val = postorder[postIdx--];
        TreeNode* root = new TreeNode(val);

        int inIdx = mp[val];

        root->right = helper(postorder, postIdx, inIdx + 1, right);
        root->left = helper(postorder, postIdx, left, inIdx - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        int postIdx = postorder.size() - 1;

        return helper(postorder, postIdx, 0, inorder.size() - 1);
    }
};