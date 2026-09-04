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
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        TreeNode* curr = root;

        while (curr != nullptr) {
            if (curr->right != nullptr) {
                TreeNode* temp = curr->right;

                while (temp->left != nullptr &&
                       temp->left != curr) {
                    temp = temp->left;
                }
                if (temp->left == nullptr) {
                    temp->left = curr;
                    curr = curr->right;
                }
                else {
                    temp->left = nullptr;
                    sum += curr->val;
                    curr->val = sum;

                    curr = curr->left;
                }
            }
            else {
                sum += curr->val;
                curr->val = sum;

                curr = curr->left;
            }
        }

        return root;
    }
};