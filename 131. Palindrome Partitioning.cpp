class Solution {
public:
    
    vector<vector<string>>res;
    string input;
    int len;
    bool isP(string s){
        int l=0, r=s.size()-1;
        while(s[l]==s[r] && l<=r) l++,r--;
        return l>r;
    }
    
    void dfs(int pos,vector<string>cur){
        if(pos>=len){
            res.push_back(cur);
            return;
        }
        string t="";
        for(int i=pos; i<len; ++i){
            t+=input[i];
            if(isP(t)){
                cur.push_back(t);
                dfs(i+1,cur);
                cur.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        res.clear();
        input = s;
        len = s.size();
        vector<string>cur;
        dfs(0,cur);
        return res;
    }
};