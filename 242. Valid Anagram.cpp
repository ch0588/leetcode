class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        if(n!=(int)t.size()) return false;
        
        int cnt[128] = {0};
        for(int i=0; i<n; ++i){
            cnt[s[i]]++;
            cnt[t[i]]--;
        }
        for(int i=0; i<128; ++i)
            if(cnt[i]!=0) return false;
        return true;
    }
};