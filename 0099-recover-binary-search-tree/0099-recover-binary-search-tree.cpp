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
    void recoverTree(TreeNode* root) {
        TreeNode* first = NULL;
        TreeNode* second = NULL;
        TreeNode* prev = NULL;
        TreeNode* curr = root;

        while (curr != NULL) {

            if (curr->left == NULL) {
                if (prev != NULL && prev->val > curr->val) {
                    if (first == NULL)
                        first = prev;

                    second = curr;
                }

                prev = curr;
                curr = curr->right;
            }
            else {
                TreeNode* pred = curr->left;

                while (pred->right != NULL && pred->right != curr)
                    pred = pred->right;

                if (pred->right == NULL) {
                    pred->right = curr;
                    curr = curr->left;
                }
                else {
                    pred->right = NULL;
                    if (prev != NULL && prev->val > curr->val) {
                        if (first == NULL)
                            first = prev;

                        second = curr;
                    }

                    prev = curr;
                    curr = curr->right;
                }
            }
        }
        swap(first->val, second->val);
    }
};