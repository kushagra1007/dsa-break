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

    void serializeHelper(TreeNode* root, string& s) {
        if (!root) {
            s += "# ";
            return;
        }

        s += to_string(root->val) + " ";

        serializeHelper(root->left, s);
        serializeHelper(root->right, s);
    }

    string serialize(TreeNode* root) {
        string s;
        serializeHelper(root, s);
        return s;
    }

    TreeNode* deserializeHelper(stringstream& ss) {
        string x;
        ss >> x;

        if (x == "#")
            return NULL;

        TreeNode* root = new TreeNode(stoi(x));

        root->left = deserializeHelper(ss);
        root->right = deserializeHelper(ss);

        return root;
    }
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserializeHelper(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));