/*
C(m+n-2,n-1)
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m<1||n<1) return 0;

        if(m>n) swap(m,n);
        int C[202][202];
        C[0][0] = 1;
        for(int i=1; i<=m+n-2; ++i){
            C[i][i] = C[i][0] = 1;
            C[i][1] = i;
        }
        for(int i=1; i<=m+n-2; ++i)
            for(int j=1; j<=i; ++j)
                C[i][j] = C[i-1][j] + C[i-1][j-1];

        return C[m+n-2][m-1];
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m<1||n<1) return 0;

        int f[101][101] = {0};
        f[1][1] = 1;
        for(int i=2; i<=m; ++i) f[1][i] = f[1][i-1];
        for(int i=2; i<=n; ++i) f[i][1] = f[i-1][1];

        for(int i=2; i<=n; ++i)
            for(int j=2; j<=m; ++j)
                f[i][j] = f[i-1][j] + f[i][j-1];

        return f[n][m];
    }
};
