class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int s2t[128],t2s[128];
        for(int i=0; i<128; ++i)
            s2t[i] = t2s[i] = -1;
        
        int len = s.size();
        if(len!=t.size()) return false;
        
        for(int i=0; i<len; ++i){
            int x = (int)s[i];
            int y = (int)t[i];
            if(s2t[x]==-1) s2t[x]=y;
            if(t2s[y]==-1) t2s[y]=x;
            if(s2t[x]!=y || t2s[y]!=x) return false;
        }
        return true;
    }
};