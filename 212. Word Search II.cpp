class TrieNode {
public:
    int cnt;
    TrieNode* children[26];
    TrieNode() {
        cnt = 0;
        for(int i=0; i<26; ++i) children[i] = NULL;
    }
};

class Solution {
    TrieNode *root;
    int go[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
    int n,m;
    vector<string>res;
public:
    void dfs(vector<vector<char>>& board,vector<vector<bool>>& vis,string str,int x,int y,TrieNode *cur){
        if(x<0||x>=n || y<0||y>=m) return;
        if(vis[x][y]) return;
        if(cur->children[board[x][y]-'a']==NULL) return;
        
        cur = cur->children[board[x][y]-'a'];
        vis[x][y] = true;
        str += board[x][y];
        
        if(cur->cnt>0){
            res.push_back(str);
            cur->cnt = 0;
        }
        
        for(int k=0; k<4; ++k){
            int nx = x + go[k][0];
            int ny = y + go[k][1];
            dfs(board,vis,str,nx,ny,cur);
        }
        
        vis[x][y] = false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        res.clear();
        n = board.size();
        if(n==0) return res;
        m = board[0].size();
        
        root = new TrieNode();
        for(string word:words){
            int len = word.size();
            TrieNode *cur = root;
            for(int i=0; i<len; ++i){
                int x = word[i]-'a';
                if(cur->children[x]==NULL) cur->children[x] = new TrieNode();
                cur = cur->children[x];
            }
            cur->cnt = cur->cnt + 1;
        }
        vector<vector<bool>>vis(n);
        for(int i=0; i<n; ++i) vis[i].resize(m);
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j)
                vis[i][j] = false;
        
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j){
                dfs(board,vis,"",i,j,root);
            }
        return res;
    }
};