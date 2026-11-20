//Last Solved on: 28 Oct, 2026, Wednesday
//Last Solved in: 35 minutes

class TrieNode {
public:
    TrieNode* children[26];
    bool isWord;

    TrieNode() {
        isWord = false;
        memset(children, 0, sizeof(children));
    }
};

class WordDictionary {
    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* current = root;

        for (char c : word) {
            int index = c - 'a';

            if (!current->children[index]) {
                current->children[index] = new TrieNode();
            }

            current = current->children[index];
        }

        current->isWord = true;
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }

    bool dfs(string& word, int i, TrieNode* node) {
        if (i == word.size()) {
            return node->isWord;
        }

        char c = word[i];

        if (c == '.') {
            for (int j = 0; j < 26; j++) {
                if (node->children[j] &&
                    dfs(word, i + 1, node->children[j])) {
                    return true;
                }
            }

            return false;
        }

        int index = c - 'a';

        if (!node->children[index]) {
            return false;
        }

        return dfs(word, i + 1, node->children[index]);
    }
};