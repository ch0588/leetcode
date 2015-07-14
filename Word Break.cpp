class Solution {
public:
    vector<int>f;
    bool dfs(int x,string s,unordered_set<string> &dict){
        if(x<=0) return 1;
        if(f[x]!=-1) return f[x];
        for(int i=0; i<x; ++i){
            if( dfs(i,s,dict)==1 && dict.count(s.substr(i,x-i)) )
                return f[x] = 1;
        }
        return f[x] = 0;
    }
    bool wordBreak(string s, unordered_set<string> &dict) {
        f.resize(s.size()+1);
        for(int i=0; i<f.size(); ++i) f[i] = -1;
        f[0] = 1;
        return dfs(s.size(), s, dict)==1;
    }
};
