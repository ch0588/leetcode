class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        bool f[2][m+1];
        memset(f,false,sizeof(f));
        f[0][0] = true;
        int i = 0;
        while(i<m && p[i]=='*'){
            f[0][i+1] = true;
            i++;
        }
        int x = 0;
        for(int i=1; i<=n; ++i){
            x = x^1;
            for(int j=1; j<=m; ++j){
                if(p[j-1]=='*')
                    f[x][j] = f[x^1][j] || f[x][j-1];
                else
                    f[x][j] = f[x^1][j-1] && (s[i-1]==p[j-1] || p[j-1]=='?');

            }
            f[x^1][0] = f[x][0];

        }
        return f[x][m];
    }
};
