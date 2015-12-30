/*
There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.

For example,
Given the following words in dictionary,

[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]
The correct order is: "wertf".

Note:
You may assume all letters are in lowercase.
If the order is invalid, return an empty string.
There may be multiple valid order of letters, return any one of them is fine.

 */

class Solution {
public:
    string alienOrder(vector<string>& words) {
        int adj[26][26]={0};
        int d[26]={0},vis[26]={0};
        
        string s;
        for (string t : words) {
            for(char ch : t) vis[ch-'a'] = 1;
            for (int i=0; i<min(s.size(), t.size()); ++i) {
                char a = s[i], b = t[i];
                if (a != b) {
                    adj[a-'a'][b-'a'] = 1;
                    //cout<<a<<"->"<<b<<endl;
                    break;
                }
            }
            s = t;
        }
        for(int i=0; i<26; ++i)
            for(int j=0; j<26; ++j)
                if(adj[i][j]) d[j]++;
        
        string res;
        queue<int>Q;
        int n = 0;
        for(int i=0; i<26; ++i){
            if(vis[i]) n++;
            if(d[i]==0 && vis[i]) Q.push(i);
        }
        while(!Q.empty()){
            int now = Q.front();
            Q.pop();
            //cout<<(char)('a'+now)<<endl;
            res += string(1,'a'+now);
            for(int i=0; i<26; ++i)
                if(adj[now][i]){
                    d[i]--;
                    if(d[i]==0&&vis[i]){
                        Q.push(i);
                    }
                }
        }
        if(res.size()!=n) return "";
        //cout<<res<<endl;
        return res;
    }
};