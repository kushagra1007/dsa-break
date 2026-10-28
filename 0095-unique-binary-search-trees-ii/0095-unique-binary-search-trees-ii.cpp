class Solution {
public:
    map<pair<int, int>, vector<TreeNode*>> dp;

    vector<TreeNode*> solve(int start, int end) {
        if (start > end) {
            return {NULL};
        }
        if (start == end) {
            TreeNode* root = new TreeNode(start);
            return {root};
        }

        if (dp.find({start, end}) != dp.end()) {
            return dp[{start, end}];
        }

        vector<TreeNode*> result;

        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left_bsts = solve(start, i - 1);
            vector<TreeNode*> right_bsts = solve(i + 1, end);

            for (TreeNode* leftRoot : left_bsts) {
                for (TreeNode* rightRoot : right_bsts) {
                    TreeNode* root = new TreeNode(i);

                    root->left = leftRoot;
                    root->right = rightRoot;

                    result.push_back(root);
                }
            }
        }

        return dp[{start, end}] = result;
    }

    vector<TreeNode*> generateTrees(int n) {
        dp.clear();
        return solve(1, n);
    }
};