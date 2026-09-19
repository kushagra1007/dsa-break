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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {

        if (root1 == NULL)
            return root2;

        if (root2 == NULL)
            return root1;

        queue<pair<TreeNode*, TreeNode*>> q;

        q.push({root1, root2});

        while (!q.empty()) {

            TreeNode* a = q.front().first;
            TreeNode* b = q.front().second;
            q.pop();

            a->val = a->val + b->val;

            // Left child
            if (a->left == NULL)
                a->left = b->left;
            else if (b->left != NULL)
                q.push({a->left, b->left});

            // Right child
            if (a->right == NULL)
                a->right = b->right;
            else if (b->right != NULL)
                q.push({a->right, b->right});
        }

        return root1;
    }
};