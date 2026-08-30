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
    int ans = INT_MAX;
    int prev = 0;
    bool first = true;
    void traverse(TreeNode* node){
        if(node == NULL) return;
        
        traverse(node->left);

        if (!first)
            ans = min(ans, node->val - prev);
        prev = node->val;
        first = false;
        traverse(node->right);
    }
    int minDiffInBST(TreeNode* root) {
        traverse(root);
        return ans;
    }
};