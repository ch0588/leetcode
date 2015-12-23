/*
设状态为 f(i, j),表示 T[0,j] 在 S[0,i] 里出现的次数。首先,无论 S[i] 和 T[j] 是 否相等,若不使用 S[i],则 f(i, j) = f(i − 1, j);若 S[i]==T[j],则可以使用 S[i],此时 f(i,j) = f(i−1,j)+f(i−1,j −1)。
*/
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        if(n==0 || m==0) return 0;
        
        int dp[n][m];
        memset(dp,0,sizeof(dp));
        dp[0][0] = s[0]==t[0]?1:0;
        for(int i=1; i<n; ++i)
            dp[i][0] = dp[i-1][0] + (s[i]==t[0]?1:0);
            
        for(int i=1; i<n; ++i)
            for(int j=1; j<m && j<=i; ++j)
                dp[i][j] = dp[i-1][j] + (s[i]==t[j]?dp[i-1][j-1]:0);
 
        return dp[n-1][m-1];
    }
};