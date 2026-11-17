class Trie {
public:
    struct Node {
        Node* children[26];
        bool isEnd;

        Node() {
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;

            isEnd = false;
        }
    };

    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;

        for (char c : word) {
            int index = c - 'a';

            if (node->children[index] == nullptr) {
                node->children[index] = new Node();
            }

            node = node->children[index];
        }

        node->isEnd = true;
    }

    bool search(string word) {
        Node* node = root;

        for (char c : word) {
            int index = c - 'a';

            if (node->children[index] == nullptr)
                return false;

            node = node->children[index];
        }

        return node->isEnd;
    }

    bool startsWith(string prefix) {
        Node* node = root;

        for (char c : prefix) {
            int index = c - 'a';

            if (node->children[index] == nullptr)
                return false;

            node = node->children[index];
        }

        return true;
    }
};