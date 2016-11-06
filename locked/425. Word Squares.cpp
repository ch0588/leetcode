/*
Given a set of words (without duplicates), find all word squares you can build from them.

A sequence of words forms a valid word square if the kth row and column read the exact same string, where 0 ≤ k < max(numRows, numColumns).

For example, the word sequence ["ball","area","lead","lady"] forms a word square because each word reads the same both horizontally and vertically.

b a l l
a r e a
l e a d
l a d y
Note:
There are at least 1 and at most 1000 words.
All words will have the exact same length.
Word length is at least 1 and at most 5.
Each word contains only lowercase English alphabet a-z.
Example 1:

Input:
["area","lead","wall","lady","ball"]

Output:
[
  [ "wall",
    "area",
    "lead",
    "lady"
  ],
  [ "ball",
    "area",
    "lead",
    "lady"
  ]
]

Explanation:
The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).
Example 2:

Input:
["abat","baba","atan","atal"]

Output:
[
  [ "baba",
    "abat",
    "baba",
    "atan"
  ],
  [ "baba",
    "abat",
    "baba",
    "atal"
  ]
]

Explanation:
The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).
*/
class TrieNode {
public:
    TrieNode *ch[26];
    vector<int>pre;
    TrieNode () {
        memset(ch, 0, sizeof(ch));
        pre.clear();
    }
};
class Solution {
public:
    TrieNode *root;
    vector<vector<string>> res;
    vector<string> vec;
    int N;

    void backtrack(vector<string>& words, int level, TrieNode *root) {
        if (level >= words[0].size()) {
            res.push_back(vec);
            return;
        }
        string str = "";
        for (int i = 0; i < level; i++) 
            str += vec[i][level];
            
        TrieNode *cur = root;
        for (int i = 0; i < level; ++i) {
            if (!cur->ch[str[i]-'a']) return;
            cur = cur->ch[str[i]-'a'];
        }
        for (int i : cur->pre) {
            vec[level] = words[i];
            backtrack(words, level + 1, root);
        }
    }
    
    vector<vector<string>> wordSquares(vector<string>& words) {
        if (words.empty()) return res;
        int len = (int)words[0].size();
        vec.resize(len);
        N = words.size();
        
        root = new TrieNode();
        for (int p = 0; p < N; ++p) {
            TrieNode *cur = root;
            for (int i = 0; i < len; ++i) {
                int x = words[p][i] - 'a';
                if (!cur->ch[x]) cur->ch[x] = new TrieNode();
                cur = cur->ch[x];
                cur->pre.push_back(p);
            }
        }
        
        for (auto& word : words) {
            vec[0] = word;
            backtrack(words, 1, root);
        }
        return res;
    }
};


class Solution {
public:
    vector<vector<string>> res;
    
    int findFirst(const vector<string>& words, string str, int n) {
        int len = str.length();
        // for (int i = 0; i < n; ++i)
        //     if (words[i].substr(0, len) == str) return i;
        // return n;
        
        
        int l = 0, r = n-1, mid, R = n;
        while(l <= r) {
            mid = (l + r) / 2;
            if(str <= words[mid].substr(0, len)) {
                R = mid;
                r = mid - 1;
            }else {
                l = mid + 1;
            }
            
        }
        return R;
    }

    void dfs(const vector<string>& words, vector<string> path, int num, const int len, const int n) {
        if(num >= len) {
            res.push_back(path);
        }
        string str = "";
        for(int i = 0; i < num; ++i) {
            str += path[i][num];
        }
        
        int fir = findFirst(words, str, n);
        while(fir < n && words[fir].substr(0, num) == str) {
            path.push_back(words[fir]);
            dfs(words, path, num + 1, len, n);
            path.pop_back();
            fir++;
        }
    }
    
    vector<vector<string>> wordSquares(vector<string>& words) {
        int n = words.size();
        if(n <= 0) return res;
        int len = words[0].size();
        
        sort(words.begin(), words.end());
        
        vector<string> path;
        for(int i = 0; i < n; ++i) {
            path.push_back(words[i]);
            dfs(words, path, 1, len, n);
            path.pop_back();
            
        }
        return res;
    }
};
