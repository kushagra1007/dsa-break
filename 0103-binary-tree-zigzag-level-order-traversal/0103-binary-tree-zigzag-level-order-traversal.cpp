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

    void solve(TreeNode* root, int level, vector<vector<int>>& ans) {

        if (root == NULL)
            return;

        if (level == ans.size())
            ans.push_back({});

        if (level % 2 == 0)
            ans[level].push_back(root->val);
        else
            ans[level].insert(ans[level].begin(), root->val);

        solve(root->left, level + 1, ans);
        solve(root->right, level + 1, ans);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        solve(root, 0, ans);

        return ans;
    }
};