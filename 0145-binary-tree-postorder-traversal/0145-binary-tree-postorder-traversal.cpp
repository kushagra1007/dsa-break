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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;

        TreeNode* curr = root;
        TreeNode* lastVisited = NULL;

        while (curr != NULL || !st.empty()) {

            // Go left
            while (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            }

            TreeNode* node = st.top();

            // Go right if not visited
            if (node->right != NULL && lastVisited != node->right) {
                curr = node->right;
            }
            else {
                result.push_back(node->val);
                lastVisited = node;
                st.pop();
            }
        }

        return result;
    }
};

