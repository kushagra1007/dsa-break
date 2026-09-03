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
    void level(TreeNode* node,int height,vector<int> &sum){
        if(node == NULL){
            return;
        }
        if(height == sum.size()){
            sum.push_back(0);
        }
        sum[height] += node->val;

        level(node->left,height+1,sum);
        level(node->right,height+1,sum);
    }
    int maxLevelSum(TreeNode* root) {
        vector<int> sum;
        level(root,0,sum);
        int maxAns = sum[0];
        int answer = 1;
        for(int i=1;i<sum.size();i++){
            if(sum[i]>maxAns){
                maxAns = sum[i];
                answer = i+1;
            }
        }
        return answer;
    }
};