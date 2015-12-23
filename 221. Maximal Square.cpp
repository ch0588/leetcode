/*
 the maximal size of the square that can be achieved at point (i, j)
 https://leetcode.com/discuss/38489/easy-solution-with-detailed-explanations-8ms-time-and-space
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n==0) return 0;
        int m = matrix[0].size();
        if(m==0) return 0;
        
        int dp[n][m];
        int res = 0;
        for(int i=0; i<m; ++i) {
            dp[0][i] = (matrix[0][i]=='1'?1:0);
            res = max(res,dp[0][i]);
        }
        for(int i=1; i<n; ++i) {
            dp[i][0] = (matrix[i][0]=='1'?1:0);
            res = max(res,dp[i][0]);
        }
        
        for(int i=1; i<n; ++i)
            for(int j=1; j<m; ++j){
                if(matrix[i][j]=='0')
                    dp[i][j] = 0;
                else{
                    int t = min(dp[i-1][j-1],dp[i-1][j]);
                    t = min(t,dp[i][j-1]);
                    dp[i][j] = t+1;
                    res = max(res,dp[i][j]);
                }
            }
        return res*res;
    }
};