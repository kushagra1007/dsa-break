class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<vector<TreeNode*>>> dp(n + 2, vector<vector<TreeNode*>>(n + 2));

        for (int i = 1; i <= n + 1; i++) {
            dp[i][i - 1] = {NULL};
        }

        for (int len = 1; len <= n; len++) {
            for (int start = 1; start + len - 1 <= n; start++) {
                int end = start + len - 1;

                if (start == end) {
                    dp[start][end] = {new TreeNode(start)};
                    continue;
                }

                for (int i = start; i <= end; i++) {
                    vector<TreeNode*> left_bsts = dp[start][i - 1];
                    vector<TreeNode*> right_bsts = dp[i + 1][end];

                    for (TreeNode* leftRoot : left_bsts) {
                        for (TreeNode* rightRoot : right_bsts) {
                            TreeNode* root = new TreeNode(i);

                            root->left = leftRoot;
                            root->right = rightRoot;

                            dp[start][end].push_back(root);
                        }
                    }
                }
            }
        }

        return dp[1][n];
    }
};