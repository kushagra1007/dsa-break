class Solution {
public:
    TreeNode* invert(TreeNode* root) {
        if (root == NULL)
            return NULL;

        TreeNode* left = invert(root->left);
        TreeNode* right = invert(root->right);

        root->left = right;
        root->right = left;

        return root;
    }

    TreeNode* invertTree(TreeNode* root) {
        return invert(root);
    }
};