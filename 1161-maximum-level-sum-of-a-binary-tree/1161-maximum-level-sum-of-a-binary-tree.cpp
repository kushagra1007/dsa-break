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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int maxSum = INT_MIN;
        int answer;
        int level = 1;
        while(!q.empty()){
            int n = q.size();
            int sum = 0;
            for(int i=0;i<n;i++){
                TreeNode *node = q.front();
                q.pop();
                sum += node->val;

                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            if(sum>maxSum){
                maxSum = sum;
                answer = level;
            }
            level++;
        }
        return answer;
    }
};