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
    void dfs(TreeNode* root, int level, vector<int>& sum) {
        if (root == nullptr)
            return;

        if (level == sum.size())
            sum.push_back(0);

        sum[level] += root->val;

        dfs(root->left, level + 1, sum);
        dfs(root->right, level + 1, sum);
    }

    int maxLevelSum(TreeNode* root) {
        vector<int> sum;

        dfs(root, 0, sum);

        int maxSum = sum[0];
        int answer = 1;

        for (int i = 1; i < sum.size(); i++) {
            if (sum[i] > maxSum) {
                maxSum = sum[i];
                answer = i + 1;
            }
        }

        return answer;
    }
};