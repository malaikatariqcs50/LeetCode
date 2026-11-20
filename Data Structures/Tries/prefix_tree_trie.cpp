// Last Solved on: 28 oct, 2026, Wednesday
// Last Solved in: 45 minutes

class TrieNode {
public:
    TrieNode* children[26];
    bool isWord;

    TrieNode() {
        isWord = false;
        memset(children, 0, sizeof(children));
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;

        for (char c : word) {
            int index = c - 'a';

            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }

            node = node->children[index];
        }

        node->isWord = true;
    }

    bool search(string word) {
        TrieNode* node = root;

        for (char c : word) {
            int index = c - 'a';

            if (!node->children[index])
                return false;

            node = node->children[index];
        }

        return node->isWord;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;

        for (char c : prefix) {
            int index = c - 'a';

            if (!node->children[index])
                return false;

            node = node->children[index];
        }

        return true;
    }
};