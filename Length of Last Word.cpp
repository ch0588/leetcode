class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int n = strlen(s);
        int last_end = n-1;
        while(s[last_end]==' ' && last_end>=0) last_end--;
        int ans = 0;
        while(s[last_end]!=' ' && last_end>=0) ans++,last_end--;
        return ans;
    }
};
