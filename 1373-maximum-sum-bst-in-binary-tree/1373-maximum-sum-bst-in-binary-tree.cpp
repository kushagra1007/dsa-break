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
    unordered_map<TreeNode*, int> mn, mx, sum;
    unordered_map<TreeNode*, bool> bst;

    int ans = 0;

    void dfs(TreeNode* root) {
        if (root == NULL)
            return;

        dfs(root->left);
        dfs(root->right);

        // Initially assume current subtree is BST
        bst[root] = true;

        // Check left subtree
        if (root->left != NULL) {
            if (!bst[root->left] || mx[root->left] >= root->val) {
                bst[root] = false;
            }
        }

        // Check right subtree
        if (root->right != NULL) {
            if (!bst[root->right] || mn[root->right] <= root->val) {
                bst[root] = false;
            }
        }

        if (bst[root]) {
            mn[root] = root->left ? mn[root->left] : root->val;
            mx[root] = root->right ? mx[root->right] : root->val;

            sum[root] = root->val;

            if (root->left)
                sum[root] += sum[root->left];

            if (root->right)
                sum[root] += sum[root->right];

            ans = max(ans, sum[root]);
        }
    }

    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};