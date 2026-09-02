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
    int ans;
    int maxDepth = -1;
    void leftMost(TreeNode* node,int height){
        if(node == NULL){
            return;
        }
        if(height>maxDepth){
            maxDepth = height;
            ans = node->val;
        }
        leftMost(node->left,height+1);
        leftMost(node->right,height+1);

    }
    int findBottomLeftValue(TreeNode* root) {
        leftMost(root,0);
        return ans;
    }
    
};