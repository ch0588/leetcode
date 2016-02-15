class TrieNode {
public:
    int cnt;
    TrieNode* children[26];
    // Initialize your data structure here.
    TrieNode() {
        cnt = 0;
        for (int i = 0; i < 26; ++i) children[i] = NULL;
    }
};

class Trie {
public:
    Trie() { root = new TrieNode(); }
    
    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* cur = root;
        int len = word.size();
        for (int i = 0; i < len; ++i) {
            int x = word[i] - 'a';
            if (cur->children[x] == NULL) cur->children[x] = new TrieNode();
            cur = cur->children[x];
        }
        cur->cnt = cur->cnt + 1;
    }
    
    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* cur = root;
        int len = word.size();
        for (int i = 0; i < len; ++i) {
            int x = word[i] - 'a';
            if (cur->children[x] == NULL) return false;
            cur = cur->children[x];
        }
        if (cur->cnt > 0)
            return true;
        else
            return false;
    }
    
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        int len = prefix.size();
        for (int i = 0; i < len; ++i) {
            int x = prefix[i] - 'a';
            if (cur->children[x] == NULL) return false;
            cur = cur->children[x];
        }
        return true;
    }
    
private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");