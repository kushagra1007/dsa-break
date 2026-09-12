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

    void solve(TreeNode* root, int level, unsigned long long index,
               vector<unsigned long long>& leftIndex, int& maxWidth) {

        if (root == NULL)
            return;

        if (level == leftIndex.size())
            leftIndex.push_back(index);

        maxWidth = max(maxWidth,
                       (int)(index - leftIndex[level] + 1));

        unsigned long long currIndex = index - leftIndex[level];

        solve(root->left, level + 1, 2 * currIndex + 1,
              leftIndex, maxWidth);

        solve(root->right, level + 1, 2 * currIndex + 2,
              leftIndex, maxWidth);
    }

    int widthOfBinaryTree(TreeNode* root) {

        if (root == NULL)
            return 0;

        vector<unsigned long long> leftIndex;

        int maxWidth = 0;

        solve(root, 0, 0, leftIndex, maxWidth);

        return maxWidth;
    }
};