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
    bool solver(TreeNode* node,long long minVal,long long maxVal){
        if(node == NULL){
            return true;
        }
        if(node->val <= minVal || node->val >= maxVal){
            return false;
        }
        return solver(node->left,minVal,node->val) && solver(node->right,node->val,maxVal);
    }
    bool isValidBST(TreeNode* root) {
        return solver(root,LLONG_MIN,LLONG_MAX);
    }
};