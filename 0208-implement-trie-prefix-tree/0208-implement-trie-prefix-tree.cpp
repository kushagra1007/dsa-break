class Trie {
public:
    struct Node {
        unordered_map<char, Node*> mp;
        bool flag = false;
    };

    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;

        for (char ch : word) {
            if (node->mp.find(ch) == node->mp.end()) {
                node->mp[ch] = new Node();
            }

            node = node->mp[ch];
        }

        node->flag = true;
    }

    bool search(string word) {
        Node* node = root;

        for (char ch : word) {
            if (node->mp.find(ch) == node->mp.end())
                return false;

            node = node->mp[ch];
        }

        return node->flag;
    }

    bool startsWith(string prefix) {
        Node* node = root;

        for (char ch : prefix) {
            if (node->mp.find(ch) == node->mp.end())
                return false;

            node = node->mp[ch];
        }

        return true;
    }
};