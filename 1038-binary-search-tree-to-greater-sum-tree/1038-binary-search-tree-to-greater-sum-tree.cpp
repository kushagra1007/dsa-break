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
    void storeInorder(TreeNode* root, vector<int>& arr) {
        if (root == nullptr)
            return;

        storeInorder(root->left, arr);
        arr.push_back(root->val);
        storeInorder(root->right, arr);
    }

    void updateTree(TreeNode* root, vector<int>& arr, int& index) {
        if (root == nullptr)
            return;

        updateTree(root->left, arr, index);

        root->val = arr[index];
        index++;

        updateTree(root->right, arr, index);
    }

    TreeNode* bstToGst(TreeNode* root) {
        vector<int> arr;
        storeInorder(root, arr);
        for (int i = arr.size() - 2; i >= 0; i--) {
            arr[i] += arr[i + 1];
        }
        int index = 0;
        updateTree(root, arr, index);

        return root;
    }
};