/*f[i][j],代表s中的前i个和模式p中前j个是否匹配。（下标从1开始）
*前面一定有一个前导字符，初始化时考虑*
memset(f,0,sizeof(f));
f[0][0] = true;
for(int j=2; j<=lenp; j+=2){
    if(f[0][j-2]&&s[j-1]=='*') f[0][j] = true;
    else break;
}
转移时，如果s中的第i个字符(p[i-1])是*,那么可以忽略p[i-2],也可以去匹配p[i-2],f[i][j] = f[i][j-2] || f[i-1][j] && (s[i-1]==p[j-2]||p[j-2]=='.');
如果s中的第i个字符(p[i-1])不是*,那么必须去匹配p[i-1],f[i][j] = f[i-1][j-1] && (s[i-1]==p[j-1]||p[j-1]=='.')
*/






class Solution {
public:
    bool isMatch(string s, string p) {
        int lens = s.size(), lenp = p.size();
        bool f[lens+1][lenp+1];
        memset(f,false,sizeof(f));
        f[0][0] = true;
        for(int j=2; j<=lenp; j+=2){
            if(f[0][j-2]&&p[j-1]=='*') f[0][j] = true;
            else break;
        }

        for(int i=1; i<=lens; ++i)
            for(int j=1; j<=lenp; ++j)
                if(p[j-1]=='*')
                    f[i][j] = f[i][j-2] || f[i-1][j]&&(s[i-1]==p[j-2]||p[j-2]=='.');
                else
                    f[i][j] = f[i-1][j-1]&&(s[i-1]==p[j-1]||p[j-1]=='.');
        return f[lens][lenp];
    }
};


//dfs
bool isMatch(const char *s, const char *p) {
    if(!*p) return !*s;
    if(!*s) return *(p+1)=='*' && isMatch(s, p+2);
    if(*(p+1)=='*')
        return isMatch(s, p+2) || (*s==*p || *p=='.') && isMatch(s+1, p);
    else
        return (*s==*p || *p=='.') && isMatch(s+1, p+1);
}
