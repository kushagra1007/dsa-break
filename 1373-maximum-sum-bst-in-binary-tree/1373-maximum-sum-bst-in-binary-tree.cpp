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
    struct Info{
        bool isBST;
        int minVal;
        int maxVal;
        int sum;
    };
    int ans = 0;
    Info solve(TreeNode* root){
        if(root == NULL){
            return {true,INT_MAX,INT_MIN,0};
        }
        Info left = solve(root->left);
        Info right = solve(root->right);
        if(left.isBST && right.isBST && left.maxVal < root->val && root->val < right.minVal){
            int sum = left.sum + right.sum + root->val;
            ans = max(ans,sum);
            int minVal = min(root->val,left.minVal);
            int maxVal = max(root->val,right.maxVal);
            return {true,minVal,maxVal,sum};
        }
        return {false,0,0,0};
    }
    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};