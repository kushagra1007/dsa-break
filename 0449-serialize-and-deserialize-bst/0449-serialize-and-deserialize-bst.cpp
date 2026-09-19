/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void preorder(TreeNode* root, string& s) {
        if (!root){
            return;
        }
        s += to_string(root->val) + " ";

        preorder(root->left, s);
        preorder(root->right, s);
    }

    string serialize(TreeNode* root) {
        string s;
        preorder(root, s);
        return s;
    }

    TreeNode* build(vector<int>& v, int& i, int low, int high) {
        if (i == v.size() || v[i] < low || v[i] > high){
            return NULL;
        }
        TreeNode* root = new TreeNode(v[i++]);

        root->left = build(v, i, low, root->val);
        root->right = build(v, i, root->val, high);

        return root;
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        vector<int> v;
        int x;

        while (ss >> x){
            v.push_back(x);
        }
        int i = 0;
        return build(v, i, INT_MIN, INT_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;