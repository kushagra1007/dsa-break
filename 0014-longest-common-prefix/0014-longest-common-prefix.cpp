class Solution {
public:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;

        TrieNode() {
            for(int i = 0; i < 26; i++)
                children[i] = NULL;
            isEnd = false;
        }
    };

    string longestCommonPrefix(vector<string>& strs) {
        TrieNode* root = new TrieNode();

        for(string s : strs) {
            TrieNode* curr = root;

            for(char ch : s) {
                int idx = ch - 'a';

                if(curr->children[idx] == NULL)
                    curr->children[idx] = new TrieNode();

                curr = curr->children[idx];
            }

            curr->isEnd = true;
        }

        string ans = "";
        TrieNode* curr = root;

        while(true) {
            int count = 0;
            int index = -1;

            for(int i = 0; i < 26; i++) {
                if(curr->children[i] != NULL) {
                    count++;
                    index = i;
                }
            }

            if(count != 1 || curr->isEnd)
                break;

            ans += char(index + 'a');
            curr = curr->children[index];
        }

        return ans;
    }
};