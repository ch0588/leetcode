class TrieNode {
public:
    int cnt;
    TrieNode* children[26];
    TrieNode() {
        cnt = 0;
        for(int i=0; i<26; ++i) children[i] = NULL;
    }
};

class WordDictionary {
private:
    TrieNode* root;
    bool query(string word,int pos,int len,TrieNode* cur){
        if(pos==len-1){
            if(word[pos]=='.'){
                for(int i=0; i<26; ++i)
                    if(cur->children[i] && cur->children[i]->cnt>0) return true;
                return false;
            }
            else{
                if( cur->children[word[pos]-'a'] && cur->children[word[pos]-'a']->cnt > 0 )
                    return true;
                return false;
            }
        }
        
        if(word[pos]=='.'){
            for(int i=0; i<26; ++i)
                if(cur->children[i]) 
                    if (query(word,pos+1,len,cur->children[i])) return true;
            return false;
        }
        else{
            int x = word[pos]-'a';
            if(cur->children[x]) return query(word,pos+1,len,cur->children[x]);
            return false;
        }
    }
public:

     WordDictionary(){
         root = new TrieNode();
     }
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *cur = root;
        int len = word.size();
        for(int i = 0; i < len; ++i){
            int x = word[i]-'a';
            if(cur->children[x]==NULL) cur->children[x] = new TrieNode();
            cur = cur->children[x];
        }
        cur->cnt = cur->cnt + 1;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return query(word,0,(int)word.size(),root);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");